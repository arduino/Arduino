#include "SimplelinkWifi.h"
#include "wifi.h"

#define NO_SOCKET_AVAIL 255

WiFiUDP::WiFiUDP() :   udpSocket (NO_SOCKET_AVAIL) {

	bytesRecvd = 0;
	packetSize = 25;
	memset(packetBuffer, 0, packetSize);
	memset(rx_buf, 0, sizeof(rx_buf));
}

/* Start WiFiUDP socket, listening at local port PORT */
uint8_t WiFiUDP::begin(uint16_t _port) {

	udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	udpSocketAddr.sa_family = AF_INET;
    // Set the Port Number
    udpSocketAddr.sa_data[0] = (unsigned char)((_port & 0xFF00)>> 8);
    udpSocketAddr.sa_data[1] = (unsigned char)(_port & 0x00FF);
    memset (&udpSocketAddr.sa_data[2], 0, 4);
	
	
	if (udpSocket != NO_SOCKET_AVAIL)
    {		
		bind(udpSocket, &udpSocketAddr, sizeof(sockaddr));
		WiFi.countSocket(1);
		return 1;
	}
	return 0;

}

int WiFiUDP::parsePacket()
{
	return available();
}
/* return number of bytes available in the current packet,
   will return zero if parsePacket hasn't been called yet */
int WiFiUDP::available() {


	socklen_t fromlen;
	sockaddr_in from;
	
	if (udpSocket >=0 && udpSocket!= 255 )
    {
		if(bytesRecvd ==0)
		{

			if( (bytesRecvd = recvfrom(udpSocket, &rx_buf, 150, 0, (sockaddr*)&from, &fromlen)) >0)
			{
				
				return bytesRecvd;
			}
		}
    }
	return 0;
}

int WiFiUDP::read(char* buffer, size_t len)
{
unsigned int i=0;
  if (bytesRecvd!=0)
  {
	while((i<len) && (i<bytesRecvd))
	{
		buffer[i] = rx_buf[i];
		i++;
	}
	buffer[i]='\0';
	bytesRecvd = 0;
	return i;
	
  }else{
	   return -1;
  }
}


int WiFiUDP::beginPacket(IPAddress ip, uint16_t port)
{
	udpSocketAddr2.sa_family = AF_INET;
    // Set the Port Number
    udpSocketAddr2.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
    udpSocketAddr2.sa_data[1] = (unsigned char)(port & 0x00FF);
	udpSocketAddr2.sa_data[2] = ip[0];
	udpSocketAddr2.sa_data[3] = ip[1];
	udpSocketAddr2.sa_data[4] = ip[2];
	udpSocketAddr2.sa_data[5] = ip[3];
	
	//socklen_t addrlen;	
	//addrlen = sizeof(udpSocketAddr2);

	if((udpSocket2 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >=0);
	WiFi.countSocket(1);

    return 0;//no good
}

size_t WiFiUDP::write(const uint8_t *buffer, size_t size)
{

	// //memcpy(packetBuffer, buffer, size);
	
	for ( unsigned int i = 0; i <size; i++)
	{
		if (buffer[i]!='\0')
		{
			packetBuffer[i] = buffer[i];
		}
		else packetBuffer[i] = '\0';
		}
	
	return sizeof(buffer);
	
  

}

int WiFiUDP::endPacket()
{


	sendto( (long)udpSocket2 &0xFF, &packetBuffer, sizeof(packetBuffer), 0, &udpSocketAddr2, sizeof(sockaddr));
	__delay_cycles(1200); //add this delay for sending time finish
	return 0;
}
void WiFiUDP::stop() {

  if (udpSocket == 255)
    return;

	closesocket(udpSocket);
	WiFi.countSocket(0);
	udpSocket = 255;
}
