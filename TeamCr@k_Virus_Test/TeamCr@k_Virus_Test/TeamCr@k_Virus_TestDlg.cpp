// TeamCr@k_Virus_TestDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CTeamCrk_Virus_TestDlg ��ȭ ����




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


// CTeamCrk_Virus_TestDlg �޽��� ó����

BOOL CTeamCrk_Virus_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//TeamCr@k_Virus_Test
	TCHAR Str1[1024]={"\0"};

	wsprintf(Str1, "�� ���α׷��� ������ŷ(�Ǽ��ڵ� ���� �ó�����)�� ���Ͽ� ���۵Ǿ����ϴ�.\r\n\r\n"
				   "�� ���α׷��� ���� �Ǽ��ڵ忡 ������ ���\r\n"
				   "Ű�α�, ��û, DDOS ����(Botnet)� ���Ǿ� �� �� �ֽ��ϴ�.");
	
	SetDlgItemText(IDC_STATIC2, Str1);
	SetDlgItemText(IDC_EDIT1, "�� ���α׷��� ������ŷ(�Ǽ��ڵ� ���� �ó�����)�� ���Ͽ� ���۵Ǿ����ϴ�.");

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTeamCrk_Virus_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTeamCrk_Virus_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTeamCrk_Virus_TestDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	//�Ǽ��ڵ� �׽�Ʈ ���� ����
	FILE *virus;

	virus = fopen(Path, "wt");
	fprintf(virus, "%s\t", "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");

	fclose(virus);

	//����
	TCHAR Str1[1024]={"\0"};

	wsprintf(Str1, "�Ǽ��ڵ忡 �����Ǿ����ϴ�!! \r\n"
			       "��ġ��� : %s", Path);

	SetDlgItemText(IDC_EDIT1, Str1);

}

void CTeamCrk_Virus_TestDlg::OnBnClickedOk2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	ShellExecute(NULL, "open", Path, NULL, NULL, SW_SHOW);

	if(GetLastError() == ERROR_FILE_NOT_FOUND)
	{
		SetDlgItemText(IDC_EDIT1, "�Ǽ� ������ �������� �ʽ��ϴ�.");
		MessageBox("�Ǽ� ������ �������� �ʽ��ϴ�.","TeamCr@k_Virus_Test");
	}

}



void CTeamCrk_Virus_TestDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnClose();

	OnCancel();
}
