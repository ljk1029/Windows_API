#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") 

using namespace std;

bool BindSocket(SOCKET& socket,short port ,const char* Ip){
	sockaddr_in address;

	address.sin_family=AF_INET;
	address.sin_addr.s_addr =inet_addr(Ip);// set machine IP; 
	address.sin_port=htons(port);   // set machine port

	if(SOCKET_ERROR == bind(socket,(const struct sockaddr*)&address,sizeof(struct sockaddr)) ){
		return false;
	} 
	return true;
}

int tcp_server(int IP_port)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int port = IP_port;           //服务器端口号 
	char IPaddr[18] = {"127.0.0.1"};    //服务器Ip 

	sockaddr_in address;  //空地址用于recvfrom接收到的地址
	int n=sizeof(struct sockaddr);
	char buffer[100] = {0};

	wVersionRequested = MAKEWORD( 2, 2);   // 请求WinSock库  
	err = WSAStartup( wVersionRequested, &wsaData);
	if(err!=0)  {return -1;} 

	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);        //创建Socket 
	if(sockSrv < 0){
		cout << "socket creation failed" << endl;
		return 0;
	}

	cout << "socket created" << endl;
	cout << IPaddr << endl << port << endl;
	if(! BindSocket(sockSrv, port, IPaddr))
	{       //将本地IP地址和端口号绑定到所创建的套接字上 
		cout << "Bind failed" << endl;
		return 0; 
	}
	cout << "Bind Socket success " << endl;

	int num =0;

	while(1)
	{           //接受来自客户端的数据包 
		if(recvfrom(sockSrv,buffer, 100, 0,(struct sockaddr*)&address, &n) == SOCKET_ERROR )
		{
			cout << "接收失败" << endl; 
		}
		else
		{
			cout << buffer << endl;
			num++;
		}
		cout << num << endl;// output situation;
	}

	closesocket(sockSrv); 
	WSACleanup(); 
}

int main()
{
	tcp_server(2000);
	return 0;
}


