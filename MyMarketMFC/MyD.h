#pragma once
#include "afxwin.h"
#include"ViewCartCont.h"
// MyD dialog
class MyD : public CDialog
{
	DECLARE_DYNAMIC(MyD)

public:
	LVITEM* lv;
	CListCtrl* ltCtl;
	MyD(CWnd* pParent = NULL);   // standard constructor
	~MyD();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog();
	CEdit ed3;
	CEdit ed5;
	CComboBox m_stNum;
	CComboBox m_des;
	afx_msg void OnClickedCancel();
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit5();
	afx_msg void OnClickedAddBut();
	CString m_Qtty;
	CString m_Each;
	CString m_StocN;
	CString m_Descr;
};
