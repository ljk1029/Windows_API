/**
* Copyright @ xxx.2020-2021. All rights reserved
* date:    2020/7/19
* version:     v 1.0
* Description: C库文件操作功能
*
* author:
**/
#include <stdio.h>
#include <windows.h>


// 打印错误消息
void get_info_error()
{
	DWORD errorCode = GetLastError();

	// 使用 FormatMessage 函数将错误代码转换为可读的错误消息
	LPVOID errorMessage;
	FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		errorCode,
		0, // 默认语言
		(LPWSTR)&errorMessage,
		0,
		NULL
		);

	// 打印错误消息
	wprintf(L"Error Code: %lu\n", errorCode);
	wprintf(L"Error Message: %s\n", errorMessage);

	// 释放消息缓冲区
	LocalFree(errorMessage);
}

// C库写
int file_w(const char* path)
{
	char szBuf[256] = {0};    
	char szTextData[] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 0};

	printf("szTextData sizeof:%d, strlen:%d\n", sizeof(szTextData), strlen(szTextData));

	FILE *fpWrite = fopen(path,"w");  
	if(fpWrite)
	{
		for(int i=0; i<strlen(szTextData); i++)  {
			fprintf(fpWrite,"%.02x ",*(szTextData+i));//%0.2x表示写入是二位
		}
		fclose(fpWrite);
	}
	else
	{
		get_info_error();
		MessageBox(NULL, "打开文件失败", "Tip", MB_OK | MB_ICONINFORMATION);
	}
	return 0;	
}

// C库读
int file_r(const char* path)
{
	char szBuf[256] = {0};     //缓存区
	char szTextData[] = "hello world!\r\n";

	FILE* fp = fopen(path,"rt+");  //读取一个文件
	if(fp == NULL){                //如果读取失败
		get_info_error();
		MessageBox(NULL, "打开文件失败", "Tip", MB_OK);
	}
	else{
		fwrite(szTextData, sizeof(szTextData), 1, fp);//写入字符
		fseek(fp,0,SEEK_SET);						  //定位文件指针到文件开始位置
		size_t nByteRead = fread(szBuf, 256, 1, fp); 
		printf("read szBuf: %s", szBuf);

		if(fp != NULL)//关闭文件
			fclose(fp);
	}
	return 0;	
}

// FMC 读写
int FMC_File(const char* path)
{
	char szBuf[256] = {0};     //缓存区
	char szTextData[] = "hello cat!\r\n";
	/*****************CFILe*********************/
	/*CFile file(path, CFile::modeRead);//打开文件
	UINT uBytesRead = file.Read(szBuf, sizeof(szBuf));   //读文件
	szBuf[uBytesRead] = 0;
	printf("%s", szBuf);
	file.Write(szTextData,sizeof(szTextData));
	file.close();*/

	return 0;
}

int main(int argc, char** argv)
{
	const char* path = "data.txt";
	file_w(path);
	file_r(path);
	FMC_File(path);
	return 0;
}