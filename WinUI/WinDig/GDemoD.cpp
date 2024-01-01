#include <Windows.h> //底层实现窗口的头文件
#include <commctrl.h>
#include <Tchar.h>
#include "resource.h"


//处理窗口过程
INT_PTR WINAPI LDilogProc(
	HWND hwndDlg,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: //初始化成功
		{
			MessageBox(NULL, _T("对话框初始化完成"), _T("Tip"), NULL);
			break;
		}

		case WM_COMMAND:  //响应按键消息
		{
			UINT nCtrlID = LOWORD(wParam); //响应消息的ID
			UINT nCode = HIWORD(wParam);   //BN_CLICKED
			if(nCode == BN_CLICKED)
			{
				if(nCtrlID == IDC_BUTTON1)
				{
					MessageBox(NULL, _T("按键1被响应"), _T("Tip"), NULL);
				}
				else if(nCtrlID == IDC_BUTTON2)
				{
					MessageBox(NULL, _T("按键2被响应"), _T("Tip"), NULL);
				}
				else if(nCtrlID == IDCANCEL)//销毁窗口
				{  
					int iret = MessageBox(NULL, _T("您确定要关闭窗口吗"), _T("Tip"), MB_OKCANCEL);//确认是否真退出
					if(iret == IDOK)
						EndDialog(hwndDlg, 888);//退出窗口，第二个参数随便写返回给DialogBox
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
	int nRet = DialogBox( hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, LDilogProc);

	return 0;
}



