/**
* Copyright @ xxx.2020-2021. All rights reserved
* date:    2020/7/19
* version:     v 1.0
* Description: C���ļ���������
*
* author:
**/
#include <stdio.h>
#include <windows.h>


// ��ӡ������Ϣ
void get_info_error()
{
	DWORD errorCode = GetLastError();

	// ʹ�� FormatMessage �������������ת��Ϊ�ɶ��Ĵ�����Ϣ
	LPVOID errorMessage;
	FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		errorCode,
		0, // Ĭ������
		(LPWSTR)&errorMessage,
		0,
		NULL
		);

	// ��ӡ������Ϣ
	wprintf(L"Error Code: %lu\n", errorCode);
	wprintf(L"Error Message: %s\n", errorMessage);

	// �ͷ���Ϣ������
	LocalFree(errorMessage);
}

// C��д
int file_w(const char* path)
{
	char szBuf[256] = {0};    
	char szTextData[] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 0};

	printf("szTextData sizeof:%d, strlen:%d\n", sizeof(szTextData), strlen(szTextData));

	FILE *fpWrite = fopen(path,"w");  
	if(fpWrite)
	{
		for(int i=0; i<strlen(szTextData); i++)  {
			fprintf(fpWrite,"%.02x ",*(szTextData+i));//%0.2x��ʾд���Ƕ�λ
		}
		fclose(fpWrite);
	}
	else
	{
		get_info_error();
		MessageBox(NULL, "���ļ�ʧ��", "Tip", MB_OK | MB_ICONINFORMATION);
	}
	return 0;	
}

// C���
int file_r(const char* path)
{
	char szBuf[256] = {0};     //������
	char szTextData[] = "hello world!\r\n";

	FILE* fp = fopen(path,"rt+");  //��ȡһ���ļ�
	if(fp == NULL){                //�����ȡʧ��
		get_info_error();
		MessageBox(NULL, "���ļ�ʧ��", "Tip", MB_OK);
	}
	else{
		fwrite(szTextData, sizeof(szTextData), 1, fp);//д���ַ�
		fseek(fp,0,SEEK_SET);						  //��λ�ļ�ָ�뵽�ļ���ʼλ��
		size_t nByteRead = fread(szBuf, 256, 1, fp); 
		printf("read szBuf: %s", szBuf);

		if(fp != NULL)//�ر��ļ�
			fclose(fp);
	}
	return 0;	
}

// FMC ��д
int FMC_File(const char* path)
{
	char szBuf[256] = {0};     //������
	char szTextData[] = "hello cat!\r\n";
	/*****************CFILe*********************/
	/*CFile file(path, CFile::modeRead);//���ļ�
	UINT uBytesRead = file.Read(szBuf, sizeof(szBuf));   //���ļ�
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