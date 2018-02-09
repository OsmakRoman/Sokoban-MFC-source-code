#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// диалоговое окно clevel

class clevel : public CDialog
{
	DECLARE_DYNAMIC(clevel)

public:
	clevel(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~clevel();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual BOOL OnInitDialog();
	//afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_slider;
	int m_numberlevel;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	
	afx_msg void OnPaint();
protected:

public:
	CButton m_ok;
	CButton m_cancel;
};
