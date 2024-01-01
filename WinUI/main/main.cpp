/**
* date:    2020/6/21
* version:     v 1.0
* Description: main与WinMain对比；main中调用win32界面
*
* author:
**/

#include<windows.h>
#include<iostream>
#define NDEBUG     //来禁用assert调用
#include"assert.h"

int main(int argc,char *argv)
{
	LPTSTR cmdline;
	cmdline = GetCommandLine();

	int v1=1,v2=2;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	std::cout << v1 << " and " << v2 << std::endl;

	assert(v1 == 2);           //判断条件不满足，就抛出异常   

	system("pause");         //暂停控制台，不让闪退
	MessageBox(NULL, cmdline, TEXT("CmdLine"), MB_OK|MB_ICONINFORMATION);
	return 0;
}