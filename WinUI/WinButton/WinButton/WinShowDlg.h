#pragma once
#include "Resource.h"

// WinShowDlg �Ի���

class WinShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WinShowDlg)

public:
	WinShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WinShowDlg();

// �Ի�������
	enum { IDD = IDD_C_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
