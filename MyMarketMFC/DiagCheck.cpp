// DiagCheck.cpp : implementation file
//

#include "stdafx.h"
//#include "MyMarketMFC.h"
#include "DiagCheck.h"
#include "afxdialogex.h"



// DiagCheck dialog

IMPLEMENT_DYNAMIC(DiagCheck, CDialog)

DiagCheck::DiagCheck(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIAL_CkOut, pParent)
	, m_Address(_T(""))
	, m_FullName(_T(""))
	, m_shipping(_T(""))
	, m_tax(_T(""))
	, m_total(_T(""))
{

}

DiagCheck::~DiagCheck()
{
}

void DiagCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, cancelBut);
	DDX_Text(pDX, IDC_Adress, m_Address);
	DDV_MaxChars(pDX, m_Address, 50);
	DDX_Text(pDX, IDC_FullName, m_FullName);
	DDX_Text(pDX, IDC_Shipping, m_shipping);
	DDX_Text(pDX, IDC_Tax, m_tax);
	DDV_MaxChars(pDX, m_tax, 10);
	DDX_Text(pDX, IDC_Total, m_total);
	DDV_MaxChars(pDX, m_total, 10);
	DDX_Control(pDX, IDC_LstChK, Clistr);
	//DDX_Text(pDX, ID_StN, name);
}


BEGIN_MESSAGE_MAP(DiagCheck, CDialog)
	ON_BN_CLICKED(IDOK, &DiagCheck::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DiagCheck::OnBnClickedCancel)
END_MESSAGE_MAP()


// DiagCheck message handlers


void DiagCheck::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void DiagCheck::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
BOOL DiagCheck::OnInitDialog() {
	int col;
	MyItemNode* myItems = nullptr;
	myItems = this->checkHeadCart;
	CDialog::OnInitDialog();
	////////////////////////
	cln = new LVCOLUMN;
	item = new LVITEM;
	//lstItemCart = new CListCtrl;
	cln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	cln->pszText = "Description";
	cln->fmt = LVCFMT_LEFT;
	cln->cx = 120;
	col = Clistr.InsertColumn(0, cln);
	cln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	cln->pszText = "Quantity";
	cln->fmt = LVCFMT_LEFT;
	cln->cx = 80;
	Clistr.InsertColumn(1, cln);
	//////////////////////////////
	cln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	cln->pszText = "price each";
	cln->fmt = LVCFMT_LEFT;
	cln->cx = 100;
	Clistr.InsertColumn(2, cln);

	///////////////////////////////
	cln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	cln->pszText = "Extension";
	cln->fmt = LVCFMT_LEFT;
	cln->cx = 75;
	col = Clistr.InsertColumn(3, cln);
	if (!myItems)
		AfxMessageBox(_T("NO ITEM TO CHECK OUT"));
	else {
		while (myItems) {
			//this->stN = thisItems->item.stockNum.c_str();
			this->qtt = to_string(checkHeadCart->item.qtte).c_str();
			this->dscp = myItems->item.descr.c_str();
			this->eacP = to_string(myItems->item.eachPrice).c_str();
			int itm;
			double ext = _tstof(this->qtt)*_tstof(this->eacP);
			string thisEx = to_string(ext);
			this->ex = thisEx.c_str();
			item->mask = LVIF_TEXT;
			item->iItem = 0;
			item->iSubItem = 0;
			item->pszText = this->dscp.GetBuffer(this->dscp.GetLength());
			itm = Clistr.InsertItem(item);
			//Clistr.SetItemText(itm, 1, this->name);
			Clistr.SetItemText(itm, 1, this->qtt);
			Clistr.SetItemText(itm, 2, this->eacP);
			Clistr.SetItemText(itm, 3, this->ex);
			myItems = myItems->nextCustItem;
		}
	}
	return TRUE;
}