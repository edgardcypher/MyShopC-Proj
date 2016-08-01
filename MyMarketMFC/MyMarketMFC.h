#pragma once
#include<afxwin.h>
#include<ostream>
#include<afxcmn.h>
#include<sstream>
#include <strstream> 
#include<iostream>
#include<string>
const int IDC_ED1 = 100;
const int IDC_ED2 = 101; 
const int IDC_ED3 = 102; 
const int IDC_RESULT = 103;
const int IDC_BUTTON = 104;
const int IDC_BUTTON2 = 105;
const int ID_MEN1 = 106;
const int ID_MEN2 = 107;
const int ID_MEN3 = 108;
const int ID_MEN4 = 109;
const int ID_MEN5 = 110;
const int ID_DIAG = 111;
const int IDC_LISTCONT = 112;
const int ID_TEXT = 113;
using namespace std;
class MyWind :public CWinApp{
public:
	virtual BOOL InitInstance();

};
class CWindow :public CFrameWnd {
public:
	CWindow();
	//afx_msg void HandleViewInventory();
	//afx_msg void HandleCheckOutBut();
	//afx_msg void HandleAddCartBut();
	afx_msg void HandleViewInventory();
	afx_msg void HandleQuitBut();
	//void listInventory(MyItemNode*);
	CMenu* m_wndMainMenu;//variable of type CMenu will be used to create my menu
	
	DECLARE_MESSAGE_MAP();
	virtual BOOL PreTranslateMessage(MSG *msg);
	~CWindow() {
	}
};
BOOL CWindow::PreTranslateMessage(MSG *msg) {
	return ::IsDialogMessage(m_hWnd, msg);
}
BEGIN_MESSAGE_MAP(CWindow, CFrameWnd)
	//ON_COMMAND(ID_MEN1, HandleViewInventory)
	//ON_COMMAND(ID_MEN2, HandleAddCartBut)
	ON_COMMAND(ID_MEN3, HandleViewInventory)
	//ON_COMMAND(ID_MEN4, HandleCheckOutBut)
	ON_COMMAND(ID_MEN5, HandleQuitBut)
END_MESSAGE_MAP()