#include"MyMarketMFC.h"
#include<afxwin.h>
#include"resource1.h"
#include<afxdlgs.h>
//#include<string>
#include"ViewInventory.h"
using namespace std;
#define MAKEINTRESOURCE
CWindow::CWindow() {
	Create(NULL, "My Market");
	
	m_wndMainMenu = new CMenu();
	//m_wndMainMenu->LoadMenu(MAKEINTRESOURCE(IDR_FIRST));
	VERIFY(m_wndMainMenu->CreateMenu());//indicate i intend to create a menu
	//m_wndMainMenu->AppendMenu(MF_STRING, ID_MEN1, "View Inventory");
	//m_wndMainMenu->AppendMenu(MF_STRING, ID_MEN2, "Add Cart");
	m_wndMainMenu->AppendMenu(MF_STRING, ID_MEN3, "View Inventory");
	//m_wndMainMenu->AppendMenu(MF_STRING, ID_MEN4, "Check out");
	m_wndMainMenu->AppendMenu(MF_STRING, ID_MEN5, "Quit");
	int col;
	int itm;
	this->SetMenu(m_wndMainMenu);
	
}
BOOL MyWind::InitInstance() {
	m_pMainWnd = new CWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
void CWindow::HandleQuitBut() {
	int result = MessageBox("Are you sure\nyou want to quit(Y/N)? ", "Exiting!", MB_ICONQUESTION | MB_YESNO);
	if (result == IDYES)
	{
	  DestroyWindow();
	}
}
void CWindow::HandleViewInventory() {
	ViewInventory  viewInventory;
	viewInventory.DoModal();
}
MyWind mywind;