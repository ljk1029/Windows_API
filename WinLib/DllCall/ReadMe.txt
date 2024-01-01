DLL 生成函数有二种导出方式

一、在Inc.h里
  使用extern"C" _declspec(dllexport)	；
  前面有extern"C" 据说C定义的函数名会被C++重写，然后调用时找不到，加上他就不会被改写。

二、在DllTest.def里
  add @1 后面的@1标号作用，这样不到可以用函数名调用还可以用数字调用。


  DLL调用也有二种

  一、隐式调用
	#pragma comment(lib, "XXX.lib")
	_declspec(dllimport)int xx(int x);
	先加载静态库，然后导出函数；下面就可以直接调用函数


  二、显式调用
		typedef int(*xx_FUNC)(int x);                        
	HMODULE hMod = LoadLibrary("XXX.dll");                   
	xx_FUNC xx_fp = (DEC_FUNC)GetProcAddress(hMod,"xx");     
		xx_fp(x);
	FreeLibrary(hMod);
	1/定义函数模型 2/加载动态库到进程 3/获取函数地址 
	4/调用  5/释放动态库