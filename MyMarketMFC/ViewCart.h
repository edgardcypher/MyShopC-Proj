#pragma once
#include "afxcmn.h"


// ViewCart dialog

class ViewCart : public CDialog
{
	DECLARE_DYNAMIC(ViewCart)

public:
	ViewCart(CWnd* pParent = NULL);   // standard constructor
	~ViewCart();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Vcart };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl thisItems;
};
