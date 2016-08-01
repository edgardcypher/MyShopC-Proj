// ViewCartCont.cpp : implementation file
//

#include "stdafx.h"
#include "ViewCartCont.h"
#include"ViewInventory.h"
#include "afxdialogex.h"
#include"resource1.h"
#include"MyD.h"

// ViewCartCont dialog

IMPLEMENT_DYNAMIC(ViewCartCont, CDialog)

ViewCartCont::ViewCartCont(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ViewCart, pParent)
{
	headCart = nullptr;
	headInventory = nullptr;
}

ViewCartCont::~ViewCartCont()
{
	/*MyItemNode* currentNode = headInventory;
	MyItemNode* currentNode2 = headCart;
	MyItemNode* oldNode = nullptr;
	MyItemNode* oldNode2 = nullptr;
	while (currentNode != nullptr) {
	oldNode = currentNode->nextInventItem;
		delete currentNode;
		currentNode = oldNode;
	}
	while (currentNode2 !=nullptr) {
		oldNode2 = currentNode2->nextCustItem;
		delete currentNode2;
		currentNode2 = oldNode2;
	}*/
}

void ViewCartCont::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ITEM, myItems);
}
BOOL ViewCartCont::OnInitDialog() {
	MyItemNode* thisItems=nullptr;
	thisItems =this->headCart;
	int col;
	MyD myForm;
	CDialog::OnInitDialog();
	////////////////////////
	lcln = new LVCOLUMN;
	//lstItemCart = new CListCtrl;
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Stock number";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 120;
	col = myItems.InsertColumn(0, lcln);
	//////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Quantity";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 100;
	myItems.InsertColumn(1, lcln);

	////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Description";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 80;
	myItems.InsertColumn(2, lcln);

	/////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Price Per Each";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 75;
	col = myItems.InsertColumn(3, lcln);
	///////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Extension";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 75;
	col = myItems.InsertColumn(4, lcln);
	if (!thisItems) {
		AfxMessageBox(_T("your cart is empty"));
	}
	else
	{
		while (thisItems) {
			addItem = new LVITEM;
			this->stN=thisItems->item.stockNum.c_str();
			this->Qt = to_string(thisItems->item.qtte).c_str();
			this->Dsc= thisItems->item.descr.c_str();
			this->prEa = to_string(thisItems->item.eachPrice).c_str();
			int itm;
			double ext = _tstof(this->Qt)*_tstof(this->prEa);
			string thisEx = to_string(ext);
			this->ext = thisEx.c_str();
			addItem->mask = LVIF_TEXT;
			addItem->iItem = 0;
			addItem->iSubItem = 0;
			addItem->pszText = this->stN.GetBuffer(this->stN.GetLength());
			itm = myItems.InsertItem(addItem);
			myItems.SetItemText(itm, 1, this->Qt);
			myItems.SetItemText(itm, 2, this->Dsc);
			myItems.SetItemText(itm, 3, this->prEa);
			myItems.SetItemText(itm, 4, this->ext);
			thisItems = thisItems->nextCustItem;
			delete addItem;
		}
	}
	delete lcln;
	
	return TRUE;
}
BEGIN_MESSAGE_MAP(ViewCartCont, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ITEM, &ViewCartCont::OnLvnItemchangedListItem)
	ON_BN_CLICKED(IDC_AddItem, &ViewCartCont::OnBnClickedAdditem)
	ON_BN_CLICKED(IDC_CHKOUT, &ViewCartCont::OnBnClickedChkout)
	ON_BN_CLICKED(IDC_Remove, &ViewCartCont::OnBnClickedRemove)
	ON_BN_CLICKED(IDC_OK, &ViewCartCont::OnBnClickedOk)
END_MESSAGE_MAP()


// ViewCartCont message handlers


void ViewCartCont::OnLvnItemchangedListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void ViewCartCont::OnBnClickedAdditem()
{
	MyD myForm;
	if (myForm.DoModal()) {
		this->stN = myForm.m_StocN;
		this->Qt = myForm.m_Qtty;
		this->Dsc = myForm.m_Descr;
		this->prEa = myForm.m_Each;
		CDialog::OnInitDialog();
		this->addItem = new LVITEM();
		this->addItem->mask = LVIF_TEXT;
		this->addItem->iItem = 0;
		this->addItem->iSubItem = 0;
		this->addItem->pszText = this->stN.GetBuffer(this->stN.GetLength());
		double ext = _tstof(this->Qt)*_tstof(this->prEa);
		string thisEx = to_string(ext);
		this->ext = thisEx.c_str();
		int itm = this->myItems.InsertItem(this->addItem);
		this->myItems.SetItemText(itm, 1, this->Qt);
		this->myItems.SetItemText(itm, 2, this->Dsc);
		this->myItems.SetItemText(itm, 3, this->prEa);
		this->myItems.SetItemText(itm, 4, this->ext);
		
		
		myItems.SetFocus();
	
	}
}

void ViewCartCont::fromForm(ViewCartCont &myCart,CString stN, CString Qt, CString Dsc, CString prEa)
{
		CDialog::OnInitDialog();
		myCart.addItem = new LVITEM();
		myCart.addItem->mask = LVIF_TEXT;
		myCart.addItem->iItem = 0;
		myCart.addItem->iSubItem = 0;
		myCart.addItem->pszText =stN.GetBuffer(stN.GetLength());
		double ext = _tstof(Qt)*_tstof(prEa);
		string thisEx = to_string(ext);
		myCart.ext = thisEx.c_str();
		int itm = this->myItems.InsertItem(myCart.addItem);
		myCart.myItems.SetItemText(itm, 1,Qt);
		myCart.myItems.SetItemText(itm, 2,Dsc);
		myCart.myItems.SetItemText(itm, 3, prEa);
		myCart.myItems.SetItemText(itm, 4, myCart.ext);


		myItems.SetFocus();
}
void ViewCartCont::OnBnClickedChkout()
{
	//CDialog::OnOK();
	DiagCheck ckOut;
		//CDialog::OnInitDialog();
		/*ckOut.item= new LVITEM();
		ckOut.item->mask = LVIF_TEXT;
		ckOut.item->iItem = 0;
		ckOut.item->iSubItem = 0;
		ckOut.item->pszText ="vjvnmmn";
		//double ext = _tstof(myForm.m_Qtty)*_tstof(myForm.m_Each);
		//string thisEx = to_string(ext);
		//int itm = ckOut.Clistr.InsertItem(ckOut.item);
		/*ckOut.Clistr.SetItemText(itm, 1,"fsdd");
		ckOut.Clistr.SetItemText(itm, 2, this->prEa);
		ckOut.Clistr.SetItemText(itm, 3, this->ext);*/
	ckOut.name="bvmbnv";
	//ckOut.Clistr.SetItemText(0, 1, this->myItems.GetItemText(0, 0));
	ckOut.DoModal();
	    
}


void ViewCartCont::OnBnClickedRemove()
{ 
}


void ViewCartCont::OnBnClickedOk()
{
	CDialog::OnOK();
}
