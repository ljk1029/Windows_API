BOOL ExitWindowsEx(UINT uFlags, DWORD dwReserved)

uFlags 
EWX_FORCE
	ǿ����ֹ���̡����˱�־���ã�Windows���ᷢ����ϢWM_QUERYENDSESSION��WM_ENDSESSION��
	��Ϣ��Ŀǰ��ϵͳ�����еĳ�������ܻᵼ��Ӧ�ó���ʧ���ݡ���ˣ���Ӧ��ֻ�ڽ��������ʹ�ô˱�־��
EWX_LOGOFF
	�ر����н��̣�Ȼ��ע���û���
EWX_POWEROFF
	�ر�ϵͳ���رյ�Դ����ϵͳ����֧�ֶϵ硣
EWX_REBOOT:
	�ر�ϵͳ��Ȼ����������ϵͳ��
EWX_SHUTDOWN:
	�ر�ϵͳ����ȫ�عرյ�Դ�������ļ��������Ѿ�ˢ�µ������ϣ������������еĽ����Ѿ�ֹͣ

����:dwReserved
����������������ԡ�һ��ȡ0��
����ֵ
��������ɹ�������ֵΪ���㡣
