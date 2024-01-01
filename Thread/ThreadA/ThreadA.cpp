#include <iostream>
#include <windows.h>

using namespace std;

//必须加参数，否则创建线程失败。提示无法将参数 3 从“DWORD (__stdcall *)(void)”转换为“LPTHREAD_START_ROUTINE” 
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
			//不会直接关闭线程，只是递减线程中的内核对象使用计数。当使用计数为0时，释放内核对象
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
		Sleep( 1000 ); //暂停当前线程，从等待的线程中执行
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

