/**
* date:    2020/6/21
* version:     v 1.0
* Description: main��WinMain�Աȣ�main�е���win32����
*
* author:
**/

#include<windows.h>
#include<iostream>
#define NDEBUG     //������assert����
#include"assert.h"

int main(int argc,char *argv)
{
	LPTSTR cmdline;
	cmdline = GetCommandLine();

	int v1=1,v2=2;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	std::cout << v1 << " and " << v2 << std::endl;

	assert(v1 == 2);           //�ж����������㣬���׳��쳣   

	system("pause");         //��ͣ����̨����������
	MessageBox(NULL, cmdline, TEXT("CmdLine"), MB_OK|MB_ICONINFORMATION);
	return 0;
}