һ��
HWND CreateDialog(          
	HINSTANCE hInstance,
    LPCTSTR lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc
);

hInstance ��ǰӦ�ó���ʵ�������
lpTemplate ��ʶ�Ի���ģ����Դ��������ʹ�÷�ʽ��һ���ǰѶԻ���ģ���IDǿ��תΪLPCTSTR��һ�ֿ���ʹ��MAKEINTRESOURCE��õ���ʶID��
hWndParent �����ڵľ����
lpDialogFunc �Ի�����Ϣ��������


NT_PTR DialogBox(          
	HINSTANCE hInstance,
    LPCTSTR lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc
);