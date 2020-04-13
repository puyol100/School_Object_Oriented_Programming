
// BamDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Bam.h"
#include "BamDlg.h"
#include "afxdialogex.h"
#include <ctime>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBamDlg 대화 상자



CBamDlg::CBamDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBamDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CBamDlg 메시지 처리기

BOOL CBamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	if (MessageBox(L"이 게임은 뱀에 대한 잔혹한 묘사가 포함되어 있습니다.\n무서운 것에 서투른 분은 플레이를 삼가해 주십시오.\n게임 진행을 원하십니까?", L"경고문", MB_YESNO) == IDNO)
	{
		this->DestroyWindow();
	}
	else
	{
		SetBackgroundColor(RGB(0, 0, 0));
		MoveWindow(0, 0,400, 500);//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		//SetTimer(0, 55, nullptr);
		srand((unsigned int)time(0));
		eat_x_pos = (rand() % 24)* LINE_INTERVAL;
		eat_y_pos = (rand() % 24)* LINE_INTERVAL;
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBamDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBamDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC dc(this);
		///////////////////Make Init background//////////////////////////
		CBrush brush;
			brush.CreateSolidBrush(RGB(128, 128, 128));//back ground color to grey
			dc.SelectObject(&brush);
			for (int y = 0; y < MAX_Y_COUNT; y++)//draw back ground
			{
				for (int x = 0; x < MAX_X_COUNT; x++)
				{
					dc.Rectangle(x*LINE_INTERVAL, y*LINE_INTERVAL,
						x*LINE_INTERVAL + LINE_INTERVAL + 1, y*LINE_INTERVAL + LINE_INTERVAL + 1);//draw rectangle.
					if (x == MAX_X_COUNT / 2 && y == MAX_Y_COUNT / 2)//value for setting snake initial pos
					{
						init_pos_x = x * LINE_INTERVAL;
						init_pos_y = y * LINE_INTERVAL;
					}
				}
			}
		/////////////////////End of Init backgound///////////////////////////
		////////////////////setting init snake////////////////////////////////
		if (init_decide == true)//when program start (init)
		{
			pos_x = init_pos_x;
			pos_y = init_pos_y;
			s_l.make_big_snake(pos_x, pos_y);//setting snake head pos
			s_l.make_big_snake(pos_x + LINE_INTERVAL, pos_y);//setting snake body pos
			s_l.make_big_snake(pos_x + 2 * LINE_INTERVAL, pos_y);//setting snake tail pos
			snake_body_size = 1;//count body.
			int x = pos_x;
			int y = pos_y;
			CBrush brush_snake_head(RGB(0, 255, 0));//setting head color
			dc.SelectObject(brush_snake_head);
			dc.Ellipse(x, y, x + LINE_INTERVAL, y + LINE_INTERVAL);//draw head
			CBrush brush_snake_body(RGB(255, 255, 0));//setting body color
			dc.SelectObject(brush_snake_body);
			dc.Rectangle(x + LINE_INTERVAL, y, x + 2 * LINE_INTERVAL, y + LINE_INTERVAL);//draw body
			CBrush brush_snake_tail(RGB(0,255, 255));//setting tail colr
			dc.SelectObject(brush_snake_tail);
			dc.Ellipse(x + 2 * LINE_INTERVAL, y, x + 3 * LINE_INTERVAL, y + LINE_INTERVAL);//draw tail			
			CBrush brush_eatting(RGB(255, 0, 0));//setting food color
			dc.SelectObject(brush_eatting);
			dc.Rectangle(eat_x_pos,eat_y_pos,eat_x_pos+LINE_INTERVAL,eat_y_pos+LINE_INTERVAL);//draw food
		}///////////////////setting of init snake//////////////////////////////////
		else //if not init case
		{
			if (s_l.Head->s_p_x == eat_x_pos && s_l.Head->s_p_y == eat_y_pos)//if snake ate food
			{
				snake_body_size = snake_body_size + 1;//add body size 1
				s_l.make_big_snake(eat_x_pos, eat_y_pos);//make body
				CBrush brush_eatting(RGB(255, 0, 0));
				srand((unsigned int)time(0));
				eat_x_pos = (rand() % 24)* LINE_INTERVAL;
				eat_y_pos = (rand() % 24)* LINE_INTERVAL;//re position for food
				dc.SelectObject(brush_eatting);
				dc.Rectangle(eat_x_pos, eat_y_pos, eat_x_pos + LINE_INTERVAL, eat_y_pos + LINE_INTERVAL);//draw food
			}
			else
			{
				CBrush brush_eatting(RGB(255, 0, 0));
				dc.SelectObject(brush_eatting);
				dc.Rectangle(eat_x_pos, eat_y_pos, eat_x_pos + LINE_INTERVAL, eat_y_pos + LINE_INTERVAL);
			}
				int x = pos_x;
				int y = pos_y;
				Snake* tmp =s_l.Head;//tmp has snake head node
				while(tmp->next != NULL)//loop until tail 
				{
					tmp = tmp->next;
				}
				while(tmp != s_l.Head)
				{
					tmp->s_p_x = tmp->prev->s_p_x;
					tmp->s_p_y = tmp->prev->s_p_y;//setting body
					tmp = tmp->prev;
				}
				
				s_l.Head->s_p_x = pos_x;
				s_l.Head->s_p_y = pos_y;//get head position
				
			
				tmp = tmp->next;
				CBrush brush_snake_head(RGB(0, 255, 0));//setting head color
				dc.SelectObject(brush_snake_head);
				dc.Ellipse(s_l.Head->s_p_x, s_l.Head->s_p_y, x + LINE_INTERVAL, y + LINE_INTERVAL);//draw head
				for (int i = 0; i < snake_body_size; i++)//loop for drawing snake body
				{
					CBrush brush_snake_body(RGB(255, 255, 0));//setting body color
					dc.SelectObject(brush_snake_body);
					dc.Rectangle(tmp->s_p_x, tmp->s_p_y, tmp->s_p_x + LINE_INTERVAL, tmp->s_p_y + LINE_INTERVAL);//draw body
					tmp = tmp->next;
				}
				CBrush brush_snake_tail(RGB(0, 255, 255));//setting tail color
				dc.SelectObject(brush_snake_tail);
				dc.Ellipse(tmp->s_p_x, tmp->s_p_y, tmp->s_p_x + LINE_INTERVAL, tmp->s_p_y + LINE_INTERVAL);//draw tail
		//////////////////End of loop ofr moving snake////////////////////////////
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBamDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)//for button event
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	init_decide = false;
	switch (nChar)//case by inputting button
	{
	case 'w'://w button input
		if (cmp_cha == 's')//if snake move down 
		{
			cmp_cha = 's';//it can't go up so keep down state
		}
		else
		{
			cmp_cha = 'w';//else case can go up so chage to up state
		}
		break;
	case 'W'://Capital same as non capital case
		if (cmp_cha == 's')
		{
			cmp_cha = 's';
		}
		else
		{
			cmp_cha = 'w';
		}
		break;
	case 's'://s button input
		if (cmp_cha == 'w')//if snake move up
		{
			cmp_cha = 'w';//it can't go down so keep up state
		}
		else
		{
			cmp_cha = 's';//else case can go down so chage to down state
		}
		break;
	case 'S'://Capital same as non capital case
		if (cmp_cha == 'w')
		{
			cmp_cha = 'w';
		}
		else
		{
			cmp_cha = 's';
		}
		break;
	case 'a'://a button input
		if (cmp_cha == 'd')//if snake move left
		{
			cmp_cha = 'd';//it can't go right so keep left state
		}
		else
		{
			cmp_cha = 'a';//else case can go right so chage to right state
		}
		break;
	case 'A'://Capital same as non capital case
		if (cmp_cha == 'd')
		{
			cmp_cha = 'd';
		}
		else
		{
			cmp_cha = 'a';
		}
		break;
	case 'd'://d button input
		if (cmp_cha == 'a' || cmp_cha == NULL)//if snake move right or it is initial state
		{
			cmp_cha = 'a';//it can't go left so keep right state
		}
		else
		{
			cmp_cha = 'd';//else case can go right so chage to right state
		}
		break;
	case 'D'://Capital same as no capital case
		if (cmp_cha == 'a' || cmp_cha == NULL)
		{
			cmp_cha = 'a';
		}
		else
		{
		    cmp_cha = 'd';
		}
		break;
	}
	SetTimer(0, 55, nullptr);//time event call
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CBamDlg::OnTimer(UINT_PTR nIDEvent)//TIMER 처리기
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nIDEvent)
	{
		case 0://TIME EVENT trigged
		if (cmp_cha == 'w')//up direct
		{
			pos_y = pos_y - LINE_INTERVAL;//chage y pos
		}
		else if (cmp_cha == 's')//down direct
		{
			pos_y = pos_y + LINE_INTERVAL;//chage y pos	
		}
		else if (cmp_cha == 'a')//left direct
		{
			pos_x = pos_x - LINE_INTERVAL;//chage x pos
		}
		else if (cmp_cha == 'd')//right direct
		{
			pos_x = pos_x + LINE_INTERVAL;//chage x pos
		}
		if(pos_x > 24 * LINE_INTERVAL || pos_y > 24 * LINE_INTERVAL || pos_x < 0 || pos_y < 0)//case for snake over wall
		{
		KillTimer(0);//kill timer
		MessageBox(L"벽에 쿵!", L"실패", MB_ICONSTOP);//message box with 벽에 쿵
		::PostQuitMessage(WM_QUIT);
		}
		Snake* inspecting_body_koong = s_l.Head->next;
		while (inspecting_body_koong != NULL)//loop for checking 몸에 쿵 case
		{
			if (pos_x == inspecting_body_koong->s_p_x && pos_y == inspecting_body_koong->s_p_y)//if snake touched his body
			{
				KillTimer(0);//타이머를 멈춥니다.
				MessageBox(L"몸에 쿵!", L"실패", MB_ICONSTOP);//message box with 몸에 쿵
				::PostQuitMessage(WM_QUIT);
			}
			inspecting_body_koong = inspecting_body_koong->next;//inspecting all snake's head to tail
		}
		Invalidate(FALSE);//re call onPaint fucntion
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
