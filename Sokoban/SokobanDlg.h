// SokobanDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
//#include "Levels.h"


// ���������� ���� CSokobanDlg
class CSokobanDlg : public CDialog
{
// ��������
public:
	CSokobanDlg(CWnd* pParent = NULL);	// ����������� �����������

 

// ������ ����������� ����
	enum { IDD = IDD_SOKOBAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������




protected:
	HICON m_hIcon;
	int  m_numberlevel;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void EndLevelTest();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	  int  GetNumberLevel()
   {return m_numberlevel;}
	CButton m_butup;
	CButton m_butleft;
	CButton m_butright;
	CButton m_butdown;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	CButton m_chooselevel;
	CButton m_undo;
	CButton m_reset;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
