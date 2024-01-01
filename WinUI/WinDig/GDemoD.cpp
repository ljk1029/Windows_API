#include <Windows.h> //�ײ�ʵ�ִ��ڵ�ͷ�ļ�
#include <commctrl.h>
#include <Tchar.h>
#include "resource.h"


//�����ڹ���
INT_PTR WINAPI LDilogProc(
	HWND hwndDlg,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: //��ʼ���ɹ�
		{
			MessageBox(NULL, _T("�Ի����ʼ�����"), _T("Tip"), NULL);
			break;
		}

		case WM_COMMAND:  //��Ӧ������Ϣ
		{
			UINT nCtrlID = LOWORD(wParam); //��Ӧ��Ϣ��ID
			UINT nCode = HIWORD(wParam);   //BN_CLICKED
			if(nCode == BN_CLICKED)
			{
				if(nCtrlID == IDC_BUTTON1)
				{
					MessageBox(NULL, _T("����1����Ӧ"), _T("Tip"), NULL);
				}
				else if(nCtrlID == IDC_BUTTON2)
				{
					MessageBox(NULL, _T("����2����Ӧ"), _T("Tip"), NULL);
				}
				else if(nCtrlID == IDCANCEL)//���ٴ���
				{  
					int iret = MessageBox(NULL, _T("��ȷ��Ҫ�رմ�����"), _T("Tip"), MB_OKCANCEL);//ȷ���Ƿ����˳�
					if(iret == IDOK)
						EndDialog(hwndDlg, 888);//�˳����ڣ��ڶ����������д���ظ�DialogBox
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
	int nRet = DialogBox( hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, LDilogProc);

	return 0;
}



