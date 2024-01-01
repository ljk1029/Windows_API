#include <stdio.h>
#include <windows.h>

int main()
{
	printf("ExitWindowsEx!\n");
	BOOL  ExitFlag = ExitWindows(EWX_REBOOT, NULL); //¹Ø»úÖØÆô

	return 0;
}