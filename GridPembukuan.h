#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
class GridPembukuan : public wxGrid
{
private:
	int jumlahdata;
public:
	GridPembukuan(wxPanel *parent);
};

