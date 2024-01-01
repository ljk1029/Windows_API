#include <Windows.h> //底层实现窗口的头文件
#include <commctrl.h>
#include <Tchar.h>
#include "resource.h"


//窗口处理过程
INT_PTR WINAPI DilogProc(
	HWND hwndDlg,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_COMMAND:  //响应按键消息
		{
			UINT nCtrlID = LOWORD(wParam); //消息的ID
			UINT nCode = HIWORD(wParam);   //BN_CLICKED
			if(nCode == BN_CLICKED)
			{
				if(nCtrlID == IDC_BUTTON1)
				{
					//创建模态子窗口
					DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwndDlg, DilogProc);
				}
				else if(nCtrlID == IDC_BUTTON2)
				{
					//创建非模态子窗口
					HWND hDialog= CreateDialog( NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwndDlg, DilogProc);
					ShowWindow(hDialog, SW_SHOW);
				}
				else if(nCtrlID == IDCANCEL) //销毁窗口
				{  
					int iret = MessageBox(NULL, _T("您确定要关闭窗口吗"), _T("Tip"), MB_OKCANCEL);
					if(iret == IDOK)
					{
						DestroyWindow(hwndDlg); //
					    PostQuitMessage(0);//销毁窗口消息  发送退出消息
					}
				}
				return TRUE;
			}
			break;
		}

		default:
			break;
	}
	return FALSE;
}

//程序入口函数
//WINAPI 代表__stdcall 参数的传递顺序； 从右到左 依次入栈， 并且在函数返回前 清空堆栈
 
int WINAPI WinMain(
	HINSTANCE hInstance, //应用程序实例句柄
	HINSTANCE hPrevInstance, //上一个应用程序句柄， 在win32环境下， 参数一般为NULL， 不去作用
	LPSTR lpCmdLine,  //相当于 char *argv[]
	int nShowCmd)     //显示命令(最大化、最小化、正常)
{
	HWND hDialog= CreateDialog( hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DilogProc);
	ShowWindow(hDialog, SW_SHOW);  

	MSG msg = {0};
 
	while (GetMessage(&msg, NULL, 0, 0))
	{
	    //翻译消息
		TranslateMessage(&msg);
	     //分发消息
		DispatchMessage(&msg);
 
	}
	 //Sleep(INFINITE);
	return TRUE;
}



