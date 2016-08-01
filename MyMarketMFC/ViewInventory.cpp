// ViewInventory.cpp : implementation file
//

#include "stdafx.h"
//#include "MyMarketMFC.h"
#include "ViewInventory.h"
#include "afxdialogex.h"
#include"resource1.h"

// ViewInventory dialog

IMPLEMENT_DYNAMIC(ViewInventory, CDialog)

ViewInventory::ViewInventory(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ViewLISTItEms, pParent)
{
	headCart = nullptr;
	headInventory = nullptr;
}

ViewInventory::~ViewInventory()
{
	MyItemNode* currentNode = headInventory;
	MyItemNode* currentNode2 = headCart;
	while (currentNode != nullptr) {
		MyItemNode* oldNode = currentNode->nextInventItem;
		delete currentNode;
		currentNode = oldNode;
	}
	while (currentNode2 != nullptr) {
		MyItemNode* oldNode2 = currentNode2->nextCustItem;
		delete currentNode2;
		currentNode2 = oldNode2;
	}
}

void ViewInventory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTInventory, *MyInVentory);
}


BEGIN_MESSAGE_MAP(ViewInventory, CDialog)
	ON_BN_CLICKED(IDC_AddITems, &ViewInventory::OnBnClickedAdditems)
	ON_BN_CLICKED(IDC_BUTTON2, &ViewInventory::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_ViewCart, &ViewInventory::OnBnClickedViewcart)
	ON_BN_CLICKED(IDC_CheckOutBut, &ViewInventory::OnBnClickedCheckoutbut)
	ON_COMMAND(IDD_Vcart, &ViewInventory::OnIddVcart)
END_MESSAGE_MAP()
void ViewInventory::listInventory(MyItemNode* nStock) {
	MyItemNode* stock;
	for (int i = 0; i < 10; i++) {
		nStock = new MyItemNode;
		nStock->item = this->myStock[i];
		nStock->nextInventItem = nullptr;
		nStock->nextCustItem = nullptr;
		if (!this->headInventory) {
			this->headInventory = nStock;
		}
		else {
			stock = this->headInventory;
			while (stock->nextInventItem)
				stock = stock->nextInventItem;
			stock->nextInventItem = nStock;
		}
	}
}
BOOL ViewInventory::OnInitDialog() {
	int col;
	int itm;
	MyInVentory = new CListCtrl;
	CDialog::OnInitDialog();
	lcln = new LVCOLUMN;
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Stock number";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 120;
	col = MyInVentory->InsertColumn(0, lcln);

	//////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Quantity";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 100;
	MyInVentory->InsertColumn(1, lcln);

	////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Description";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 80;
	MyInVentory->InsertColumn(2, lcln);
	/////////////////////////////
	lcln->mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lcln->pszText = "Price Per Each";
	lcln->fmt = LVCFMT_LEFT;
	lcln->cx = 75;
	string stNum, qtt, des;
	string price;
	col = MyInVentory->InsertColumn(3, lcln);
	///////////////////////////////
	lvItem = new LVITEM;
	myItem = new MyItemNode();
	this->listInventory(myItem);//create my node list inventory
	MyItemNode* myItem1;
	myItem1 = headInventory;
	if (!myItem1)
		AfxMessageBox(_T("SORRY STORE IS EMPTY "));
	else {
		while (myItem1) {
			lvItem->mask = LVIF_TEXT;
			lvItem->iItem = 0;
			lvItem->iSubItem = 0;
			stNum = myItem1->item.stockNum;
			lvItem->pszText = const_cast<char *>(stNum.c_str());
			itm = MyInVentory->InsertItem(lvItem);
			qtt = to_string(myItem1->item.qtte);
			MyInVentory->SetItemText(itm, 1, qtt.c_str());
			des = myItem1->item.descr;
			MyInVentory->SetItemText(itm, 2, des.c_str());
			price = to_string(myItem1->item.eachPrice);
			MyInVentory->SetItemText(itm, 3, const_cast<char *>(price.c_str()));
			myItem1 = myItem1->nextInventItem;
		}
	}
	delete lcln;
	delete lvItem;
	return TRUE;
}
// ViewInventory message handlers


void ViewInventory::OnBnClickedAdditems()
{
	lvItem = new LVITEM;
	myItem = new MyItemNode();
	string stNum, qtt, des;
	string price;
	MyItemNode* myItem1;
	long respo;
	do {
		
			MyD addItmForm1;
		if (addItmForm1.DoModal()) {
			Item myItms;
			myItms.stockNum = addItmForm1.m_StocN;
			myItms.eachPrice = _tstof(addItmForm1.m_Each);
			myItms.descr = addItmForm1.m_Descr;
			myItms.qtte = _tstof(addItmForm1.m_Qtty);
			if (this->addCartNode(myItms)) {
				this->verify = true;
				double ext = _tstof(addItmForm1.m_Qtty)*_tstof(addItmForm1.m_Each);
				string thisEx = to_string(ext);
				this->viewCart.stN = addItmForm1.m_StocN;
				this->viewCart.Qt = addItmForm1.m_Qtty;
				this->viewCart.Dsc = addItmForm1.m_Descr;
				this->viewCart.prEa = addItmForm1.m_Each;
				this->viewCart.ext = thisEx.c_str();
				//this->viewCart.fromForm(this->viewCart,addItmForm1.m_StocN, addItmForm1.m_Qtty, addItmForm1.m_Descr, addItmForm1.m_Each);
			}
		}
		
		respo = MessageBox("Do you want to do another purchase?","Closing", MB_ICONQUESTION | MB_YESNO);
	} while (respo == IDYES);
	myItem1 = headInventory;
	if (this->verify) {
		MyInVentory->DeleteAllItems();//delete the all items 
		//MyInVentory = new CListCtrl;
		if (!myItem1)
			AfxMessageBox(_T("SORRY STORE IS EMPTY "));
		else {
			while (myItem1) {
				lvItem->mask = LVIF_TEXT;
				lvItem->iItem = 0;
				lvItem->iSubItem = 0;
				stNum = myItem1->item.stockNum;
				lvItem->pszText = const_cast<char *>(stNum.c_str());
				int itm = MyInVentory->InsertItem(lvItem);
				qtt = to_string(myItem1->item.qtte);
				MyInVentory->SetItemText(itm, 1, qtt.c_str());
				des = myItem1->item.descr;
				MyInVentory->SetItemText(itm, 2, des.c_str());
				price = to_string(myItem1->item.eachPrice);
				MyInVentory->SetItemText(itm, 3, const_cast<char *>(price.c_str()));
				myItem1 = myItem1->nextInventItem;
			}
		}
	}

}


void ViewInventory::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


void ViewInventory::OnBnClickedViewcart()
{
	this->viewCart.DoModal();
}


void ViewInventory::OnBnClickedCheckoutbut()
{
	MyItemNode* Items = nullptr;
	Items = this->checkForm.checkHeadCart;
	double totExt = 0.0;
	double total;
	while (Items) {
		totExt += (Items->item.qtte*Items->item.eachPrice);
		Items = Items->nextCustItem;
	}
	total = totExt*0.0625 + 9.95+totExt;
	if (totExt > 0) {
		this->checkForm.m_shipping = "9.95";
		this->checkForm.m_tax = to_string(totExt*0.0625).c_str();
		this->checkForm.m_total = to_string(total).c_str();
	}
	this->checkForm.DoModal();
	AfxMessageBox(_T("Thank you for your Purchase"));
}
BOOL ViewInventory::checkStoreItems(string sNum, MyItemNode *prcNode, int &qt) {
	if (!prcNode)return false;

	else {
		while (prcNode) {
			if ((prcNode->item.stockNum == sNum))
				break;
			prcNode = prcNode->nextInventItem;

		}
		if (prcNode == nullptr) {
			AfxMessageBox(_T("we don't have that item in stock"));
			return FALSE;

		}
		if (prcNode) {
			if (prcNode->item.qtte == 0) {
				AfxMessageBox(_T("SORRY WE ARE OUT OF STOCK FOR THIS ITEM"));
				return false;
			}
			if (prcNode->item.qtte <= qt) {
				AfxMessageBox(_T("quantity in stock is not enough for your order"));
				return false;
			}
			prcNode->item.qtte -= qt;
			return true;
		}

	}

}
bool ViewInventory::addCartNode(Item customerItem) {
	MyItemNode *custNode=nullptr, *parNode=nullptr;
	custNode = new MyItemNode;
	custNode->item = customerItem;
	custNode->nextInventItem = nullptr;
	custNode->nextCustItem = nullptr;
	if (checkStoreItems(customerItem.stockNum, this->headInventory, customerItem.qtte)) {
		if (!headCart) {
			this->viewCart.headCart = custNode;
			this->checkForm.checkHeadCart = custNode;
			headCart = custNode;
			AfxMessageBox(_T("Items added to the cart"));
			return true;
		}
		else {
			parNode = headCart;
			while (parNode->nextCustItem)
				parNode = parNode->nextCustItem;
			parNode->nextCustItem = custNode;
			AfxMessageBox(_T("Items added to the cart"));
			return true;
		}
	}
	delete custNode;
}


void ViewInventory::OnIddVcart()
{
	// TODO: Add your command handler code here
}
