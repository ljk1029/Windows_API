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
	CPaintDC dc(this); 
	//dc.TextOutW(100, 100, TEXT("Fighting!"));
	//����Բ ��������Բ
	dc.Ellipse(10, 10, 300, 300);
}
