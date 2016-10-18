#pragma once
#include "wxImagePanel.h"
#include <wx/wx.h>
#include "GridBarang.h"
#include "Barang.h"
#include "wx/textfile.h"
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
#include <wx/arrimpl.cpp>
#include "SearchBarang.h"

class Barang;
WX_DECLARE_OBJARRAY(Barang*, BarangArray);
class BarangMenu : public wxFrame
{
private:
	wxStaticBitmap* staticBitmap; //untuk menampung gambar judul yg ada di Left Panel
	wxStaticBitmap* staticBitmap2; //untukmnampung gambar footer yg ada di Left Panel
	wxStaticText *gudang_number;
	wxStaticText *gudang_condition;
	wxStaticText *gudang_name;
	wxStaticText *gudang_source;
	wxStaticText *gudang_amount;
	wxButton *AddGudang;
	wxStaticText *dump; //text berupah spasi . spasi ini berada sebelum tombol AddGudang
	wxPanel *ToolbarPanel;//panelnya toolbar
	wxPanel *RightPanel;//panel sebelah kanan
	wxPanel *LeftPanel;//panel sebelah kiri
	wxTextCtrl *i_nomor;//Kolom Input Nomor
	wxTextCtrl *i_nama;//Kolom Input nama
	wxTextCtrl *i_asal;//Kolom input asal
	wxTextCtrl *i_jumlah;// Kolom input jumlah
	wxTextCtrl *i_tanggal;// Kolom input tanggal
	GridBarang *grid;//deklarasi grid barang
	Barang *barang;
	Barang *barangprint;
	BarangArray barangs;//arraybarnag
	int jml_data;
	SearchBarang *searchin;
public:
	BarangMenu();
	~BarangMenu();
	void OnOpen(wxCommandEvent & event);
	void OnSave(wxCommandEvent& event);
	void OnEdit(wxCommandEvent & event);
	void OnSort(wxCommandEvent& event);
	void OnSearch(wxCommandEvent & event);
	void OnAddClick(wxCommandEvent& event);
	void OnQuit(wxCommandEvent & event);
	const int open = 1;
	const int save = 2;
	const int edit = 3;
	const int sort = 4;
	const int search = 5;
	const int insert = 6;
	const int back = 7;
	const int sorting = 8;
	const int searching = 9;
};