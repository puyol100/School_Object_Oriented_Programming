
// MFCApplication1View.cpp: CMFCApplication1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RESET, &CMFCApplication1View::OnReset)
	ON_COMMAND(ID_1STEP, &CMFCApplication1View::On1step)
	ON_COMMAND(ID_FINAL, &CMFCApplication1View::OnFinal)
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//강제 형변환을 시켜줘야 하는데 문자열 앞에 L을 붙여주는 이유가 그 이유입니다.
	CString str;
	if (!m_card_flip.IsNull())
	{
		m_card_flip.Destroy();
	}
	for (int i = 0; i < MAX_TOTAL_CARD_COUNT; i++)
	{
		if (!m_card_image[i].IsNull())
		{
			m_card_image[i].Destroy();
		}
	}
	m_card_flip.Load(L"C:\\Users\\한성민\\source\\repos\\MFCApplication1\\MFCApplication1\\cards\\53.bmp");
	for (int i = 0; i < MAX_TOTAL_CARD_COUNT; i++)
	{
		str.Format(L"C:\\Users\\한성민\\source\\repos\\MFCApplication1\\MFCApplication1\\cards\\%02d.bmp", i + 1);
		m_card_image[i].Load(str);
	}
	//if(reset event)
	//if(1 step button)
	//if(final button)
	if (flag == 0)
	{
		for (int i = 0; i < MAX_TOTAL_CARD_COUNT; i++)
		{
				m_card_image[i].Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);	
		}
	}
	else if (flag == 1)
	{
		for(int j=2; j <= count_step; j++)
		{
			for (int i = 0; i < MAX_TOTAL_CARD_COUNT; i++)
			{
				if (j == 2)
				{
					if ((i + 1) % j == 0)
					{
						m_card_step[i] = m_card_flip;
						m_card_flip.Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);
					}
					else
					{
						m_card_step[i] = m_card_image[i];
						m_card_image[i].Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);
					}
				}
				else if (j != 2)
				{
					if ((i + 1) % j == 0)
					{
						if (m_card_step[i] == m_card_flip)
						{
							m_card_step[i] = m_card_image[i];
							m_card_image[i].Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);
						}
						else if(m_card_step[i] == m_card_image[i])
						{
							m_card_step[i] = m_card_flip;
							m_card_flip.Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);
						}
					}
				}		
			}
		}
		count_step = count_step + 1;
	}
}


// CMFCApplication1View 인쇄

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기


void CMFCApplication1View::OnReset()//event for Reset
{
	flag = 0;//flag ==0
	count_step = 2;//counter_step is 2
	RedrawWindow();//re drawing
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMFCApplication1View::On1step()//event for 1step
{
	flag = 1;//flag 1
	if (count_step > 52)//if 1step push count is over 52 
	{
		count_step = 52;
	}
	RedrawWindow();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMFCApplication1View::OnFinal()//event for final
{
	flag = 1;//flag 1
	count_step = 52;
	RedrawWindow();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
