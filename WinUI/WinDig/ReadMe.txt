一、
INT_PTR  DialogBox(
    HINSTANCE hInstance,
    LPCWSTR lpTemplateName,
    HWND hWndParent,
    DLGPROC lpDialogFunc
);
 
hInstance是当前应用程序的实例句柄。
lpTemplateName是对话框的资源模板。
hWndParent是父窗口的句柄。
lpDialogFunc是对话框的消息处理函数。

二、对话框初始化消息
win32是 WM_CREATE
对话框是 WM_INITDIALOG

三、
WINUSERAPI BOOL WINAPI EndDialog(
    HWND hDlg,
    INT_PTR nResult
);
hDlg是对话框窗口的句柄。
nResult是设置给函数DialogBox的返回值。