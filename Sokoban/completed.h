#pragma once
#include "afxwin.h"


// ���������� ���� ccompleted

class ccompleted : public CDialog
{
	DECLARE_DYNAMIC(ccompleted)

public:
	ccompleted(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~ccompleted();


// ������ ����������� ����
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()

public:
	int m_numberlevel;
	CButton m_ok;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
