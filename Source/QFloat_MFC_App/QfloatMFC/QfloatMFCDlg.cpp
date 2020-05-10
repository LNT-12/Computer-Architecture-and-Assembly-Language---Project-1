
// QfloatMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "QfloatMFC.h"
#include "QfloatMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CQfloatMFCDlg dialog



CQfloatMFCDlg::CQfloatMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QFLOATMFC_DIALOG, pParent)
	, inputString(_T(""))
	, outputString(_T(""))
	, stringInput2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQfloatMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT, inputString);
	DDX_Text(pDX, IDC_OUTPUT, outputString);
	DDX_Text(pDX, IDC_INPUT2, stringInput2);
}

BEGIN_MESSAGE_MAP(CQfloatMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON, &CQfloatMFCDlg::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CQfloatMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CQfloatMFCDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CQfloatMFCDlg message handlers

BOOL CQfloatMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQfloatMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQfloatMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQfloatMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CQfloatMFCDlg::OnBnClickedButton()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_INPUT, inputString);
	string s((CT2CA)inputString);
	ScanQfloat(q, s);
	int countComma = 0;
	int countSign = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			countComma++;
		if (s[i] == '-')
			countSign++;
		if (s[i] != '.' && s[i] != '-' && s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9')
		{
			MessageBox(_T("Vui lòng nhập đúng định dạng!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
	}
	if (countComma >= 2 || countSign >= 2)
	{
		MessageBox(_T("Vui lòng nhập đúng định dạng!"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	string res = QfloatToStringBin(s);
	res = QfloatBitToString(res);
	CString temp(res.c_str());
	outputString = temp;
	CWnd* label = GetDlgItem(IDC_OUTPUT);
	label->SetWindowText(outputString);
	
	string res2 = QfloatToStringBin(s);
	res2 = res2.insert(15, " ");
	res2 = res2.insert(1, " ");
	CString temp2(res2.c_str());
	CString outputString2 = temp2;
	CWnd* label2 = GetDlgItem(IDC_OUTPUT2);
	label2->SetWindowText(outputString2);
}


void CQfloatMFCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_INPUT2, stringInput2);
	string s((CT2CA)stringInput2);
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '0' && s[i] != '1')
		{
			MessageBox(_T("Vui lòng nhập đúng định dạng!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
	if (s.length() != 128)
	{
		MessageBox(_T("Vui lòng nhập đủ 128 bit!"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	string res = QfloatBitToString(s);
	CString temp(res.c_str());
	CString outputString3 = temp;
	CWnd* label = GetDlgItem(IDC_OUTPUT3);
	label->SetWindowText(outputString3);
}


void CQfloatMFCDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString cs1, cs2, cs3;
	GetDlgItemText(IDC_INPUT3, cs1);
	string s1((CT2CA)cs1);
	GetDlgItemText(IDC_INPUT4, cs2);
	string s2((CT2CA)cs2);
	GetDlgItemText(IDC_INPUT5, cs3);
	string s3((CT2CA)cs3);
	string s = s1;
	s += s2;
	s += s3;
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '0' && s[i] != '1')
		{
			MessageBox(_T("Vui lòng nhập đúng định dạng!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
	if (s1.length() != 1 || s2.length() != 15 || s3.length() != 112)
	{
		MessageBox(_T("Vui lòng nhập đủ 1 bit ở Sign, 15 bit ở Exp và 112 bit ở Significand!"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	if (s.length() != 128)
	{
		MessageBox(_T("Vui lòng nhập đủ 128 bit!"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	string res = QfloatBitToString(s);
	CString temp(res.c_str());
	CString outputString3 = temp;
	CWnd* label = GetDlgItem(IDC_OUTPUT3);
	label->SetWindowText(outputString3);
}
