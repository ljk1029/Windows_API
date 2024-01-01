/**
* date:    2020/6/21
* version:     v 1.0
* Description: 调用win32的api显示界面过程，vc书上第一个test程序
*
* author:
**/

#if 0
#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);//声明回调函数
char szWinName[] = "MyWindow";                          //程序的类名称


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd;                  //窗口句柄    
	MSG msg;					//消息
	WNDCLASS WndClass;			//窗口类

	WndClass.style = CS_HREDRAW|CS_VREDRAW; //定义窗口类型
	WndClass.lpfnWndProc = WindowFunc;		//消息处理
	WndClass.cbClsExtra = 0;				//预留空间，0为不预留
	WndClass.cbWndExtra = 0;				//预留空间
	WndClass.hInstance = hInstance;			//程序的实例句柄
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//设置窗口的图标
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);  //设置鼠标光标形状
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景为白色
	WndClass.lpszMenuName = NULL;               //设置窗口菜单
	WndClass.lpszClassName = szWinName;			//定义窗口类的名称
	
	if(!RegisterClass(&WndClass))    //注册窗口
		return 1;
	hWnd = CreateWindow(szWinName,  //窗口的类的名称
		"MyWindow",					//窗口的标题
		WS_OVERLAPPEDWINDOW,		//窗口的风格
		CW_USEDEFAULT,				//窗口的坐标x
		CW_USEDEFAULT,				//窗口的坐标y
		CW_USEDEFAULT,				//窗口的宽度
		CW_USEDEFAULT,				//窗口的高度
		NULL,		//父窗口句柄
		NULL,		//窗口的目录
		hInstance,	//窗口的句柄
		NULL);		//参数指针
	ShowWindow(hWnd, nShowCmd);		//显示窗口
	UpdateWindow(hWnd);				//更新窗口
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//定义回调处理函数
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;				//设备句柄
	PAINTSTRUCT PainStruct; //声明绘制窗口客户区
	RECT Rect;				//矩形区域
	switch(message)
	{
	case WM_PAINT://重画消息
		hDC = BeginPaint(hWnd, &PainStruct);//准备窗口绘图  
		GetClientRect(hWnd, &Rect);			//得到客户 区矩形区域
		//在窗口显示字符串"Hello, Windows"
		DrawText(hDC, "Hello, Windows", -1, &Rect,
			DT_SINGLELINE|DT_CENTER|DT_VCENTER);//绘制字符串
		EndPaint(hWnd, &PainStruct);		//结束窗口绘图
		return 0;
	case WM_DESTROY://销毁窗口消息
		PostQuitMessage(0);//发送退出消息
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif