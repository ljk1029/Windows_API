#include <iostream>
#include <windows.h>

using namespace std;

//����Ӳ��������򴴽��߳�ʧ�ܡ���ʾ�޷������� 3 �ӡ�DWORD (__stdcall *)(void)��ת��Ϊ��LPTHREAD_START_ROUTINE�� 
DWORD WINAPI Fun1( LPVOID lpParam );
DWORD WINAPI Fun2( LPVOID lpParam ); 

int main()
{
	HANDLE h1 = CreateThread( NULL, 0, Fun1, NULL, 0, NULL );
	cout << "Thread1 create." << endl;

	HANDLE h2 = CreateThread( NULL, 0, Fun2, NULL, 0, NULL );
	cout << "Thread2 create." << endl;

	while( 1 )
	{
		if( getchar() == 'q' )
		{
			//����ֱ�ӹر��̣߳�ֻ�ǵݼ��߳��е��ں˶���ʹ�ü�������ʹ�ü���Ϊ0ʱ���ͷ��ں˶���
			CloseHandle( h1 );
			CloseHandle( h2 );
			return 0;
		}
		else
		{
			Sleep( 1000 );
		}
	}

	system( "pause" );
	return 0;
}

DWORD WINAPI Fun1( LPVOID lpParam )
{
	while( 1 )
	{
		cout << "Thread1 is running." << endl;
		Sleep( 1000 ); //��ͣ��ǰ�̣߳��ӵȴ����߳���ִ��
	}

	return 0;
}

DWORD WINAPI Fun2( LPVOID lpParam )
{
	while( 1 )
	{
		cout << "Thread2 is running." << endl;
		Sleep( 1000 );
	}

	return 0;
}

