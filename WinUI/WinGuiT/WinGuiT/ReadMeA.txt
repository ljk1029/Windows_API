一、创建窗口
该函数创建一个重叠式窗口、弹出式窗口或子窗口。它指定窗口类，窗口标题，窗口风格，以及窗口的初始位置及大小（可选的）。
函数也指该窗口的父窗口或所属窗口（如果存在的话），及窗口的菜单。

若要使用除 CreateWindow 函数支持的风格外的扩展风格，则使用 CreateWindowEx 函数代替 CreateWindow 函数。


函数原型：
HWND CreateWindow(
	LPCTSTR lpClassName,  //窗口类名称
	LPCTSTR lpWindowName, //窗口标题
	DWORD dwStyle,        //窗口风格
	int x,				  //窗口坐标x
	int y,				  //窗口坐标y
	int nWidth，			  //窗口宽度
	int nHeight，		  //窗口高度
	HWND hWndParent,	  //父窗口句柄
	HMENU hMenu，		  //窗口菜单句柄
	HANDLE hlnstance，	  //程序实例句柄
	LPVOID lpParam		  //创建参数
）；


参数：
lpClassName

1. 窗口类名称，可以是一个指向 NULL 结束的字符串或一个整型数值
2. 如果是字符串，它指定了窗口的类名。这个类名可以是任何用函数 RegisterClass 注册的类名，或是任何预定义的控制类名
3. 如是一个整型量，它是由此前调用 theGlobalAddAtom 函数产生的全局量。这个小于 0xC000 的 16 位数必须是 lpClassName 参数字的低 16 位，该参数的高位必须是 0

lpWindowName

1. 窗口标题，一个指向 NULL 结束的字符串指针
2. 如果窗口风格指定了标题条，由 lpWindowName 指向的窗口标题将显示在标题条上
3. 当使用 Createwindow 函数来创建控制例如按钮，选择框和静态控制时，可使用 lpWindowName 来指定控制文本

dwStyle

指定创建窗口的风格（详见下方↓）

x

1. 指定窗口的初始水平位置（x 坐标）
2. 对一个层叠或弹出式窗口，x 参数是屏幕坐标系的窗口的左上角的初始 x 坐标
3. 对于子窗口，x 是子窗口左上角相对父窗口客户区左上角的初始 x 坐标
4. 如果该参数被设为 CW_USEDEFAULT 则系统为窗口选择缺省的左上角坐标并忽略 y 参数，CW_USEDEFAULT 只对层叠窗口有效，如果为弹出式窗口或子窗口设定，则 x 和 y 参数被设为零。

y

1. 指定窗口的初始垂直位置（y 坐标）
2. 对一个层叠或弹出式窗口，y 参数是屏幕坐标系的窗口的左上角的初始 y 坐标
3. 对于子窗口，y 是子窗口左上角相对父窗口客户区左上角的初始 y 坐标
4. 对于列表框，y 是列表框客户区左上角相对父窗口客户区左上角的初始 y 坐标
5. 如果层叠窗口是使用 WS_VISIBLE 风格位创建的并且 x 参数被设为 CW_USEDEFAULT，则系统将忽略 y 参数

nWidth

1. 以设备单元指明窗口的宽度
2. 对于层叠窗口，nWidth 的值或是屏幕坐标的窗口宽度或是 CW_USEDEFAULT
3. 若 nWidth 是 CW_USEDEFAULT，则系统为窗口选择一个默认的高度和宽度（默认宽度为从初始 x 坐标开始到屏幕的右边界，缺省高度为从初始 y 坐标开始到目标区域的顶部。)，CW_USEDEFAULT 只对层叠窗口有效，如果为弹出式窗口和子窗口设定 CW_USEDEFAULT 标志则 nWidth 和 nHeight 被设为零

nHeight

1. 以设备单元指明窗口的高度
2. 对于层叠窗口，nHeight 是屏幕坐标的窗口宽度
3. 若 nWidth 被设为 CW_USEDEFAULT，则系统忽略 nHeight 参数，自动为 nWidth 和 nHeight 设置默认参数

hWndParent

1. 指向被创建窗口的父窗口或所有者窗口的句柄
2. 若要创建一个子窗口或一个从属窗口，需提供一个有效的窗口句柄
3. 创建一个单纯的消息窗口，可以提供 HWND_MESSAGE 或提供一个己存在的消息窗口的句柄

hMenu

1. 指向窗口菜单句柄，或依据窗口风格指明一个子窗口标识
2. 对于层叠或弹出式窗口，hMenu 指定窗口使用的菜单：如果使用了菜单类，则 hMenu 可以为 NULL
3. 对于子窗口，hMenu 指定了该子窗口标识（一个整型量），一个对话框使用这个整型值将事件通知父类。应用程序确定子窗口标识，这个值对于相同父窗口的所有子窗口必须是唯一的

hInstance

与窗口相关联的模块实例的句柄

lpParam

1. 指向一个值的指针，该值传递给窗口 WM_CREATE 消息。该值通过在 IParam 参数中的 CREATESTRUCT 结构传递
2. 如果应用程序调用 CreateWindow 创建一个 MDI 客户窗口，则 lpParam 必须指向一个 CLIENTCREATESTRUCT 结构


dwStyle 窗口风格解析:

WS_BORDER
创建一个带边框的窗口

WS_CAPTION
创建一个有标题框的窗口（包含了 WS_BODER 风格）

WS_CHILD
创建一个子窗口，这个风格的窗口不能拥有菜单也不能与 WS_POPUP 风格合用

WS_CHILDWINDOW
与 WS_CHILD 相同

WS_CLIPCHILDREN
当在父窗口内绘图时，排除子窗口区域，在创建父窗口时使用这个风格

WS_CLIPSIBLINGS
1. 排除子窗口之间的相对区域，也就是，当一个特定的窗口接收到 WM_PAINT 消息时，WS_CLIPSIBLINGS 风格将所有层叠窗口排除在绘图之外，只重绘指定的子窗口
2. 如果未指定该风格，并且子窗口是层叠的，则在重绘子窗口的客户区时，就会重绘邻近的子窗口

WS_DISABLED
1. 创建一个初始状态为禁止的子窗口，一个禁止状态的窗口不能接受来自用户的输入信息
2. 在窗口创建之后，可以调用 EnableWindow 函数来启用该窗口

WS_DLGFRAME
创建一个带对话框边框风格的窗口，这种风格的窗口不能带标题条

WS_GROUP
1. 指定一组“控制窗口”的第一个“控制窗口”
2. 这个“控制窗口”组由第一个“控制窗口”和随后定义的“控制窗口”组成，自第二个“控制窗口”开始每个“控制窗口”具有 WS_GROUP 风格
3. 每个组的第一个“控制窗口”带有 WS_TABSTOP 风格，从而使用户可以在组间移动
4. 用户随后可以使用光标在组内的控制间改变键盘焦点

WS_HSCROLL
创建一个有水平滚动条的窗口

WS_ICONIC
创建一个初始状态为最小化状态的窗口，与 WS_MINIMIZE 风格相同

WS_MAXIMIZE
创建一个初始状态为最大化状态的窗口

WS_MAXIMIZEBOX
创建一个具有最大化按钮的窗口，该风格不能与 WS_EX_CONTEXTHELP 风格同时出现，同时必须指定 WS_SYSMENU 风格

WS_MINIMIZE
创建一个初始状态为最小化状态的窗口，与 WS_ICONIC 风格相同

WS_MINIMIZEBOX
创建一个具有最小化按钮的窗口，该风格不能与 WS_EX_CONTEXTHELP 风格同时出现，同时必须指定 WS_SYSMENU 风格

WS_OVERLAPPED
产生一个层叠的窗口，一个层叠的窗口有一个标题条和一个边框，与 WS_TILED 风格相同

WS_OVERLAPPEDWINDOW
相当于（WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX），与 WS_TILEDWINDOW 风格相同

WS_POPUP
创建一个弹出式窗口，该风格不能与 WS_CHILD 风格同时使用。

WS_POPUPWINDOW
相当于（WS_POPUP | WS_BORDER | WS_SYSMENU），但 WS_CAPTION 和 WS_POPUPWINDOW 必须同时设定才能使窗口某单可见

WS_SIZEBOX
创建一个可调边框的窗口，与 WS_THICKFRAME 风格相同

WS_SYSMENU
创建一个在标题条上带有窗口菜单的窗口，必须同时设定 WS_CAPTION 风格

WS_TABSTOP
1. 创建一个“控制窗口”，在用户按下 Tab 键时可以获得键盘焦点。
2. 按下 Tab 键后使键盘焦点转移到下一具有 WS_TABSTOP 风格的“控制窗口”

WS_THICKFRAME
创建一个具有可调边框的窗口，与 WS_SIZEBOX 风格相同

WS_TILED
产生一个层叠的窗口，一个层叠的窗口有一个标题和一个边框，与 WS_OVERLAPPED 风格相同

WS_TILEDWINDOW
相当于（WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX），与 WS_OVERLAPPEDWINDOW 风格相同

WS_VISIBLE
创建一个初始状态为可见的窗口

WS_VSCROLL
创建一个有垂直滚动条的窗口


返回值：

1. 如果函数成功，返回值为新窗口的句柄。
2. 如果函数失败，返回值为 NULL。



备注：在返回前，CreateWindow给窗口过程发送一个WM_CREATE消息。对于层叠，弹出式和子窗口，CreateWindow给窗口发送 WM_CREATE，WM_GETMINMAXINFO和WM_NCCREATE消息。消息WM_CREATE的lParam参数包含一个指向 CREATESTRUCT结构的指针。如果指定了WS_VISIBLE风格，CreateWindow向窗口发送所有需要激活和显示窗口的消息。
获取有关任务条是否为创建的窗口显示一个按钮的控制信息，参看Taskbar按钮的Visbility。
    
以下预定义的控制类可以在lpClassName参数中指定。注意在dwStyle参数中可以使用的相应的控制风格。

BUTTON：    按钮，是一个小矩形子窗口，用户可以点击来打开或关闭。按钮控制可以单独使用或包含在组中使用，可以为控制写标签或不写标签。当用户点击按钮控制时按钮的外观有明显的改变。请参看Button。查看dwStyle参数中指定的按钮风格表请参考Button Style。
COMBOBOX：  组合框，由一个列表框和一个类似于编辑控制的选择域组成。在使用这个风格控制时，应用程序或者使列表框一直显示或者是作成一个下拉列表。如果列表框可见，则在编辑域中输入字符将使列表框中与字符一致的第一个域高亮。反之，在列表框中选择的项将显示在编辑域中。请参看Combo Boxes。
    查看dwStyle参数中指定的组合框风格表请参考Combo Boxes Style。
EDIT：      编辑框，一 个小的矩形子窗口，用户可以使用键盘向其中输入文本。用户可以通过点击或按Tab键来选中编辑框控制并且使控制获得焦点。当编辑框中显示一个闪烁的插入记 号时，用户可以输入文本。使用鼠标移动光标，选择被替换的字符或设置插入字符的位置或使用回退键删除字符。请参看Edit controls。
    查看dwStyle参数中指定的编辑框风格的表格请参考Edit Control Style。
LISTBOX：   列表框，字符串的列表。当应用程序必须显示名称的列表，例如文件名列表等，使用户可以从中选择时就可指定列表框。用户可以通过单击来选择名称。选择时，被选择名高亮，同时传递给父窗口一个通知消息。请参看LiSt Box Style。查看dwStyle参数中指定的列表风格表请参考List BOX Control Style。
MDICLIENT： 客户设计出MDI客户窗口。窗口接收控制MDI应用程序子窗口的消息。建议使用两种控制风格位：WS_CLIPCHILDREN和WS_CHILD。指定了 WS_HSCROLL和WS_VSCROLL风格的MDI客户窗口允许用户将MDI子窗口滑动进入视窗。请参看MDI。
RichEdit：  设计一个Rich Editl.0版的控制。该控制使用户可以以字符和段落格式测览和编辑文本，并且可以包含嵌入的COM对象。请参看Rich Edit Controls。查看dwStyle参数中指定的RichEdit风格表请参考List Box Control Style。
RICHEDIT_CLASS：设计一个Rich Edik2.0版的控制。该控制使用户可以以字符和段落格式测览和编辑文本，并且可以包含嵌入的COM对象。请参看RichEditControls。查看dwStyle参数中指定的RichEdit风格表请参考RichEditControIStyle。
SCROLLBAR：     滚动条，设计的一个包含着一个滚动盒和两端有方向箭头的矩形。只要用户点击了控制，滚动条就给父窗口发送一个通知消息。如有必要，父窗口负责更新滚动条的位置。请参看ScrollBars。查看dwStyle参数中指定的滚动条风格表请参考Scroll Bars Style。
STATIC：        一个简单的静态文本域，文本盒或矩形用于给控制加标签，组合控制或将控制与其他控制分开。
    静态控制不提供输入和也不提供输出。请参看Static Control Styles。查看dwStyle参数中指定的静态文本风格表请参考Scroll Bars Style。


二、注册窗口
ATON RegisterClass（CONST WNDCLASS *lpWndClass）；

参数：
lpWndClass：指向一个WNDCLASS结构的指针。在将它传递给函数之前，必须在该结构中填充适当的类属性。

返回值：
如果函数成功，返回值是唯一标识已注册的类的一个原子；如果函数失败，返回值为0。


typedef struct _WNDCLASS {
　　UINT style;
　　WNDPROC lpfnWndProc;
　　int cbClsExtra;
　　int cbWndExtra;
　　HINSTANCE hInstance;
　　HICON hIcon;
　　HCURSOR hCursor;
　　HBRUSH hbrBackground;
　　LPCTSTR lpszMenuName;
　　LPCTSTR lpszClassName;
} WNDCLASS, *PWNDCLASS;

style: 指定类风格。这些风格可通过按位或操作组合起来。风格如下:
　　CS_BYTEALIGNCLIENT: 在字节边界上（在x方向上）定位窗口的用户区域的位置
　　CS_BYTEALIGNWINDOW: 在字节边界上（在x方向上）定位窗口的位置
　　CS_CLASSDC: 该窗口类的所有窗口实例都共享一个窗口类DC
　　CS_DBLCLKS: 允许向窗口发送双击鼠标键的消息
　　CS_GLOBALCLASS: 当调用CreateWindow 或 CreateWindowEx 函数来创建窗口时允许它的hInstance参数和注册窗口类时传递给
　　RegisterClass 的 hInstance参数不同。如果不指定该风格，则这两个 hInstance 必须相同。
　　CS_HREDRAW: 当水平长度改变或移动窗口时，重画整个窗口
　　CS_NOCLOSE: 禁止系统菜单的关闭选项
　　CS_OWNDC: 给予每个窗口实例它本身的DC。注意，尽管这样是很方便，但它必须慎重使用，因为每个DC大约要占800个字节的内存。
　　CS_PARENTDC: 将子窗口的裁剪区域设置到父窗口的DC中去，这样子窗口便可以在父窗口上绘制自身。
		注意，这是子窗口还是从系统缓存中获取DC，而不是使用父窗口的DC。使用该风格可以提高系统性能。
　　CS_SAVEBITS: 以位图形式保存被该窗口遮挡的屏幕部分，这样当给窗口移动以后，系统便可以用该保存的位图恢复屏幕移动的相应部分，
		从而系统不用向被该窗口遮挡的窗口发送 WM_PAINT 消息。该特性对于菜单类型的窗口比较合适，因为它通常是简短的显示一下之后便消失。设置该特性将增加显示该窗口的时间，因为它通常要先分配保存位图的内存。
　　CS_VREDRAW: 当垂直长度改变或移动窗口时，重画整个窗口

lpfnWndProc: 指向窗口过程

cbClsExtra: 指定紧随在 WNDCLASS 数据结构后分配的字节数。系统将其初始化为零。

cbWndExtra: 指定紧随在窗口实例之后分配的字节数，系统将其初始化为零。如果应用程序正在用WNDCLASS结构注册
		一个在RC资源描述文件中用CLASS指令创建的对话框时，它必须设置这个字段为 DLGWINDOWEXTRA。

hInstance: 标识了该窗口类的窗口过程所在的模块实例的句柄，不能为NULL。

hIcon: 标识了该窗口类的图标。hIcon字段必须是一个图标的句柄；若hIcon字段为NULL，则无论何时用户把应用程序缩至最小时，应用程序必须画一个图标。

hCursor: 标识该窗口类的光标，hCursor必须是一个光标资源的句柄。若hCursor字段为NULL，则无论何时鼠标移到应用程序窗口时，应用程序必须显式设置光标形状。

hbrBackground: 标识了该窗口类的背景画笔。hbrBackground字段必须是用于绘制背景的物理刷子的句柄，或者是一个颜色的值。
		如果给出一个颜色的值，它必须是下面列出的标准系统颜色之一（系统将对所选颜色加1）。如果给出了颜色值，
		它必须是转换成下列的HBRUSH类型之一的颜色:
　　COLOR_ACTIVEBORDER
　　COLOR_ACTIVECAPTION
　　COLOR_APPWORKSPACE
　　COLOR_BACKGROUND
　　COLOR_BTNFACE
　　COLOR_BTHSHADOW
　　COLOR_BTNTEXT
　　COLOR_CAPTIONTEXT
　　COLOR_GRAYTEXT
　　COLOR_HIGHLIGHT
　　COLOR_HIGHLIGHTTEXT
　　COLOR_INACTIVEBORDER
　　COLOR_INACTIVECAPTION
　　COLOR_MENU
　　COLOR_MENUTEXT
　　COLOR_SCROLLBAR
　　COLOR_WINDOW
　　COLOR_WINDOWFRAME
　　COLOR_WINDOWTEXT

　　当hbrBackground字段为NULL时，每当需要绘制其用户区域时，应用程序必须自己来绘制其背景。应用程序可以通过处理WM_ERASEBKGND 消息或检查由 BeginPaint 函数填写的 PAINTSTRUCT 结构的fErase 字段来确定背景什么时候需要着色。
lpszMenuName：指向NULL结束的字符串，该字符串描述菜单的资源名，如同在资源文件里显示的名字一样。若使用一个整数标识菜单，可以使用MAKEINTRESOURCE宏。如果lpszMenuName为NULL，
　　那么该窗口类的窗口将没有默认菜单。

lpszClassName：指向NULL结束的字符串，或者是一个原型(atom)。若该参数是一个原型，它必须是一个有先前调用RegisterClass或者
		 RegisterClassEx函数产生的类原型。类原型必须作为lpszClassName的低字，高字必须为0.若lpszClassName是一个字符串，
		 它描述了窗口类名。这个类名可以是由RegisterClass或者RegisterClassEx注册的名字，或者是任何预定义的控件类名。

　　结构信息Header 在winuser.h声明，包含windows.h




typedef struct tagWNDCLASSEXW {
    UINT        cbSize;
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPCWSTR     lpszMenuName;
    LPCWSTR     lpszClassName;
    HICON       hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, NEAR *NPWNDCLASSEXW, FAR *LPWNDCLASSEXW;
 
cbSize是本结构的字节大小，一般设置为sizeof(WNDCLASSEXW);
style是窗口类型。
lpfnWndProc是窗口处理消息的回调函数。
cbClsExtra是窗口类型的扩展。
cbWndExtra是窗口实例的扩展。
hInstance是窗口实例句柄。
hIcon是窗口图标。
hCursor是窗口的光标。
hbrBackground是窗口背景颜色。
lpszMenuName是窗口菜单名称。
lpszClassName是窗口类型的名称。
hIconSm是窗口小图标。


 
 三、窗口显示
BOOL ShowWindow（HWND hWnd, int nCmdShow）

其中hWnd指窗口句柄；nCmdShow指定窗口如何显示。如果发送应用程序的程序提供了STARTUPINFO结构，
	则应用程序第一次调用ShowWindow时该参数被忽略。否则，在第一次调用ShowWindow函数时，
	该值应为在函数WinMain中nCmdShow参数。在随后的调用中，该参数可以为下列值之一：

预定义值
SW_FORCEMINIMIZE	在WindowNT5.0中最小化窗口，即使拥有窗口的线程被挂起也会最小化。在从其他线程最小化窗口时才使用这个参数	
11

SW_HIDE	     隐藏窗口，大小不变，激活状态不变
0

SW_MAXIMIZE	 最大化窗口，显示状态不变，激活状态不变	
3

SW_MINIMIZE	 最小化指定的窗口并且激活在Z序中的下一个顶层窗口	
6

SW_RESTORE	 激活并显示窗口。如果窗口最小化或最大化，则系统将窗口恢复到原来的尺寸和位置。
				在恢复最小化窗口时，应用程序应该指定这个标志	
9

SW_SHOW	     在窗口原来的位置以原来的尺寸激活和显示窗口	
5

SW_SHOWMAXIMIZED	 显示并激活窗口，以最大化显示	
3

SW_SHOWMINIMIZED	 显示并激活窗口，以最小化显示	
2

SW_SHOWMINNOACTIVE	 显示窗口并最小化，激活窗口仍然维持激活状态	
7

SW_SHOWNA	 以窗口原来的状态显示窗口。激活窗口仍然维持激活状态	
8

SW_SHOWNOACTIVATE	 以窗口最近一次的大小和状态显示窗口。激活窗口仍然维持激活状态	
4

SW_SHOWDEFAULT	 依据在STARTUPINFO结构中指定的SW_FLAG标志设定显示状态，STARTUPINFO结构
					是由启动应用程序的程序传递给CreateProcess函数的	
10

SW_SHOWNORMAL	 激活并显示一个窗口。如果窗口被最小化或最大化，系统将其恢复到原来的尺寸和大小。
					应用程序在第一次显示窗口的时候应该指定此标志	
1

四、获得消息
BOOL GetMessage(
       LPMSG lpMsg,   // 检索到的消息
       HWND  hWnd,    // 窗口指向
       UINT  wMsgFilterMin, // 消息范围的下界限参数
       UINT  wMsgFilterMax  // 上界限参数
);

lpMsg	是从线程消息队列里获取到的消息指针。
hWnd	是想获取那个窗口的消息，当设置为NULL时是获取所有窗口的消息。
wMsgFilterMin	是获取消息的ID编号最小值，如果小于这个值就不获取回来。
wMsgFilterMax	是获取消息的ID编号最大值，如果大于这个值就不获取回来。

函数返回值可能是0，大于0，或者等于-1。
如果成功获取一条非WM_QUIT消息时，就返回大于0的值；如果获取WM_QUIT消息时，就返回值0值，消息结束。如果出错就返回-1的值。



BOOL TranslateMessage(  CONST MSG *lpMsg );

函数功能描述:将虚拟键消息转换为字符消息。字符消息被送到调用线程的消息队列中，在下一次线程调用函数GetMessage或PeekMessage时被读出。

参数：
lpMsg 
    指向一个含有用GetMessage或PeekMessage函数从调用线程的消息队列中取得消息信息的MSG结构的指针。

返回值：
    如果消息被转换（即，字符消息被送到线程的消息队列中），返回非零值。
    如果消息是 WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN, 或 WM_SYSKEYUP，返回非零值，不考虑转换。
    如果消息没有转换（即，字符消息没被送到线程的消息队列中），返回值是零。


LONG DispatchMessage（CONST MSG*lpmsg );

函数功能：该函数调度一个消息给窗口程序。通常调度从GetMessage取得的消息。消息被调度到的窗口程序即是MainProc()函数。

参数：
lpmsg：指向含有消息的MSG结构的指针。

返回值：返回值是窗口程序返回的值。尽管返回值的含义依赖于被调度的消息，但返回值通常被忽略。


LRESULT SendMessage（HWND hWnd，UINT Msg，WPARAM wParam，LPARAM IParam）；

参数：

hWnd：其窗口程序将接收消息的窗口的句柄。如果此参数为HWND_BROADCAST，则消息将被发送到系统中所有顶层窗口，包括无效或不可见的非自身拥有的窗口、被覆盖的窗口和弹出式窗口，但消息不被发送到子窗口。

Msg：指定被发送的消息。

wParam：指定附加的消息指定信息。

IParam：指定附加的消息指定信息。

返回值：返回值指定消息处理的结果，依赖于所发送的消息。


typedef struct tagMSG{
            HWND hwnd;  窗口句柄(索引内存当中的资源)
            UINT(无符号整型)  message;  
            WPARAM(整型) wParam; //关于消息的附加参数,例如:按下一个键,具体是哪个按键
            LPARAM(整型) LParam; //关于消息的附加参数
            DWORD(32位整数) time;//消息被传递时候的时间
            POINT(坐标结构体) pt; //消息被传递时候,光标在屏幕上的位置
} MSG;

