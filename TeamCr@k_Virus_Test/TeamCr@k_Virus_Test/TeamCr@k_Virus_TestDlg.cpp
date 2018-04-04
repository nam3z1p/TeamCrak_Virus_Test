// TeamCr@k_Virus_TestDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TeamCr@k_Virus_Test.h"
#include "TeamCr@k_Virus_TestDlg.h"
#include "stdio.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TCHAR Path[MAX_PATH] = "C:\\TeamCr@k_Virus.txt";


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTeamCrk_Virus_TestDlg 대화 상자




CTeamCrk_Virus_TestDlg::CTeamCrk_Virus_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTeamCrk_Virus_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTeamCrk_Virus_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTeamCrk_Virus_TestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTeamCrk_Virus_TestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CTeamCrk_Virus_TestDlg::OnBnClickedOk2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CTeamCrk_Virus_TestDlg 메시지 처리기

BOOL CTeamCrk_Virus_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//TeamCr@k_Virus_Test
	TCHAR Str1[1024]={"\0"};

	wsprintf(Str1, "본 프로그램은 모의해킹(악성코드 감염 시나리오)를 위하여 제작되었습니다.\r\n\r\n"
				   "본 프로그램과 같은 악성코드에 감염될 경우\r\n"
				   "키로깅, 도청, DDOS 공격(Botnet)등에 사용되어 질 수 있습니다.");
	
	SetDlgItemText(IDC_STATIC2, Str1);
	SetDlgItemText(IDC_EDIT1, "본 프로그램은 모의해킹(악성코드 감염 시나리오)를 위하여 제작되었습니다.");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTeamCrk_Virus_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTeamCrk_Virus_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

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
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTeamCrk_Virus_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTeamCrk_Virus_TestDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//악성코드 테스트 파일 생성
	FILE *virus;

	virus = fopen(Path, "wt");
	fprintf(virus, "%s\t", "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");

	fclose(virus);

	//감염
	TCHAR Str1[1024]={"\0"};

	wsprintf(Str1, "악성코드에 감염되었습니다!! \r\n"
			       "설치경로 : %s", Path);

	SetDlgItemText(IDC_EDIT1, Str1);

}

void CTeamCrk_Virus_TestDlg::OnBnClickedOk2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	ShellExecute(NULL, "open", Path, NULL, NULL, SW_SHOW);

	if(GetLastError() == ERROR_FILE_NOT_FOUND)
	{
		SetDlgItemText(IDC_EDIT1, "악성 파일이 존재하지 않습니다.");
		MessageBox("악성 파일이 존재하지 않습니다.","TeamCr@k_Virus_Test");
	}

}



void CTeamCrk_Virus_TestDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnClose();

	OnCancel();
}
