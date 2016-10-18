#include "SearchTransaksi.h"
WX_DEFINE_OBJARRAY(TransaksiArraySearch);

SearchTransaksi::SearchTransaksi()
	:wxFrame(NULL, -1, _("Cari Transaksi"), wxDefaultPosition, wxSize(300, 120))
{

	wxPanel *panel;
	wxArrayString temp;
	wxStaticText *pilih;
	wxStaticText *nilai;
	wxBoxSizer *top;
	wxBoxSizer *middle;
	wxBoxSizer *bottom;
	wxStaticText *dump;
	wxBoxSizer *main;
	transaksithis = new Transaksi();

	SetIcon(wxICON(ivt));
	panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColour(0, 162, 232));

	temp.Add(wxT("ID"));
	temp.Add(wxT("DEBET"));
	temp.Add(wxT("KREDIT"));
	pilih = new wxStaticText(panel, -1, wxT("PILIH                  :  "));
	nilai = new wxStaticText(panel, -1, wxT("NILAI                  :  "));
	pilih->SetForegroundColour(wxColor(*wxWHITE));
	nilai->SetForegroundColour(wxColor(*wxWHITE));
	searchingz = new wxComboBox(panel, -1, wxT(" "), wxDefaultPosition, wxDefaultSize,
		temp, wxCB_DROPDOWN);
	searchingzz = new wxTextCtrl(panel, -1);
	top = new wxBoxSizer(wxHORIZONTAL);
	top->Add(pilih, 1, wxEXPAND | wxALL);
	top->Add(searchingz, 6, wxEXPAND | wxALL);
	middle = new wxBoxSizer(wxHORIZONTAL);
	middle->Add(nilai, 1, wxEXPAND | wxALL);
	middle->Add(searchingzz, 6, wxEXPAND | wxALL);
	bottom = new wxBoxSizer(wxHORIZONTAL);
	cari = new wxButton(panel, tombol_cari, wxT("CARI"), wxDefaultPosition);
	cari->SetBackgroundColour(wxColour(209, 209, 209));
	dump = new wxStaticText(panel, -1, wxT("                              "));
	bottom->Add(dump);
	bottom->Add(cari);
	main = new wxBoxSizer(wxVERTICAL);
	main->Add(top);
	main->Add(middle);
	main->Add(bottom);
	panel->SetSizer(main);
	Connect(tombol_cari, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(SearchTransaksi::OnSearching));
}
SearchTransaksi::~SearchTransaksi() {
	delete searchingz;
	delete searchingzz;
	delete cari;
	delete transaksithis;
}
void SearchTransaksi::OnSearching(wxCommandEvent &event)
{
	wxString column;
	column = searchingz->GetValue();
	wxString key;
	key = searchingzz->GetValue();
	for (unsigned int i = 0; i < transaksisearch.GetCount();i++)
	{
		if (key == transaksisearch[i]->idTransaksi&&column == "ID") {
			baris = i + 1;
			kolom = 1;
		}
		else if (key == transaksisearch[i]->debetTransaksi&&column == "DEBET") {
			baris = i + 1;
			kolom = 2;
		}
		else if (key == transaksisearch[i]->kreditTransaksi&&column == "KREDIT") {
			baris = i + 1;
			kolom = 3;
		}
	}
	if (baris == 0 && kolom == 0) {
		wxMessageBox(_("Data Tidak Ditemukan"));
	}
	else {
		wxString brs, klm;
		brs << baris;
		klm << kolom;
		wxString kalimat;
		kalimat = _("Data Yang Anda Cari Berada di Baris ke-") + brs + _(" Kolom ke-") + klm;
		wxMessageBox(kalimat);
	}

}

void SearchTransaksi::SetSearchArray(wxString a, wxString b, wxString c)
{
	transaksithis = new Transaksi();
	transaksithis->SetidTransaksi(a);
	transaksithis->SetdebetTransaksi(b);
	transaksithis->SetkreditTransaksi(c);
	transaksisearch.Add(transaksithis);
}
int SearchTransaksi::GetBaris()
{
	return baris;
}

int SearchTransaksi::GetKolom()
{
	return kolom;
}