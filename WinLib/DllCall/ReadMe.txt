DLL ���ɺ����ж��ֵ�����ʽ

һ����Inc.h��
  ʹ��extern"C" _declspec(dllexport)	��
  ǰ����extern"C" ��˵C����ĺ������ᱻC++��д��Ȼ�����ʱ�Ҳ������������Ͳ��ᱻ��д��

������DllTest.def��
  add @1 �����@1������ã��������������ú��������û����������ֵ��á�


  DLL����Ҳ�ж���

  һ����ʽ����
	#pragma comment(lib, "XXX.lib")
	_declspec(dllimport)int xx(int x);
	�ȼ��ؾ�̬�⣬Ȼ�󵼳�����������Ϳ���ֱ�ӵ��ú���


  ������ʽ����
		typedef int(*xx_FUNC)(int x);                        
	HMODULE hMod = LoadLibrary("XXX.dll");                   
	xx_FUNC xx_fp = (DEC_FUNC)GetProcAddress(hMod,"xx");     
		xx_fp(x);
	FreeLibrary(hMod);
	1/���庯��ģ�� 2/���ض�̬�⵽���� 3/��ȡ������ַ 
	4/����  5/�ͷŶ�̬��