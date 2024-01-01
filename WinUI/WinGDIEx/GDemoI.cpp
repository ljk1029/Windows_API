/**
* date:    2020/11/18
* version:     v 1.0
* Description: ����win32�ģ�GDI
*
* author:
**/


#include "mfc.h"

MyApp app; //ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance()
{
	//��������
	MyFrame *frame = new MyFrame;

	//��ʾ�͸���
	frame->ShowWindow(SW_SHOWDEFAULT);
	frame->UpdateWindow();

	m_pMainWnd = frame; //����ָ��Ӧ�ó���������ڵ�ָ��

	return TRUE;
}

//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)

	//������Ϣ��
	ON_WM_LBUTTONDOWN() //����������(key)
	ON_WM_CHAR()  //����(key)
	ON_WM_PAINT() //��ͼ(key)

END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
	m_MemDC=CWnd::GetDC();//����4
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	//TCHAR buf[1024];
	//wsprintf(buf, TEXT("x = %d, y = %d"), point.x, point.y);

	//MessageBox(buf);

	//mfc�еõ��ַ��� CString
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("������%c ��"), key);
	MessageBox(str);
	
}

void MyFrame::OnPaint()
{
	char nchar[256]= "hello!";

	//��ȡ��ʾ���������С
	CRect rect;
	GetClientRect(rect);

	//����2�����ַ������溯���÷�ͨ�ã�������ûд����
	CPaintDC dc(this); 
	dc.SetDCPenColor(RGB(0, 255 ,0));
	dc.Rectangle(10, 10, 300, 300);//������,���������һ��Ҫ�ڻ���ǰ��
	dc.Ellipse(10, 10, 300, 300);  //����Բ

	dc.MoveTo(100, 100);
	dc.LineTo(200, 200);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOut(100, 100, TEXT("Fighting!"));

#if 1
	//����3
	CClientDC dcx(this);
	CPen newPen(PS_SOLID, 1, RGB(255, 0 ,0));  //������ɫ
	CPen *pOldPen = dcx.SelectObject(&newPen);

	dcx.MoveTo(rect.left,rect.top);
	dcx.LineTo(rect.right,rect.bottom);
	dcx.MoveTo(rect.right,rect.top);
	dcx.LineTo(rect.left,rect.bottom);
	dcx.SelectObject(pOldPen);
	

	//����4��m_MemDCָ�����������λ�ö���
	CPen PenGray(PS_SOLID, 1, RGB(0, 0 ,255));
	CPen *PenOld;
	PenOld = m_MemDC->SelectObject(&PenGray);
	m_MemDC->MoveTo(100, 200);
	m_MemDC->LineTo(200, 100);

	m_MemDC->SetTextColor(RGB(0, 255, 0));
	m_MemDC->TextOut(10, 20, nchar);
	m_MemDC->SelectObject(PenOld);

	//���¶��廭��
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
