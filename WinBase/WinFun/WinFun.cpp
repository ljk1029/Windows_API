/**
* date:    2020/6/23
* version:     v 1.0
* Description: URLDownloadToFile下载功能
*
* author:
**/

#include <windows.h>
#pragma comment (lib,"Urlmon.lib")

// 下载
int download(char* url, char* file)
{
	//HRESULT hret =URLDownloadToFile(NULL,"https://avatar.cctry.com/uc_server/data/avatar/000/00/00/51_avatar_small.jpg","C:\\1.jpg",0,NULL);
	HRESULT hret =URLDownloadToFile(NULL, url, file, 0, NULL);
	if(hret == S_OK)
	{
		MessageBox(NULL,"下载成功","Tip",MB_OK);
	}
	else
	{
		MessageBox(NULL,"下载失败","Tip",MB_OK);
	}
	return 0;
}

// shell执行
int shellEx(int OWEB = 1)
{
	SHELLEXECUTEINFO ShellInfo;    

	memset(&ShellInfo, 0, sizeof(ShellInfo));    

	ShellInfo.cbSize = sizeof(ShellInfo); //大小  

	ShellInfo.lpVerb = "open";       //运行  

	if(OWEB == 1)  //打开网站还是运行notepad++.exe
	{
		ShellInfo.lpFile = "https://www.bilibili.com/video/av46038943/?p=4";
	}
	else
	{
		ShellInfo.lpFile = "D:\\EditTool\\Notepad++\\notepad++.exe"; // 带路径的执行文件名
	}

	ShellInfo.nShow = SW_SHOWNORMAL;  //正常显示  

	//	ShellInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;//保存新程序句柄到hProcess,不显示错误提示框


	BOOL bResult = ShellExecuteEx(&ShellInfo);  
	//	WaitForSingleObject(ShellInfo.hProcess,INFINITE);

	return 0;
}


int main(int argc, char* argv[])
{
	char* url = "https://avatar.cctry.com/uc_server/data/avatar/000/00/00/51_avatar_small.jpg";
	download(url, "1.jpg");
	shellEx(1);
	shellEx(0);
	
	return 0;
}