#include <Windows.h> //�ײ�ʵ�ִ��ڵ�ͷ�ļ�
#include <commctrl.h>
#include <Tchar.h>

UINT IDC_BUTTON_1 = 200; //���尴ť�ؼ�ID
UINT IDC_LIST_1 = 201;   //�����б�ؼ�ID
UINT IDC_EDIT_1 = 202;   //����༭��ؼ�ID

HWND hEdit = NULL;    //�༭�ؼ������Ϊ����Ӧcase��Ҳ������Ϊȫ�ֱ���

//6�������ڹ���
//CALLBACK ����__stdcall �����Ĵ���˳�� ���ҵ��� ������ջ�� �����ں�������ǰ ��ն�ջ

LRESULT CALLBACK WindowProc(
	HWND hwnd, //��Ϣ�����Ĵ��ھ��
	UINT  uMsg,  //�������Ϣ���� ��Ϣ����ʽ:WM_XXX
	WPARAM wParam,  //���̸�����Ϣ
	LPARAM lParam    //��긽����Ϣ
	) 
{
	switch (uMsg)
	{
	case WM_CLOSE: DestroyWindow(hwnd); //DestoryWindow ������һ����Ϣ WM_DESTROY
		break;

	case WM_DESTROY: PostQuitMessage(0);//���ٴ�����Ϣ  �����˳���Ϣ
		break;

	case WM_CREATE:  //�����ӿؼ�
	{  
		//������ť�ؼ�
		HWND hButton = CreateWindow(WC_BUTTON, _T("��ť"), WS_VISIBLE|WS_CHILD|BS_PUSHBUTTON, 200, 100, 50, 20, hwnd, (HMENU)IDC_BUTTON_1, NULL, NULL);
		//����list�б�ؼ�
		HWND hListCtrl = CreateWindow(WC_LISTVIEW, _T(""), WS_VISIBLE|WS_CHILD|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS, 300, 100, 200, 200, hwnd, (HMENU)IDC_LIST_1, NULL, NULL);
		//HWND hListCtrl = CreateWindowEx(LVS_EX_FULLROWSELECT, WC_LISTVIEW, _T(""), WS_VISIBLE|WS_CHILD|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS, 300, 100, 200, 200, hwnd, (HMENU)IDC_LIST_1, NULL, NULL);
		//�����༭��ؼ�
		hEdit = CreateWindow(WC_EDIT, _T("���Ǳ༭��"), WS_VISIBLE|WS_CHILD|WS_BORDER, 600, 100, 200, 200, hwnd, (HMENU)IDC_EDIT_1, NULL, NULL);

		//��������Ϣ
		LVCOLUMN colinfo ={0};
		colinfo.mask |= LVCF_TEXT|LVCF_WIDTH;
		colinfo.cx = 100;
		colinfo.pszText = _T("��0��");
		SendMessage(hListCtrl, LVM_INSERTCOLUMN, 0, (LPARAM)&colinfo);//��һ��

		LVCOLUMN colinfo1 ={0};
		colinfo1.mask |= LVCF_TEXT|LVCF_WIDTH;
		colinfo1.cx = 100;
		colinfo1.pszText = _T("��1��");
		//SendMessage(hListCtrl, LVM_INSERTCOLUMN, 1, (LPARAM)&colinfo1);//�ڶ���
		ListView_InsertColumn(hListCtrl, 1, &colinfo1);//΢���װ�ĺ�

		//��������Ϣ
		LV_ITEM rowitem = {0};
		rowitem.mask |= LVIF_TEXT;
		rowitem.pszText =_T("�й�");
		ListView_InsertItem(hListCtrl, &rowitem);//΢���װ�ĺ�

		/*LV_ITEM rowitem1 = {0};
		rowitem1.mask |= LVIF_TEXT;
		rowitem1.pszText =_T("��ɵ��");
		rowitem1.iItem = 0;     //�ڼ���
		rowitem1.iSubItem =1;   //�ڼ���
		ListView_SetItem(hListCtrl, &rowitem1);*/
		ListView_SetItemText(hListCtrl, 0, 1, _T("���ð�"));

		break;
	}

	case WM_COMMAND:  //��Ӧ������Ϣ
	{
		UINT nCtrlID = LOWORD(wParam); 
		UINT nCode = HIWORD(wParam); //BN_CLICKED
		if(nCode == BN_CLICKED && nCtrlID == IDC_BUTTON_1)
		{
			TCHAR editText[256] = {0};
			GetWindowText(hEdit, editText, 256);   //��ñ༭���ı�����
			MessageBox(NULL, _T("��������Ӧ"), _T("Tip"), NULL);
		}
		break;
	}

	case WM_LBUTTONDOWN:   //����������
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
 
		char buf[1024];
		wsprintf(buf, TEXT("x = %d, y %d"), xPos, yPos);
		MessageBox(hwnd, buf, TEXT("����������"), MB_OK);
		break;
	}
 
	case WM_KEYDOWN: //����
		MessageBox(hwnd, TEXT("����"), TEXT("���̰���"), MB_OK);
		break;
 
	case WM_PAINT: //�ػ���Ϣ
	{
		PAINTSTRUCT ps; //��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);//׼�����ڻ�ͼ 
 
		TextOut(hdc, 100, 100, TEXT("world"), strlen("world"));
 
		EndPaint(hwnd, &ps);//�������ڻ�ͼ
		break;
	}
		
	default:
		break;
	} 
	//����ֵʹ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
 
//������ں���
//WINAPI ����__stdcall �����Ĵ���˳�� ���ҵ��� ������ջ�� �����ں�������ǰ ��ն�ջ
 
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó������� ��win32�����£� ����һ��ΪNULL�� ��ȥ����
	LPSTR lpCmdLine,  //�൱�� char *argv[]
	int nShowCmd)     //��ʾ����(��󻯡���С��������)
{
	/*
	 * �������ڵĲ���
	 * 1����ƴ���
	 * 2��ע�ᴰ��
	 * 3����������
	 * 4����ʾ�͸���
	 * 5��ͨ��ѭ��ȡ��Ϣ
	 * 6��������Ϣ (���ڹ���)
	 */
 
	//1����ƴ���
	WNDCLASS wc; //WND = WINDOW
	wc.cbClsExtra = 0; //��Ķ�����ڴ�
	wc.cbWndExtra = 0; //���ڶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND); //���ù�꣬�����һ������ΪNULL������ϵͳ�ṩ�Ĺ��
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ͼ��
	wc.hInstance = hInstance; //Ӧ�ó���ʵ����� ����WinMain���βμ���
	wc.lpfnWndProc = WindowProc;//�ص����� ���ڹ��� �տ�ʼ��Ҫд���庯��
	wc.lpszClassName = TEXT("WIN"); //ָ������������
	wc.lpszMenuName = NULL; //�˵�����
	wc.style = 0; //��ʾ��� 0����Ĭ�Ϸ��
 
	//2��ע�ᴰ����
	if(!RegisterClass(&wc))
	{
		MessageBox(NULL, "ע��ʧ��", "Tip", MB_OK);
		return 1;
	}
 
	//3����������
	/* CreateWindow�����б�,����ֵHWND ���ھ��
	   lpClassName, ����
	   lpWindowName, ������
	   dwStyle, ѡ WS_OVERLAPPEDWINDOW ���
	   x,  ��ʾ���� CW_USEDEFAULT Ĭ��ֵ
	   y,   
	   nWidth, ���
	   nHeight,
	   hWndParent, ������ NULL
	   hMenu,  �˵� NULL
	   hInstance, ʵ����� hInstance
	   lpParam ����ֵ NULL
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("MyWindow"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	//4����ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
 
	//5��ͨ��ѭ��ȡ��Ϣ
	/*
	HWND        hwnd; �����ھ��
	UINT        message; ������Ϣ����
	WPARAM      wParam; ������Ϣ ������Ϣ
	LPARAM      lParam; ������Ϣ �����Ϣ 
	DWORD       time; ��Ϣ����ʱ��
	POINT       pt; ������Ϣ �����Ϣ x��y����
	*/
	MSG msg;
 
	/* GetMessage()����
	_Out_ LPMSG lpMsg, ��Ϣ
	_In_opt_ HWND hWnd, ���񴰿� ��NULL���������еĴ���
	_In_ UINT wMsgFilterMin, ��С�����Ĺ��˵���Ϣ һ������0
	_In_ UINT wMsgFilterMax   ��0������������Ϣ
	*/
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
	  //������Ϣ
		TranslateMessage(&msg);

	  //�ַ���Ϣ
		DispatchMessage(&msg);
	}
 
	//6��������Ϣ
 
	return 0;
}
