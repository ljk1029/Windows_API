/**
* date:    2020/11/18
* version:     v 1.0
* Description: ����win32�ģ�GDI
*
* author:
**/


#include <windows.h>
//#include <afxwin.h>

//����������
void Paint(HWND hwnd); 
// ����ע��Ĵ�������
const char g_szClassName[] = "myWindowClass";

/*
 * ���Ĳ�,���ڹ���
 */  //��Ϣ�����Ĵ��ھ��,�������Ϣ���� ��Ϣ����ʽ:WM_XXX,���̸�����Ϣ,��긽����Ϣ
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
		case WM_CLOSE: DestroyWindow(hwnd); // ���ڹر���Ϣ
		break; 
        case WM_DESTROY: PostQuitMessage(0); //����������Ϣ �����뿪��Ϣ��ϵͳ
		break;
        
        case WM_PAINT:   // ���ڻ�����Ϣ
            Paint(hwnd); // �������ǵ� GDI ���ƺ���
		break;
		
		case WM_KEYDOWN: //����
			MessageBox(hwnd, TEXT("����"), TEXT("���̰���"), MB_OK);
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
       
        default: // ������Ϣ
        break; 
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);// pass ��ϵͳ���۲���
}

/*
 * ��һ��,ע�ᴰ����
 */
void RegisterMyWindow(HINSTANCE hInstance)
{
    WNDCLASSEX wc;  

    // 1)���ô�������
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = MyWindowProc; // ���õ��Ĳ��Ĵ��ڹ��̻ص�����
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    // 2)ע��
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, TEXT("����ע��ʧ��!"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // �����˳�
    }
}

/*
 * �ڶ�������������
 */
HWND CreateMyWindow(HINSTANCE hInstance, int nCmdShow)
{
    HWND hwnd;
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        TEXT("�ҵĴ�������"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, // �������� x,y Ĭ�Ϸ��� ���ڿ� 400 �� 300
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("���ڴ���ʧ��!"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // �����˳�
    }

    // ��ʾ����
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return hwnd;
}

/*
 * ������
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG Msg;

    // ��һ��,ע�ᴰ����
    RegisterMyWindow(hInstance);
    // �ڶ���:��������
    hwnd =  CreateMyWindow(hInstance, nCmdShow);
    // ������:��Ϣѭ��
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


/****************************������̺���********************************/
void Paint(HWND hwnd) //����1
{
    // paint struct ��ͼ�ṹ�壬�洢Ŀ�괰�ڿ��Ի�ͼ�Ŀͻ�������(client area)
    PAINTSTRUCT ps;
    HDC hdc;   // DC(�ɻ�ͼ���ڴ����) �ľ��
    HPEN hpen; // ����

    // ͨ�����ھ����ȡ�ô��ڵ� DC
    hdc = BeginPaint(hwnd, &ps);
    // ��������
    hpen = CreatePen(PS_SOLID, 1, RGB(255,0,0));
    // DC ѡ�񻭱�
    SelectObject(hdc,hpen);
    // (����)�ӳ�ʼ���ƶ��� 50,50
    MoveToEx(hdc, 50, 50, NULL);
    // (����)�ӳ�ʼ�㻭�ߵ� 100,100
    LineTo(hdc, 150, 100);

	MoveToEx(hdc, 100, 100, NULL);
    // (����)�ӳ�ʼ�㻭�ߵ� 100,100
    LineTo(hdc, 200, 200);

    EndPaint(hwnd, &ps);
}
















