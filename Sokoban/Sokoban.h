// Sokoban.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSokobanApp:
// � ���������� ������� ������ ��. Sokoban.cpp
//

class CSokobanApp : public CWinApp
{
public:
	CSokobanApp();

// ���������������
	public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSokobanApp theApp;