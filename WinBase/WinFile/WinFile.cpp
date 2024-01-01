/**
* date:    2020/6/23
* version:     v 1.0
* Description: �����ļ�����ȡ�ļ����Ȳ�������
*
* author:
**/

#include <windows.h>
#include <tchar.h>
#include <iostream>

#pragma comment ( lib,"user32.lib" )  


// �����ļ�
int file_create(char* path)
{
	/*�����ļ�*/
	HANDLE hFile = CreateFile(_T(path), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"�����ɹ�","Tip",MB_OK);

		/*��ȡ�����ļ�*/
		DWORD dwFSize = GetFileSize(hFile, NULL);  

		TCHAR szFSize[128] = {0};    
		_stprintf(szFSize,_T("�ļ���С�ǣ�%d"),dwFSize);  //תΪ�ַ���
		MessageBox(NULL, szFSize, "Tip", MB_OK);

		BOOL hHand = CloseHandle(hFile);  //�ر��ļ�
		if(hHand)
		{
			MessageBox(NULL,"�رճɹ�","Tip",MB_OK);
		}
		else
		{ 
			DWORD error_rus = GetLastError();  //��ȡ��һ�δ���
			MessageBox(NULL,"�ر�ʧ��","Tip",MB_OK);
		}
	}
	return 0;
}

// �����ļ�
int file_copy(char* path, char* dest_path)
{
	BOOL bRet = CopyFile( _T(path), _T(dest_path), FALSE);
	if (bRet)
	{
		MessageBox(NULL, _T("�����ɹ�"), _T("�ļ�����"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("����ʧ��"), _T("�ļ�����"), MB_OK);
	}
	return 0;
}

// �ƶ��ļ�
int file_move(char* path, char* dest_path)
{
	BOOL bRes = MoveFile( _T(path), _T(dest_path));
	if (bRes)
	{
		MessageBox(NULL, _T("�ƶ��ɹ�"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("�ƶ�ʧ��"), _T("Tip"), MB_OK);
	}
	return 0;
}

// ɾ���ļ�
int file_delete(char* path)
{
	BOOL del=DeleteFile(_T(path));
	if (del)
	{
		MessageBox(NULL, _T("ɾ���ɹ�"), _T("�ļ�ɾ��"), MB_OK);
	}
	else
	{
		//DWORD error_rus = GetLastError();  //��ȡ��һ�δ���
		MessageBox(NULL, _T("ɾ��ʧ��"), _T("�ļ�ɾ��"), MB_OK);
	}
	return 0;
}

struct Student
{
	int age;
	char sex;
	char name[32];
};

// �ļ�д��
int file_write(char* path, char* data)
{
	HANDLE hFile = CreateFile(_T(path), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"���ļ�ʧ��","Tip",MB_OK);
		return -1;
	}

	DWORD dwRealWrite = 0;
	Student Stu;
	Stu.age = 20;
	Stu.sex = 'm';
	if(data)
		strcpy(Stu.name, data);
	else
		strcpy(Stu.name, "zhangsan");
	/*�ļ�д����*/
	BOOL bRet = WriteFile(hFile, &Stu, sizeof(Stu), &dwRealWrite, NULL );
	if(bRet)
	{
		MessageBox(NULL, "д�ɹ�", "Tip", MB_OK);
	}
	else
	{
		DWORD error_rus = GetLastError();  //��ȡ��һ�δ���
		MessageBox(NULL, "дʧ��", "Tip", MB_OK);
	}

	/////////////////////////////////////////////////////
	SetFilePointer(hFile, -32*sizeof(Student), NULL, FILE_CURRENT);/*ָ���赽�ļ�ͷ*/

	Student Stu1;
	memset(&Stu1, 0, sizeof(Stu1));
	/*�ļ�������*/
	BOOL bRes= ReadFile(hFile, &Stu1, sizeof(Stu1), &dwRealWrite, NULL);
	if(bRes)
	{
		MessageBox(NULL, "���ɹ�", "Tip", MB_OK);
		printf("age:%d, sex:%c, name:%s\n", Stu1.age, Stu1.sex, Stu1.name);
	}

	BOOL hHand = CloseHandle(hFile);	
	if(!hHand)
	{ 
		MessageBox(NULL,"�ر�ʧ��","Tip",MB_OK);
	}
	return 0;
}

// Ŀ¼����
int dir_create(char* path)
{
	CreateDirectory(_T(path),NULL);  
	return 0;
}

// Ŀ¼ɾ��
int dir_delete(char* path)
{
	RemoveDirectory(_T(path));       
	return 0;
}

int main(int argc, char* argv[])
{
	char* path = "win_data.txt";
	char* copy_path = "copy_data.txt";
	char* move_path = "move_data.txt";
	char* dir = "win_dir";
	printf("WinFile demo\n");

	file_create(path);
	file_copy(path, copy_path);
	file_move(path, move_path);
	file_delete(copy_path);
	file_delete(move_path);

	file_write(path, "lisi");

	dir_create(dir);
	dir_delete(dir);
	return 0;
}
