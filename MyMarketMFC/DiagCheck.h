#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include"resource1.h"
#include"Node.h"

// DiagCheck dialog

class DiagCheck : public CDialog
{
	DECLARE_DYNAMIC(DiagCheck)

public:
	DiagCheck(CWnd* pParent = NULL);   // standard constructor
	~DiagCheck();
	LVCOLUMN* cln;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIAL_CkOut };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog();
	CButton cancelBut;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_Address;
	CString m_FullName;
	CString m_shipping;
	CString m_tax;
	CString m_total;
	CString name,qtt,dscp,eacP,ex;
	CListCtrl Clistr;
	LVITEM* item;
	MyItemNode* checkHeadCart = nullptr;
};
