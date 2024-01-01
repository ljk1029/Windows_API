#include <stdio.h>

#include "../LibTest/Inc.h"//../代表进入当前目录的上一级目录

#pragma comment(lib, "../Debug/LibTest.lib")

int main(int argc, char* argv[])
{
	int iRet = add(7,8);
		printf("7+8=%d\n", iRet);
	return 0;
}