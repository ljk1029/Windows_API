/**
* date:    2020/6/23
* version:     v 1.0
* Description: URLDownloadToFile���ع���
*
* author:
**/

#include <windows.h>
#pragma comment (lib,"Urlmon.lib")

// ����
int download(char* url, char* file)
{
	//HRESULT hret =URLDownloadToFile(NULL,"https://avatar.cctry.com/uc_server/data/avatar/000/00/00/51_avatar_small.jpg","C:\\1.jpg",0,NULL);
	HRESULT hret =URLDownloadToFile(NULL, url, file, 0, NULL);
	if(hret == S_OK)
	{
		MessageBox(NULL,"���سɹ�","Tip",MB_OK);
	}
	else
	{
		MessageBox(NULL,"����ʧ��","Tip",MB_OK);
	}
	return 0;
}

// shellִ��
int shellEx(int OWEB = 1)
{
	SHELLEXECUTEINFO ShellInfo;    

	memset(&ShellInfo, 0, sizeof(ShellInfo));    

	ShellInfo.cbSize = sizeof(ShellInfo); //��С  

	ShellInfo.lpVerb = "open";       //����  

	if(OWEB == 1)  //����վ��������notepad++.exe
	{
		ShellInfo.lpFile = "https://www.bilibili.com/video/av46038943/?p=4";
	}
	else
	{
		ShellInfo.lpFile = "D:\\EditTool\\Notepad++\\notepad++.exe"; // ��·����ִ���ļ���
	}

	ShellInfo.nShow = SW_SHOWNORMAL;  //������ʾ  

	//	ShellInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;//�����³�������hProcess,����ʾ������ʾ��


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