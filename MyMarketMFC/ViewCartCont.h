#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include<string>
#include"DiagCheck.h"
#include"Node.h"
using namespace std;
// ViewCartCont dialog

class ViewCartCont : public CDialog
{
	DECLARE_DYNAMIC(ViewCartCont)
public:
	ViewCartCont(CWnd* pParent = NULL);   // standard constructor
	~ViewCartCont();
	CListCtrl* lstItemCart;
	LVCOLUMN* lcln;
	LVITEM* addItem;
	CString stN, Qt, Dsc, prEa ,ext;
	void fromForm(ViewCartCont &,CString, CString, CString, CString);
	MyItemNode* headCart=nullptr;
	MyItemNode* headInventory=nullptr;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ViewCart };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl myItems;
	BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListItem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAdditem();
	afx_msg void OnBnClickedChkout();
	afx_msg void OnBnClickedRemove();
	afx_msg void OnBnClickedOk();
};
