#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
#include "Barang.h"
#include <wx/arrimpl.cpp>

class Barang;
WX_DECLARE_OBJARRAY(Barang*, GridBarangArray);
class GridBarang : public wxGrid
{
private:
	int jumlahdata;
	Barang *barang;
	GridBarangArray barangs;
	int temp;
public:
	GridBarang(wxPanel *parent);
	//void SetGridArray(Barang* a);
//	void Insert(Barang* a);
//	void Update();
//	void Delete(Barang* a);
//	void Print();
};//


