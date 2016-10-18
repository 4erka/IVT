#include "GridPembukuan.h"


GridPembukuan::GridPembukuan(wxPanel * parent)
	: wxGrid(parent, wxID_ANY)
{
	CreateGrid(30, 4);
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 4;j++) {
			SetReadOnly(i, j);
		}
	}
	SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	SetColLabelValue(0, _("          ID          "));
	SetColLabelValue(1, _("                              Debit                              "));
	SetColLabelValue(2, _("                              Kredit                              "));
	SetColLabelValue(3, _("                                                                                                          Keterangan                                                                                                         "));
	SetRowLabelSize(1);
	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT,
		wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	AutoSize();
}