一、
HWND CreateDialog(          
	HINSTANCE hInstance,
    LPCTSTR lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc
);

hInstance 当前应用程序实例句柄。
lpTemplate 标识对话框模板资源，有两种使用方式：一种是把对话框模板的ID强制转为LPCTSTR，一种可以使用MAKEINTRESOURCE宏得到标识ID。
hWndParent 父窗口的句柄。
lpDialogFunc 对话框消息处理函数。


NT_PTR DialogBox(          
	HINSTANCE hInstance,
    LPCTSTR lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc
);