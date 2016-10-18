#include "Barang.h"

Barang::Barang()
{
}

void Barang::SetnamaBarang(wxString namaBarang)
{
	this->namaBarang = namaBarang;
}

void Barang::SetnomorBarang(wxString nomorBarang)
{
	this->nomorBarang = nomorBarang;
}

void Barang::SettanggalBarang(wxString tanggalBarang)
{
	this->tanggalBarang = tanggalBarang;
}

void Barang::SetasalBarang(wxString asalBarang)
{
	this->asalBarang = asalBarang;
}

void Barang::SetjumlahBarang(wxString jumlahBarang)
{
	this->jumlahBarang = jumlahBarang;
}