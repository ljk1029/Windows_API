#include <Windows.h> //底层实现窗口的头文件
#include <commctrl.h>
#include <Tchar.h>

UINT IDC_BUTTON_1 = 200; //定义按钮控件ID
UINT IDC_LIST_1 = 201;   //定义列表控件ID
UINT IDC_EDIT_1 = 202;   //定义编辑框控件ID

HWND hEdit = NULL;    //编辑控件句柄，为了响应case里也能用设为全局变量

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
	case WM_CLOSE: DestroyWindow(hwnd); //DestoryWindow 发送另一个消息 WM_DESTROY
		break;

	case WM_DESTROY: PostQuitMessage(0);//销毁窗口消息  发送退出消息
		break;

	case WM_CREATE:  //创建子控件
	{  
		//创建按钮控件
		HWND hButton = CreateWindow(WC_BUTTON, _T("按钮"), WS_VISIBLE|WS_CHILD|BS_PUSHBUTTON, 200, 100, 50, 20, hwnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
		//创建list列表控件
		HWND hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_VISIBLE|WS_CHILD|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS, 300, 100, 200, 200, hwnd, (HMENU)IDC_LIST_1, NULL, NULL);
		//HWND hListCtrl = CreateWindowEx(LVS_EX_FULLROWSELECT, WC_LISTVIEW, _T(""), WS_VISIBLE|WS_CHILD|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS, 300, 100, 200, 200, hwnd, (HMENU)IDC_LIST_1, NULL, NULL);
		//创建编辑框控件
		hEdit = CreateWindow(WC_EDIT, _T("我是编辑框"), WS_VISIBLE|WS_CHILD|WS_BORDER, 600, 100, 200, 200, hwnd, (HMENU)IDC_EDIT_1, NULL, NULL);

		//插入列信息
		LVCOLUMN colinfo ={0};
		colinfo.mask |= LVCF_TEXT|LVCF_WIDTH;
		colinfo.cx = 100;
		colinfo.pszText = _T("第0列");
		SendMessage(hListCtrl, LVM_INSERTCOLUMN, 0, (LPARAM)&colinfo);//第一列

		LVCOLUMN colinfo1 ={0};
		colinfo1.mask |= LVCF_TEXT|LVCF_WIDTH;
		colinfo1.cx = 100;
		colinfo1.pszText = _T("第1列");
		//SendMessage(hListCtrl, LVM_INSERTCOLUMN, 1, (LPARAM)&colinfo1);//第二列
		ListView_InsertColumn(hListCtrl, 1, &colinfo1);//微软封装的宏

		//插入行信息
		LV_ITEM rowitem = {0};
		rowitem.mask |= LVIF_TEXT;
		rowitem.pszText =_T("中国");
		ListView_InsertItem(hListCtrl, &rowitem);//微软封装的宏

		/*LV_ITEM rowitem1 = {0};
		rowitem1.mask |= LVIF_TEXT;
		rowitem1.pszText =_T("二傻子");
		rowitem1.iItem = 0;     //第几行
		rowitem1.iSubItem =1;   //第几列
		ListView_SetItem(hListCtrl, &rowitem1);*/
		ListView_SetItemText(hListCtrl, 0, 1, _T("您好啊"));

		break;
	}

	case WM_COMMAND:  //响应按键消息
	{
		UINT nCtrlID = LOWORD(wParam); 
		UINT nCode = HIWORD(wParam); //BN_CLICKED
		if(nCode == BN_CLICKED && nCtrlID == IDC_BUTTON_1)
		{
			TCHAR editText[256] = {0};
			GetWindowText(hEdit, editText, 256);   //获得编辑框文本内容
			MessageBox(NULL, _T("按键被响应"), _T("Tip"), NULL);
		}
		break;
	}

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
 
	case WM_PAINT: //重画消息
	{
		PAINTSTRUCT ps; //绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);//准备窗口绘图 
 
		TextOut(hdc, 100, 100, TEXT("world"), strlen("world"));
 
		EndPaint(hwnd, &ps);//结束窗口绘图
		break;
	}
		
	default:
		break;
	} 
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
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标
	wc.hInstance = hInstance; //应用程序实例句柄 传入WinMain的形参即可
	wc.lpfnWndProc = WindowProc;//回调函数 窗口过程 刚开始不要写具体函数
	wc.lpszClassName = TEXT("WIN"); //指定窗口类名称
	wc.lpszMenuName = NULL; //菜单名称
	wc.style = 0; //显示风格 0代表默认风格
 
	//2、注册窗口类
	if(!RegisterClass(&wc))
	{
		MessageBox(NULL, "注册失败", "Tip", MB_OK);
		return 1;
	}
 
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
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("MyWindow"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
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
	}
 
	//6、处理消息
 
	return 0;
}
