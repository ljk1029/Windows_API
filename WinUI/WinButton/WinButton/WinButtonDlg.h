
// WinButtonDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#define     S_KEY (0x53)//S
#define     R_KEY (0x52)//R

#define		KEY_DOWN(vk_code)	(((GetAsyncKeyState(vk_code))&0x8000)?1:0)
#define		KEY_UP(vk_code)		(((GetAsyncKeyState(vk_code))&0x8000)?0:1)

#include "WinShowDlg.h"


// CWinButtonDlg �Ի���
class CWinButtonDlg : public CDialogEx
{
// ����
public:
	CWinButtonDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CWinButtonDlg::~CWinButtonDlg();

	//����ӽ���
	WinShowDlg ShowDlg;
// �Ի�������
	enum { IDD = IDD_W_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

	//�Զ���༭��
	CStatic *m_Edit;
};
