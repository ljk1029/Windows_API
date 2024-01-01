1、TEST_EXPORTS: 定义这个变量在 属性 ->C/C++ ->预处理器 ->预处理器定义
			  生产DLL库的工程添加这个变量；
			  应用这个库的工程不添加。
			  Inc.h在DLL工程定义了变量，应用库的工程没有定义，简便实现DLL工程导出函数，用的工程导入

2、在属性-> 链接器 -> 输入-> 附加依赖项添加 
	$(SolutionDir)$(Configuration)\DllTest.lib
	在当前工程直接填这个，可以找到Debug/Release里，
	如果库在其他工程还可以在前面添加其他工程路径到其他路径
	也可以填绝对相对路径
	例如../Test/$(SolutionDir)$(Configuration)\Test.lib
