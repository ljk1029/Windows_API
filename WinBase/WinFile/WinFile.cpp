/**
* date:    2020/6/23
* version:     v 1.0
* Description: 创建文件、读取文件长度操作功能
*
* author:
**/

#include <windows.h>
#include <tchar.h>
#include <iostream>

#pragma comment ( lib,"user32.lib" )  


// 创建文件
int file_create(char* path)
{
	/*创建文件*/
	HANDLE hFile = CreateFile(_T(path), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"创建成功","Tip",MB_OK);

		/*读取长度文件*/
		DWORD dwFSize = GetFileSize(hFile, NULL);  

		TCHAR szFSize[128] = {0};    
		_stprintf(szFSize,_T("文件大小是：%d"),dwFSize);  //转为字符串
		MessageBox(NULL, szFSize, "Tip", MB_OK);

		BOOL hHand = CloseHandle(hFile);  //关闭文件
		if(hHand)
		{
			MessageBox(NULL,"关闭成功","Tip",MB_OK);
		}
		else
		{ 
			DWORD error_rus = GetLastError();  //获取上一次错误
			MessageBox(NULL,"关闭失败","Tip",MB_OK);
		}
	}
	return 0;
}

// 拷贝文件
int file_copy(char* path, char* dest_path)
{
	BOOL bRet = CopyFile( _T(path), _T(dest_path), FALSE);
	if (bRet)
	{
		MessageBox(NULL, _T("拷贝成功"), _T("文件拷贝"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("拷贝失败"), _T("文件拷贝"), MB_OK);
	}
	return 0;
}

// 移动文件
int file_move(char* path, char* dest_path)
{
	BOOL bRes = MoveFile( _T(path), _T(dest_path));
	if (bRes)
	{
		MessageBox(NULL, _T("移动成功"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("移动失败"), _T("Tip"), MB_OK);
	}
	return 0;
}

// 删除文件
int file_delete(char* path)
{
	BOOL del=DeleteFile(_T(path));
	if (del)
	{
		MessageBox(NULL, _T("删除成功"), _T("文件删除"), MB_OK);
	}
	else
	{
		//DWORD error_rus = GetLastError();  //获取上一次错误
		MessageBox(NULL, _T("删除失败"), _T("文件删除"), MB_OK);
	}
	return 0;
}

struct Student
{
	int age;
	char sex;
	char name[32];
};

// 文件写入
int file_write(char* path, char* data)
{
	HANDLE hFile = CreateFile(_T(path), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"打开文件失败","Tip",MB_OK);
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
	/*文件写操作*/
	BOOL bRet = WriteFile(hFile, &Stu, sizeof(Stu), &dwRealWrite, NULL );
	if(bRet)
	{
		MessageBox(NULL, "写成功", "Tip", MB_OK);
	}
	else
	{
		DWORD error_rus = GetLastError();  //获取上一次错误
		MessageBox(NULL, "写失败", "Tip", MB_OK);
	}

	/////////////////////////////////////////////////////
	SetFilePointer(hFile, -32*sizeof(Student), NULL, FILE_CURRENT);/*指针设到文件头*/

	Student Stu1;
	memset(&Stu1, 0, sizeof(Stu1));
	/*文件读操作*/
	BOOL bRes= ReadFile(hFile, &Stu1, sizeof(Stu1), &dwRealWrite, NULL);
	if(bRes)
	{
		MessageBox(NULL, "读成功", "Tip", MB_OK);
		printf("age:%d, sex:%c, name:%s\n", Stu1.age, Stu1.sex, Stu1.name);
	}

	BOOL hHand = CloseHandle(hFile);	
	if(!hHand)
	{ 
		MessageBox(NULL,"关闭失败","Tip",MB_OK);
	}
	return 0;
}

// 目录创建
int dir_create(char* path)
{
	CreateDirectory(_T(path),NULL);  
	return 0;
}

// 目录删除
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
