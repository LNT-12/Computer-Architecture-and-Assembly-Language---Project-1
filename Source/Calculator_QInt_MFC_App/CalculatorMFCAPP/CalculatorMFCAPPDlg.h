
// CalculatorMFCAPPDlg.h : header file
//

#pragma once


// CCalculatorMFCAPPDlg dialog
class CCalculatorMFCAPPDlg : public CDialogEx
{
// Construction
public:
	CCalculatorMFCAPPDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORMFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString ENTER_INPUT;
	CStatic HEX;
	CStatic DEC;
	CStatic BIN;
	afx_msg void OnEnChangeEditEnterInput();
	afx_msg void OnBnClickedButtonEnter();
	CEdit INPUT_CONTROL;

	CButton rad_hex_control;
	CButton rad_dec_control;
	CButton rad_bin_control;
	CButton btn_A_control;
	CButton btn_B_control;
	CButton btn_C_control;
	CButton btn_D_control;
	CButton btn_E_control;
	CButton btn_F_control;
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedRadioHex();
	afx_msg void OnBnClickedRadioDec();
	afx_msg void OnBnClickedRadioBin();
	afx_msg void OnBnClickedButtonAnd();

	CStatic static_text_no1_control;
	CStatic static_text_operator_control;
	CStatic static_text_no2_control;
	CStatic static_text_result_control;

	int status = DEFAULT;
	int status2 = DEFAULT;
	bool flag = false;
	int base_flag = 0;
	int base_flag2 = 0;
	int base_flag3 = 0;

	QInt NUMBER1;
	QInt NUMBER2;
	QInt RESULT = 0;

	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnBnClickedButtonOr();
	afx_msg void OnBnClickedButtonXor();
	afx_msg void OnBnClickedButtonNot();
	afx_msg void OnBnClickedButtonRol();
	afx_msg void OnBnClickedButtonRor();
	afx_msg void OnBnClickedButtonLeftShift();
	afx_msg void OnBnClickedButtonRightShift();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonDel();

	afx_msg void OnBnClickedButtonResult2();
	afx_msg void OnBnClickedButtonResult3();
	afx_msg void OnBnClickedButtonSmaller();
	afx_msg void OnBnClickedButtonGreater();
	afx_msg void OnBnClickedButtonSmallerEqual();
	afx_msg void OnBnClickedButtonGreaterEqual();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonDiff();
};
