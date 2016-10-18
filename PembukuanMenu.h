#pragma once
#include "wxImagePanel.h"
#include <wx/wx.h>
#include "GridPembukuan.h"
#include "wx/textfile.h"
#include <iostream>
#include <fstream>
#include "wx/combobox.h"
#include "Transaksi.h"
#pragma warning(disable:4996)
#include <wx/arrimpl.cpp>
#include "SearchTransaksi.h"

class Transaksi;
WX_DECLARE_OBJARRAY(Transaksi*, TransaksiArray);
class PembukuanMenu : public wxFrame
{
private:
	wxToolBar *toolbar1;//toolbar
	wxStaticBitmap* staticBitmap; //untuk menampung gambar judul yg ada di Left Panel
	wxStaticBitmap* staticBitmap2; //untuk menampung gambar footer yg ada di Left Panel
	wxFlexGridSizer *fgs; //sizer penampung kolom-kolom input + keterangannya
	wxStaticText *id;
	wxStaticText *keterangan;
	wxStaticText *nominal;
	wxStaticText *jenis;
	wxButton *Add;
	wxStaticText *dump;//text berupa spasi . spasi ini berada sebelum tombol AddGudang
	wxPanel *ToolbarPanel;//Panel untuk toolbar
	wxPanel *RightPanel; // panel kanan
	wxPanel *LeftPanel; //panel kiri
	wxTextCtrl *i_id; //kolom input id
	wxTextCtrl *i_keterangan; //kolom input keterangan
	wxTextCtrl *i_nominal; // kolom input nominal
	wxComboBox* i_jenis; // kolom memilih jenis transaksi
	GridPembukuan *grid;
	Transaksi *transaksi;
	Transaksi *transaksiprint;
	TransaksiArray transaksis;
	SearchTransaksi *searchin;
	int jml_data;
	int jumlahdebit;
	int jumlahkredit;
public:
	PembukuanMenu();
	~PembukuanMenu();
	void OnOpen(wxCommandEvent & event);
	void OnSave(wxCommandEvent& event);
	void OnEdit(wxCommandEvent & event);
	void OnSort(wxCommandEvent& event);
	void OnSorting(wxCommandEvent& event);
	void OnSearch(wxCommandEvent & event);
	void OnSearching(wxCommandEvent & event);
	void OnAddClick(wxCommandEvent& event);
	void OnQuit(wxCommandEvent & event);
	const int open = 8;
	const int save = 9;
	const int edit = 10;
	const int sort = 11;
	const int search = 12;
	const int insert = 13;
	const int back = 14;
};
