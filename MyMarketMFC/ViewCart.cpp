// ViewCart.cpp : implementation file
//

#include "stdafx.h"
//#include "MyMarketMFC.h"
#include "ViewCart.h"
#include "afxdialogex.h"
#include"resource1.h"


// ViewCart dialog

IMPLEMENT_DYNAMIC(ViewCart, CDialog)

ViewCart::ViewCart(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_Vcart, pParent)
{

}

ViewCart::~ViewCart()
{
}

void ViewCart::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ListVcart, thisItems);
}


BEGIN_MESSAGE_MAP(ViewCart, CDialog)
END_MESSAGE_MAP()


// ViewCart message handlers
