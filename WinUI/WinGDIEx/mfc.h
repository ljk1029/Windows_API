#ifndef __MFC_H__
#define __MFC_H__
#include <afxwin.h>


class MyApp :public CWinApp //CWinApp应用程序类
{
public:
	//程序入口
	virtual BOOL InitInstance();
};

class MyFrame :public CFrameWnd //CFrameWnd 窗口框架类
{
public:
	MyFrame();

	//声明宏 提供消息映射机制
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
	CDC* m_MemDC;//方法4	
};


#endif



