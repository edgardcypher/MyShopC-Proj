// MyD.cpp : implementation file
//
#include<string>
#include "stdafx.h"
//#include "MyMarketMFC.h"
#include "MyD.h"
#include"resource1.h"
#include "afxdialogex.h"
using namespace std;

// MyD dialog

IMPLEMENT_DYNAMIC(MyD, CDialog)

MyD::MyD(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALO)
	, m_Qtty(_T(""))
	, m_Each(_T(""))
	, m_StocN(_T(""))
	, m_Descr(_T(""))
{
	
}

MyD::~MyD()
{
}

void MyD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, ed3);
	DDX_Control(pDX, IDC_EDIT5, ed5);
	DDX_Control(pDX, IDC_COMBO1, m_stNum);
	DDX_Control(pDX, IDC_COMBO2, m_des);
	//  DDX_Text(pDX, IDC_EDIT3, m_stNumb);
	//  DDV_MaxChars(pDX, m_stNumb, 10);
	//  DDX_Text(pDX, IDC_EDIT5, m_eacPr);
	//  DDV_MinMaxDouble(pDX, m_eacPr, 0.0, 100.0);
	DDX_Text(pDX, IDC_EDIT3, m_Qtty);
	DDV_MaxChars(pDX, m_Qtty, 5);
	DDX_Text(pDX, IDC_EDIT5, m_Each);
	DDV_MaxChars(pDX, m_Each, 5);
	DDX_CBString(pDX, IDC_COMBO1, m_StocN);
	DDV_MaxChars(pDX, m_StocN, 50);
	DDX_CBString(pDX, IDC_COMBO2, m_Descr);
}


BEGIN_MESSAGE_MAP(MyD, CDialog)
//	ON_BN_CLICKED(IDC_BUTTON1, &MyD::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyD::OnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT3, &MyD::OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &MyD::OnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON1, &MyD::OnClickedAddBut)
END_MESSAGE_MAP()


// MyD message handlers



void MyD::OnClickedCancel()
{
	CDialog::OnCancel();
}


void MyD::OnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyD::OnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyD::OnClickedAddBut()
{ 
	CDialog::OnOK();
	/*this->myView = new ViewCartCont();
	this->myView->addItem = new LVITEM();
	this->myView->addItem->mask = LVIF_TEXT;
	this->myView->addItem->iItem = 0;
    this->myView->addItem->iSubItem = 0;
	this->myView->addItem->pszText = this->m_StocN.GetBuffer(this->m_StocN.GetLength());
	int itm = this->myView->myItems.InsertItem(this->myView->addItem);
	//this->myView->myItems.SetItemText(itm, 1, this->m_Qtty);
	//this->myView->myItems.SetItemText(itm, 2, this->m_Descr);
	//this->myView->myItems.SetItemText(itm, 3, this->m_Each);
	//this->myView->myItems.SetItemText(itm, 4, "12"); 

	this->m_stNum.GetWindowTextA(this->m_StocN);
	myView->stN ="Edgard";
	this->ed3.GetWindowTextA(this->m_Qtty);
	myView->Qt = this->m_Qtty;
	this->m_des.GetWindowTextA(this->m_Descr);
	myView->Dsc = this->m_Descr;
	this->ed5.GetWindowTextA(this->m_Each);
	myView->prEa = this->m_Each;
	//SetDlgItemInt(myView->stN,this->m_Qt);
	/*this->m_StocN.GetWindowTextW(myView->stN);
	SetDlgItemTextW(myView->stN,m_StocN);
	myView->Qt= GetDlgItemInt(IDC_EDIT5);
	myView->Dsc = GetDlgItemInt(IDC_COMBO1); 
    myView->prEa = GetDlgItemInt(IDC_COMBO2);
	/int itm;
	string thisQt =to_string(qt);
	string thisPr = to_string(price);
	string thisSN = to_string(stN);
	string thisDesc = to_string(desc);
	double ext = (double)qt*(double)price;
	string thisEx = to_string(ext);
	lv = new LVITEM;
	ltCtl=new CListCtrl;
	lv->mask = LVIF_TEXT;
	lv->iItem = 0;
	lv->iSubItem = 0;
	lv->pszText = const_cast<char *>(thisSN.c_str());
	itm = ltCtl->InsertItem(lv);
	ltCtl->SetItemText(itm, 1, thisQt.c_str());
	ltCtl->SetItemText(itm, 2, thisDesc.c_str());
	ltCtl->SetItemText(itm, 3, const_cast<char *>(thisPr.c_str()));
	ltCtl->SetItemText(itm, 4, const_cast<char *>(thisEx.c_str()));*/
	//myView = new ViewCartCont();
	//myView.addCart(thisSN, thisQt, thisDesc, thisPr, thisEx);

}
BOOL MyD::OnInitDialog()
{
	string sn[] = { "A100","A250","B400","C888", "A499","C667","B875","D547","A910","B123" };
	string des[] = { "Hammer","Saw","Flat-Head Nails","Flat-Head Screwdriver",
		"Pliers", "Drill","Plumber's Wrench","Ladder 10 foot" ,"Flashlight 10 inch","Assorted Buss Fuses" };
	CDialog::OnInitDialog();
	for (int i = 0; i < 10; i++) {
		m_stNum.AddString(sn[i].c_str());
		m_des.AddString(des[i].c_str());
	}



	return TRUE;
}