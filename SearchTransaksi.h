#pragma once
#include"wx/wx.h"
#include <wx/arrimpl.cpp>
#include"Transaksi.h"

WX_DECLARE_OBJARRAY(Transaksi*, TransaksiArraySearch);

class SearchTransaksi :public wxFrame
{
private:
	wxComboBox *searchingz; //Untuk memilih kolom apa yang akan dicari
	wxTextCtrl *searchingzz; //tempat input kata yang akan dicari
	wxButton *cari;
	unsigned int i = 0;
	Transaksi *transaksithis;
	TransaksiArraySearch transaksisearch;
	int baris;
	int kolom;
public:
	SearchTransaksi();
	~SearchTransaksi();
	int GetBaris();//Mendapatkan posisi baris barang yang dicari
	int GetKolom();//Mendapatkan posisi kolom barang yang dicari
	void OnSearching(wxCommandEvent & event);//Fungsi untuk mencari
	void SetSearchArray(wxString a, wxString b, wxString c); //Set barangsearch
	const int tombol_cari = 910;
};
