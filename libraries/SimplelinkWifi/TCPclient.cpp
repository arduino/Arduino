#include "SimplelinkWifi.h"
#include "wifi.h"
extern WiFiClass WiFi;
#define socket_overflow 2

WiFiClient::WiFiClient() : clientSocket(255) {
rx_buf_pos=0;
rx_buf_fill=0;
}

WiFiClient::WiFiClient(long _sock) : clientSocket(_sock) {
rx_buf_pos=0;
rx_buf_fill=0;
}


int WiFiClient::available() {
  if (clientSocket != 255)
  {
      return clientSocket;
  }
   
  return 0;
}

int WiFiClient::read() {

	

   uint8_t b=0;

   if (!available())
     return -1;
	/*
	 recv(((long)clientSocket)&0xFF, &b, 1, 0);
	__delay_cycles(200); //add this delay for sending time finish
	*/
	
	if(!rx_buf_fill){
		rx_buf_fill=recv(((long)clientSocket)&0xFF, rx_buf, 16, 0);//RX_BUF_SIZE
		__delay_cycles(200);
		if(rx_buf_fill<=0) {
			rx_buf_fill=0;
			return 0;
		}
	}
	b=rx_buf[rx_buf_pos];
	rx_buf_pos++;
	if(rx_buf_pos>=rx_buf_fill){rx_buf_pos=0;rx_buf_fill=0;}
	
   return b;
}

uint8_t WiFiClient::connected()
{
  if (clientSocket == 255) {
    return 0;
  } else return 1;
}

WiFiClient::operator bool() {
  return clientSocket != 255;
}

int WiFiClient::connect(IPAddress ip, uint16_t port) {

	
	clientSocketAddr.sa_family = AF_INET;
    // Set the Port Number
    clientSocketAddr.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
    clientSocketAddr.sa_data[1] = (unsigned char)(port & 0x00FF);
	clientSocketAddr.sa_data[2] = ip[0];
	clientSocketAddr.sa_data[3] = ip[1];
	clientSocketAddr.sa_data[4] = ip[2];
	clientSocketAddr.sa_data[5] = ip[3];
	
	socklen_t addrlen;	
	addrlen = sizeof(clientSocketAddr);

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >=0)
	{
		
		__delay_cycles(100);

		if (sl_connect(clientSocket, (sockaddr *)&clientSocketAddr, addrlen) >=0)
		{
			
			__delay_cycles(100);
			// clientSocket=255;
			WiFi.countSocket(1);
			return 0;
		}
	}

    return 1;//ng
}


 size_t WiFiClient::write(uint8_t b)
{
	send(((long)clientSocket)&0xFF, &b, 1, 0);
	__delay_cycles(1200); //add this delay for sending time finish
    return 1;
}


 size_t WiFiClient::print(char* str)
{
	int strlen=0,i=0;

	while(str[strlen]!=0){
		strlen++;
	}
	
	if(strlen>0){
	
		do{
			if(strlen-i<TX_BUF_SIZE){
				send(((long)clientSocket)&0xFF, str+i, strlen-i, 0);
				i=strlen;
			}
			else {
				send(((long)clientSocket)&0xFF, str+i, TX_BUF_SIZE, 0);
				i+=TX_BUF_SIZE;
			}
		__delay_cycles(120); //add this delay for sending time finish
		}while(i<strlen);
	}
	/*
	send(((long)clientSocket)&0xFF, str, strlen, 0);
	__delay_cycles(120); //add this delay for sending time finish
	*/
    return strlen;
}
 size_t WiFiClient::println(char* buffer)
{
	/*
	size_t t=0;

	while(buffer[t]!=0){
		t++;
	}

	if(t>0){
		buffer[t]='\n';
		t++;
		send(((long)clientSocket)&0xFF, buffer, t, 0);
		__delay_cycles(120); //add this delay for sending time finish
	}
	
    return t;
	*/
	int t=print(buffer);
	send(((long)clientSocket)&0xFF, "\n", 1, 0);
		__delay_cycles(120); //add this delay for sending time finish
		
	return t+1;
}

 size_t WiFiClient::println()
{

		send(((long)clientSocket)&0xFF, "\n", 1, 0);
		__delay_cycles(120); //add this delay for sending time finish

    return 1;
}


 size_t WiFiClient::print(uint16_t val)
{
char *str;
	int strlen;
	strlen=sprintf(str,"%i",val);
	if(strlen>0){
		send(((long)clientSocket)&0xFF, str, strlen-1, 0);
		__delay_cycles(120); //add this delay for sending time finish
	}
    return 1;
}

 size_t WiFiClient::println(uint16_t val)
{
char *str;
	int strlen;
	strlen=sprintf(str,"%i",val);
	str[strlen]='\n';
	send(((long)clientSocket)&0xFF, str, strlen, 0);
	__delay_cycles(120); //add this delay for sending time finish

    return 1;
}

void WiFiClient::stop() {

  if (clientSocket == 255)
    return;

	closesocket(clientSocket);
	WiFi.countSocket(0);
	clientSocket = 255;
}