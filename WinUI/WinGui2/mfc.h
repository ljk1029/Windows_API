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
};


#endif
