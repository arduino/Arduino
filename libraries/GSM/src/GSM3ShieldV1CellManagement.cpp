#include <GSM3ShieldV1CellManagement.h>
#include <util/delay.h>

GSM3ShieldV1CellManagement::GSM3ShieldV1CellManagement()
{
	memset(cells, 0, sizeof(Cell) * 7);
	cellsLength = 0;
	neighboursActivated = false;
}

bool GSM3ShieldV1CellManagement::parseCBC_available(bool& rsp)
{
	char c;
	bool powerDataFound = false;
	int i = 0;
	
	if (!(theGSM3ShieldV1ModemCore.theBuffer().chopUntil("+CBC", true)))
		rsp = false;
	else 
		rsp = true;
	
	while(((c = theGSM3ShieldV1ModemCore.theBuffer().read()) != 0) && (i < 12))
	{
		if((c < 58) && (c > 47))
			powerDataFound = true;
			
		if(powerDataFound)
		{
			if(c == 13 || c == 10)
				break;
		
			powerData[i] = c;
			i++;
		}
	}
	
	powerData[i]=0;
	
	return true;
}

bool GSM3ShieldV1CellManagement::parseQCCID_available(bool& rsp)
{
	char c;
	bool iccidFound = false;
	int i = 0;
	
	while(((c = theGSM3ShieldV1ModemCore.theBuffer().read()) != 0) && (i < 19))
	{
		if((c < 58) && (c > 47))
			iccidFound = true;
		
		if(iccidFound)
		{
			bufferICCID[i] = c;
			i++;
		}
	}
	bufferICCID[i]=0;
	
	return true;
}

bool GSM3ShieldV1CellManagement::parseGSN_available(bool& rsp)
{
	char c;
	bool imeiFound = false;
	int i = 0;
	
	while(((c = theGSM3ShieldV1ModemCore.theBuffer().read()) != 0) && (i < 15))
	{
		if((c < 58) && (c > 47))
			imeiFound = true;
		
		if(imeiFound)
		{
			bufferIMEI[i] = c;
			i++;
		}
	}
	
	bufferIMEI[i]=0;
	
	return true;
}

bool GSM3ShieldV1CellManagement::parseQENG_available(bool& rsp)
{
	char c;
	bool readingCell = true;
	
	rsp = false;
	
	// Ignore response until '+QENG: 1,0' or '+QENG: 1,1'
	if (!(theGSM3ShieldV1ModemCore.theBuffer().chopUntil("+QENG: 1,0", true)) && !(theGSM3ShieldV1ModemCore.theBuffer().chopUntil("+QENG: 1,1", true)))
		return rsp;
		
	// Ignore response until first '+QENG: 0,'
	if (!theGSM3ShieldV1ModemCore.theBuffer().chopUntil("+QENG: 0,", true))
		return rsp;
	
	int selectField = 0;
	int fieldIndex = 0;
	
	// Read all characters of response and save cell info into 'struct'
	while(((c = readCompleteResponse()) != 0) && (readingCell))
	{
		if(c == ',') // fields separator
		{
			if(selectField == 6)
				readingCell = false;
			else
				selectField++;
			
			fieldIndex = 0;
		}
		else
		{
			// Switch between different fields of response to save
			// Fields: <mcc>,<mnc>,<lac>,<cellid>,<bcch>,<bsic>,<dbm>,<c1>,<c2>,<txp>,<rla>,<tch>,<ts>,<maio>,<hsn>,<ta>,<rxq_sub>,<rxq_full> - See M95 manual.
			switch(selectField)
			{
				// MCC
				case 0:
					if(fieldIndex < 6) cells[0].mcc[fieldIndex] = c;
					break;
					
				// MNC
				case 1:
					if(fieldIndex < 6) cells[0].mnc[fieldIndex] = c;
					break;
					
				// LOCATION AREA
				case 2:
					if(fieldIndex < 6) cells[0].lac[fieldIndex] = c;
					break;
				
				// CELL ID
				case 3:
					if(fieldIndex < 8) cells[0].cellId[fieldIndex] = c;
					break;
				
				// BCCH
				case 4:
					break;
				
				// BSIC
				case 5:
					break;
					
				// DBM
				case 6:
					if(fieldIndex < 6) cells[0].dbm[fieldIndex] = c;
					break;
			}
			
			fieldIndex++;
		}
	}

	cellsLength = 1;
	rsp = true;
	
	if(neighboursActivated)
		extractNeighbours(rsp);
		
	return rsp;
}

bool GSM3ShieldV1CellManagement::extractNeighbours(bool &rsp)
{
	char c;
	bool readingCell = true;
	
	rsp = false;
	
	// Ignore response until first '+QENG: 1,'
	if (!theGSM3ShieldV1ModemCore.theBuffer().chopUntil("+QENG: 1,", true))
		return rsp;
	
	int selectField = 0;
	int fieldIndex = 0;
	
	// Read all characters of response and save cell info into 'struct'
	while(((c = readCompleteResponse()) != 0) && (readingCell))
	{	
		if(c == ',') // fields separator
		{
			if(selectField == 9)
				if(cellsLength > 6)
					readingCell = false;
				else
				{
					cellsLength++;
					selectField = 0;
				}
			else
				selectField++;
			
			fieldIndex = 0;
		}
		else if(((c == 'x' || c == ' ') || c == '\n') || c == '\r')
		{
			readingCell = false;
			if(c == 'x') cellsLength--;
		}
		else
		{
			// Switch between different fields of response to save
			// Fields: <ncell>,<bcch>,<dbm>,<bsic>,<c1>,<c2>,<mcc>,<mnc>,<lac>,<cellid> - See M95 manual.
			switch(selectField)
			{
				// NUMBER OF CELL
				case 0:
					break;
					
				// BCCH
				case 1:
					break;
					
				// DBM
				case 2:
					if(fieldIndex < 6) cells[cellsLength].dbm[fieldIndex] = c;
					break;
				
				// BSIC
				case 3:
					break;
				
				// C1
				case 4:
					break;
				
				// C2
				case 5:
					break;
					
				// MCC
				case 6:
					if(fieldIndex < 6) cells[cellsLength].mcc[fieldIndex] = c;
					break;
				
				// MNC
				case 7:
					if(fieldIndex < 6) cells[cellsLength].mnc[fieldIndex] = c;
					break;
				
				// LAC
				case 8:
					if(fieldIndex < 6) cells[cellsLength].lac[fieldIndex] = c;
					break;
				
				// CELL ID
				case 9:
					if(fieldIndex < 8) cells[cellsLength].cellId[fieldIndex] = c;
					break;
			}
			
			fieldIndex++;
		}
	}

	while((c = readCompleteResponse()) != 0);
	
	cellsLength++;	
	
	rsp = true;
	
	return rsp;
}

uint8_t GSM3ShieldV1CellManagement::updateLocation(bool neighbours)
{	
	memset(cells, 0, sizeof(Cell) * 7);
	cellsLength = 0;
	
	neighboursActivated = neighbours;
	
	theGSM3ShieldV1ModemCore.openCommand(this, UPDATELOCATION);
	updateLocationContinue();
	
	while(ready() == 0)
		delay(1000);
	
	return cellsLength;
}

void GSM3ShieldV1CellManagement::updateLocationContinue()
{
	bool resp;

	switch(theGSM3ShieldV1ModemCore.getCommandCounter())
	{
		case 1:
			theGSM3ShieldV1ModemCore.setCommandCounter(2);
			
			// Select between two commands if we want get neighbours cells
			if(neighboursActivated)
				theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+QENG=1,1"), false);
			else
				theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+QENG=1"), false);
				
			theGSM3ShieldV1ModemCore.print('\r');
			break;
		
		case 2:
			if (theGSM3ShieldV1ModemCore.genericParse_rsp(resp))
			{
				// Get neighbours cells requires more time 
				if(neighboursActivated)
					_delay_ms(15000);
				else
					_delay_ms(600);
					
				theGSM3ShieldV1ModemCore.setCommandCounter(3);
				theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+QENG?"));
			}
			else theGSM3ShieldV1ModemCore.closeCommand(1);
			break;
		
		case 3:
			if (resp)
			{
				if(parseQENG_available(resp))
					theGSM3ShieldV1ModemCore.closeCommand(3);
				else
					theGSM3ShieldV1ModemCore.closeCommand(2);
			}
			else theGSM3ShieldV1ModemCore.closeCommand(2);
			break;
	}
}

int8_t GSM3ShieldV1CellManagement::getPowerData(char *info)
{
	powerData = info;
	theGSM3ShieldV1ModemCore.openCommand(this, GETPOWERDATA);
	getPowerDataContinue();
	
	while(ready() == 0)
		delay(1000);
		
	return theGSM3ShieldV1ModemCore.getCommandError();
}

void GSM3ShieldV1CellManagement::getPowerDataContinue()
{
	bool resp;
	
	switch (theGSM3ShieldV1ModemCore.getCommandCounter())
	{
		case 1:
			
			theGSM3ShieldV1ModemCore.setCommandCounter(2);
			theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+CBC"), false);
			theGSM3ShieldV1ModemCore.print("\r");
			
			break;
			
		case 2:
			
			if (theGSM3ShieldV1ModemCore.genericParse_rsp(resp))
			{
				parseCBC_available(resp);
				if(resp)
					theGSM3ShieldV1ModemCore.closeCommand(2);
			}
			else
				theGSM3ShieldV1ModemCore.closeCommand(1);
			
			break;
	}
}

int8_t GSM3ShieldV1CellManagement::getICCID(char *iccid)
{
	bufferICCID = iccid;
	theGSM3ShieldV1ModemCore.openCommand(this, GETICCID);
	getICCIDContinue();
	
	while(ready() == 0)
		delay(1000);
		
	return theGSM3ShieldV1ModemCore.getCommandError();
}

int8_t GSM3ShieldV1CellManagement::getIMEI(char *imei)
{
	bufferIMEI = imei;
	theGSM3ShieldV1ModemCore.openCommand(this, GETIMEI);
	getIMEIContinue();
	
	while(ready() == 0)
		delay(1000);
		
	return theGSM3ShieldV1ModemCore.getCommandError();
}

void GSM3ShieldV1CellManagement::getICCIDContinue()
{
	bool resp;
	
	switch (theGSM3ShieldV1ModemCore.getCommandCounter())
	{
		case 1:
			theGSM3ShieldV1ModemCore.setCommandCounter(2);
			_delay_ms(500);
			theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+QCCID"), false);
			theGSM3ShieldV1ModemCore.print("\r");
			break;
			
		case 2:
			if(theGSM3ShieldV1ModemCore.genericParse_rsp(resp))
			{
				parseQCCID_available(resp);
				if(resp)
					theGSM3ShieldV1ModemCore.closeCommand(2);
			}
			else theGSM3ShieldV1ModemCore.closeCommand(1);
			break;
	}
}

void GSM3ShieldV1CellManagement::getIMEIContinue()
{
	bool resp;
	
	switch (theGSM3ShieldV1ModemCore.getCommandCounter())
	{
		case 1:
			theGSM3ShieldV1ModemCore.setCommandCounter(2);
			_delay_ms(500);
			theGSM3ShieldV1ModemCore.genericCommand_rq(PSTR("AT+GSN"), false);
			theGSM3ShieldV1ModemCore.print("\r");
			break;
			
		case 2:
			if(theGSM3ShieldV1ModemCore.genericParse_rsp(resp))
			{
				parseGSN_available(resp);
				if(resp)
					theGSM3ShieldV1ModemCore.closeCommand(2);
			}
			else theGSM3ShieldV1ModemCore.closeCommand(1);
			break;
	}
}

void GSM3ShieldV1CellManagement::manageResponse(byte from, byte to)
{
	switch(theGSM3ShieldV1ModemCore.getOngoingCommand())
	{
		default:
			// For remove enum switch warnings
			break;
		case GSM_NONE:
			theGSM3ShieldV1ModemCore.gss.cb.deleteToTheEnd(from);
			break;
		case UPDATELOCATION:
			updateLocationContinue();
			break;
		case GETICCID:
			getICCIDContinue();
			break;
		case GETIMEI:
			getIMEIContinue();
			break;
		case GETPOWERDATA:
			getPowerDataContinue();
			break;
	}
}

int GSM3ShieldV1CellManagement::readCompleteResponse()
{
	char charResponse;
		
	if(theGSM3ShieldV1ModemCore.theBuffer().availableBytes()==0)
		return 0;
	
	charResponse = theGSM3ShieldV1ModemCore.theBuffer().read(); 
	
	if(theGSM3ShieldV1ModemCore.theBuffer().availableBytes()==100)
		theGSM3ShieldV1ModemCore.gss.spaceAvailable();

	return charResponse;
}