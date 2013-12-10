// serial_loader2000.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <stdint.h>

//*****************************************************************************
//
// Helpful macros for generating output depending upon verbose and quiet flags.
//
//*****************************************************************************
#define VERBOSEPRINT(...) if(g_bVerbose) { _tprintf(__VA_ARGS__); }
#define QUIETPRINT(...) if(!g_bQuiet) { _tprintf(__VA_ARGS__); }

//*****************************************************************************
//
// Globals whose values are set or overridden via command line parameters.
//
//*****************************************************************************
bool g_bVerbose = false;
bool g_bQuiet = false;
bool g_bOverwrite = false;
bool g_bUpload = false;
bool g_bClear = false;
bool g_bBinary = false;
bool g_bWaitOnExit = false;
bool g_bReset = false;
bool g_bSwitchMode = false;
wchar_t *g_pszAppFile = NULL;
wchar_t *g_pszKernelFile = NULL;
wchar_t *g_pszComPort = NULL;
wchar_t *g_pszBaudRate;
int g_iDeviceIndex = 0;

//COM Port stuff
HANDLE file;
DCB port;

//*****************************************************************************
//
// Exit the application, optionally pausing for a key press first.
//
//*****************************************************************************
void
ExitApp(int iRetcode)
{

	//
	// Has the caller asked us to pause before exiting?
	//
	if (g_bWaitOnExit)
	{
		_tprintf(_T("\nPress any key to exit...\n"));
		while (!_kbhit())
		{
			//
			// Wait for a key press.
			//
		}
	}

	exit(iRetcode);
}

//*****************************************************************************
//
// Display the welcome banner when the program is started.
//
//*****************************************************************************
void
PrintWelcome(void)
{
	if (g_bQuiet)
	{
		return;
	}

	_tprintf(_T("\nC2000 Serial Firmware Upgrader\n"));
	_tprintf(_T("Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.\n\n"));
}

//*****************************************************************************
//
// Show help on the application command line parameters.
//
//*****************************************************************************
void
ShowHelp(void)
{
	//
	// Only print help if we are not in quiet mode.
	//
	if (g_bQuiet)
	{
		return;
	}

	_tprintf(_T("This application may be used to download images to a Texas Instruments\n"));
	_tprintf(_T("C2000 microcontroller in the SCI boot mode.\n\n"));
	_tprintf(_T("Supported parameters are:\n\n"));

	_tprintf(_T("-f <file>    - The file name for download use.\n"));
	_tprintf(_T("               This file must be in the SCI boot format.\n"));
	_tprintf(_T("-k <file>    - The file name for flash kernel.\n"));
	_tprintf(_T("               This file must be in the SCI boot format.\n"));
	_tprintf(_T("-p COM<num>  - Set the COM port to be used for communications.\n"));
	_tprintf(_T("-b <num>     - Set the baud rate for the COM port.\n"));
	_tprintf(_T("-? or -h     - Show this help.\n"));
	_tprintf(_T("-q           - Quiet mode. Disable output to stdio.\n"));
	_tprintf(_T("-w           - Wait for a key press before exiting.\n"));
	_tprintf(_T("-v           - Enable verbose output\n\n"));
	_tprintf(_T("-f, -k, and -p are mandatory parameters.  If baud rate is omitted, \nthe communications will occur at 9600 baud.\n\n"));


	_tprintf(_T("Example:\n\n"));
	_tprintf(_T("serial_loader2000 -f application.txt -k flash_kernel.txt -p COM4 -b 38400\n"));
	_tprintf(_T("Writes an application in application.txt to flash of the target device using\n"));
    _tprintf(_T("the kernel in flash_kernel.txt.  COM port 4 is used to do the load \nat 38400 Baud.\n\n"));

	_tprintf(_T("Application and kernel files must be in the SCI8 boot format. \nThese can be generated using the hex2000 utility.  An example of how to do \nthis follows:\nhex2000 application.out -boot -sci8 -a -o application.txt\n\n"));


}

//*****************************************************************************
//
// Parse the command line, extracting all parameters.
//
// Returns 0 on success. On failure, calls ExitApp(1).
//
//*****************************************************************************
int
ParseCommandLine(int argc, wchar_t *argv[])
{
	int iParm;
	bool bShowHelp;
	wchar_t *pcOptArg;

	//
	// By default, don't show the help screen.
	//
	bShowHelp = false;

	// Set the default baud rate
	g_pszBaudRate = L"9600";

	//
	// Walk through each of the parameters in the list, skipping the first one
	// which is the executable name itself.
	//
	for (iParm = 1; iParm < argc; iParm++)
	{
		//
		// Does this look like a valid switch?
		//
		if (!argv || ((argv[iParm][0] != L'-') && (argv[iParm][0] != L'/')) ||
			(argv[iParm][1] == L'\0'))
		{
			//
			// We found something on the command line that didn't look like a
			// switch so bomb out.
			//
			_tprintf(_T("Unrecognized or invalid argument: %s\n"), argv[iParm]);
			ExitApp(1);
		}
		else
		{
			//
			// For convenience, get a pointer to the next argument since this
			// is often a parameter for a given switch (and since this code was
			// converted from a previous version which used getopt which is not
			// available in the Windows SDK).
			//
			pcOptArg = ((iParm + 1) < argc) ? argv[iParm + 1] : NULL;
		}

		switch (argv[iParm][1])
		{
		case 'w':
			g_bWaitOnExit = true;
			break;

		case 'f':
			g_pszAppFile = pcOptArg;
			iParm++;
			break;

		case 'k':
			g_pszKernelFile = pcOptArg;
			iParm++;
			break;

		case 'b':
			g_pszBaudRate = pcOptArg;
			iParm++;
			break;

		case 'p':
			g_pszComPort = pcOptArg;
			iParm++;
			break;

		case 'v':
			g_bVerbose = TRUE;
			break;

		case 'q':
			g_bQuiet = TRUE;
			break;

		case 'x':
			g_bOverwrite = TRUE;
			break;

		case '?':
		case 'h':
			bShowHelp = TRUE;
			break;

		default:
			_tprintf(_T("Unrecognized argument: %s\n"), argv[iParm]);
			ExitApp(1);
		}
	}

	//
	// Show the welcome banner unless we have been told to be quiet.
	//
	PrintWelcome();

	//
	// Show the help screen if requested.
	//
	if (bShowHelp)
	{
		ShowHelp();
		ExitApp(0);
	}

	//
	// Catch various invalid or pointless parameter cases.
	//
	if (!g_pszAppFile || !g_pszKernelFile || !g_pszComPort)
	{
		//
		// No file name provided.  If we haven't displayed it already,
		// show command line help then display the error information.
		//
		ShowHelp();

		if (!g_pszAppFile)
		{
			QUIETPRINT(_T("ERROR: No application file name was specified. Please use -f to provide one.\n"));
		}
		if (!g_pszKernelFile)
		{
			QUIETPRINT(_T("ERROR: No flash kernel file name was specified. Please use -k to provide one.\n"));
		}
		if (!g_pszComPort)
		{
			QUIETPRINT(_T("ERROR: No COM port number was specified. Please use -p to provide one.\n"));
		}

		ExitApp(1);
	}

	

	//
	// Tell the caller that everything is OK.
	//
	return(0);
}



//*****************************************************************************
//
// Download an image to the the device identified by the passed handle.  The
// image to be downloaded and other parameters related to the operation are
// controlled by command line parameters via global variables.
//
// Returns 0 on success or a positive error return code on failure.
//
//*****************************************************************************
int
DownloadImage(void)
{
	FILE *Kfh;
	FILE *Afh;
	unsigned char *pcKFileBuf;
	unsigned char *pcKNextChar;
	unsigned char *pcAFileBuf;
	unsigned char *pcANextChar;
	unsigned char sendData[8];
	unsigned int rcvData = 0;
	unsigned int rcvDataH = 0;
	unsigned int txCount = 0;
	size_t iLen;
	size_t iRead;
	bool bTIFormat;
	DWORD dwWritten;
	DWORD dwRead;
	uint16_t checksum;
	unsigned int fileStatus;
	unsigned char readLine[80];

	QUIETPRINT(_T("Downloading %s to device...\n"), g_pszAppFile);



	//
	// Does the input file exist?
	//
	Kfh = _tfopen(g_pszKernelFile, _T("rb"));
	if (!Kfh)
	{
		QUIETPRINT(_T("Unable to open Kernel file %s. Does it exist?\n"), g_pszAppFile);
		return(10);
	}
	//
	// How big is the file?
	//
	//fseek(Kfh, 0, SEEK_END);
	//iLen = ftell(Kfh);
	//fseek(Kfh, 0, SEEK_SET);

	//
	// Allocate a buffer large enough for the file.
	//
	//pcKFileBuf = (unsigned char *)malloc(iLen);
	//if (!pcKFileBuf)
	//{
	//	QUIETPRINT(_T("Error allocating %d bytes of memory!\n"), iLen);
	//	fclose(Kfh);
	//	return(11);
	//}

	//
	// Read the file into our buffer and check that it was correctly read.
	//
	//iRead = fread(pcKFileBuf, 1, iLen, Kfh);
	//fclose(Kfh);

	//if (iRead != iLen)
	//{
	//	QUIETPRINT(_T("Error reading input file!\n"));
	//	free(pcKFileBuf);
	//	return(12);
	//}
	//pcKNextChar = pcKFileBuf + 3;




	Afh = _tfopen(g_pszAppFile, L"rb");
	if (!Afh)
	{
		QUIETPRINT(_T("Unable to open Application file %s. Does it exist?\n"), g_pszAppFile);
		return(10);
	}
	//
	// How big is the file?
	//
	//fseek(Afh, 0, SEEK_END);
	//iLen = ftell(Afh);
	//fseek(Afh, 0, SEEK_SET);

	//
	// Allocate a buffer large enough for the file.
	//
	//pcAFileBuf = (unsigned char *)malloc(iLen);
	//if (!pcAFileBuf)
	//{
	//	QUIETPRINT(_T("Error allocating %d bytes of memory!\n"), iLen);
	//	fclose(Afh);
	//	return(11);
	//}

	//
	//Read the file into our buffer and check that it was correctly read.
	//
	//iRead = fread(pcAFileBuf, 1, iLen, Afh);
	//fclose(Afh);

	//if (iRead != iLen)
	//{
	//	QUIETPRINT(_T("Error reading input file!\n"));
	//	free(pcAFileBuf);
	//	return(12);
	//}
	//pcANextChar = pcAFileBuf;


	//Both Kernel, Application, and COM port are open
	//Time to blow an go!

	//Do AutoBaud
	dwRead = 0;
	sendData[0] = 'A';
	WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
	while (dwRead == 0)
	{
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	}

	if (sendData[0] != rcvData)
		return(12);

	VERBOSEPRINT(_T("\nKernel AutoBaud Successful"));
	//Find the start of the kernel data
	getc(Kfh);
	getc(Kfh);
	getc(Kfh);

	fileStatus = fscanf_s(Kfh, "%x", &sendData[0]);

	while (fileStatus == 1)
	{
		//Send next char
		WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
		//dwRead = 0;
		//while (dwRead == 0)
		//{
			//ReadFile(file, &rcvData, 1, &dwRead, NULL);
		//}
		////Ensure data matches
		//if (sendData[0] != rcvData)
		//	return(12);
		//Read next char
		fileStatus = fscanf_s(Kfh, "%x ", &sendData[0]);

	}

	VERBOSEPRINT(_T("\nKernel Loaded"));
	Sleep(5000);
	VERBOSEPRINT(_T("\nDone Waiting for kernel boot...attempting autobaud"));
	PurgeComm(file, PURGE_RXCLEAR);
	//Do AutoBaud
	sendData[0] = 'A';
	WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
	dwRead = 0;
	while (dwRead == 0)
	{
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	}

	if (sendData[0] != rcvData)
		return(12);

	VERBOSEPRINT(_T("\nApplication AutoBaud Successful"));
	//Find the start of the application data
	txCount = 0;
	checksum = 0;
	getc(Afh);
	getc(Afh);
	getc(Afh);



	while (txCount < 22)
	{
		txCount++;
		fscanf_s(Afh, "%x", &sendData[0]);
		checksum += sendData[0];
		//Send next char
		WriteFile(file, &sendData[0], 1, &dwWritten, NULL);

	}
	dwRead = 0;
	while (dwRead == 0)
	{
		ReadFile(file, &rcvData, 1, &dwRead, NULL);
	}	
	dwRead = 0;
	while (dwRead == 0)
	{
		ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
	}
	//Ensure checksum matches
	if (checksum != (rcvData | (rcvDataH << 8)))
		return(12);


	//RONNIES CODE
	int wordData;
	int byteData;
	txCount = 0;
	checksum = 0;
	int j;
	int totalCount = 0;
	wordData = 0x0000;
	byteData = 0x0000;
	fileStatus = 1;

	//Load the flash kernel
	while (1){

		if (totalCount == 0x101)
			j = 0;

		fileStatus = fscanf_s(Afh, "%x ", &sendData[0]);
		if (fileStatus == 0)
			break;
		WriteFile(file, &sendData[0], 1, &dwWritten, NULL);
		checksum += sendData[0];

		// Get a dest addr
		if (txCount == 0x00)
		{
			wordData = sendData[0];
		}
		else if (txCount == 0x01)
		{
			byteData = sendData[0];
			// form the wordData from the MSB:LSB
			wordData |= (byteData << 8);
		}

		txCount++;
		totalCount++;

		//If the next block size is 0, exit the while loop. 
		if (wordData == 0x00 && txCount > 1)
		{

			//for (j = 0; j<10000000; j++);

			wordData = 0x0000;
			byteData = 0x0000;

			break;
		}
		//If the block size is bigger than 0x400 words, every 0x400 words later it takes time for flash program. Them waiting for feedback.
		else if ((txCount - 6) % 0x800 == 0 && txCount > 6)
		{
			dwRead = 0;
			while (dwRead == 0)
			{
				ReadFile(file, &rcvData, 1, &dwRead, NULL);
			}
			dwRead = 0;
			while (dwRead == 0)
			{
				ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
			}
			//Ensure checksum matches
			if (checksum != (rcvData | (rcvDataH << 8)))
				return(12);
			else
				checksum = 0;
		}
		//If CountInt meets the block size, countint and dest addr will be initialized. 
		else if (txCount == 2 * (wordData + 3))
		{
			dwRead = 0;
			while (dwRead == 0)
			{
				ReadFile(file, &rcvData, 1, &dwRead, NULL);
			}
			dwRead = 0;
			while (dwRead == 0)
			{
				ReadFile(file, &rcvDataH, 1, &dwRead, NULL);
			}
			//Ensure checksum matches
			if (checksum != (rcvData | (rcvDataH << 8)))
				return(12);
			else
				checksum = 0;

			wordData = 0x0000;
			byteData = 0x0000;
			txCount = 0x00;
		}
	}

	VERBOSEPRINT(_T("\nApplication Load Successful"));

}


//*****************************************************************************
//
// The main entry point of the DFU programmer example application.
//
//*****************************************************************************
int
_tmain(int argc, TCHAR* argv[])
{
	int iRetCode = 0;
	int iExitCode = 0;
	int iDevIndex;
	bool bCompleted;
	bool bDeviceFound;
	TCHAR baudString[32];
	TCHAR comString[32];
	DWORD error;


	//
	// Parse the command line parameters, print the welcome banner and
	// tell the user about any errors they made.
	//
	ParseCommandLine(argc, argv);

	//Try opening the COM Port
	// open the comm port.
	//Append stupid windows crap to COM port name
	_stprintf(comString, _T("\\\\.\\%s"), g_pszComPort);
	file = CreateFile((LPCWSTR)comString,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	//Check if COM port opened correctly
	if (INVALID_HANDLE_VALUE == file) {
		QUIETPRINT(_T("Unable to open COM port %s...does someone else have it open?\n"), g_pszComPort);
		ExitApp(1);
	}

	//Append baudrate to config string
	_stprintf(baudString, _T("%s,n,8,1"), g_pszBaudRate);

	// get the current DCB, and adjust a few bits to our liking.
	memset(&port, 0, sizeof(port));
	port.DCBlength = sizeof(port);
	iRetCode = GetCommState(file, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("getting comm state \n"));
	}
	else
	{
		QUIETPRINT(_T("Problem Getting Comm State \n"));
		ExitApp(iExitCode);
	}


	iRetCode = BuildCommDCB((LPCTSTR)baudString, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("building comm DCB\n"));
	}
	else
	{
		QUIETPRINT(_T("Problem Building DCB...are your parameters correct? \n"));
		ExitApp(iExitCode);
	}

	iRetCode = SetCommState(file, &port);
	if (iRetCode)
	{
		QUIETPRINT(_T("adjusting port settings\n"));
	}
	else
	{
		QUIETPRINT(_T("Problem setting port configuration \n"));
		ExitApp(iExitCode);
	}

	iRetCode = DownloadImage();
	
	

	ExitApp(iExitCode);
}


