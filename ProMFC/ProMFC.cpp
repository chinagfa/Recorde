// ProMFC.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ProMFC.h"
#include "ProMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProMFCApp

BEGIN_MESSAGE_MAP(CProMFCApp, CWinApp)
	//{{AFX_MSG_MAP(CProMFCApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProMFCApp construction

CProMFCApp::CProMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CProMFCApp object

CProMFCApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CProMFCApp initialization

BOOL CProMFCApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CProMFCDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		HWND hProgram=::FindWindow("Progman","Program Manager");
		HWND hChild=::FindWindowEx(hProgram,NULL,"SHELLDLL_DefView",NULL);
		::EnableWindow(hChild,true);//允许使用桌面,但其它程序窗口还能使用
		::EnableWindow(::FindWindow("Shell_TrayWnd",NULL),true);//允许使用"开始"菜单栏
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
