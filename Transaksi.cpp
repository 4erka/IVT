#include "Transaksi.h"

Transaksi::Transaksi()
{
}

void Transaksi::SetidTransaksi(wxString idTransaksi)
{
	this->idTransaksi = idTransaksi;
}

void Transaksi::SetdebetTransaksi(wxString debetTransaksi)
{
	this->debetTransaksi = debetTransaksi;
}

void Transaksi::SetkreditTransaksi(wxString kreditTransaksi)
{
	this->kreditTransaksi = kreditTransaksi;
}

void Transaksi::SetketeranganTransaksi(wxString keteranganTransaksi)
{
	this->keteranganTransaksi = keteranganTransaksi;
}