#pragma once
#include "afxwin.h"


// диалоговое окно cresetlevel

class cresetlevel : public CDialog
{
	DECLARE_DYNAMIC(cresetlevel)

public:
	cresetlevel(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~cresetlevel();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CButton m_ok;
	CButton m_cancel;
	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
};
