// resetlevel.cpp: файл реализации
//

#include "stdafx.h"
#include "Sokoban.h"
#include "resetlevel.h"


// диалоговое окно cresetlevel

IMPLEMENT_DYNAMIC(cresetlevel, CDialog)



static	 CImageList imgListReset;
static   CPoint m_drawPointReset (58,27);



cresetlevel::cresetlevel(CWnd* pParent /*=NULL*/)
	: CDialog(cresetlevel::IDD, pParent)
{

}

cresetlevel::~cresetlevel()
{
	imgListReset.DeleteImageList();
}

void cresetlevel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancel);
}


BEGIN_MESSAGE_MAP(cresetlevel, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// обработчики сообщений cresetlevel

BOOL cresetlevel::OnInitDialog()
{
	CDialog::OnInitDialog();

		CBitmap temp;
		CImageList yes;
		yes.Create (25,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP14);
		yes.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		m_ok.SetIcon (yes.ExtractIcon (0));


		CImageList no;
		no.Create (17,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP15);
		no.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		m_cancel.SetIcon (no.ExtractIcon (0));


	    CBitmap m_Bmp;
		m_Bmp.LoadBitmap (IDB_BITMAP13);
		imgListReset.Create (89, 11, ILC_COLOR4|ILC_MASK, 1, 0);
		imgListReset.Add (&m_Bmp, RGB (255,255,255));

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}


void cresetlevel::OnPaint()
{
		CPaintDC dc(this); // device context for painting

	// Не вызывать CDialog::OnPaint() для сообщений рисования

		CDC* pDC = &dc;
		imgListReset.Draw (pDC, 0, m_drawPointReset, ILD_TRANSPARENT);
		ReleaseDC(pDC);
}
