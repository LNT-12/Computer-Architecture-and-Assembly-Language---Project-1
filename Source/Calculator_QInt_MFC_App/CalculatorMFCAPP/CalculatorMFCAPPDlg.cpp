// CalculatorMFCAPPDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorMFCAPP.h"
#include "CalculatorMFCAPPDlg.h"
#include "afxdialogex.h"
#include <string>

using namespace std;

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


// CCalculatorMFCAPPDlg dialog
CCalculatorMFCAPPDlg::CCalculatorMFCAPPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORMFCAPP_DIALOG, pParent)
	, ENTER_INPUT(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorMFCAPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ENTER_INPUT, ENTER_INPUT);
	DDX_Control(pDX, IDC_STATIC_HEX, HEX);
	DDX_Control(pDX, IDC_STATIC_DEC, DEC);
	DDX_Control(pDX, IDC_STATIC_BIN, BIN);
	DDX_Control(pDX, IDC_EDIT_ENTER_INPUT, INPUT_CONTROL);
	DDX_Control(pDX, IDC_RADIO_HEX, rad_hex_control);
	DDX_Control(pDX, IDC_RADIO_DEC, rad_dec_control);
	DDX_Control(pDX, IDC_RADIO_BIN, rad_bin_control);
	DDX_Control(pDX, IDC_BUTTON_A, btn_A_control);
	DDX_Control(pDX, IDC_BUTTON_B, btn_B_control);
	DDX_Control(pDX, IDC_BUTTON_C, btn_C_control);
	DDX_Control(pDX, IDC_BUTTON_D, btn_D_control);
	DDX_Control(pDX, IDC_BUTTON_E, btn_E_control);
	DDX_Control(pDX, IDC_BUTTON_F, btn_F_control);
	DDX_Control(pDX, IDC_STATIC_NO1, static_text_no1_control);
	DDX_Control(pDX, IDC_STATIC_OPERATOR, static_text_operator_control);
	DDX_Control(pDX, IDC_STATIC_NO2, static_text_no2_control);
	DDX_Control(pDX, IDC_STATIC_RESULT, static_text_result_control);
}

BEGIN_MESSAGE_MAP(CCalculatorMFCAPPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_ENTER_INPUT, &CCalculatorMFCAPPDlg::OnEnChangeEditEnterInput)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CCalculatorMFCAPPDlg::OnBnClickedButtonEnter)
	ON_BN_CLICKED(IDC_BUTTON_A, &CCalculatorMFCAPPDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorMFCAPPDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorMFCAPPDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorMFCAPPDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorMFCAPPDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorMFCAPPDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorMFCAPPDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorMFCAPPDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorMFCAPPDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorMFCAPPDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorMFCAPPDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_B, &CCalculatorMFCAPPDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorMFCAPPDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, &CCalculatorMFCAPPDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_E, &CCalculatorMFCAPPDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_F, &CCalculatorMFCAPPDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_RADIO_HEX, &CCalculatorMFCAPPDlg::OnBnClickedRadioHex)
	ON_BN_CLICKED(IDC_RADIO_DEC, &CCalculatorMFCAPPDlg::OnBnClickedRadioDec)
	ON_BN_CLICKED(IDC_RADIO_BIN, &CCalculatorMFCAPPDlg::OnBnClickedRadioBin)
	ON_BN_CLICKED(IDC_BUTTON_AND, &CCalculatorMFCAPPDlg::OnBnClickedButtonAnd)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CCalculatorMFCAPPDlg::OnBnClickedButtonResult)
	ON_BN_CLICKED(IDC_BUTTON_OR, &CCalculatorMFCAPPDlg::OnBnClickedButtonOr)
	ON_BN_CLICKED(IDC_BUTTON_XOR, &CCalculatorMFCAPPDlg::OnBnClickedButtonXor)
	ON_BN_CLICKED(IDC_BUTTON_NOT, &CCalculatorMFCAPPDlg::OnBnClickedButtonNot)
	ON_BN_CLICKED(IDC_BUTTON_ROL, &CCalculatorMFCAPPDlg::OnBnClickedButtonRol)
	ON_BN_CLICKED(IDC_BUTTON_ROR, &CCalculatorMFCAPPDlg::OnBnClickedButtonRor)
	ON_BN_CLICKED(IDC_BUTTON_LEFt_SHIFT, &CCalculatorMFCAPPDlg::OnBnClickedButtonLeftShift)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT_SHIFT, &CCalculatorMFCAPPDlg::OnBnClickedButtonRightShift)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorMFCAPPDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalculatorMFCAPPDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculatorMFCAPPDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculatorMFCAPPDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CCalculatorMFCAPPDlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalculatorMFCAPPDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_SMALLER, &CCalculatorMFCAPPDlg::OnBnClickedButtonSmaller)
	ON_BN_CLICKED(IDC_BUTTON_GREATER, &CCalculatorMFCAPPDlg::OnBnClickedButtonGreater)
	ON_BN_CLICKED(IDC_BUTTON_SMALLER_EQUAL, &CCalculatorMFCAPPDlg::OnBnClickedButtonSmallerEqual)
	ON_BN_CLICKED(IDC_BUTTON_GREATER_EQUAL, &CCalculatorMFCAPPDlg::OnBnClickedButtonGreaterEqual)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorMFCAPPDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_DIFF, &CCalculatorMFCAPPDlg::OnBnClickedButtonDiff)
END_MESSAGE_MAP()


// CCalculatorMFCAPPDlg message handlers

BOOL CCalculatorMFCAPPDlg::OnInitDialog()
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

	// TODO: Add extra initialization here
	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);

	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorMFCAPPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorMFCAPPDlg::OnPaint()
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
HCURSOR CCalculatorMFCAPPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorMFCAPPDlg::OnEnChangeEditEnterInput()
{
	if (rad_dec_control.GetCheck() == 1) {
		CString InputCString;
		GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);;
			
		if (!CheckInputDec(DecString)) {
			MessageBox(_T("Sorry, this type dosen't support that value"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			return;
		}

		char check;

		if (DecString[0] != '-') {
			check = ComparePositiveString(DecString, MAX_QINT);

			if (check == 1) {
				MessageBox(_T("Sorry, overload MAX_INT128: 170141183460469231731687303715884105727"), _T("Error"), MB_ICONERROR | MB_OK);
				INPUT_CONTROL.SetWindowTextW(CString(""));
				return;
			}
		}
		else {
			check = CompareNegativeString(DecString, MIN_QINT);
			if (check == 0) {
				MessageBox(_T("Sorry, overload MIN_INT128: -170141183460469231731687303715884105728"), _T("Error"), MB_ICONERROR | MB_OK);
				INPUT_CONTROL.SetWindowTextW(CString(""));
				return;
			}
		}

		QInt Input = ConvertStringToQInt(DecString);

		if (!InputCString.IsEmpty())
		{
			string BinString = boolToString(DecToBin(Input));
			string HexString = charHexToString(DecToHex(Input));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));

			if (Input == 0 && DecString[0] == '-')
				DEC.SetWindowTextW(CString("-"));
			else
				DEC.SetWindowTextW(CString(GetQIntValue(Input).c_str()));

			BIN.SetWindowTextW(CString(BinString.c_str()));
		}

		if (status == DEFAULT) {
			if (Input == 0 && DecString[0] == '-')
				static_text_no1_control.SetWindowTextW(CString("-"));
			else
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(Input).c_str()));
		}

		if (status != DEFAULT && static_text_result_control.GetWindowTextLengthW() == 0) {
			if (Input == 0 && DecString[0] == '-')
				static_text_no2_control.SetWindowTextW(CString("-"));
			else
				static_text_no2_control.SetWindowTextW(CString(GetQIntValue(Input).c_str()));
		}
	}

	if (rad_hex_control.GetCheck() == 1) {
		CString InputCString;
		GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string HexString(pszConvertedAnsiStringInput);

		if (!CheckInputHex(HexString)) {
			MessageBox(_T("Sorry, this type dosen't support that value"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			return;
		}

		string BinString = HexToBinString(HexString);

		bool check = CheckInputBin(BinString);

		if (!check) {
			MessageBox(_T("Sorry, this type dosen't support that value"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			return;
		}

		while (HexString.length() < 32)
			HexString = '0' + HexString;

		QInt Input = HexToDec(HexString.data());

		if (!InputCString.IsEmpty()) {
			BinString = boolToString(DecToBin(Input));
			HexString = charHexToString(DecToHex(Input));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));

			GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);
			if (!InputCString.IsEmpty())
				DEC.SetWindowTextW(CString(GetQIntValue(Input).c_str()));
			else
				DEC.SetWindowTextW(CString(""));
		}

		if (status == DEFAULT) {
			if (!InputCString.IsEmpty())
				static_text_no1_control.SetWindowTextW(InputCString);
		}

		if (status != DEFAULT && static_text_result_control.GetWindowTextLengthW() == 0)
			static_text_no2_control.SetWindowTextW(InputCString);
	}


	if (rad_bin_control.GetCheck() == 1) {
		CString InputCString;
		GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string BinString(pszConvertedAnsiStringInput);

		if (!CheckInputBin(BinString)) {
			MessageBox(_T("Sorry, this type dosen't support that value"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			return;
		}

		if (!InputCString.IsEmpty()) {
			QInt Input = BinStringToDec(BinString);

			BinString = boolToString(DecToBin(Input));
			string HexString = charHexToString(DecToHex(Input));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));

			GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);
			if (!InputCString.IsEmpty())
				DEC.SetWindowTextW(CString(GetQIntValue(Input).c_str()));
			else
				DEC.SetWindowTextW(CString(""));
		}

		if (status == DEFAULT) {
			if (!InputCString.IsEmpty())
				static_text_no1_control.SetWindowTextW(InputCString);
		}

		if (status != DEFAULT && static_text_result_control.GetWindowTextLengthW() == 0)
			static_text_no2_control.SetWindowTextW(InputCString);
	}
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonEnter()
{
	status = DEFAULT;
	flag = false;
	base_flag = 0;
	base_flag2 = 0;
	INPUT_CONTROL.SetWindowTextW(CString(""));
	HEX.SetWindowTextW(CString(""));
	DEC.SetWindowTextW(CString(""));
	BIN.SetWindowTextW(CString(""));
	static_text_no1_control.SetWindowTextW(CString(""));
	static_text_no2_control.SetWindowTextW(CString(""));
	static_text_operator_control.SetWindowTextW(CString(""));
	static_text_result_control.SetWindowTextW(CString(""));
	/*RESULT = 0;
	NUMBER1 = 0;
	NUMBER2 = 0;*/
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonA()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "A";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton1()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1) 
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1) 
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_bin_control.GetCheck() == 1) 
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string bin = boolToString(DecToBin(RESULT));
			if (bin.empty())
				bin += "0";
			static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "1";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}


void CCalculatorMFCAPPDlg::OnBnClickedButton2()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "2";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton3()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "3";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton4()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "4";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton5()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "5";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton6()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "6";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton7()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "7";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton8()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "8";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton9()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "9";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButton0()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)  && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_dec_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	if (rad_bin_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string bin = boolToString(DecToBin(RESULT));
			if (bin.empty())
				bin += "0";
			static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "0";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonB()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "B";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonC()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "C";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonD()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "D";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonE()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "E";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonF()
{
	if ((status == NOT || status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF) && static_text_result_control.GetWindowTextLengthW() != 0)
		OnBnClickedButtonEnter();

	if (rad_hex_control.GetCheck() == 1)
		if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
			string hex = charHexToString(DecToHex(RESULT));
			if (hex.empty())
				hex += "0";
			static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
			static_text_result_control.SetWindowTextW(CString(""));
			INPUT_CONTROL.SetWindowTextW(CString(""));
		}

	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	InputString += "F";

	while (InputString[0] == '0' && InputString.length() > 1)
		InputString = InputString.substr(1);

	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedRadioHex()
{
	if ((status == ROTATE_LEFT || status == ROTATE_RIGHT) && static_text_result_control.GetWindowTextLengthW() == 0) {
		MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
		INPUT_CONTROL.SetWindowTextW(CString(""));
		OnBnClickedButtonEnter();
		rad_dec_control.SetCheck(1);
		rad_hex_control.SetCheck(0);
		rad_bin_control.SetCheck(0);
		return;
	}

	if ((status == SHIFT_LEFT || status == SHIFT_RIGHT) && static_text_result_control.GetWindowTextLengthW() == 0) {
		MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
		INPUT_CONTROL.SetWindowTextW(CString(""));
		OnBnClickedButtonEnter();
		rad_dec_control.SetCheck(1);
		rad_hex_control.SetCheck(0);
		rad_bin_control.SetCheck(0);
		return;
	}

	OnBnClickedButtonEnter();
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);
}


void CCalculatorMFCAPPDlg::OnBnClickedRadioDec()
{
	OnBnClickedButtonEnter();

	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);
}


void CCalculatorMFCAPPDlg::OnBnClickedRadioBin()
{
	if ((status == ROTATE_LEFT || status == ROTATE_RIGHT) && static_text_result_control.GetWindowTextLengthW() == 0) {
		MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
		INPUT_CONTROL.SetWindowTextW(CString(""));
		OnBnClickedButtonEnter();
		rad_dec_control.SetCheck(1);
		rad_hex_control.SetCheck(0);
		rad_bin_control.SetCheck(0);
		return;
	}

	if ((status == SHIFT_LEFT || status == SHIFT_RIGHT) && static_text_result_control.GetWindowTextLengthW() == 0) {
		MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
		INPUT_CONTROL.SetWindowTextW(CString(""));
		OnBnClickedButtonEnter();
		rad_dec_control.SetCheck(1);
		rad_hex_control.SetCheck(0);
		rad_bin_control.SetCheck(0);
		return;
	}

	OnBnClickedButtonEnter();
	if (rad_bin_control.GetCheck() == 1) {
		GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);
	}
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonAnd()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("AND"));
	status = AND;
	status2 = AND;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonResult() {
	switch (status) {
	case DIFF: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case GREATER_EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case SMALLER_EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case GREATER: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case SMALLER: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else 
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 < NUMBER2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case AND: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case OR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case XOR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case ROTATE_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				//base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				//base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				//base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case ROTATE_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				//base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				//base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				//base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case SHIFT_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);
			
			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				//base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";

				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				//base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				//base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case SHIFT_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE); 
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			}

			//base_flag = 0;
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}
		break;
	}
	case ADD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case SUB: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MUL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case DIV: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MOD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 % NUMBER2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	}

	string BinString = boolToString(DecToBin(RESULT));
	string HexString = charHexToString(DecToHex(RESULT));

	if (BinString.empty())
		BinString += "0";

	if (HexString.empty())
		HexString += "0";

	HEX.SetWindowTextW(CString(HexString.c_str()));
	DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
	BIN.SetWindowTextW(CString(BinString.c_str()));
	//INPUT_CONTROL.SetWindowTextW(CString(""));

	status2 = DEFAULT;
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonOr()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("OR"));
	status = OR;
	status2 = OR;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonXor()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("XOR"));
	status = XOR;
	status2 = XOR;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonNot()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	static_text_operator_control.SetWindowTextW(CString("NOT"));
	static_text_no2_control.SetWindowTextW(CString(""));
	status = NOT;
	status2 = NOT;

	if (rad_dec_control.GetCheck() == 1) {
		CString InputCString;
		static_text_no1_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number1 = ConvertStringToQInt(DecString);
		NUMBER1 = Number1;
		RESULT = ~NUMBER1;
		static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
	}

	if (rad_hex_control.GetCheck() == 1) {
		CString InputCString;
		static_text_no1_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string HexString(pszConvertedAnsiStringInput);

		while (HexString.length() < 32)
			HexString = '0' + HexString;

		QInt Number1 = HexToDec(HexString.data());

		NUMBER1 = Number1;
		RESULT = ~NUMBER1;

		string hexResult = charHexToString(DecToHex(RESULT));
		if (hexResult.empty())
			hexResult += "0";
		static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
	}

	if (rad_bin_control.GetCheck() == 1) {
		CString InputCString;
		static_text_no1_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string BinString(pszConvertedAnsiStringInput);

		QInt Number1 = BinStringToDec(BinString);
		NUMBER1 = Number1;
		RESULT = ~NUMBER1;
		string binResult = boolToString(DecToBin(RESULT));
		if (binResult.empty())
			binResult += "0";

		static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
	}
	  
	flag = true;

	string BinString = boolToString(DecToBin(RESULT));
	string HexString = charHexToString(DecToHex(RESULT));

	if (BinString.empty())
		BinString += "0";

	if (HexString.empty())
		HexString += "0";

	HEX.SetWindowTextW(CString(HexString.c_str()));
	DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
	BIN.SetWindowTextW(CString(BinString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonRol()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (rad_dec_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 1;
				base_flag2 = 1;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_hex_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 2;
				base_flag2 = 2;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_bin_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 3;
				base_flag2 = 3;
			}
			else
				base_flag2 = base_flag;
		}
	}

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	if (status != DEFAULT) {
		CString InputCString2;
		static_text_no2_control.GetWindowTextW(InputCString2);
		if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
			int temp = base_flag;
			if (static_text_result_control.GetWindowTextLengthW() == 0)
				OnBnClickedButtonResult3();
			if (base_flag2 == 1)
				if (flag) {
					static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 2)
				if (flag) {
					string hex = charHexToString(DecToHex(RESULT));
					if (hex.empty())
						hex += "0";
					static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 3)
				if (flag) {
					string bin = boolToString(DecToBin(RESULT));
					if (bin.empty())
						bin += "0";
					static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			base_flag2 = 0;
			base_flag = temp;

			string BinString = boolToString(DecToBin(RESULT));
			string HexString = charHexToString(DecToHex(RESULT));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));
		}
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	static_text_operator_control.SetWindowTextW(CString("LEFT ROTATE"));
	status = ROTATE_LEFT;
	status2 = ROTATE_LEFT;

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonRor()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (rad_dec_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 1;
				base_flag2 = 1;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_hex_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 2;
				base_flag2 = 2;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_bin_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 3;
				base_flag2 = 3;
			}
			else
				base_flag2 = base_flag;
		}
	}

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	if (status != DEFAULT) {
		CString InputCString2;
		static_text_no2_control.GetWindowTextW(InputCString2);
		if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
			int temp = base_flag;
			if (static_text_result_control.GetWindowTextLengthW() == 0)
				OnBnClickedButtonResult3();
			if (base_flag2 == 1)
				if (flag) {
					static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 2)
				if (flag) {
					string hex = charHexToString(DecToHex(RESULT));
					if (hex.empty())
						hex += "0";
					static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 3)
				if (flag) {
					string bin = boolToString(DecToBin(RESULT));
					if (bin.empty())
						bin += "0";
					static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			base_flag2 = 0;
			base_flag = temp;

			string BinString = boolToString(DecToBin(RESULT));
			string HexString = charHexToString(DecToHex(RESULT));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));
		}
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	static_text_operator_control.SetWindowTextW(CString("RIGHT ROTATE"));
	status = ROTATE_RIGHT;
	status2 = ROTATE_RIGHT;

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	INPUT_CONTROL.SetWindowTextW(CString(""));

}


void CCalculatorMFCAPPDlg::OnBnClickedButtonLeftShift()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (rad_dec_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 1;
				base_flag2 = 1;
			}
			else
				base_flag2 = base_flag;
		}	
	}

	if (rad_hex_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 2;
				base_flag2 = 2;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_bin_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 3;
				base_flag2 = 3;
			}
			else
				base_flag2 = base_flag;
		}
	}

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	if (status != DEFAULT) {
		CString InputCString2;
		static_text_no2_control.GetWindowTextW(InputCString2);
		if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty() ) {
			int temp = base_flag;
			if (static_text_result_control.GetWindowTextLengthW() == 0)
				OnBnClickedButtonResult3();
			if (base_flag2 == 1)
				if (flag) {
					static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 2)
				if (flag) {
					string hex = charHexToString(DecToHex(RESULT));
					if (hex.empty())
						hex += "0";
					static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 3)
				if (flag) {
					string bin = boolToString(DecToBin(RESULT));
					if (bin.empty())
						bin += "0";
					static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			base_flag2 = 0;
			base_flag = temp;

			string BinString = boolToString(DecToBin(RESULT));
			string HexString = charHexToString(DecToHex(RESULT));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));
		}
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	static_text_operator_control.SetWindowTextW(CString("LEFT SHIFT"));
	status = SHIFT_LEFT;
	status2 = SHIFT_LEFT; 

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	INPUT_CONTROL.SetWindowTextW(CString(""));
	//HEX.SetWindowTextW(CString(""));
	//DEC.SetWindowTextW(CString(""));
	//BIN.SetWindowTextW(CString(""));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonRightShift()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (rad_dec_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 1;
				base_flag2 = 1;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_hex_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 2;
				base_flag2 = 2;
			}
			else
				base_flag2 = base_flag;
		}
	}

	if (rad_bin_control.GetCheck() == 1) {
		if (base_flag2 == 0) {
			if (base_flag == 0) {
				base_flag = 3;
				base_flag2 = 3;
			}
			else
				base_flag2 = base_flag;
		}
	}

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	if (status != DEFAULT) {
		CString InputCString2;
		static_text_no2_control.GetWindowTextW(InputCString2);
		if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
			int temp = base_flag;
			if (static_text_result_control.GetWindowTextLengthW() == 0)
				OnBnClickedButtonResult3();
			if (base_flag2 == 1)
				if (flag) {
					static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 2)
				if (flag) {
					string hex = charHexToString(DecToHex(RESULT));
					if (hex.empty())
						hex += "0";
					static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (base_flag2 == 3)
				if (flag) {
					string bin = boolToString(DecToBin(RESULT));
					if (bin.empty())
						bin += "0";
					static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			base_flag2 = 0;
			base_flag = temp;

			string BinString = boolToString(DecToBin(RESULT));
			string HexString = charHexToString(DecToHex(RESULT));

			if (BinString.empty())
				BinString += "0";

			if (HexString.empty())
				HexString += "0";

			HEX.SetWindowTextW(CString(HexString.c_str()));
			DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			BIN.SetWindowTextW(CString(BinString.c_str()));
		}
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	static_text_operator_control.SetWindowTextW(CString("RIGHT SHIFT"));
	status = SHIFT_RIGHT;
	status2 = SHIFT_RIGHT;

	rad_dec_control.SetCheck(1);
	rad_hex_control.SetCheck(0);
	rad_bin_control.SetCheck(0);
	GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonAdd()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}
		
	static_text_operator_control.SetWindowTextW(CString("+"));
	status = ADD;
	status2 = ADD;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonSub()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	bool flag1 = false, flag2 = false;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		if (rad_hex_control.GetCheck() == 1 || rad_bin_control.GetCheck() == 1) {
			MessageBox(_T("Sign character '-' only use for base decimal"), _T("Error"), MB_ICONERROR | MB_OK);
			OnBnClickedButtonEnter();
			return;
		}
		static_text_no1_control.SetWindowTextW(CString("-"));
		INPUT_CONTROL.SetWindowTextW(CString("-"));
	}
	else {
		flag1 = true;
		CString InputCString2;
		static_text_no2_control.GetWindowTextW(InputCString2);

		if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
			OnBnClickedButtonResult();
			if (rad_dec_control.GetCheck() == 1)
				if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
					static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (rad_hex_control.GetCheck() == 1)
				if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
					string hex = charHexToString(DecToHex(RESULT));
					if (hex.empty())
						hex += "0";
					static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			if (rad_bin_control.GetCheck() == 1)
				if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
					string bin = boolToString(DecToBin(RESULT));
					if (bin.empty())
						bin += "0";
					static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
					static_text_result_control.SetWindowTextW(CString(""));
					INPUT_CONTROL.SetWindowTextW(CString(""));
				}

			static_text_operator_control.SetWindowTextW(CString("-"));
			status = SUB;
			status2 = SUB;

			INPUT_CONTROL.SetWindowTextW(CString(""));
			HEX.SetWindowTextW(CString(""));
			DEC.SetWindowTextW(CString(""));
			BIN.SetWindowTextW(CString(""));
		}
		else {
			if (status != DEFAULT && status2 != DEFAULT) {
				if (rad_hex_control.GetCheck() == 1 || rad_bin_control.GetCheck() == 1) {
					MessageBox(_T("Sign character '-' only use for base decimal"), _T("Error"), MB_ICONERROR | MB_OK);
					OnBnClickedButtonEnter();
					return;
				}
				static_text_no2_control.SetWindowTextW(CString("-"));
				INPUT_CONTROL.SetWindowTextW(CString("-"));
			}
			else {
				static_text_operator_control.SetWindowTextW(CString("-"));
				status = SUB;
				status2 = SUB;

				INPUT_CONTROL.SetWindowTextW(CString(""));
				HEX.SetWindowTextW(CString(""));
				DEC.SetWindowTextW(CString(""));
				BIN.SetWindowTextW(CString(""));
			}
		}
	}
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonMul()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("*"));
	status = MUL;
	status2 = MUL;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonDiv()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("/"));
	status = DIV;
	status2 = DIV;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonMod()
{
	if (status == SMALLER || status == GREATER || status == SMALLER_EQUAL || status == GREATER_EQUAL
		|| status == EQUAL || status == DIFF)
		return;

	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";

		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("%"));
	status = MOD;
	status2 = MOD;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonDel()
{
	CString InputCString;
	GetDlgItemText(IDC_EDIT_ENTER_INPUT, InputCString);

	CT2CA pszConvertedAnsiStringInput(InputCString);
	string InputString(pszConvertedAnsiStringInput);
	
	if (!InputString.empty())
		InputString.pop_back();
	INPUT_CONTROL.SetWindowTextW(CString(InputString.c_str()));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonResult2() {
	switch (status) {
	case AND: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case OR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case XOR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case ROTATE_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case ROTATE_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case SHIFT_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				base_flag = 0;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
				base_flag = 0;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
				base_flag = 0;
			}
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}
		break;
	}
	case SHIFT_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				string hexResult = charHexToString(DecToHex(RESULT));
				if (hexResult.empty())
					hexResult += "0";
				static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;

				string binResult = boolToString(DecToBin(RESULT));
				if (binResult.empty())
					binResult += "0";

				static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			}

			base_flag = 0;
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}
		break;
	}
	case ADD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case SUB: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MUL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case DIV: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MOD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 % NUMBER2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	}

	string BinString = boolToString(DecToBin(RESULT));
	string HexString = charHexToString(DecToHex(RESULT));

	if (BinString.empty())
		BinString += "0";

	if (HexString.empty())
		HexString += "0";

	HEX.SetWindowTextW(CString(HexString.c_str()));
	DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
	BIN.SetWindowTextW(CString(BinString.c_str()));
	//INPUT_CONTROL.SetWindowTextW(CString(""));

	status = DEFAULT;
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonSmaller()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("<"));
	status = SMALLER;
	status2 = SMALLER;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonGreater()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString(">"));
	status = GREATER;
	status2 = GREATER;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonSmallerEqual()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("<="));
	status = SMALLER_EQUAL;
	status2 = SMALLER_EQUAL;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonGreaterEqual()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString(">="));
	status = GREATER_EQUAL;
	status2 = GREATER_EQUAL;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonEqual()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("=="));
	status = EQUAL;
	status2 = EQUAL;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}


void CCalculatorMFCAPPDlg::OnBnClickedButtonDiff()
{
	if (status != DEFAULT) {
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	CString Number1CString;
	GetDlgItemText(IDC_STATIC_NO1, Number1CString);
	if (Number1CString.IsEmpty()) {
		MessageBox(_T("Add More Number"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	CString InputCString2;
	static_text_no2_control.GetWindowTextW(InputCString2);

	if (InputCString2.Compare(CString("0")) != 0 && !InputCString2.IsEmpty()) {
		OnBnClickedButtonResult();
		if (rad_dec_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				static_text_no1_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_hex_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string hex = charHexToString(DecToHex(RESULT));
				if (hex.empty())
					hex += "0";
				static_text_no1_control.SetWindowTextW(CString(hex.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		if (rad_bin_control.GetCheck() == 1)
			if (flag && static_text_result_control.GetWindowTextLengthW() != 0) {
				string bin = boolToString(DecToBin(RESULT));
				if (bin.empty())
					bin += "0";
				static_text_no1_control.SetWindowTextW(CString(bin.c_str()));
				static_text_result_control.SetWindowTextW(CString(""));
				INPUT_CONTROL.SetWindowTextW(CString(""));
			}

		string BinString = boolToString(DecToBin(RESULT));
		string HexString = charHexToString(DecToHex(RESULT));

		if (BinString.empty())
			BinString += "0";

		if (HexString.empty())
			HexString += "0";


		HEX.SetWindowTextW(CString(HexString.c_str()));
		DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
		BIN.SetWindowTextW(CString(BinString.c_str()));
	}

	static_text_operator_control.SetWindowTextW(CString("!="));
	status = DIFF;
	status2 = DIFF;

	INPUT_CONTROL.SetWindowTextW(CString(""));
}

void CCalculatorMFCAPPDlg::OnBnClickedButtonResult3() {
	switch (status) {
	case DIFF: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 != NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 == NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case GREATER_EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 >= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case SMALLER_EQUAL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 <= NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case GREATER: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 > NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case SMALLER: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));

			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 < NUMBER2;

			bool result = NUMBER1 < NUMBER2;

			if (result)
				static_text_result_control.SetWindowTextW(CString("TRUE"));
			else
				static_text_result_control.SetWindowTextW(CString("FALSE"));
			break;
		}
	}
	case AND: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 & NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case OR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 | NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case XOR: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 ^ NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case ROTATE_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				rol(NUMBER1, count);
				RESULT = NUMBER1;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case ROTATE_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				ror(NUMBER1, count);
				RESULT = NUMBER1;
			}
		}
		else {
			MessageBox(_T("Sorry, number of ratations is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case SHIFT_LEFT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 << count;
			}
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}

		break;
	}
	case SHIFT_RIGHT: {
		flag = true;
		CString InputCString;
		static_text_no2_control.GetWindowTextW(InputCString);

		CT2CA pszConvertedAnsiStringInput(InputCString);
		string DecString(pszConvertedAnsiStringInput);

		QInt Number2 = ConvertStringToQInt(DecString);
		NUMBER2 = Number2;

		if (NUMBER2 >= 0 && NUMBER2 <= 128) {
			string countString = GetQIntValue(NUMBER2);
			int count = stoi(countString);

			if (base_flag == 1) {
				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string DecString1(pszConvertedAnsiStringInput1);

				QInt Number1 = ConvertStringToQInt(DecString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;
			}

			if (base_flag == 2) {
				rad_hex_control.SetCheck(1);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(0);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(TRUE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string HexString1(pszConvertedAnsiStringInput1);

				while (HexString1.length() < 32)
					HexString1 = '0' + HexString1;

				QInt Number1 = HexToDec(HexString1.data());
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;
			}

			if (base_flag == 3) {
				rad_hex_control.SetCheck(0);
				rad_dec_control.SetCheck(0);
				rad_bin_control.SetCheck(1);

				GetDlgItem(IDC_BUTTON_A)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_B)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_C)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_D)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_E)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_F)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_5)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_6)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_7)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_8)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON_9)->EnableWindow(FALSE);

				CString InputCString1;
				static_text_no1_control.GetWindowTextW(InputCString1);

				CT2CA pszConvertedAnsiStringInput1(InputCString1);
				string BinString1(pszConvertedAnsiStringInput1);

				QInt Number1 = BinStringToDec(BinString1);
				NUMBER1 = Number1;

				RESULT = NUMBER1 >> count;
			}

			//base_flag = 0;
		}
		else {
			MessageBox(_T("Sorry, number of shift is a decimal number in [0..128]"), _T("Error"), MB_ICONERROR | MB_OK);
			INPUT_CONTROL.SetWindowTextW(CString(""));
			OnBnClickedButtonEnter();
			rad_dec_control.SetCheck(1);
			rad_hex_control.SetCheck(0);
			rad_bin_control.SetCheck(0);
			return;
		}
		break;
	}
	case ADD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 + NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case SUB: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 - NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MUL: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 * NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case DIV: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 / NUMBER2;

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	case MOD: {
		flag = true;
		if (rad_dec_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string DecString1(pszConvertedAnsiStringInput1);

			QInt Number1 = ConvertStringToQInt(DecString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string DecString2(pszConvertedAnsiStringInput);

			QInt Number2 = ConvertStringToQInt(DecString2);
			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			static_text_result_control.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
			break;
		}

		if (rad_hex_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string HexString1(pszConvertedAnsiStringInput1);

			while (HexString1.length() < 32)
				HexString1 = '0' + HexString1;

			QInt Number1 = HexToDec(HexString1.data());

			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput(InputCString2);
			string HexString2(pszConvertedAnsiStringInput);

			while (HexString2.length() < 32)
				HexString2 = '0' + HexString2;

			QInt Number2 = HexToDec(HexString2.data());

			NUMBER2 = Number2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			RESULT = NUMBER1 % NUMBER2;

			string hexResult = charHexToString(DecToHex(RESULT));
			if (hexResult.empty())
				hexResult += "0";

			static_text_result_control.SetWindowTextW(CString(hexResult.c_str()));
			break;
		}

		if (rad_bin_control.GetCheck() == 1) {
			CString InputCString1;
			static_text_no1_control.GetWindowTextW(InputCString1);

			CT2CA pszConvertedAnsiStringInput1(InputCString1);
			string BinString1(pszConvertedAnsiStringInput1);

			QInt Number1 = BinStringToDec(BinString1);
			NUMBER1 = Number1;

			if (NUMBER1 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			CString InputCString2;
			static_text_no2_control.GetWindowTextW(InputCString2);

			CT2CA pszConvertedAnsiStringInput2(InputCString2);
			string BinString2(pszConvertedAnsiStringInput2);

			QInt Number2 = BinStringToDec(BinString2);
			NUMBER2 = Number2;

			RESULT = NUMBER1 % NUMBER2;

			if (NUMBER2 < 0) {
				MessageBox(_T("Sorry, Cannot enforcement MOD with negative number"), _T("Error"), MB_ICONERROR | MB_OK);
			}

			string binResult = boolToString(DecToBin(RESULT));
			if (binResult.empty())
				binResult += "0";

			static_text_result_control.SetWindowTextW(CString(binResult.c_str()));
			break;
		}
	}
	}

	string BinString = boolToString(DecToBin(RESULT));
	string HexString = charHexToString(DecToHex(RESULT));

	if (BinString.empty())
		BinString += "0";

	if (HexString.empty())
		HexString += "0";

	HEX.SetWindowTextW(CString(HexString.c_str()));
	DEC.SetWindowTextW(CString(GetQIntValue(RESULT).c_str()));
	BIN.SetWindowTextW(CString(BinString.c_str()));
	//INPUT_CONTROL.SetWindowTextW(CString(""));

	status2 = DEFAULT;
}