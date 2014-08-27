/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  ************************************************************************
  *	C2000Uploader.java
  *
  *	abstract uploading baseclass for c2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  Uploader - abstract uploading baseclass (common to both uisp and avrdude)
  Part of the Arduino project - http://www.arduino.cc/

  Copyright (c) 2004-05
  Hernando Barragan

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  
  $Id$
*/
package processing.app.debug;

import processing.app.Base;
import processing.app.Preferences;
import processing.app.Serial;
import processing.app.SerialException;

import java.awt.Component;
import java.io.*;
import java.util.*;
import java.util.concurrent.Delayed;
import java.util.zip.*;

import javax.swing.*;

import gnu.io.*;

public class C2000Uploader extends Uploader implements MessageConsumer{
	private Serial serial;
	private String port;
	private String serialRate;
//	private int serialRate;
	int testInt, rcvInt;
	

	public C2000Uploader() {
		this.port = Preferences.get("serial.port");
	}
	
	//After Flash erase or Flash program, PC program is waiting for feedback
	boolean CheckFeedback()
	{
		while(serial.available() == 0)
		{		 	
		    	
		}

		rcvInt = serial.readChar();

		if(rcvInt != 'C'){
		System.err.println("Uploading flash kernel failed.");
			serial.dispose();
			return false;
		}
		rcvInt = 0;		
		return true;
	}
	
//	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
//	throws RunnerException, SerialException {
//		Scanner kernelScanner, appScanner;
//		String testString;		
//		
//		this.verbose = verbose;
//		Map<String, String> boardPreferences = Base.getBoardPreferences();
//		
//		//Setup serial objects
//	    serialRate = Preferences.getInteger("serial.debug_rate");
//		serial = new Serial(port, serialRate);
//		
//		
//		
//		System.out.println("Put C2000 LaunchPad switches Up-Down-Down and press the reset button");
//		Component frame = null;
//		JOptionPane.showMessageDialog(frame,
//			    "Put C2000 LaunchPad serial switch up and the boot switches Up-Down-Down and press the reset button before clicking OK.");
//
//		Target target = Base.getTarget();
//		Collection params = new ArrayList();
//		
//		//Find our flash kernel
//	    File flashKernel = new File(new File(new File(target.getFolder(), "flash_kernel"),"Debug"), "flash_kernel.txt");
//	    String flashKernelPath = flashKernel.getAbsolutePath();
//
//	    //Try to open Flash Kernel for reading
//	    try {
//			kernelScanner = new Scanner(new FileReader(flashKernel));
//		} catch (FileNotFoundException e) {
//			System.err.println("Energia couldn't find the flash kernel for the C2000 LaunchPad.");
//			System.err.println("Uploading aborted.");
//			serial.dispose();
//			return false;
//		}
//	    
//		System.out.println("Flash kernel found...loading");
//	    
//	    //Read start of file
//	    testString = kernelScanner.next();
//	    
//	    //Autobaud only works up to 38.4k baud on C2k LP
//	    serial.write('A');
//	    while(serial.available() == 0){
//	    	
//	    }
//    	rcvInt = serial.readChar();
//    	if(rcvInt != 'A'){
//    		System.err.println("Autobaud Failed.  Try a baud rate below 38.4k.");
//			serial.dispose();
//    		return false;
//    	}
//    	
//
//	    int CountInt;
//	    CountInt = 0;
//	    
//	    //Load the flash kernel
//	    while(kernelScanner.hasNextInt(16)){
//	    	testInt = kernelScanner.nextInt(16);
//	    	serial.write(testInt);
//	    	
//	    	CountInt++;
//	    }
//	    
//		System.out.println("Flash kernel load complete");
//
//		System.out.println("Flash kernel CountInt is " + CountInt);
//		
//	    
//	    //TODO Load the user application
//	    
//		//Find our application image
//	    File appImage = new File(buildPath + File.separator + className + ".txt");
//	    //Try to open application image for reading
//	    try {
//			appScanner = new Scanner(new FileReader(appImage));
//		} catch (FileNotFoundException e) {
//			System.err.println("Energia couldn't find the application image for the C2000 LaunchPad.");
//			System.err.println("Uploading aborted.");
//			serial.dispose();
//			return false;
//		}
//	    
//		System.out.println("Application found...loading");
//	    
//		//Read start of file
//	    testString = appScanner.next();
//	    
//	    //Wait for our kernel to boot
//	    try {
//	        Thread.sleep(2000);
//	    } catch(InterruptedException ex) {
//	        Thread.currentThread().interrupt();
//	    }
//	    
//	    //Autobaud only works up to 38.4k baud on C2k LP
//
//	    CountInt = 0;
//	    serial.clear();
//	    serial.write('A');
//	    while(serial.available() == 0){
//	    	
//	    }
//    	rcvInt = serial.readChar();
//    	if(rcvInt != 'A'){
//    		System.err.println("Autobaud Failed.  Try a baud rate below 38.4k.");
//			serial.dispose();
//    		return false;
//    	}
//	    //Load the flash kernel
//	    while(appScanner.hasNextInt(16)){
//
//	    	CountInt++;
//	    	testInt = appScanner.nextInt(16);
//	    	serial.write(testInt);
//
//	    	//22 contains Keyvalue and reserved words and Entry address
//	    	if(CountInt == 22)
//	    	{	   
//	    		CountInt =0x00;
//	    		break ;
//	    	}	    		    		    	
//	    }
//	    
//    	if(!CheckFeedback()){
//    		serial.dispose();
//	    	return false;
//    	}
//
//    	int wordData;
//    	int byteData;
//    	int j;
//    	int totalCount = 0;
//    	
//    	wordData = 0x0000;
//    	byteData = 0x0000;
//    	
//	    //Load the flash kernel
//	    while(appScanner.hasNextInt(16)){
//
//	    	testInt = appScanner.nextInt(16);
//	    	serial.write(testInt);	 
//	    	
//	    	// Get a dest addr
//	    	if(CountInt == 0x00 )
//	    	{		    	
//	    		wordData = testInt;		
//	    	}
//	    	else if(CountInt == 0x01)
//	    	{
//		    	byteData = testInt;		    	
//		    	// form the wordData from the MSB:LSB
//		    	wordData |= (byteData << 8);
//	    	}	    	   		    	
//
//	    	CountInt++;	  
//	    	totalCount++; 
//		    	
//	    	//If the next block size is 0, exit the while loop. 
//		    if(wordData == 0x00 && CountInt > 1)
//		    {
//		    	
//	    		for(j=0;j<10000000;j++);
//	    		
//	    		wordData = 0x0000;
//	        	byteData = 0x0000;
//	        	
//		    	break;		    
//		    }		    	
//		    //If the block size is bigger than 0x400 words, every 0x400 words later it takes time for flash program. Them waiting for feedback.
//		    else if((CountInt - 6) % 0x800 ==0 && CountInt > 6)
//		    {
//		    	if(!CheckFeedback()){
//		    		serial.dispose();
//			    	return false;
//		    	}
//		    }
//		    //If CountInt meets the block size, countint and dest addr will be initialized. 
//		    else if(CountInt == 2*(wordData + 3))
//	    	{	    		
//		    	if(!CheckFeedback()){
//		    		serial.dispose();
//			    	return false;
//		    	}
//		    	
//	    		wordData = 0x0000;
//	        	byteData = 0x0000;
//	        	CountInt = 0x00;
//	    	}	    		    		    	
//	    }	    
//	    
//	    
//    	///////////
//		System.out.println("Application loaded");
//		
//		/* debugging for flash program
//		System.out.println("CountInt is " + CountInt);
//		System.out.println("TotalInt is " + totalCount);
//		*/
//	    //Close the serial port
//		serial.dispose();
//	    return true;
//	}
	

	
	public boolean uploadUsingPreferences(String buildPath, String className, boolean usingProgrammer)
	throws RunnerException, SerialException {
		this.verbose = verbose;
		Map<String, String> boardPreferences = Base.getBoardPreferences();

		Target target = Base.getTarget();
		Collection params = new ArrayList();

		//if (Base.isMacOS() || Base.isLinux()) {
		if (Base.isMacOS()) {
			System.out.println("Firmware programming not currently supported in Linux and MacOS");
			Component frame = null;
			JOptionPane.showMessageDialog(frame,
				    "Firmware programming not currently supported in Linux and MacOS");
			return false;
	
		} else {
			System.out.println("Put C2000 LaunchPad switches Up-Down-Down and press the reset button");
			Component frame = null;
			JOptionPane.showMessageDialog(frame,
				    "Put C2000 LaunchPad serial switch up and the boot switches Up-Down-Down and press the reset button before clicking OK.");
		}

//		boolean ret = mspdebug(params);
		//Find our flash kernel
		String name = boardPreferences.get("build.mcu");
		File flashKernel;
		if(name.equals("TMS320F28027"))
		{
			flashKernel = new File(new File(new File(target.getFolder(), "F28027_flash_kernel"),"Debug"), "flash_kernel.txt");
		}
		else if(name.equals("TMS320F28069"))
		{
			flashKernel = new File(new File(new File(target.getFolder(), "F28069_flash_kernel"),"Debug"), "2806_flash_kernel.txt");
		}
		else
		{
			flashKernel = new File(new File(new File(target.getFolder(), "F28027_flash_kernel"),"Debug"), "flash_kernel.txt");
		}
	    String flashKernelPath = flashKernel.getAbsolutePath();
	    File appImage = new File(buildPath + File.separator + className + ".txt");
	    String applicationPath = appImage.getAbsolutePath();
	    File serialLoader = new File(new File(new File(target.getFolder(), "serial_loader2000"),"Release"), "serial_loader2000.exe");
	    String loaderPath = serialLoader.getAbsolutePath();

	    serialRate = String.format("%d", Preferences.getInteger("serial.debug_rate"));
	    List commandDownloader = new ArrayList();

//	    commandDownloader.add(loaderPath);
//	    commandDownloader.add(" -f " + applicationPath + " -k " + flashKernelPath + " -b " + serialRate + " -p " + port);
//	    commandDownloader.add("-f " + applicationPath);
//	    commandDownloader.add("-k " + flashKernelPath);
//	    commandDownloader.add("-b " + serialRate);
//	    commandDownloader.add("-p " + port);
//	    commandDownloader.add(String.format("%s -f %s -k %s -b %s -p %s",loaderPath, applicationPath, flashKernelPath, serialRate, port));

	    String osName = System.getProperty("os.name" );
        String[] cmd = new String[3];
        if( osName.equals( "Windows NT" ) || osName.equals( "Windows 7" ) )
        {
            cmd[0] = "cmd.exe" ;
            cmd[1] = "/C" ;
            cmd[2] = String.format("%s -f %s -k %s -b %s -p %s",loaderPath, applicationPath, flashKernelPath, serialRate, port);
        }
        else if( osName.equals( "Windows 95" ) )
        {
            cmd[0] = "command.com" ;
            cmd[1] = "/C" ;
            cmd[2] = String.format("%s -f %s -k %s -b %s -p %s",loaderPath, applicationPath, flashKernelPath, serialRate, port);
        }
        else if( osName.equals("Linux"))
        {
           	loaderPath = loaderPath.substring(0,loaderPath.length()-4);
        	cmd[0] = "bash" ;
            cmd[1] = "-c" ;
            cmd[2] = String.format("%s -f %s -k %s -b %s -p %s",loaderPath, applicationPath, flashKernelPath, serialRate, port);
        }
		return executeUploadCommand(cmd);
	}
	
//	  public void message(final String s) {
//		    SwingUtilities.invokeLater(new Runnable() {
//		      public void run() {
//		    	  System.out.println(s);
//		      }});
//		  }

	public boolean burnBootloader() throws RunnerException {
		//nothing do do for MSP430
		return false;
	}


}
