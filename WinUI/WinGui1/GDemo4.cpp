/**
* date:    2020/6/21
* version:     v 1.0
* Description: ����win32��api��ʾ������̣�vc���ϵ�һ��test����
*
* author:
**/

#if 0
#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);//�����ص�����
char szWinName[] = "MyWindow";                          //�����������


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd;                  //���ھ��    
	MSG msg;					//��Ϣ
	WNDCLASS WndClass;			//������

	WndClass.style = CS_HREDRAW|CS_VREDRAW; //���崰������
	WndClass.lpfnWndProc = WindowFunc;		//��Ϣ����
	WndClass.cbClsExtra = 0;				//Ԥ���ռ䣬0Ϊ��Ԥ��
	WndClass.cbWndExtra = 0;				//Ԥ���ռ�
	WndClass.hInstance = hInstance;			//�����ʵ�����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//���ô��ڵ�ͼ��
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);  //�����������״
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ڱ���Ϊ��ɫ
	WndClass.lpszMenuName = NULL;               //���ô��ڲ˵�
	WndClass.lpszClassName = szWinName;			//���崰���������
	
	if(!RegisterClass(&WndClass))    //ע�ᴰ��
		return 1;
	hWnd = CreateWindow(szWinName,  //���ڵ��������
		"MyWindow",					//���ڵı���
		WS_OVERLAPPEDWINDOW,		//���ڵķ��
		CW_USEDEFAULT,				//���ڵ�����x
		CW_USEDEFAULT,				//���ڵ�����y
		CW_USEDEFAULT,				//���ڵĿ��
		CW_USEDEFAULT,				//���ڵĸ߶�
		NULL,		//�����ھ��
		NULL,		//���ڵ�Ŀ¼
		hInstance,	//���ڵľ��
		NULL);		//����ָ��
	ShowWindow(hWnd, nShowCmd);		//��ʾ����
	UpdateWindow(hWnd);				//���´���
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//����ص�������
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;				//�豸���
	PAINTSTRUCT PainStruct; //�������ƴ��ڿͻ���
	RECT Rect;				//��������
	switch(message)
	{
	case WM_PAINT://�ػ���Ϣ
		hDC = BeginPaint(hWnd, &PainStruct);//׼�����ڻ�ͼ  
		GetClientRect(hWnd, &Rect);			//�õ��ͻ� ����������
		//�ڴ�����ʾ�ַ���"Hello, Windows"
		DrawText(hDC, "Hello, Windows", -1, &Rect,
			DT_SINGLELINE|DT_CENTER|DT_VCENTER);//�����ַ���
		EndPaint(hWnd, &PainStruct);		//�������ڻ�ͼ
		return 0;
	case WM_DESTROY://���ٴ�����Ϣ
		PostQuitMessage(0);//�����˳���Ϣ
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif