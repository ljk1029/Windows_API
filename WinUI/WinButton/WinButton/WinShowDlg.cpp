// WinShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WinShowDlg.h"
#include "afxdialogex.h"


// WinShowDlg �Ի���

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


// WinShowDlg ��Ϣ�������
