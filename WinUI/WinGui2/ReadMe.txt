1�������� ��Ŀ->����->MFC��ʹ�ã�����׼Windows���Ϊ�ڹ���DLL��ʹ��MFC

2���Ҽ�����->������->�߼�->��ڵ㣺WinMainCRTStartup


//��ԭ�������Ͻ���
3��windows����һ������Ĺ��̴���������ģ���������ǳ��򣨱���Explorer������CreateProcess���ϵͳ���ã�CreateProcessΪ������̴��������ַ��Ȼ�󽫴�����������룬Ȼ��ϵͳ�ٴ���һ�����߳̿�ʼִ��

run time startup�����Ĵ��룬run time startup ���������յ�����ڵ㺯����main, WinMain����

run time startup�����ܶ����飬����ȫ�ֱ����Ĵ��������٣���ڵ㺯���ĵ��õȡ������Ҿ�Ҫ������Ҫ���ˣ�run time startup���������ұ�������ǲ��ɼ��ģ���ô������������������أ�����һ���Ϊ����һ����̬���ӿ��

�������Ҿͷ��ֲ��ԡ������ӳ����ʱ���ҷ�������һ����Ϣ��

  Found _printf
        Referenced in temporary.obj
        Loaded LIBCD.lib(printf.obj)
      Found _mainCRTStartup
        Loaded LIBCD.lib(crt0.obj)

�����ԣ�������libcd.lib��̬�����ӵ��ҵ�exe����ġ���������������ص���Ϣ��������һ������Ȥ�ĳ���

�������û��WinMain��������ȴ�ܹ�����ַ������������£�

//�ļ���:a.c

#include < windows.h >

const char str[] = "This is Zouxiao's blog";

void DrawString(HDC hDC, int x, int y)
{    
    SetBkMode(hDC, TRANSPARENT);
    SetTextColor(hDC, RGB(255, 0, 0));
    TextOut(hDC, x, y, str, strlen(str));
}

void WinMainCRTStartup()
{
    HDC hDC = GetDC(NULL);

    DrawString(hDC, GetSystemMetrics(SM_CXSCREEN) / 2,
                    GetSystemMetrics(SM_CYSCREEN) / 2);
    
    ReleaseDC(NULL, hDC);

}

�ɹ�����������ļ���Ҫע�����㣺1���ļ��ĺ�׺������Ϊ.c��������.cpp�� 2�������/SUBSYSTEM:WINDOWS�����ӿ��ء�

�������������Կ�����

WinMainCRTStartup�������������������ѡ���ģ������/SUBSYSTEMָ������windows����ô����WinMainCRTStartup,���/SUBSYSTEMָ������console,��ô����mainCRTStartup�����û��ָ���Ļ����������Զ�������ڵ㺯����main,WinMain���Զ�ѡ����������������û����ڵ㺯���������ͻᱨ��CRTStartup��������������д����libc.lib(libcd.lib)����һ�ݱ�����˵�CRTStartup������Դ����visual studioĿ¼�п����ҵ�(crt0.c,wincrt0.c)�������������Ĭ�ϵĵ������ǵ���ڵ㺯�����������������Զ��������ӵ����ǵ�exe�����������ļ���û����Щ������ǰ���£�

����ҵ�������ô�࣬����Ϊʲô������Ҫ��.cΪ��׺��������Ϊ��������c���Ա��룬��������Ϊ������c run time library ��

������ֻʶ����c���Ա���ĺ�����Ե�ʰ�