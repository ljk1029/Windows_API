#include <winsock2.h>
#include <iostream> 
#pragma comment(lib, "ws2_32.lib") 

using namespace std;


int tcp_client(char* addr, int IP_port)
{
	WORD wVersionRequested;
    WSADATA wData;
    int err;
    int port = 2000;               //�ͻ��˶˿ں� 
    int Otherport = IP_port;          //�������˿ں� 
    char IPaddr[18]  = {"192.168.204.1"};         //�ͻ���Ip 
    char* OtherIP    = addr;       //������Ip 

    wVersionRequested = MAKEWORD( 2, 2);   // ����WinSock��
    err = WSAStartup( wVersionRequested, &wData);
    if(err!=0)  {return -1;}                // ����ֵΪ��ʱ��ʾ�ɹ�WSAStartup

    SOCKET sockCli = socket(AF_INET, SOCK_DGRAM, 0);        //����Socket 
    if(sockCli < 0){
        cout << "socket creation failed" << endl;
        return 0; 
    } 

	//sendtoʱ�Զ��󶨱��ص�ַ����������ע����;
	//Winsock�ֲ�����ȷ���˲�֧���ڿͻ�����ʹ��bind����ʾ���Լ��ĵ�ַ,��Ϊ�ͻ��˵�ַ���ܶ�̬���䡣
    /*
    sockaddr_in address;  //������IP��ַ�Ͷ˿ںŰ󶨵����������׽�����
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
    sockaddr_in address;                //��������IP�Ͷ˿ں� 
    
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr(OtherIP); 
    address.sin_port=htons(Otherport);


    char talk[100]="nin hao a"; 
    for(int i=0;i<50;i++)
	{         //����100�����ݰ� 
        sendto(sockCli,talk, sizeof(talk), 0,(const struct sockaddr*)&address,sizeof(struct sockaddr) );
    }
	cout<<"����50�� "<< talk << endl;

    closesocket(sockCli); 
    WSACleanup(); 
}

//�ͻ���
int main()
{
    char OtherIP[18] = {"127.0.0.1"};       //������Ip
	tcp_client(OtherIP, 2000);
    return 0; 
}
