
// WinButtonDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#define     S_KEY (0x53)//S
#define     R_KEY (0x52)//R

#define		KEY_DOWN(vk_code)	(((GetAsyncKeyState(vk_code))&0x8000)?1:0)
#define		KEY_UP(vk_code)		(((GetAsyncKeyState(vk_code))&0x8000)?0:1)

#include "WinShowDlg.h"


// CWinButtonDlg 对话框
class CWinButtonDlg : public CDialogEx
{
// 构造
public:
	CWinButtonDlg(CWnd* pParent = NULL);	// 标准构造函数
	CWinButtonDlg::~CWinButtonDlg();

	//添加子界面
	WinShowDlg ShowDlg;
// 对话框数据
	enum { IDD = IDD_W_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnBnClickedBcolor();
	afx_msg void OnBnClickedCbtn1();
	afx_msg void OnBnClickedBtn8();
	BOOL m_Btn1;
	CComboBox m_Btn2;
	BOOL m_Btn3;
	BOOL m_Btn6;
	CButton m_Btn8;

	//自定义编辑框
	CStatic *m_Edit;
};
