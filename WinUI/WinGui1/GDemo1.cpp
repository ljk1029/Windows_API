#include <Windows.h> //�ײ�ʵ�ִ��ڵ�ͷ�ļ�
#include <stdio.h>
 
//6�������ڹ���
//CALLBACK ����__stdcall �����Ĵ���˳�� ���ҵ��� ������ջ�� �����ں�������ǰ ��ն�ջ
 
LRESULT CALLBACK WindowProc(
	HWND hwnd, //��Ϣ�����Ĵ��ھ��
	UINT  uMsg,  //�������Ϣ���� ��Ϣ����ʽ:WM_XXX
	WPARAM wParam,  //���̸�����Ϣ
	LPARAM lParam    //��긽����Ϣ
	) 
{
	switch (uMsg)
	{
		OutputDebugStringA("bbbb\r\n");
	case WM_CLOSE: DestroyWindow(hwnd); //DestoryWindow ������һ����Ϣ WM_DESTROY
		break;
	case WM_DESTROY: PostQuitMessage(0);//���ٴ�����Ϣ  �����˳���Ϣ
		break;
	case WM_LBUTTONDOWN:   //����������
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
 
		char buf[1024];
		wsprintf(buf, TEXT("x = %d, y %d"), xPos, yPos);
		MessageBox(hwnd, buf, TEXT("����������"), MB_OK);
		break;
	}
 
	case WM_KEYDOWN: //����
		MessageBox(hwnd, TEXT("����"), TEXT("���̰���"), MB_OK);
		break;
 
	case WM_PAINT: //��ͼ
	{
		PAINTSTRUCT ps; //��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);
 
		TextOut(hdc, 100, 100, TEXT("world"), strlen("world"));
 
		EndPaint(hwnd, &ps);
		break;
	}
		
	default:
		break;
	} 
	OutputDebugStringA("cccc\r\n");
	//����ֵʹ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
 
//������ں���
//WINAPI ����__stdcall �����Ĵ���˳�� ���ҵ��� ������ջ�� �����ں�������ǰ ��ն�ջ
 
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó������� ��win32�����£� ����һ��ΪNULL�� ��ȥ����
	LPSTR lpCmdLine,  //�൱�� char *argv[]
	int nShowCmd)     //��ʾ����(��󻯡���С��������)
{
	/*
	 * �������ڵĲ���
	 * 1����ƴ���
	 * 2��ע�ᴰ��
	 * 3����������
	 * 4����ʾ�͸���
	 * 5��ͨ��ѭ��ȡ��Ϣ
	 * 6��������Ϣ (���ڹ���)
	 */
 
	//1����ƴ���
	WNDCLASS wc; //WND = WINDOW
	wc.cbClsExtra = 0; //��Ķ�����ڴ�
	wc.cbWndExtra = 0; //���ڶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND); //���ù�꣬�����һ������ΪNULL������ϵͳ�ṩ�Ĺ��
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);//ͼ��
	wc.hInstance = hInstance; //Ӧ�ó���ʵ����� ����WinMain���βμ���
	wc.lpfnWndProc = WindowProc;//�ص����� ���ڹ��� �տ�ʼ��Ҫд���庯��
	wc.lpszClassName = TEXT("WIN"); //ָ������������
	wc.lpszMenuName = NULL; //�˵�����
	wc.style = 0; //��ʾ��� 0����Ĭ�Ϸ��
 
	//2��ע�ᴰ����
	RegisterClass(&wc);
 
	//3����������
	/* CreateWindow�����б�,����ֵHWND ���ھ��
	   lpClassName, ����
	   lpWindowName, ������
	   dwStyle, ѡ WS_OVERLAPPEDWINDOW ���
	   x,  ��ʾ���� CW_USEDEFAULT Ĭ��ֵ
	   y,   
	   nWidth, ���
	   nHeight,
	   hWndParent, ������ NULL
	   hMenu,  �˵� NULL
	   hInstance, ʵ����� hInstance
	   lpParam ����ֵ NULL
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("Hello"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	//4����ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
 
	//5��ͨ��ѭ��ȡ��Ϣ
	/*
	HWND        hwnd; �����ھ��
	UINT        message; ������Ϣ����
	WPARAM      wParam; ������Ϣ ������Ϣ
	LPARAM      lParam; ������Ϣ �����Ϣ 
	DWORD       time; ��Ϣ����ʱ��
	POINT       pt; ������Ϣ �����Ϣ x��y����
	*/
	MSG msg;
 
	/* GetMessage()����
	_Out_ LPMSG lpMsg, ��Ϣ
	_In_opt_ HWND hWnd, ���񴰿� ��NULL���������еĴ���
	_In_ UINT wMsgFilterMin, ��С�����Ĺ��˵���Ϣ һ������0
	_In_ UINT wMsgFilterMax   ��0������������Ϣ
	*/
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
	  //������Ϣ
		TranslateMessage(&msg);
 
	  //�ַ���Ϣ
		DispatchMessage(&msg);
		OutputDebugStringA("aaaa\r\n");
 
	}
 
	//6��������Ϣ
 
	return 0;
}
