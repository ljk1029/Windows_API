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
};


#endif
