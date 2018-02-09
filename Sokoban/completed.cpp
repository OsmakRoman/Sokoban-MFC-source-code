// completed.cpp: файл реализации
//

#include "stdafx.h"
#include "Sokoban.h"
#include "completed.h"


// диалоговое окно ccompleted

IMPLEMENT_DYNAMIC(ccompleted, CDialog)

    	 CImageList imgListLevel;
         CPoint m_drawPointLevel (36,36);

         CImageList imgListDigit;
         CPoint m_drawPointDigit1 (76,36);
         CPoint m_drawPointDigit2 (83,36);

		 CImageList imgListCongratulations;
		 CPoint m_drawPointCongratulations (41,19);

		 CImageList imgListCompleted;
		 CPoint m_drawPointCompleted (94,36);


ccompleted::ccompleted(CWnd* pParent /*=NULL*/)
	: CDialog(ccompleted::IDD, pParent)
	, m_numberlevel(0)
{

}

ccompleted::~ccompleted()
{
	imgListLevel.DeleteImageList();
	imgListDigit.DeleteImageList();
	imgListCongratulations.DeleteImageList();
	imgListCompleted.DeleteImageList();
}

void ccompleted::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_ok);
}


BEGIN_MESSAGE_MAP(ccompleted, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// обработчики сообщений ccompleted

BOOL ccompleted::OnInitDialog()
{
	CDialog::OnInitDialog();

		CBitmap temp;
		CImageList ok2;
		ok2.Create (17,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP11);
		ok2.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		m_ok.SetIcon (ok2.ExtractIcon (0));


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

		CBitmap m_Bmp4;
		m_Bmp4.LoadBitmap (IDB_BITMAP16);
		imgListCongratulations.Create (123, 11, ILC_COLOR4|ILC_MASK, 1, 0);
		imgListCongratulations.Add (&m_Bmp4, RGB (255,255,255));

		m_Bmp4.DeleteObject();
		m_Bmp4.LoadBitmap (IDB_BITMAP17);
		imgListCompleted.Create (76, 11, ILC_COLOR4|ILC_MASK, 1, 0);
		imgListCompleted.Add (&m_Bmp4, RGB (255,255,255));


	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}

void ccompleted::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	// Не вызывать CDialog::OnPaint() для сообщений рисования

	CDC* pDC = &dc;
	
	imgListLevel.Draw (pDC, 0, m_drawPointLevel, ILD_TRANSPARENT);

	imgListDigit.Draw (pDC, m_numberlevel/10, m_drawPointDigit1, ILD_TRANSPARENT);
	imgListDigit.Draw (pDC, m_numberlevel%10, m_drawPointDigit2, ILD_TRANSPARENT);

	imgListCongratulations.Draw (pDC, 0, m_drawPointCongratulations, ILD_TRANSPARENT);
	imgListCompleted.Draw (pDC, 0, m_drawPointCompleted, ILD_TRANSPARENT);

	ReleaseDC(pDC);
}
