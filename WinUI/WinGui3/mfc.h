#ifndef __MFC_H__
#define __MFC_H__
#include <afxwin.h>
 

class MyApp :public CWinApp //CWinAppӦ�ó�����
{
public:
	//�������
	virtual BOOL InitInstance();
};
 
class MyFrame :public CFrameWnd //CFrameWnd ���ڿ����
{
public:
	MyFrame();
 
	//������ �ṩ��Ϣӳ�����
	DECLARE_MESSAGE_MAP()
 
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
};


#endif



