
// BamDlg.h: 헤더 파일
//

#pragma once
# include "Snake.h"
# define MAX_X_COUNT 25//for map x size
# define MAX_Y_COUNT 25//for map y size
# define LINE_INTERVAL 15//for square each shape

// CBamDlg 대화 상자
class CBamDlg : public CDialogEx
{public:
	int eat_x_pos;//for food x pos
	int eat_y_pos;//for food y pos
	char cmp_cha = NULL;//for keep previous direction
	SnakeList s_l;//snake list info
	int snake_body_size;//for keep snake body length
	bool init_decide = true;//for decide it is first of game
	int pos_x;//for snake x pos
	int pos_y;//for snake y pos
	int init_pos_x;//for initial snake of pos x
	int init_pos_y;//for initial snake of pos y
// 생성입니다.
public:
	CBamDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
