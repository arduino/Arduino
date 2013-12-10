#include "utility/SimplelinkWifi.h"
#include "WiFi.h"

WiFiServer::WiFiServer(uint16_t _port)
{
	serverSocket=-1;
	clientDescriptor = -1;
    port = _port;
}

 void WiFiServer::begin()
 {
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	serverSocketAddr.sa_family = AF_INET;
    // Set the Port Number
    serverSocketAddr.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
    serverSocketAddr.sa_data[1] = (unsigned char)(port & 0x00FF);
    memset (&serverSocketAddr.sa_data[2], 0, 4);
	

	if(serverSocket>=0 && serverSocket != 255 ){
		if (bind(serverSocket, &serverSocketAddr, sizeof(sockaddr)) != 0) 
		{
			return;
		}
	}

	if (listen (serverSocket, 1) != 0)
    {         
		return ;
    }


 }

 WiFiClient WiFiServer::available()
 {
	sockaddr clientaddr;
	socklen_t addrlen;	
	WiFi.countSocket(1);


	addrlen = sizeof(clientaddr);

    clientDescriptor = accept(serverSocket, (sockaddr *) &clientaddr, &addrlen);
	if(clientDescriptor<0) //return 0;
	return WiFiClient(255);

	WiFiClient client(clientDescriptor);

	return client;

 }
 
 size_t WiFiServer::write(uint8_t b)
{

	send(((long)clientDescriptor)&0xFF, &b, 1, 0);
    return 1;
}
 
