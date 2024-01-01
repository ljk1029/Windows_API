#include <Windows.h> //�ײ�ʵ�ִ��ڵ�ͷ�ļ�
#include <commctrl.h>
#include <Tchar.h>
#include "resource.h"


//���ڴ������
INT_PTR WINAPI DilogProc(
	HWND hwndDlg,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_COMMAND:  //��Ӧ������Ϣ
		{
			UINT nCtrlID = LOWORD(wParam); //��Ϣ��ID
			UINT nCode = HIWORD(wParam);   //BN_CLICKED
			if(nCode == BN_CLICKED)
			{
				if(nCtrlID == IDC_BUTTON1)
				{
					//����ģ̬�Ӵ���
					DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwndDlg, DilogProc);
				}
				else if(nCtrlID == IDC_BUTTON2)
				{
					//������ģ̬�Ӵ���
					HWND hDialog= CreateDialog( NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwndDlg, DilogProc);
					ShowWindow(hDialog, SW_SHOW);
				}
				else if(nCtrlID == IDCANCEL) //���ٴ���
				{  
					int iret = MessageBox(NULL, _T("��ȷ��Ҫ�رմ�����"), _T("Tip"), MB_OKCANCEL);
					if(iret == IDOK)
					{
						DestroyWindow(hwndDlg); //
					    PostQuitMessage(0);//���ٴ�����Ϣ  �����˳���Ϣ
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

//������ں���
//WINAPI ����__stdcall �����Ĵ���˳�� ���ҵ��� ������ջ�� �����ں�������ǰ ��ն�ջ
 
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó������� ��win32�����£� ����һ��ΪNULL�� ��ȥ����
	LPSTR lpCmdLine,  //�൱�� char *argv[]
	int nShowCmd)     //��ʾ����(��󻯡���С��������)
{
	HWND hDialog= CreateDialog( hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DilogProc);
	ShowWindow(hDialog, SW_SHOW);  

	MSG msg = {0};
 
	while (GetMessage(&msg, NULL, 0, 0))
	{
	    //������Ϣ
		TranslateMessage(&msg);
	     //�ַ���Ϣ
		DispatchMessage(&msg);
 
	}
	 //Sleep(INFINITE);
	return TRUE;
}



