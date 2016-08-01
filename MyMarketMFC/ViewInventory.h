#pragma once
#include "afxcmn.h"
#include<string>
#include"MyD.h"
#include"ViewCartCont.h"
#include"DiagCheck.h"
#include"Node.h"
using namespace std;
/*struct Item {
	string stockNum;
	int qtte;
	string descr;
	double eachPrice;

};

struct MyItemNode {
	Item item;
	MyItemNode* nextInventItem;
	MyItemNode* nextCustItem;

};*/
// ViewInventory dialog

class ViewInventory : public CDialog
{
	DECLARE_DYNAMIC(ViewInventory)

public:
	ViewInventory(CWnd* pParent = NULL);   // standard constructor
	 ~ViewInventory();
	Item myStock[10] = {
		{ "A100", 20, "Hammer", 9.95 },
		{ "A250", 25, "Saw", 13.95 },
		{ "B400", 50, "Flat-Head Nails", 11.99 },
		{ "C888", 50, "Flat-Head Screwdriver", 6.59 },
		{ "A499", 75, "Pliers", 4.95 },
		{ "C667", 50, "Drill", 22.95 },
		{ "B875", 70, "Plumber's Wrench", 11.90 },
		{ "D547", 60, "Ladder 10 foot", 70.44 },
		{ "A910", 85, "Flashlight 10 inch", 9.99 },
		{ "B123", 90, "Assorted Buss Fuses", 4.99 }
	};
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ViewLISTItEms };
#endif
public:
	MyItemNode* headCart;
	MyItemNode* headInventory;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl* MyInVentory, MyInVentory1;
	MyItemNode* myItem1, *myItem2;
	bool verify = false;
	BOOL OnInitDialog();
	LVCOLUMN* lcln;
	LVITEM*  lvItem;
	MyItemNode* myItem;
	void listInventory(MyItemNode*);
	bool addCartNode(Item);
	BOOL checkStoreItems(string, MyItemNode *, int &);
	afx_msg void OnBnClickedAdditems();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedViewcart();
	afx_msg void OnBnClickedCheckoutbut();
	DiagCheck checkForm;
	MyD addItmForm;
	ViewCartCont viewCart;
	afx_msg void OnIddVcart();
};
