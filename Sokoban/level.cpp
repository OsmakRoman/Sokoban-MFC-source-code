// level.cpp: файл реализации
//

#include "stdafx.h"
#include "Sokoban.h"
#include "level.h"
//#include "SokobanDlg.h"



// диалоговое окно clevel

IMPLEMENT_DYNAMIC(clevel, CDialog)


static	 CImageList imgListLevel;
static   CPoint m_drawPointLevel (390,23);

static   CImageList imgListDigit;
static   CPoint m_drawPointDigit1 (430,23);
static   CPoint m_drawPointDigit2 (437,23);

clevel::clevel(CWnd* pParent /*=NULL*/)
	: CDialog(clevel::IDD, pParent)
{
	
}

clevel::~clevel()
{
	imgListDigit.DeleteImageList();
	imgListLevel.DeleteImageList();
}

void clevel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancel);
}


BEGIN_MESSAGE_MAP(clevel, CDialog)
	ON_WM_HSCROLL()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// обработчики сообщений clevel

BOOL clevel::OnInitDialog()
{
	CDialog::OnInitDialog();


		CBitmap temp;
		CImageList ok;
		ok.Create (17,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP11);
		ok.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		m_ok.SetIcon (ok.ExtractIcon (0));


		CImageList cancel;
		cancel.Create (50,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP12);
		cancel.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		m_cancel.SetIcon (cancel.ExtractIcon (0));
		

		CBitmap m_Bmp2;
		m_Bmp2.LoadBitmap (IDB_BITMAP10);
		imgListLevel.Create (38, 11, ILC_COLOR4|ILC_MASK, 1, 0);
		imgListLevel.Add (&m_Bmp2, RGB (255,255,255));

		CBitmap m_Bmp3;
		m_Bmp3.LoadBitmap (IDB_DIGIT0);
		imgListDigit.Create (7,11, ILC_COLOR4|ILC_MASK,10,0);
		imgListDigit.Add (&m_Bmp3, RGB (255,255,255));

		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT1);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));

		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT2);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));

		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT3);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));

		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT4);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));
		 
		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT5);
	    imgListDigit.Add (&m_Bmp3,RGB (255,255,255));

		 
		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT6);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));

	 
		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT7);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));
		 
		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT8);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));
		 
		m_Bmp3.DeleteObject();
		m_Bmp3.LoadBitmap (IDB_DIGIT9);
		imgListDigit.Add (&m_Bmp3,RGB (255,255,255));


	m_slider.SetRange(1,60,TRUE);
	m_slider.SetPos(m_numberlevel);
	return TRUE;
}
void clevel::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	m_numberlevel = m_slider.GetPos();
	InvalidateRect (NULL);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void clevel::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// Не вызывать CDialog::OnPaint() для сообщений рисования

	CDC* pDC = &dc;
	imgListLevel.Draw (pDC, 0, m_drawPointLevel, ILD_TRANSPARENT);
	imgListDigit.Draw (pDC, m_numberlevel/10, m_drawPointDigit1, ILD_TRANSPARENT);
	imgListDigit.Draw (pDC, m_numberlevel%10, m_drawPointDigit2, ILD_TRANSPARENT);
	ReleaseDC(pDC);
	
}


