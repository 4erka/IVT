#include "SearchBarang.h"
WX_DEFINE_OBJARRAY(BarangArraySearch);

SearchBarang::SearchBarang()
	:wxFrame(NULL, -1, _("Cari Barang"), wxDefaultPosition, wxSize(300, 120))
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
	barangthis = new Barang();

	SetIcon(wxICON(ivt));
	panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColour(0, 162, 232));
	
	temp.Add(wxT("NOMOR"));
	temp.Add(wxT("TANGGAL"));
	temp.Add(wxT("NAMA"));
	temp.Add(wxT("ASAL"));
	temp.Add(wxT("JUMLAH"));
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
		wxCommandEventHandler(SearchBarang::OnSearching));
}
SearchBarang::~SearchBarang() {
	delete searchingz;
	delete searchingzz;
	delete cari;
	delete barangthis;
}
void SearchBarang::OnSearching(wxCommandEvent &event)
{
	wxString column;
	column = searchingz->GetValue();
	wxString key;
	key = searchingzz->GetValue();
	for (unsigned int i = 0; i < barangsearch.GetCount();i++)
	{
		if (key == barangsearch[i]->nomorBarang&&column == "NOMOR") {
			baris = i+1;
			kolom = 1;
		}
		else if (key == barangsearch[i]->tanggalBarang&&column == "TANGGAL") {
			baris = i+1;
			kolom = 2;
		}
		else if (key == barangsearch[i]->namaBarang&&column == "NAMA") {
			baris = i+1;
			kolom = 3;
		}
		else if (key == barangsearch[i]->asalBarang&&column == "ASAL") {
			baris = i+1;
			kolom = 4;
		}
		else if (key == barangsearch[i]->jumlahBarang&&column == "JUMLAH") {
			baris = i+1;
			kolom = 5;
		}
		else {

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

void SearchBarang::SetSearchArray(wxString a, wxString b, wxString c, wxString d, wxString e)
{
	barangthis = new Barang();
	barangthis->SetnomorBarang(a);
	barangthis->SettanggalBarang(b);
	barangthis->SetnamaBarang(c);
	barangthis->SetasalBarang(d);
	barangthis->SetjumlahBarang(e);
	barangsearch.Add(barangthis);
}
int SearchBarang::GetBaris()
{
	return baris;
}

int SearchBarang::GetKolom()
{
	return kolom;
}