
// ThreadMFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ThreadMFC.h"
#include "ThreadMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThreadMFCDlg 对话框




CThreadMFCDlg::CThreadMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThreadMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CThreadMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CThreadMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CThreadMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CThreadMFCDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CThreadMFCDlg 消息处理程序

BOOL CThreadMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CThreadMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CThreadMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




/***************************MFC创建线程****************************/
UINT ThreadFunction(LPVOID lpParameter)
{
	int tlpMsg = (int)lpParameter;
	CString strMsg;
	while(TRUE)
	{
		strMsg.Format(_T("%d"),tlpMsg++);
		MessageBox(NULL, strMsg, _T("Tip"), MB_OK);
		OutputDebugString(strMsg);
		Sleep(1000);
	}
	return 0;
}

HANDLE hTread = NULL;
void CThreadMFCDlg::OnBnClickedButton1()
{
	//创建MFC线程
	CWinThread *pThread = AfxBeginThread(ThreadFunction, (LPVOID)100);
	hTread = pThread->m_hThread;
}


void CThreadMFCDlg::OnBnClickedButton2()
{
	//挂起
	SuspendThread(hTread);	
}


void CThreadMFCDlg::OnBnClickedButton3()
{
	//恢复
	ResumeThread(hTread);
}


/***************************WIN32创建线程***************************/
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	int tlpMsg = (int)lpParameter;
	CString strMsg;
	strMsg.Format(_T("%d"),tlpMsg);
	AfxMessageBox(strMsg);
	return 0;
}

void CThreadMFCDlg::OnBnClickedButton4()
{
	// 创建线程
	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, (LPVOID)123, 0, &dwThreadID);
	CloseHandle( hThread );
}
