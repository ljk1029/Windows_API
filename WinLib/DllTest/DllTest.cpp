#include <windows.h>
#include "Inc.h"


#ifdef _MANAGED  //不知道什么用处，删除也可以运行
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)  
{  
    return TRUE;  
} 

#ifdef _MANAGED
#pragma managed(pop)
#endif


/*生成动态库二个函数*/
int add(int a, int b)
{
	return a+b;
}
int dec(int a, int b)
{
	return a-b;
}