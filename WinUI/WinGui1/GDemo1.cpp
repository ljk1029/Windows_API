#include <Windows.h> //底层实现窗口的头文件
#include <stdio.h>
 
//6、处理窗口过程
//CALLBACK 代表__stdcall 参数的传递顺序； 从右到左 依次入栈， 并且在函数返回前 清空堆栈
 
LRESULT CALLBACK WindowProc(
	HWND hwnd, //消息所属的窗口句柄
	UINT  uMsg,  //具体的消息名称 消息名形式:WM_XXX
	WPARAM wParam,  //键盘附加消息
	LPARAM lParam    //鼠标附加消息
	) 
{
	switch (uMsg)
	{
		OutputDebugStringA("bbbb\r\n");
	case WM_CLOSE: DestroyWindow(hwnd); //DestoryWindow 发送另一个消息 WM_DESTROY
		break;
	case WM_DESTROY: PostQuitMessage(0);//销毁窗口消息  发送退出消息
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
 
	case WM_KEYDOWN: //键盘
		MessageBox(hwnd, TEXT("键盘"), TEXT("键盘按下"), MB_OK);
		break;
 
	case WM_PAINT: //绘图
	{
		PAINTSTRUCT ps; //绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);
 
		TextOut(hdc, 100, 100, TEXT("world"), strlen("world"));
 
		EndPaint(hwnd, &ps);
		break;
	}
		
	default:
		break;
	} 
	OutputDebugStringA("cccc\r\n");
	//返回值使用默认处理方式
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
 
//程序入口函数
//WINAPI 代表__stdcall 参数的传递顺序； 从右到左 依次入栈， 并且在函数返回前 清空堆栈
 
int WINAPI WinMain(
	HINSTANCE hInstance, //应用程序实例句柄
	HINSTANCE hPrevInstance, //上一个应用程序句柄， 在win32环境下， 参数一般为NULL， 不去作用
	LPSTR lpCmdLine,  //相当于 char *argv[]
	int nShowCmd)     //显示命令(最大化、最小化、正常)
{
	/*
	 * 创建窗口的步骤
	 * 1、设计窗口
	 * 2、注册窗口
	 * 3、创建窗口
	 * 4、显示和更新
	 * 5、通过循环取消息
	 * 6、处理消息 (窗口过程)
	 */
 
	//1、设计窗口
	WNDCLASS wc; //WND = WINDOW
	wc.cbClsExtra = 0; //类的额外的内存
	wc.cbWndExtra = 0; //窗口额外的内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //设置背景
	wc.hCursor = LoadCursor(NULL, IDC_HAND); //设置光标，如果第一个参数为NULL，代表系统提供的光标
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);//图标
	wc.hInstance = hInstance; //应用程序实例句柄 传入WinMain的形参即可
	wc.lpfnWndProc = WindowProc;//回调函数 窗口过程 刚开始不要写具体函数
	wc.lpszClassName = TEXT("WIN"); //指定窗口类名称
	wc.lpszMenuName = NULL; //菜单名称
	wc.style = 0; //显示风格 0代表默认风格
 
	//2、注册窗口类
	RegisterClass(&wc);
 
	//3、创建窗口
	/* CreateWindow参数列表,返回值HWND 窗口句柄
	   lpClassName, 类名
	   lpWindowName, 窗口名
	   dwStyle, 选 WS_OVERLAPPEDWINDOW 风格
	   x,  显示坐标 CW_USEDEFAULT 默认值
	   y,   
	   nWidth, 宽高
	   nHeight,
	   hWndParent, 父窗口 NULL
	   hMenu,  菜单 NULL
	   hInstance, 实例句柄 hInstance
	   lpParam 附加值 NULL
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("Hello"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	//4、显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
 
	//5、通过循环取消息
	/*
	HWND        hwnd; 主窗口句柄
	UINT        message; 具体消息名称
	WPARAM      wParam; 附加消息 键盘消息
	LPARAM      lParam; 附加消息 鼠标消息 
	DWORD       time; 消息产生时间
	POINT       pt; 附加消息 鼠标消息 x、y坐标
	*/
	MSG msg;
 
	/* GetMessage()方法
	_Out_ LPMSG lpMsg, 消息
	_In_opt_ HWND hWnd, 捕获窗口 填NULL代表捕获所有的窗口
	_In_ UINT wMsgFilterMin, 最小和最大的过滤的消息 一般填入0
	_In_ UINT wMsgFilterMax   填0代表捕获所有消息
	*/
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
	  //翻译消息
		TranslateMessage(&msg);
 
	  //分发消息
		DispatchMessage(&msg);
		OutputDebugStringA("aaaa\r\n");
 
	}
 
	//6、处理消息
 
	return 0;
}
