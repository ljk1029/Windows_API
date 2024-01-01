#include <winsock2.h>
#include <iostream> 
#pragma comment(lib, "ws2_32.lib") 

using namespace std;


int tcp_client(char* addr, int IP_port)
{
	WORD wVersionRequested;
    WSADATA wData;
    int err;
    int port = 2000;               //客户端端口号 
    int Otherport = IP_port;          //服务器端口号 
    char IPaddr[18]  = {"192.168.204.1"};         //客户端Ip 
    char* OtherIP    = addr;       //服务器Ip 

    wVersionRequested = MAKEWORD( 2, 2);   // 请求WinSock库
    err = WSAStartup( wVersionRequested, &wData);
    if(err!=0)  {return -1;}                // 返回值为零时表示成功WSAStartup

    SOCKET sockCli = socket(AF_INET, SOCK_DGRAM, 0);        //创建Socket 
    if(sockCli < 0){
        cout << "socket creation failed" << endl;
        return 0; 
    } 

	//sendto时自动绑定本地地址，所以下面注释了;
	//Winsock手册中明确讲了不支持在客户端中使用bind来显示绑定自己的地址,因为客户端地址可能动态分配。
    /*
    sockaddr_in address;  //将本地IP地址和端口号绑定到所创建的套接字上
    address.sin_family=AF_INET;
    address.sin_addr.s_addr =inet_addr(IPaddr);
    address.sin_port=htons(port);
    if(SOCKET_ERROR == bind(sockCli,(const struct sockaddr*)&address,sizeof(struct sockaddr)) )
	{
		cout << "Bind failed" << endl;
        return false;
    } 
    cout << "Bind Socket success " << endl;
	*/
    sockaddr_in address;                //服务器的IP和端口号 
    
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr(OtherIP); 
    address.sin_port=htons(Otherport);


    char talk[100]="nin hao a"; 
    for(int i=0;i<50;i++)
	{         //发送100个数据包 
        sendto(sockCli,talk, sizeof(talk), 0,(const struct sockaddr*)&address,sizeof(struct sockaddr) );
    }
	cout<<"发送50遍 "<< talk << endl;

    closesocket(sockCli); 
    WSACleanup(); 
}

//客户端
int main()
{
    char OtherIP[18] = {"127.0.0.1"};       //服务器Ip
	tcp_client(OtherIP, 2000);
    return 0; 
}
