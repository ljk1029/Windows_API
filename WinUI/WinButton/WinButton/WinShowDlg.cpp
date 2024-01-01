// WinShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WinShowDlg.h"
#include "afxdialogex.h"


// WinShowDlg 对话框

IMPLEMENT_DYNAMIC(WinShowDlg, CDialogEx)

WinShowDlg::WinShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(WinShowDlg::IDD, pParent)
{

}

WinShowDlg::~WinShowDlg()
{
}

void WinShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WinShowDlg, CDialogEx)
END_MESSAGE_MAP()


// WinShowDlg 消息处理程序
