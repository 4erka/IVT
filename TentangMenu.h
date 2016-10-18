#pragma once
#include "wxImagePanel.h"
#include <wx/wx.h>
class TentangMenu : public wxFrame
{
private:
	wxImagePanel *MainPanel;
	wxStaticText *judul;
	wxStaticText *deskripsi;
	wxButton *close;
public:
	TentangMenu();
	void Keluar(wxCommandEvent & event);
};

