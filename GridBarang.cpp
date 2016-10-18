#include "GridBarang.h"
//WX_DEFINE_OBJARRAY(BarangArray);
WX_DEFINE_OBJARRAY(GridBarangArray);
GridBarang::GridBarang(wxPanel * parent)
	: wxGrid(parent, wxID_ANY)
{
	CreateGrid(300, 5);
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 5;j++) {
			SetReadOnly(i,j);
		}
	}
	
	SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	SetColLabelValue(0, _("          Nomor          "));
	SetColLabelValue(1, _("          Tanggal          "));
	SetColLabelValue(2, _("                              Nama                              "));
	SetColLabelValue(3, _("                                                                                                          Asal                                                                                                         "));
	SetColLabelValue(4, _("       Jumlah       "));
	SetRowLabelSize(1);
	//AutoSize();
	//AppendRows(4);
	//SelectRow(0);
	/*wxArrayInt 	GetSelectedCols() const
	Returns an array of selected columns.More...

	wxArrayInt 	GetSelectedRows() const
	Returns an array of selected rows.More...
	*/
	//SetCellSize(0, 0, 1, 3);
	//SetReadOnly(0, 0);
	//SetCellAlignment(wxALIGN_CENTER, 0, 0);

	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT,
		wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	//Fit();
	//MakeCellVisible(3,3);
	//SetScrollLineX(30);
	AutoSize();
}
/*
void GridBarang::Insert(Barang* a) {
	barangs.Add(barang);
	wxMessageOutputDebug().Printf("%s", "insert");
}
void GridBarang::Update() {
	for (int i = 0; i < barangs.GetCount(); i++)
	{
		//Barang *bra = barangs[i];
		//grid->Update(bra);
		SetCellValue(i, 1, barangs[i]->tanggalBarang);
		SetCellValue(i, 2, barangs[i]->namaBarang);
		SetCellValue(i, 3, barangs[i]->asalBarang);
		SetCellValue(i, 4, barangs[i]->jumlahBarang);
	}
	//wxMessageOutputDebug().Printf("%d", barangs.GetCount());
}
void GridBarang::Delete(Barang* a) {
	for (unsigned int i = 0; i < barangs.GetCount(); i++)
	{
		Barang *bra = barangs[i];
		if (a->nomorBarang == bra->nomorBarang) {
			barangs.Detach(i);
		}
	}
}
void GridBarang::Print() {
	temp += 1;
	wxMessageOutputDebug().Printf("%d", temp);
}
*/