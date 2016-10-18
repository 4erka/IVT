#include "TentangMenu.h"

TentangMenu::TentangMenu()
	: wxFrame(NULL, -1, _("TENTANG"),wxDefaultPosition,wxDefaultSize)
{
	this->SetInitialSize(wxSize(600, 450));
	SetIcon(wxICON(about));
	MainPanel = new wxImagePanel(this, wxT("TentangMenu.png"), wxBITMAP_TYPE_PNG);
	this->Centre();
}