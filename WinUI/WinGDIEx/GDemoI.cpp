/**
* date:    2020/11/18
* version:     v 1.0
* Description: 调用win32的，GDI
*
* author:
**/


#include "mfc.h"

MyApp app; //全局应用程序对象，有且仅有一个

BOOL MyApp::InitInstance()
{
	//创建窗口
	MyFrame *frame = new MyFrame;

	//显示和更新
	frame->ShowWindow(SW_SHOWDEFAULT);
	frame->UpdateWindow();

	m_pMainWnd = frame; //保存指向应用程序的主窗口的指针

	return TRUE;
}

//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)

	//各种消息宏
	ON_WM_LBUTTONDOWN() //鼠标左键按下(key)
	ON_WM_CHAR()  //键盘(key)
	ON_WM_PAINT() //绘图(key)

END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
	m_MemDC=CWnd::GetDC();//方法4
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	//TCHAR buf[1024];
	//wsprintf(buf, TEXT("x = %d, y = %d"), point.x, point.y);

	//MessageBox(buf);

	//mfc中得到字符串 CString
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("按下了%c 键"), key);
	MessageBox(str);
	
}

void MyFrame::OnPaint()
{
	char nchar[256]= "hello!";

	//获取显示窗口区域大小
	CRect rect;
	GetClientRect(rect);

	//方法2，三种方法下面函数用法通用，其他的没写例子
	CPaintDC dc(this); 
	dc.SetDCPenColor(RGB(0, 255 ,0));
	dc.Rectangle(10, 10, 300, 300);//画矩形,这二个函数一定要在画线前面
	dc.Ellipse(10, 10, 300, 300);  //画椭圆

	dc.MoveTo(100, 100);
	dc.LineTo(200, 200);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOut(100, 100, TEXT("Fighting!"));

#if 1
	//方法3
	CClientDC dcx(this);
	CPen newPen(PS_SOLID, 1, RGB(255, 0 ,0));  //设置颜色
	CPen *pOldPen = dcx.SelectObject(&newPen);

	dcx.MoveTo(rect.left,rect.top);
	dcx.LineTo(rect.right,rect.bottom);
	dcx.MoveTo(rect.right,rect.top);
	dcx.LineTo(rect.left,rect.bottom);
	dcx.SelectObject(pOldPen);
	

	//方法4，m_MemDC指针变量在其他位置定义
	CPen PenGray(PS_SOLID, 1, RGB(0, 0 ,255));
	CPen *PenOld;
	PenOld = m_MemDC->SelectObject(&PenGray);
	m_MemDC->MoveTo(100, 200);
	m_MemDC->LineTo(200, 100);

	m_MemDC->SetTextColor(RGB(0, 255, 0));
	m_MemDC->TextOut(10, 20, nchar);
	m_MemDC->SelectObject(PenOld);

	//重新定义画笔
	COLORREF mColor[3];
	CPen pen[3];
	mColor[0] = RGB(255, 0, 0);
	mColor[1] = RGB(0, 255, 0);
	mColor[2] = RGB(0, 0, 255);
	int nPenWidth = 1;
	for (int i = 0; i < sizeof(pen)/sizeof(pen[0]); i++)
	{
		pen[i].DeleteObject();
		pen[i].CreatePen(PS_SOLID, nPenWidth, mColor[i]);
	}
	//m_MemDC = CWnd::GetDC();
	m_MemDC->SelectObject(&pen[0]);
	m_MemDC->MoveTo(100, 100);
	m_MemDC->LineTo(100, 500);
	m_MemDC->SelectObject(&pen[1]);
	m_MemDC->MoveTo(200, 100);
	m_MemDC->LineTo(200, 500);
	m_MemDC->SelectObject(&pen[2]);
	m_MemDC->MoveTo(300, 100);
	m_MemDC->LineTo(300, 500);
	
#endif 
}
