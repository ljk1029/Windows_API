#include <windows.h>
#include "Inc.h"


#ifdef _MANAGED  //��֪��ʲô�ô���ɾ��Ҳ��������
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)  
{  
    return TRUE;  
} 

#ifdef _MANAGED
#pragma managed(pop)
#endif


/*���ɶ�̬���������*/
int add(int a, int b)
{
	return a+b;
}
int dec(int a, int b)
{
	return a-b;
}