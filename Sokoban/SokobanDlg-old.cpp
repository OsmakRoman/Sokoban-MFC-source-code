// SokobanDlg.cpp : файл реализации
//
#include "stdafx.h"
#include "Sokoban.h"
#include "SokobanDlg.h"
#include "level.h"
#include "resetlevel.h"
#include "completed.h"


#include "Levels.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CSokobanDlg
static	LEVELS m_playlevel;
static  LEVELS m_originallevel;
static  CList<LEVELS> m_list;


static   CImageList imgListLogo;  
static	 CPoint m_drawPointLogo (598,30);

static	 CImageList imgListLevel;
static   CPoint m_drawPointLevel (627,155);

static   CImageList imgListDigit;
static   CPoint m_drawPointDigit1 (667,155);
static   CPoint m_drawPointDigit2 (674,155);




		CBrush WallBrush (RGB(0,0,0));
		CBrush PusherBrush (RGB(255,255,0));
		CBrush BoxBrush (RGB(255,0,0));
		CBrush PlaceForBoxBrush (RGB(200,200,200));
		CBrush PlaceForBoxOkBrush (RGB (0,205,0));
    	CBrush Place (RGB (0,0,255));


CSokobanDlg::CSokobanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSokobanDlg::IDD, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSokobanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON1, m_butup);
	DDX_Control(pDX, IDC_BUTTON2, m_butleft);
	DDX_Control(pDX, IDC_BUTTON3, m_butright);
	DDX_Control(pDX, IDC_BUTTON4, m_butdown);
	DDX_Control(pDX, IDC_BUTTON7, m_chooselevel);
	DDX_Control(pDX, IDC_BUTTON5, m_undo);
	DDX_Control(pDX, IDC_BUTTON6, m_reset);
}

BEGIN_MESSAGE_MAP(CSokobanDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CSokobanDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSokobanDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CSokobanDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CSokobanDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CSokobanDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CSokobanDlg::OnBnClickedButton5)

	ON_BN_CLICKED(IDC_BUTTON7, &CSokobanDlg::OnBnClickedButton7)
//	ON_WM_GETDLGCODE()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// обработчики сообщений CSokobanDlg

BOOL CSokobanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ModifyStyle(0, WS_CLIPCHILDREN, 0);


	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

		InitLevels();
		m_numberlevel =1;
		m_playlevel = level[m_numberlevel-1];
		m_originallevel = level[m_numberlevel-1];
		m_list.AddTail(m_playlevel);

	
	
		CImageList directions;
		directions.Create(55, 55, ILC_COLOR16|ILC_MASK, 4,0);
		CBitmap temp;
		temp.LoadBitmap(IDB_BITMAP2);
		directions.Add (&temp,RGB(255,255,255));
		temp.DeleteObject();
		temp.LoadBitmap(IDB_BITMAP3);
		directions.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();
		temp.LoadBitmap(IDB_BITMAP4);
		directions.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();
		temp.LoadBitmap(IDB_BITMAP5);
		directions.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

  


		m_butup.SetIcon (directions.ExtractIcon (0));
		m_butleft.SetIcon (directions.ExtractIcon (1));
		m_butright.SetIcon (directions.ExtractIcon (2));
		m_butdown.SetIcon (directions.ExtractIcon (3));

		CImageList undo;
		undo.Create (33,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP8);
		undo.Add (&temp, RGB (255,255,255));
		m_undo.SetIcon (undo.ExtractIcon (0));
		temp.DeleteObject();


		CImageList choose;
		choose.Create (49,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP7);
		choose.Add (&temp, RGB (255,255,255));
		m_chooselevel.SetIcon (choose.ExtractIcon(0));
		temp.DeleteObject();


		CImageList reset;
		reset.Create (40,11, ILC_COLOR16|ILC_MASK,1,0);
		temp.LoadBitmap (IDB_BITMAP9);
		reset.Add (&temp, RGB (255,255,255));
		m_reset.SetIcon (reset.ExtractIcon (0));
		temp.DeleteObject();



		temp.LoadBitmap(IDB_BITMAP6);  
        imgListLogo.Create(200, 100, ILC_COLOR16|ILC_MASK, 1, 0);
        imgListLogo.Add(&temp, RGB(255,255,255));
		temp.DeleteObject();
		

		temp.LoadBitmap (IDB_BITMAP10);
		imgListLevel.Create (38, 11, ILC_COLOR4|ILC_MASK, 1, 0);
		imgListLevel.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT0);
		imgListDigit.Create (7,11, ILC_COLOR4|ILC_MASK,10,0);
		imgListDigit.Add (&temp, RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT1);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT2);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT3);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT4);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();
		 
		temp.LoadBitmap (IDB_DIGIT5);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();
 
		temp.LoadBitmap (IDB_DIGIT6);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();

		temp.LoadBitmap (IDB_DIGIT7);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();
		 
		temp.LoadBitmap (IDB_DIGIT8);
		imgListDigit.Add (&temp,RGB (255,255,255));
		temp.DeleteObject();
		 
		
		temp.LoadBitmap (IDB_DIGIT9);
		imgListDigit.Add (&temp,RGB (255,255,255));
		
		temp.DeleteObject();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей средой.

void CSokobanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
	 
		CDC* pDC = &dc;


        CDC cdc; 
        CRect r; 
        CBitmap bitmap; 
        cdc.CreateCompatibleDC(pDC);
		
        this->GetClientRect(r); 
        bitmap.CreateCompatibleBitmap(pDC, r.Width(), r.Height()); 
        CBitmap *oldBitmap = cdc.SelectObject(&bitmap); 
	    cdc.FillSolidRect(r, GetSysColor (COLOR_3DFACE));
	

		CDC* pcdc = &cdc;

		imgListLevel.Draw (pcdc, 0, m_drawPointLevel, ILD_TRANSPARENT);
	    imgListLogo.Draw(pcdc, 0, m_drawPointLogo, ILD_TRANSPARENT);
		imgListDigit.Draw (pcdc, m_numberlevel/10, m_drawPointDigit1, ILD_TRANSPARENT);
		imgListDigit.Draw (pcdc, m_numberlevel%10, m_drawPointDigit2, ILD_TRANSPARENT);
	

		cdc.MoveTo (10,10);
		cdc.LineTo (590,10);
		cdc.LineTo (590,410);
		cdc.LineTo (10,410);
		cdc.LineTo (10,10);


	for (int i=1; i<=m_playlevel.sizey; i++)
	    for (int j=1; j<=m_playlevel.sizex; j++)
	
				{
					

	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]==' ')
		cdc.SelectStockObject (NULL_BRUSH);
 	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='@')
		cdc.SelectObject(&PusherBrush);
	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='X')
		cdc.SelectObject(&WallBrush);
	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='*')
		cdc.SelectObject(&BoxBrush);
	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='.')
		cdc.SelectObject(&PlaceForBoxBrush);
	if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='&')
		cdc.SelectObject(&PlaceForBoxOkBrush);
	
	double z = (29-m_playlevel.sizex)/2;
	double y = (20-m_playlevel.sizey)/2;

    CRect rect (10+z*20+(j-1)*20,10+y*20+(i-1)*20,30+z*20+(j-1)*20,30+y*20+(i-1)*20);

	
		cdc.FillRect (&rect, 0);


			}

		pDC->BitBlt(0, 0, r.Width(), r.Height(), &cdc, 0, 0, SRCCOPY);

		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSokobanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSokobanDlg::OnBnClickedButton1()  // КНОПКА НАЖАТА ВВЕРХ
  
{
	if (m_playlevel.element[ ((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]==' '||
		m_playlevel.element[ ((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='.')

	{   
		m_playlevel.element.SetAt (((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '@');


		    if (m_originallevel.element [((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||
			    m_originallevel.element [((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
			     m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
			else
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');


		m_playlevel.pushery = m_playlevel.pushery - 1;
		m_list.AddHead(m_playlevel);
		InvalidateRect (NULL);
		return;
	}

	if (m_playlevel.element[ ((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='*'||
		m_playlevel.element[ ((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='&') //ОБРАБОТКА ПЕРЕДВИЖЕНИЯ КОНТЕЙНЕРА
	{
		if (m_playlevel.element[ ((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]==' '||
			m_playlevel.element[ ((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='.')
		{
			if (m_playlevel.element[ ((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]==' ')
			 m_playlevel.element.SetAt (((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '*');
			if  (m_playlevel.element[ ((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='.')
			m_playlevel.element.SetAt (((m_playlevel.pushery-3)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '&');

			m_playlevel.element.SetAt (((m_playlevel.pushery-2)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '@');  //Рисует пушера за коробкой

			if (m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||
				m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')    //Перерисовываем за пушером
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
			else
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');
	
			

			m_playlevel.pushery = m_playlevel.pushery - 1;
			m_list.AddHead(m_playlevel);
		InvalidateRect (NULL); 
			EndLevelTest();
			return;  
		}
	}
}

void CSokobanDlg::OnBnClickedButton2() //КНОПКА НАЖАТА ВЛЕВО
{
	if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 ]==' '||
		m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 ]=='.')
	{
		m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 , '@');

		if (m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||
			m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
			m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
		else
			m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');


		
		m_playlevel.pusherx = m_playlevel.pusherx - 1;
		m_list.AddHead(m_playlevel);
	InvalidateRect (NULL);
		return;
   	}

	if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 ]=='*'||
		m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 ]=='&') //ОБРАБОТКА ПЕРЕДВИЖЕНИЯ КОНТЕЙНЕРА
	{
		if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 ]==' '||
			m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 ]=='.')
		{
			if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 ]==' ')   //Рисует коробку вперед
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 , '*');
			if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 ]=='.')
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-3 , '&');
						      
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-2 , '@');  //Рисует пушера за коробкой

				if (m_originallevel.element [((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||//Перерисовываем за пушером
					m_originallevel.element [((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
					m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1, '.');
				else
					m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1, ' ');
					
			
			m_playlevel.pusherx = m_playlevel.pusherx - 1;
			m_list.AddHead(m_playlevel);
			InvalidateRect (NULL);
			EndLevelTest();
			return;
		}
	}
 }

void CSokobanDlg::OnBnClickedButton4() //КНОПКА НАЖАТА ВНИЗ
{

	if (m_playlevel.element[ ((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]==' '||
		m_playlevel.element[ ((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='.')
	{
		m_playlevel.element.SetAt (((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '@');
		if (m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||
			m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
		m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
		else
			m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');

		
		m_playlevel.pushery = m_playlevel.pushery +1;
		m_list.AddHead(m_playlevel);
		InvalidateRect (NULL);
		return;
	}

	if (m_playlevel.element[ ((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='*'||
		m_playlevel.element[ ((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='&')//ОБРАБОТКА ПЕРЕМЕЩЕНИЯ КОНТЕЙНЕРА
	{
		if (m_playlevel.element[ ((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]==' '||
			m_playlevel.element[ ((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1 ]=='.')
			{
				if (m_playlevel.element[((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == ' ')//Рисует коробку вперед
				m_playlevel.element.SetAt (((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '*');
				if (m_playlevel.element[((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.')
					m_playlevel.element.SetAt (((m_playlevel.pushery+1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '&');
				
				m_playlevel.element.SetAt (((m_playlevel.pushery)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '@');  //Рисует пушера за коробкой

				if (m_originallevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'|| //Перерисовываем за пушером
					m_originallevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
					m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
				else
					m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');

					

				
				m_playlevel.pushery = m_playlevel.pushery +1;
				m_list.AddHead(m_playlevel);
				InvalidateRect (NULL);
				EndLevelTest();
				return;
			}
	}

}

void CSokobanDlg::OnBnClickedButton3() //КНОПКА НАЖАТА ВПРАВО
{
	if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) ]==' '||
		m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) ]=='.')
	{
		m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) , '@');
		if (m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||
			m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
		m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , '.');
		else
			m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1 , ' ');

		
		m_playlevel.pusherx = m_playlevel.pusherx + 1;
		m_list.AddHead(m_playlevel);
		InvalidateRect (NULL); 
		return;
   	}


	if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) ]=='*'||
		m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) ]=='&')//ОБРАБОТКА ПЕРЕДВИЖЕНИЯ КОНТЕЙНЕРА
	{
		
		if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 ]==' '||
			m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 ]=='.')
		{
			if (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 ]==' ') //Рисует коробку вперед
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 , '*');
			if  (m_playlevel.element[ ((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 ]=='.')
				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)+1 , '&');

				m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx) , '@');  //Рисует пушера за коробкой

				if (m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '.'||//Перерисовываем за пушером
					m_originallevel.element[((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1] == '&')
			        m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1, '.');
				else
					m_playlevel.element.SetAt (((m_playlevel.pushery-1)*m_playlevel.sizex+m_playlevel.pusherx)-1, ' ');

		
			

			m_playlevel.pusherx = m_playlevel.pusherx + 1;

			m_list.AddHead(m_playlevel);
			InvalidateRect (NULL); 
			EndLevelTest();
			return;
		}
	}
	
}


void CSokobanDlg::OnBnClickedButton6()
{
	cresetlevel dlg2;
	if (dlg2.DoModal()==IDOK)
	{
		m_playlevel=m_originallevel;
		m_list.RemoveAll();
		m_list.AddTail(m_playlevel);
		InvalidateRect (NULL);
	}
}

void CSokobanDlg::OnBnClickedButton5()

{ 
	
	if (m_list.GetCount()>1) m_list.RemoveHead();

	if (m_list.IsEmpty() == 0)
	{m_playlevel=m_list.GetHead();
	InvalidateRect (NULL);}

	
}


void CSokobanDlg::OnBnClickedButton7()
{
	clevel dlg;
	dlg.m_numberlevel = m_numberlevel;
	if (dlg.DoModal()==IDOK)
	{
		m_numberlevel = dlg.m_numberlevel;
		m_playlevel = level[m_numberlevel-1];
	    m_originallevel = level[m_numberlevel-1];
		m_list.RemoveAll();

	    m_list.AddTail(m_playlevel);
		InvalidateRect (NULL);
	}	
	// TODO: добавьте свой код обработчика уведомлений
}

void CSokobanDlg::EndLevelTest()

{
	for (int i=1; i<=m_playlevel.sizey; i++)
	    for (int j=1; j<=m_playlevel.sizex; j++)
			if (m_playlevel.element[ ((i-1)*m_playlevel.sizex+j)-1 ]=='*')
				return;

	ccompleted dlg;
	dlg.m_numberlevel = m_numberlevel;
	dlg.DoModal();

if (m_numberlevel==60)

m_numberlevel = 1;
else 
		m_numberlevel = m_numberlevel+1;

		m_playlevel = level[m_numberlevel-1];
	    m_originallevel = level[m_numberlevel-1];
		m_list.RemoveAll();
	    m_list.AddTail(m_playlevel);
		InvalidateRect (NULL);

}


BOOL CSokobanDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: добавьте специализированный код или вызов базового класса


	 if(pMsg->message==WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_UP)

        {
			CSokobanDlg::OnBnClickedButton1();
         
	
        }
		if(pMsg->wParam == VK_LEFT)

        {
			CSokobanDlg::OnBnClickedButton2();
           
	
        }

        if(pMsg->wParam == VK_DOWN)
        {
          
		 CSokobanDlg::OnBnClickedButton4();
        }
		if(pMsg->wParam == VK_RIGHT)

        {
			CSokobanDlg::OnBnClickedButton3();
        
	
        }
		return 1;
    }
  


	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CSokobanDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
return TRUE;
//return CDialog::OnEraseBkgnd(pDC);
}
