
// CalculatorMFCAPP.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalculatorMFCAPPApp:
// See CalculatorMFCAPP.cpp for the implementation of this class
//

class CCalculatorMFCAPPApp : public CWinApp
{
public:
	CCalculatorMFCAPPApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorMFCAPPApp theApp;
