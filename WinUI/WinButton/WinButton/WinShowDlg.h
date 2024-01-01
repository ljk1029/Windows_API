#pragma once
#include "Resource.h"

// WinShowDlg 对话框

class WinShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WinShowDlg)

public:
	WinShowDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~WinShowDlg();

// 对话框数据
	enum { IDD = IDD_C_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
