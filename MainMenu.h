#pragma once
#include "wxImagePanel.h"
#include "BarangMenu.h"
#include "TentangMenu.h"
#include "PembukuanMenu.h"
#include <wx/wx.h>
#include "wx/statbmp.h"
#pragma warning(disable:4996)
class MainMenu : public wxFrame
{
private:
	wxPanel *toolbar;
	wxPanel *right;
	wxPanel *left;
	wxToolBar *toolbar1;
	wxToolBar *toolbar2;
	BarangMenu *barangframe;
	TentangMenu *tentangframe;
	PembukuanMenu *pembukuanframe;
	wxStaticBitmap* staticBitmap;
public:
	MainMenu();
	~MainMenu();
	void Barang(wxCommandEvent & event);
	void Pembukuan(wxCommandEvent & event);
	void Tentang(wxCommandEvent & event);
	void Keluar(wxCommandEvent & event);
	const int ID_BARANG = 101;
	const int ID_PEMBUKUAN = 102;
	const int ID_TENTANG = 103;
	const int ID_KELUAR = 104;
};

