#include <stdio.h>
#include <Windows.h>

//1隐式链接
#define LIB_PATH "E:\\VMCode\\Common\\Windows_API\\WinLib\\Debug\\DllTest.lib"

#pragma comment(lib, LIB_PATH)
_declspec(dllimport)int add(int a, int b);

//2显示链接
typedef int(*DEC_FUNC)(int a, int b);

int main(int argc, char* argv[])
{
	//1隐式链接
	int r = add(7, 8);
	printf("7+8=%d\n", r);

	/*********************************************/
	HMODULE hMod = LoadLibrary(LIB_PATH);//2显示加载动态库
	if(hMod)
	{
		DEC_FUNC dec_fp = (DEC_FUNC)GetProcAddress(hMod,"dec");
		if(dec_fp)
		{
			int r = dec_fp(10, 6);
			printf("10-6=%d\n", r);
		}
		FreeLibrary(hMod);//2显示释放动态库
	}
	

	system("pause");
	return 0;
}
