#include <stdlib.h>
#include <iostream>
#include <atlstr.h>

using namespace std; 

//����Ӳ��������򴴽��߳�ʧ�ܡ���ʾ�޷������� 3 �ӡ�DWORD (__stdcall *)(void)��ת��Ϊ��LPTHREAD_START_ROUTINE�� 
DWORD WINAPI ThreadProFuncA(LPVOID lpParam);
DWORD WINAPI ThreadProFuncB(LPVOID lpParam);


DWORD dwThreadIdB;

int main(int argc, char **argv)
{
	HANDLE hA;
	HANDLE hB;
	DWORD dwThreadIdA;

	hA = CreateThread( NULL	    // Ĭ�ϰ�ȫ����
		, NULL		// Ĭ�϶�ջ��С
		, ThreadProFuncA // �߳���ڵ�ַ
		, NULL	    //���ݸ��̺߳����Ĳ���
		, 0	        // �������߳�����ִ��
		, &dwThreadIdA);	//�߳�ID��
	hB = CreateThread( NULL, NULL, ThreadProFuncB, NULL, CREATE_SUSPENDED, &dwThreadIdB);
	//�̴߳��������ֱ������ ResumeThread ����

	while( 1 )
	{
		if( getchar() == 'q' )
		{
			//����ֱ�ӹر��̣߳�ֻ�ǵݼ��߳��е��ں˶���ʹ�ü�������ʹ�ü���Ϊ0ʱ���ͷ��ں˶���
			CloseHandle(hA);	// �ر��߳̾��
			CloseHandle(hB);	// �ر��߳̾��
			return 0;
		}
		else if(getchar() == 'r')
		{
			ResumeThread(hB); // �ָ��߳�Bִ��
			SetThreadPriority(hB, THREAD_PRIORITY_LOWEST);	// �����߳�B���ȼ����
		}
		else
		{
			Sleep( 1000 );
		}
	}

	system("pause");
	return 0;
}

#define MY_MSG WM_USER+100//������Ϣʱ��Ҫ

DWORD WINAPI ThreadProFuncA( LPVOID lpParam )
{
	int nCount = 0;
	while( 1 )
	{
		cout << "ThreadA is running." << endl;
		PostThreadMessage(dwThreadIdB, MY_MSG, nCount++, 0);//�������ݸ�����һ���߳�
		Sleep( 1000 ); //��ͣ��ǰ�̣߳��ӵȴ����߳���ִ��
	}

	return 0;
}

DWORD WINAPI ThreadProFuncB( LPVOID lpParam )
{
	MSG msg;
	CString Str;
	PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);//�൱��msg = {0};
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
					Str.Format("%d",nCount);  //��ֵ��������ַ���
					cout << "ThreadB is running."<< Str<< endl;
					OutputDebugString(Str);   //��ӡ�����DebugView.exe
				}
				break;
			}
		}
		Sleep( 1000 );
	}

	return 0;
}

