#pragma once
#include <wx/wx.h>
class Barang
{
public:
	Barang();
	wxString namaBarang;
	wxString nomorBarang;
	wxString tanggalBarang;
	wxString asalBarang;
	wxString jumlahBarang;
	void SetnamaBarang(wxString namaBarang);
	void SetnomorBarang(wxString nomorBarang);
	void SettanggalBarang(wxString tanggalBarang);
	void SetasalBarang(wxString asalBarang);
	void SetjumlahBarang(wxString jumlahBarang);
};