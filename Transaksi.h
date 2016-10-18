#pragma once
#include <wx/wx.h>
class Transaksi
{
public:
	Transaksi();
	wxString idTransaksi;
	wxString debetTransaksi;
	wxString kreditTransaksi;
	wxString keteranganTransaksi;
	void SetidTransaksi(wxString idTransaksi);
	void SetdebetTransaksi(wxString debetransaksi);
	void SetkreditTransaksi(wxString kreditTransaksi);
	void SetketeranganTransaksi(wxString keteranganTransaksi);
};