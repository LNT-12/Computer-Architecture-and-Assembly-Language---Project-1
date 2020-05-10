
// QfloatMFCDlg.h : header file
//
#include "Qfloat.h"
#pragma once


// CQfloatMFCDlg dialog
class CQfloatMFCDlg : public CDialogEx
{
// Construction
public:
	CQfloatMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QFLOATMFC_DIALOG };
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
	Qfloat q;
	CString inputString;
	CString outputString;
	afx_msg void OnBnClickedButton();
	CString stringInput2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
