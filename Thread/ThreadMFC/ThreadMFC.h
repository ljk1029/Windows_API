
// ThreadMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CThreadMFCApp:
// �йش����ʵ�֣������ ThreadMFC.cpp
//

class CThreadMFCApp : public CWinApp
{
public:
	CThreadMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CThreadMFCApp theApp;