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
 
MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}
