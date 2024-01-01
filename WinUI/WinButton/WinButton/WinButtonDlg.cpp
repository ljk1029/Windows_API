
// WinButtonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WinButtonApp.h"
#include "WinButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif






// 构造
CWinButtonDlg::CWinButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWinButtonDlg::IDD, pParent)
	, m_Btn1(FALSE)
	, m_Btn3(2)  //多选框默认选择3
	, m_Btn6(FALSE)//默认选择1
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

//映射
BEGIN_MESSAGE_MAP(CWinButtonDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BColor, &CWinButtonDlg::OnBnClickedBcolor)
	ON_BN_CLICKED(IDC_CBtn1, &CWinButtonDlg::OnBnClickedCbtn1)
	ON_BN_CLICKED(IDC_Btn8, &CWinButtonDlg::OnBnClickedBtn8)
END_MESSAGE_MAP()



//初始化
BOOL CWinButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString NumTmp;//下拉框选择
	for (int i = 0; i < 40; i++)
	{
		NumTmp.Format("%d", 60 - i);
		m_Btn2.AddString(NumTmp);
	}
	m_Btn2.SetCurSel(0);//设置显示第一个值


	//获取显示屏幕尺寸
	int mWidth = GetSystemMetrics(SM_CXSCREEN);
	int mHeight = GetSystemMetrics(SM_CYSCREEN);
	//显示区大小信息
	CRect rect;
	GetClientRect(&rect);

	//自定义编辑框创建
	CString strTmp;
	m_Edit = new CStatic;
	strTmp.Format("hello Edit");
	m_Edit->Create(strTmp, WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(0, rect.bottom -20, 100, rect.bottom), this);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//绘图
void CWinButtonDlg::OnPaint()
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
HCURSOR CWinButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//消息
BOOL CWinButtonDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{

		if (KEY_DOWN(VK_CONTROL) && KEY_DOWN(S_KEY))
		{
			static bool bFlg;
			bFlg = !bFlg;
		
			//隐藏和使按钮不可控
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

		//回车
		if (KEY_DOWN(VK_RETURN))
		{
			
			return 0;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

//颜色
void CWinButtonDlg::OnBnClickedBcolor()
{
	//CColorDialog   ColorDlg;
	CColorDialog   ColorDlg(RGB(80,80,80), CC_FULLOPEN);//设置默认参数
	if(ColorDlg.DoModal()==IDOK)
	{
		COLORREF color = ColorDlg.GetColor();  //也可以使用CColorDialog类成员m_cc操作
		int Red =GetRValue(color);
		int Green =GetGValue(color);
		int Blue = GetBValue(color);

		COLORREF color1 = RGB(Red,Green,Blue);//(Red|Green<<8|Blue<<16)
#if 1
		CString str;
		str.Format(_T("Color RGB：%d %d %d"),Red, Green, Blue);
		MessageBox(str,"tip",NULL);
#endif 
	}
}


//复选
void CWinButtonDlg::OnBnClickedCbtn1()
{
	CString Num = "1";
	int m_Num;

	m_Btn2.GetWindowTextA(Num);
	m_Num = atoi(Num);
	UpdateData(TRUE);//从控件获得数据

	CString str;
	str.Format(_T("Button:复选:%d 数字选择:%d 选择1：%d 选择2：%d"),m_Btn1, m_Num, m_Btn3, m_Btn6);
	MessageBox(str,"tip",NULL);


	//自定义编辑框改变显示内容
	char buf[64];
	sprintf(buf, "renew:%d", m_Num);
	m_Edit->SetWindowTextA(buf);

	//隐藏/使不可操作
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

//显示子窗口
void CWinButtonDlg::OnBnClickedBtn8()
{
	if (ShowDlg.DoModal() == IDOK)
	{
	}
}
