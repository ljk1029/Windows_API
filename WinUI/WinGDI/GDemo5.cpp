/**
* date:    2020/11/18
* version:     v 1.0
* Description: 调用win32的，GDI
*
* author:
**/


#include <windows.h>
//#include <afxwin.h>

//处理函数声明
void Paint(HWND hwnd); 
// 用于注册的窗口类名
const char g_szClassName[] = "myWindowClass";

/*
 * 第四步,窗口过程
 */  //消息所属的窗口句柄,具体的消息名称 消息名形式:WM_XXX,键盘附加消息,鼠标附加消息
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
		case WM_CLOSE: DestroyWindow(hwnd); // 窗口关闭消息
		break; 
        case WM_DESTROY: PostQuitMessage(0); //窗口销毁消息 发送离开消息给系统
		break;
        
        case WM_PAINT:   // 窗口绘制消息
            Paint(hwnd); // 调用我们的 GDI 绘制函数
		break;
		
		case WM_KEYDOWN: //键盘
			MessageBox(hwnd, TEXT("键盘"), TEXT("键盘按下"), MB_OK);
		break;

		case WM_LBUTTONDOWN:   //鼠标左击按下
		{
			int xPos = LOWORD(lParam);
			int yPos = HIWORD(lParam);
 
			char buf[1024];
			wsprintf(buf, TEXT("x = %d, y %d"), xPos, yPos);
			MessageBox(hwnd, buf, TEXT("鼠标左击按下"), MB_OK);
		break;
		}
       
        default: // 其他消息
        break; 
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);// pass 给系统，咱不管
}

/*
 * 第一步,注册窗口类
 */
void RegisterMyWindow(HINSTANCE hInstance)
{
    WNDCLASSEX wc;  

    // 1)配置窗口属性
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = MyWindowProc; // 设置第四步的窗口过程回调函数
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    // 2)注册
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, TEXT("窗口注册失败!"), TEXT("错误"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // 进程退出
    }
}

/*
 * 第二步，创建窗口
 */
HWND CreateMyWindow(HINSTANCE hInstance, int nCmdShow)
{
    HWND hwnd;
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        TEXT("我的窗口名称"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, // 出现坐标 x,y 默认分配 窗口宽 400 高 300
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("窗口创建失败!"), TEXT("错误"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // 进程退出
    }

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return hwnd;
}

/*
 * 主函数
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG Msg;

    // 第一步,注册窗口类
    RegisterMyWindow(hInstance);
    // 第二步:创建窗口
    hwnd =  CreateMyWindow(hInstance, nCmdShow);
    // 第三步:消息循环
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


/****************************处理过程函数********************************/
void Paint(HWND hwnd) //方法1
{
    // paint struct 绘图结构体，存储目标窗口可以绘图的客户端区域(client area)
    PAINTSTRUCT ps;
    HDC hdc;   // DC(可画图的内存对象) 的句柄
    HPEN hpen; // 画笔

    // 通过窗口句柄获取该窗口的 DC
    hdc = BeginPaint(hwnd, &ps);
    // 创建画笔
    hpen = CreatePen(PS_SOLID, 1, RGB(255,0,0));
    // DC 选择画笔
    SelectObject(hdc,hpen);
    // (画笔)从初始点移动到 50,50
    MoveToEx(hdc, 50, 50, NULL);
    // (画笔)从初始点画线到 100,100
    LineTo(hdc, 150, 100);

	MoveToEx(hdc, 100, 100, NULL);
    // (画笔)从初始点画线到 100,100
    LineTo(hdc, 200, 200);

    EndPaint(hwnd, &ps);
}
















