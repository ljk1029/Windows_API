
// WinButtonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WinButtonApp.h"
#include "WinButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif






// ����
CWinButtonDlg::CWinButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWinButtonDlg::IDD, pParent)
	, m_Btn1(FALSE)
	, m_Btn3(2)  //��ѡ��Ĭ��ѡ��3
	, m_Btn6(FALSE)//Ĭ��ѡ��1
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CWinButtonDlg::~CWinButtonDlg()
{
	delete m_Edit;
	m_Edit = nullptr;
}

void CWinButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CBtn1, m_Btn1);
	DDX_Control(pDX, IDC_CBtn2, m_Btn2);
	DDX_Radio(pDX, IDC_RBtn3, m_Btn3);
	DDX_Radio(pDX, IDC_RBtn6, m_Btn6);
	DDX_Control(pDX, IDC_Btn8, m_Btn8);
}

//ӳ��
BEGIN_MESSAGE_MAP(CWinButtonDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BColor, &CWinButtonDlg::OnBnClickedBcolor)
	ON_BN_CLICKED(IDC_CBtn1, &CWinButtonDlg::OnBnClickedCbtn1)
	ON_BN_CLICKED(IDC_Btn8, &CWinButtonDlg::OnBnClickedBtn8)
END_MESSAGE_MAP()



//��ʼ��
BOOL CWinButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CString NumTmp;//������ѡ��
	for (int i = 0; i < 40; i++)
	{
		NumTmp.Format("%d", 60 - i);
		m_Btn2.AddString(NumTmp);
	}
	m_Btn2.SetCurSel(0);//������ʾ��һ��ֵ


	//��ȡ��ʾ��Ļ�ߴ�
	int mWidth = GetSystemMetrics(SM_CXSCREEN);
	int mHeight = GetSystemMetrics(SM_CYSCREEN);
	//��ʾ����С��Ϣ
	CRect rect;
	GetClientRect(&rect);

	//�Զ���༭�򴴽�
	CString strTmp;
	m_Edit = new CStatic;
	strTmp.Format("hello Edit");
	m_Edit->Create(strTmp, WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(0, rect.bottom -20, 100, rect.bottom), this);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//��ͼ
void CWinButtonDlg::OnPaint()
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
HCURSOR CWinButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��Ϣ
BOOL CWinButtonDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{

		if (KEY_DOWN(VK_CONTROL) && KEY_DOWN(S_KEY))
		{
			static bool bFlg;
			bFlg = !bFlg;
		
			//���غ�ʹ��ť���ɿ�
			if(bFlg)
			{
				m_Btn8.ShowWindow(FALSE);
				m_Btn2.EnableWindow(FALSE);
			}
			else
			{
				m_Btn8.ShowWindow(TRUE);
				m_Btn2.EnableWindow(TRUE);
			}
			return 0;
		}

		//�س�
		if (KEY_DOWN(VK_RETURN))
		{
			
			return 0;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

//��ɫ
void CWinButtonDlg::OnBnClickedBcolor()
{
	//CColorDialog   ColorDlg;
	CColorDialog   ColorDlg(RGB(80,80,80), CC_FULLOPEN);//����Ĭ�ϲ���
	if(ColorDlg.DoModal()==IDOK)
	{
		COLORREF color = ColorDlg.GetColor();  //Ҳ����ʹ��CColorDialog���Աm_cc����
		int Red =GetRValue(color);
		int Green =GetGValue(color);
		int Blue = GetBValue(color);

		COLORREF color1 = RGB(Red,Green,Blue);//(Red|Green<<8|Blue<<16)
#if 1
		CString str;
		str.Format(_T("Color RGB��%d %d %d"),Red, Green, Blue);
		MessageBox(str,"tip",NULL);
#endif 
	}
}


//��ѡ
void CWinButtonDlg::OnBnClickedCbtn1()
{
	CString Num = "1";
	int m_Num;

	m_Btn2.GetWindowTextA(Num);
	m_Num = atoi(Num);
	UpdateData(TRUE);//�ӿؼ��������

	CString str;
	str.Format(_T("Button:��ѡ:%d ����ѡ��:%d ѡ��1��%d ѡ��2��%d"),m_Btn1, m_Num, m_Btn3, m_Btn6);
	MessageBox(str,"tip",NULL);


	//�Զ���༭��ı���ʾ����
	char buf[64];
	sprintf(buf, "renew:%d", m_Num);
	m_Edit->SetWindowTextA(buf);

	//����/ʹ���ɲ���
	if(m_Btn1)
	{
		GetDlgItem(IDC_RBtn3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RBtn4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RBtn5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RBtn6)->EnableWindow(SW_HIDE);
		GetDlgItem(IDC_RBtn7)->EnableWindow(SW_HIDE);
	}
	else
	{
		GetDlgItem(IDC_RBtn3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RBtn4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RBtn5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RBtn6)->EnableWindow(SW_SHOW);
		GetDlgItem(IDC_RBtn7)->EnableWindow(SW_SHOW);
	}
}

//��ʾ�Ӵ���
void CWinButtonDlg::OnBnClickedBtn8()
{
	if (ShowDlg.DoModal() == IDOK)
	{
	}
}
