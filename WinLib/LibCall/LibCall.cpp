#include <stdio.h>

#include "../LibTest/Inc.h"//../������뵱ǰĿ¼����һ��Ŀ¼

#pragma comment(lib, "../Debug/LibTest.lib")

int main(int argc, char* argv[])
{
	int iRet = add(7,8);
		printf("7+8=%d\n", iRet);
	return 0;
}