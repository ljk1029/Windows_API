BOOL ExitWindowsEx(UINT uFlags, DWORD dwReserved)

uFlags 
EWX_FORCE
	强制终止进程。当此标志设置，Windows不会发送消息WM_QUERYENDSESSION和WM_ENDSESSION的
	消息给目前在系统中运行的程序。这可能会导致应用程序丢失数据。因此，你应该只在紧急情况下使用此标志。
EWX_LOGOFF
	关闭所有进程，然后注销用户。
EWX_POWEROFF
	关闭系统并关闭电源。该系统必须支持断电。
EWX_REBOOT:
	关闭系统，然后重新启动系统。
EWX_SHUTDOWN:
	关闭系统，安全地关闭电源。所有文件缓冲区已经刷新到磁盘上，所有正在运行的进程已经停止

参数:dwReserved
保留，这参数被忽略。一般取0。
返回值
如果函数成功，返回值为非零。
