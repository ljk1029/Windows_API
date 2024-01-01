
// ThreadMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadMFC.h"
#include "ThreadMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThreadMFCDlg �Ի���




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


// CThreadMFCDlg ��Ϣ�������

BOOL CThreadMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CThreadMFCDlg::OnPaint()
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
HCURSOR CThreadMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




/***************************MFC�����߳�****************************/
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
	//����MFC�߳�
	CWinThread *pThread = AfxBeginThread(ThreadFunction, (LPVOID)100);
	hTread = pThread->m_hThread;
}


void CThreadMFCDlg::OnBnClickedButton2()
{
	//����
	SuspendThread(hTread);	
}


void CThreadMFCDlg::OnBnClickedButton3()
{
	//�ָ�
	ResumeThread(hTread);
}


/***************************WIN32�����߳�***************************/
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
	// �����߳�
	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, (LPVOID)123, 0, &dwThreadID);
	CloseHandle( hThread );
}
