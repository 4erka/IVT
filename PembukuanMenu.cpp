#include "PembukuanMenu.h"

WX_DEFINE_OBJARRAY(TransaksiArray);
PembukuanMenu::PembukuanMenu()
	: wxFrame(NULL, -1, _("Menu Pembukuan"))
{
	wxBoxSizer *juduls; //sizer penampung judul
	wxBoxSizer *footers; // sizer penampung footer
	wxBoxSizer *hbox;//sizer penampung sizer judul dan sizer fgs
	wxBoxSizer *vbox;//sizer toolbar
	wxBoxSizer *hbox1;// sizer yang mengatur letak tombol "TAMBAH"
	wxBoxSizer *Grid;//sizer untuk grid
	wxBoxSizer *bottom;//sizer untuk panel kanan dan panel kiri
	wxBoxSizer *main;//sizer untuk panel utama
	transaksi = new Transaksi(); //insialisasi transaksi
	//--------------------------Menset Ukuran Layar,Ikon,StatusBar--------------------------------------------
	this->SetInitialSize(wxSize(1366, 738));
	SetIcon(wxICON(ivt));
	CreateStatusBar(2);
	SetStatusText(_("Ready"), 0);
	//--------------------------------------------------------------------------------------------------
	//-------------------------Menset dan mengatur toolbar dan ikon - ikonnya-----------------------------------------------
	ToolbarPanel = new wxPanel(this);
	ToolbarPanel->SetBackgroundColour(wxColour(0, 162, 232));
	wxBitmap tool_new(wxT("open.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_save(wxT("save.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_edit(wxT("edit.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_sort(wxT("sort.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_search(wxT("search.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_back(wxT("back.png"), wxBITMAP_TYPE_PNG);
	wxBitmap judul(wxT("spaceatas.png"), wxBITMAP_TYPE_PNG);
	wxBitmap footer(wxT("spacebawah.png"), wxBITMAP_TYPE_PNG);
	
	vbox = new wxBoxSizer(wxVERTICAL);
	toolbar1 = new wxToolBar(ToolbarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_NODIVIDER | wxTB_NOALIGN);
	
	toolbar1->SetBackgroundColour(wxColour(0, 162, 232));
	toolbar1->AddTool(open, tool_new, wxT(""));
	toolbar1->AddTool(save, tool_save, wxT(""));
	toolbar1->AddTool(edit, tool_edit, wxT(""));
	toolbar1->AddTool(sort, tool_sort, wxT(""));
	toolbar1->AddTool(search, tool_search, wxT(""));
	toolbar1->AddTool(back, tool_back, wxT(""));
	toolbar1->Realize();
	
	vbox->Add(toolbar1, 0, wxEXPAND);
	
	ToolbarPanel->SetSizer(vbox);
	//--------------------------------------------------------------------------------------------------
	//-------------------------Menset dan mengatur Left Panel-----------------------------------------------
	LeftPanel = new wxPanel(this);
	LeftPanel->SetBackgroundColour(wxColour(0, 162, 232));
	LeftPanel->SetBackgroundColour(wxColour(0, 162, 232));
	staticBitmap = new wxStaticBitmap(LeftPanel, -1, judul);
	juduls = new wxBoxSizer(wxVERTICAL);
	juduls->Add(staticBitmap);
	staticBitmap2 = new wxStaticBitmap(LeftPanel, -1, footer);
	footers = new wxBoxSizer(wxVERTICAL);
	footers->Add(staticBitmap2);

	hbox = new wxBoxSizer(wxVERTICAL);
	fgs = new wxFlexGridSizer(5, 2, 1, 1);

	wxArrayString temp;
	temp.Add(wxT("Debit"));
	temp.Add(wxT("Kredit"));

	id = new wxStaticText(LeftPanel, -1, wxT("ID  "));
	keterangan = new wxStaticText(LeftPanel, -1, wxT("KET"));
	nominal = new wxStaticText(LeftPanel, -1, wxT("NOMINAL"));
	jenis = new wxStaticText(LeftPanel, -1, wxT("JENIS  "));

	id->SetForegroundColour(wxColor(*wxWHITE));
	keterangan->SetForegroundColour(wxColor(*wxWHITE));
	nominal->SetForegroundColour(wxColor(*wxWHITE));
	jenis->SetForegroundColour(wxColor(*wxWHITE));

	i_id = new wxTextCtrl(LeftPanel, -1);
	i_keterangan = new wxTextCtrl(LeftPanel, -1);
	i_nominal = new wxTextCtrl(LeftPanel, -1);
	i_jenis = new wxComboBox(LeftPanel, -1,wxT(" "), wxDefaultPosition, wxDefaultSize,
		temp, wxCB_DROPDOWN);
	fgs->Add(id);
	fgs->Add(i_id, 1, wxEXPAND);
	fgs->Add(keterangan);
	fgs->Add(i_keterangan, 1, wxEXPAND);
	fgs->Add(nominal);
	fgs->Add(i_nominal, 1, wxEXPAND);
	fgs->Add(jenis);
	fgs->Add(i_jenis, 1, wxEXPAND);

	hbox->Add(juduls);
	hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);
	LeftPanel->SetSizerAndFit(hbox);

	Centre();
	hbox1 = new wxBoxSizer(wxHORIZONTAL);

	Add = new wxButton(LeftPanel, insert, wxT("TAMBAH"), wxDefaultPosition, wxSize(130, 70));
	Add->SetBackgroundColour(wxColour(209, 209, 209));
	dump = new wxStaticText(LeftPanel, -1, wxT("             "));
	
	
	hbox1->Add(dump);
	hbox1->Add(Add);

	hbox->Add(hbox1);
	hbox->Add(footers);
	LeftPanel->SetSizerAndFit(hbox);
	//--------------------------------------------------------------------------------------------------
	//---------------------Mengatur dan Menset Right Panel-----------------------------------------------
	RightPanel = new wxPanel(this);
	RightPanel->SetBackgroundColour(wxColour(0, 162, 232));
	grid = new GridPembukuan(RightPanel);
	Grid = new wxBoxSizer(wxHORIZONTAL);
	Grid->Add(grid);
	RightPanel->SetSizer(Grid);

	//--------------------------ATUR PANEL SEMUA----------------------------------------------------------------------
	bottom = new wxBoxSizer(wxHORIZONTAL);
	main = new wxBoxSizer(wxVERTICAL);
	bottom->Add(LeftPanel, 1, wxEXPAND | wxALL);
	bottom->Add(RightPanel, 6, wxEXPAND | wxALL);
	main->Add(ToolbarPanel, 1, wxEXPAND | wxALL);
	main->Add(bottom, 3, wxEXPAND | wxALL);
	this->SetSizer(main);
	Connect(open, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnOpen));
	Connect(save, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnSave));
	Connect(edit, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnEdit));
	Connect(sort, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnSort));
	Connect(search, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnSearch));
	Connect(back, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnQuit));
	Connect(insert, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(PembukuanMenu::OnAddClick));
	jumlahdebit = 0;
	jumlahkredit = 0;
}
PembukuanMenu::~PembukuanMenu() {
	delete staticBitmap;
	delete staticBitmap2;
	delete id;
	delete keterangan;
	delete nominal;
	delete jenis;
	delete Add;
	delete dump;
	delete ToolbarPanel;
	delete RightPanel;
	delete LeftPanel;
	transaksis.Empty();
//	delete transaksi;
}
void PembukuanMenu::OnOpen(wxCommandEvent & WXUNUSED(event))
{
	transaksis.Empty();
	transaksi = new Transaksi();
	wxString        file;
	wxFileDialog    fdlog(this);

	if (fdlog.ShowModal() != wxID_OK) return;
	file.Clear();
	file = fdlog.GetPath();

	wxString str;
	wxTextFile tfile;
	tfile.Open(file);

	str = tfile.GetFirstLine();
	int flag = 0;

	while (str == "")
	{
		str = tfile.GetNextLine();
	}
	transaksi->SetidTransaksi(str);
	while (!tfile.Eof())
	{
		str = tfile.GetNextLine();
		if (str == "#")
		{
			flag = 0;
			transaksis.Add(transaksi);
			//grid->Insert(barang);
			transaksi = new Transaksi();
			str = tfile.GetNextLine();
		}
		else if (str == "")
		{
			flag++;
			str = tfile.GetNextLine();
		}
		else
		{
			flag++;
		}
		if (flag == 0 && str != "")
			transaksi->SetidTransaksi(str);
		else if (flag == 1 && str != "")
			transaksi->SetdebetTransaksi(str);
		else if (flag == 2 && str != "")
			transaksi->SetkreditTransaksi(str);
		else if (flag == 3 && str != "")
			transaksi->SetketeranganTransaksi(str);
	}
	//grid->Update();
	for (unsigned int i = 0; i < transaksis.GetCount(); i++)
	{
		Transaksi *trk = transaksis[i];
		//grid->Update(bra);
		grid->SetCellValue(i, 0, trk->idTransaksi);
		grid->SetCellValue(i, 1, trk->debetTransaksi);
		grid->SetCellValue(i, 2, trk->kreditTransaksi);
		grid->SetCellValue(i, 3, trk->keteranganTransaksi);
		jml_data = i + 1;
	}

	SetStatusText(_("Open File Succesfully"), 0);
	wxMessageBox(wxT("Buka Data Sukses"));
}
void PembukuanMenu::OnSave(wxCommandEvent & WXUNUSED(event))
{
	wxFileDialog dlg(this, "Save .txt file...",
		"", "",
		"Save Files (*.txt) | *.txt | All files (*.*)|*.*", wxFD_SAVE);
	if (dlg.ShowModal() == wxID_OK)
	{
		wxFile file(dlg.GetPath(), wxFile::write);
		if (file.IsOpened())
		{
			for (unsigned int i = 0; i < transaksis.GetCount(); i++)
			{
				Transaksi *trk = transaksis[i];
				for (unsigned int j = 0; j < 4; j++)
				{
					if (j == 0)
					{
						file.Write(trk->idTransaksi + "\r\n");
					}
					else if (j == 1)
					{
						file.Write(trk->debetTransaksi + "\r\n");
					}
					else if (j == 2)
					{
						file.Write(trk->kreditTransaksi + "\r\n");
					}
					else if (j == 3)
					{
						file.Write(trk->keteranganTransaksi + "\r\n");
					}

				}
				file.Write("#\r\n");
				//wxMessageBox(stu->asalBarang);
			}
			file.Close();
		}
	}
	SetStatusText(_("Save File Succesfully"), 0);
	wxMessageBox(wxT("Data Telah Disimpan"));
}
void PembukuanMenu::OnEdit(wxCommandEvent & WXUNUSED(event))
{
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 4;j++) {
			grid->SetReadOnly(i,j,false);
		}
	}
	SetStatusText(_("Grid Editable"), 0);

}
void PembukuanMenu::OnSearch(wxCommandEvent & WXUNUSED(event))
{
	searchin = new SearchTransaksi();

	for (unsigned int i = 0; i < transaksis.GetCount();i++)
	{
		searchin->SetSearchArray(transaksis[i]->idTransaksi,transaksis[i]->debetTransaksi,transaksis[i]->keteranganTransaksi);
	}
	searchin->Show(true);
}
void PembukuanMenu::OnSort(wxCommandEvent & WXUNUSED(event))
{
	grid->ClearGrid();
	int flag = 1;    // set flag to 1 to start first pass
	Transaksi *temp;             // holding variable
	for (int i = 1; (i <= transaksis.GetCount()) && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < (transaksis.GetCount() - 1); j++)
		{
			if (transaksis[j + 1]->idTransaksi < transaksis[j]->idTransaksi)      // ascending order simply changes to <
			{
				temp = transaksis[j];             // swap elements
				transaksis[j] = transaksis[j + 1];
				transaksis[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}

	for (unsigned int i = 0; i < transaksis.GetCount();i++)
	{
		grid->SetCellValue(i, 0, transaksis[i]->idTransaksi);
		grid->SetCellValue(i, 1, transaksis[i]->debetTransaksi);
		grid->SetCellValue(i, 2, transaksis[i]->kreditTransaksi);
		grid->SetCellValue(i, 3, transaksis[i]->keteranganTransaksi);
	}
	
}
void PembukuanMenu::OnAddClick(wxCommandEvent & event)
{
	wxString temp = i_jenis->GetStringSelection();
	wxString s = i_id->GetValue();
	wxString s1 = i_keterangan->GetValue();
	wxString s2 = i_nominal->GetValue();
	wxString debitt;
	wxString kreditt;
	transaksi = new Transaksi();
	transaksi->SetidTransaksi(s);
	grid->SetCellValue(jml_data, 0, s);
	if (temp == "Debit") {
		transaksi->SetdebetTransaksi(s2);
		transaksi->SetkreditTransaksi(_("0"));
		grid->SetCellValue(jml_data, 1, s2);
		grid->SetCellValue(jml_data, 2,_("0"));
		//int temp=wxAtoi(transaksi->debetTransaksi);
		//jumlahdebit += temp;
		
		debitt << jumlahdebit;
		
	}
	else if (temp == "Kredit") {
		transaksi->SetkreditTransaksi(s2);
		transaksi->SetdebetTransaksi(_("0"));
		grid->SetCellValue(jml_data, 1, _("0"));
		grid->SetCellValue(jml_data, 2, s2);
		//int temp = wxAtoi(transaksi->kreditTransaksi);
		//jumlahkredit += temp;
		kreditt << jumlahkredit;
		
	}
	//SetStatusText(debitt, 0);
	//SetStatusText(kreditt, 1);
	transaksi->SetketeranganTransaksi(s1);
	grid->SetCellValue(jml_data, 3, s1);
	jml_data += 1;
	transaksis.Add(transaksi);
	wxMessageBox(wxT("Input Data Berhasil"));
}
void PembukuanMenu::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
