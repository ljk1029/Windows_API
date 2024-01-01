#include <stdlib.h>
#include <iostream>
#include <atlstr.h>

using namespace std; 

//必须加参数，否则创建线程失败。提示无法将参数 3 从“DWORD (__stdcall *)(void)”转换为“LPTHREAD_START_ROUTINE” 
DWORD WINAPI ThreadProFuncA(LPVOID lpParam);
DWORD WINAPI ThreadProFuncB(LPVOID lpParam);


DWORD dwThreadIdB;

int main(int argc, char **argv)
{
	HANDLE hA;
	HANDLE hB;
	DWORD dwThreadIdA;

	hA = CreateThread( NULL	    // 默认安全属性
		, NULL		// 默认堆栈大小
		, ThreadProFuncA // 线程入口地址
		, NULL	    //传递给线程函数的参数
		, 0	        // 创建完线程立即执行
		, &dwThreadIdA);	//线程ID号
	hB = CreateThread( NULL, NULL, ThreadProFuncB, NULL, CREATE_SUSPENDED, &dwThreadIdB);
	//线程创建后挂起，直到调用 ResumeThread 运行

	while( 1 )
	{
		if( getchar() == 'q' )
		{
			//不会直接关闭线程，只是递减线程中的内核对象使用计数。当使用计数为0时，释放内核对象
			CloseHandle(hA);	// 关闭线程句柄
			CloseHandle(hB);	// 关闭线程句柄
			return 0;
		}
		else if(getchar() == 'r')
		{
			ResumeThread(hB); // 恢复线程B执行
			SetThreadPriority(hB, THREAD_PRIORITY_LOWEST);	// 设置线程B优先级最低
		}
		else
		{
			Sleep( 1000 );
		}
	}

	system("pause");
	return 0;
}

#define MY_MSG WM_USER+100//发送消息时需要

DWORD WINAPI ThreadProFuncA( LPVOID lpParam )
{
	int nCount = 0;
	while( 1 )
	{
		cout << "ThreadA is running." << endl;
		PostThreadMessage(dwThreadIdB, MY_MSG, nCount++, 0);//发送数据给另外一个线程
		Sleep( 1000 ); //暂停当前线程，从等待的线程中执行
	}

	return 0;
}

DWORD WINAPI ThreadProFuncB( LPVOID lpParam )
{
	MSG msg;
	CString Str;
	PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);//相当于msg = {0};
	while( true )
	{
		cout << "ThreadB is running." << endl;
		if(GetMessage(&msg,0,0,0)) //get msg from message queue
		{
			switch(msg.message)
			{
			case MY_MSG:
				{
					int nCount = (int)msg.wParam;
					Str.Format("%d",nCount);  //数值变量变成字符串
					cout << "ThreadB is running."<< Str<< endl;
					OutputDebugString(Str);   //打印输出到DebugView.exe
				}
				break;
			}
		}
		Sleep( 1000 );
	}

	return 0;
}

