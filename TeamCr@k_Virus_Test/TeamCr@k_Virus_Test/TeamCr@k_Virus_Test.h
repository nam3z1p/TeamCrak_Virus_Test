// TeamCr@k_Virus_Test.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTeamCrk_Virus_TestApp:
// �� Ŭ������ ������ ���ؼ��� TeamCr@k_Virus_Test.cpp�� �����Ͻʽÿ�.
//

class CTeamCrk_Virus_TestApp : public CWinApp
{
public:
	CTeamCrk_Virus_TestApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTeamCrk_Virus_TestApp theApp;