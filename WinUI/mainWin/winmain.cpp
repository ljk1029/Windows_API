/**
* date:    2020/6/21
* version:     v 1.0
* Description: main��WinMain�Աȣ�WinMain�е���win32����
*
* author:
**/
#include <windows.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE h2, LPTSTR cmdline, int cmdshow)
{
	MessageBox(NULL, cmdline, TEXT("CmdLine"), MB_OK|MB_ICONINFORMATION);
	return 0;
}