#pragma once
#include"wx/wx.h"
#include <wx/arrimpl.cpp>
#include"Barang.h"

WX_DECLARE_OBJARRAY(Barang*, BarangArraySearch);

class SearchBarang : public wxFrame
{
private:
	wxComboBox *searchingz; //Untuk memilih kolom apa yang akan dicari
	wxTextCtrl *searchingzz; //tempat input kata yang akan dicari
	wxButton *cari;
	unsigned int i = 0;
	Barang *barangthis;
	BarangArraySearch barangsearch;
	int baris;
	int kolom;
public:
	SearchBarang();
	~SearchBarang();
	int GetBaris();//Mendapatkan posisi baris barang yang dicari
	int GetKolom();//Mendapatkan posisi kolom barang yang dicari
	void OnSearching(wxCommandEvent & event);//Fungsi untuk mencari
	void SetSearchArray(wxString a, wxString b, wxString c, wxString d, wxString e); //Set barangsearch
	const int tombol_cari = 909;
};
