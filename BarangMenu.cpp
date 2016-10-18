#include "BarangMenu.h"
#include <wx/string.h>
WX_DEFINE_OBJARRAY(BarangArray);
BarangMenu::BarangMenu()
	: wxFrame(NULL,-1,_("Menu Barang"))
{
	wxBoxSizer *vbox;//sizer toolbar
	wxBoxSizer *Grid;  //sizer untuk grid
	wxBoxSizer *bottom; //sizer untuk panel kanan dan panel kiri
	wxBoxSizer *main; //sizer untuk panel utama
	wxBoxSizer *juduls; //sizer penampung judul
	wxBoxSizer *footers; // sizer penampung footer
	wxBoxSizer *hbox; //sizer penampung sizer judul dan sizer fgs
	wxBoxSizer *hbox1; // sizer yang mengatur letak tombol "TAMBAH"
	wxFlexGridSizer *fgs; //sizer penampung kolom-kolom input + keterangannya
	wxToolBar *toolbar1;//toolbar
	barang = new Barang();//Inisialisasi barang
	//---------------------------------Mengeset Ukuran,Ikon,Status bar------------------------------------------
	this->SetInitialSize(wxSize(1366, 738));
	SetIcon(wxICON(ivt));
	CreateStatusBar(2); 
	SetStatusText(_("Ready"),0);
	//---------------------------------Mengeset Toolbar dan ikon - ikonnya---------------------------------------------------
	ToolbarPanel = new wxPanel(this); 
	ToolbarPanel->SetBackgroundColour(wxColour(0,162, 232));
	wxBitmap tool_new(wxT("open.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_save(wxT("save.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_edit(wxT("edit.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_sort(wxT("sort.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_search(wxT("search.png"), wxBITMAP_TYPE_PNG);
	wxBitmap tool_back(wxT("back.png"), wxBITMAP_TYPE_PNG);
	wxBitmap judul(wxT("spaceatas.png"), wxBITMAP_TYPE_PNG);
	wxBitmap footer(wxT("spacebawah.png"), wxBITMAP_TYPE_PNG);
	vbox = new wxBoxSizer(wxVERTICAL);
	toolbar1 = new wxToolBar(ToolbarPanel, wxID_ANY,wxDefaultPosition,wxDefaultSize, wxTB_NODIVIDER| wxTB_NOALIGN);
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
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------Mengatur Left Panel--------------------------------------------------------------------
	LeftPanel = new wxPanel(this);
	LeftPanel->SetBackgroundColour(wxColour(0, 162, 232));
	staticBitmap = new wxStaticBitmap(LeftPanel, -1, judul);
	juduls = new wxBoxSizer(wxVERTICAL);
	juduls->Add(staticBitmap);
	staticBitmap2 = new wxStaticBitmap(LeftPanel, -1, footer);
	footers = new wxBoxSizer(wxVERTICAL);
	footers->Add(staticBitmap2);
	hbox = new wxBoxSizer(wxVERTICAL);
	fgs = new wxFlexGridSizer(5, 2, 1, 1);

	gudang_number = new wxStaticText(LeftPanel, -1, wxT("NOMOR"));
	gudang_condition = new wxStaticText(LeftPanel, -1, wxT("TANGGAL"));
	gudang_name = new wxStaticText(LeftPanel, -1, wxT("NAMA"));
	gudang_source = new wxStaticText(LeftPanel, -1, wxT("ASAL"));
	gudang_amount = new wxStaticText(LeftPanel, -1, wxT("JUMLAH"));
	gudang_number->SetForegroundColour(wxColor(*wxWHITE));
	gudang_condition->SetForegroundColour(wxColor(*wxWHITE));
	gudang_name->SetForegroundColour(wxColor(*wxWHITE));
	gudang_source->SetForegroundColour(wxColor(*wxWHITE));
	gudang_amount->SetForegroundColour(wxColor(*wxWHITE));
	
	i_nomor = new wxTextCtrl(LeftPanel, -1);
	i_tanggal = new wxTextCtrl(LeftPanel, -1);
	i_nama = new wxTextCtrl(LeftPanel, -1);
	i_asal = new wxTextCtrl(LeftPanel, -1);
	i_jumlah = new wxTextCtrl(LeftPanel, -1);

	fgs->Add(gudang_number);
	fgs->Add(i_nomor, 1, wxEXPAND);
	fgs->Add(gudang_condition);
	fgs->Add(i_tanggal, 1, wxEXPAND);
	fgs->Add(gudang_name);
	fgs->Add(i_nama, 1, wxEXPAND);
	fgs->Add(gudang_source);
	fgs->Add(i_asal, 1, wxEXPAND);
	fgs->Add(gudang_amount);
	fgs->Add(i_jumlah, 1, wxEXPAND);

	hbox->Add(juduls);
	hbox->Add(fgs, 1, wxALL | wxEXPAND, 1);
	LeftPanel->SetSizerAndFit(hbox);

	Centre();
	hbox1 = new wxBoxSizer(wxHORIZONTAL);
	AddGudang = new wxButton(LeftPanel, insert, wxT("TAMBAH"),wxDefaultPosition,wxSize(130,70));
	AddGudang->SetBackgroundColour(wxColour(209, 209, 209));
	dump = new wxStaticText(LeftPanel, -1, wxT("             "));
	hbox1->Add(dump);
	hbox1->Add(AddGudang);
	hbox->Add(hbox1);
	hbox->Add(footers);
	LeftPanel->SetSizerAndFit(hbox);
	//------------------------------------------------------------Mengatur Right Panel--------------------------------------------------------------------
	RightPanel = new wxPanel(this);
	RightPanel->SetBackgroundColour(wxColour(0, 162, 232));
	grid = new GridBarang(RightPanel);
	Grid = new wxBoxSizer(wxHORIZONTAL);
	Grid->Add(grid);
	RightPanel->SetSizer(Grid);
	//ATUR PANEL SEMUA----------------------------------------------------------------------
	bottom = new wxBoxSizer(wxHORIZONTAL);
	main = new wxBoxSizer(wxVERTICAL);
	bottom->Add(LeftPanel, 1, wxEXPAND | wxALL);
	bottom->Add(RightPanel, 6, wxEXPAND | wxALL);
	main->Add(ToolbarPanel, 1, wxEXPAND | wxALL);
	main->Add(bottom, 3, wxEXPAND | wxALL);
	Connect(open, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnOpen));
	Connect(save, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnSave));
	Connect(edit, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnEdit));
	Connect(sort, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnSort));
	Connect(search, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnSearch));
	Connect(back, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(BarangMenu::OnQuit));
	Connect(insert, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(BarangMenu::OnAddClick));
	this->SetSizer(main);
}
BarangMenu::~BarangMenu() {
	delete staticBitmap;
	delete staticBitmap2;
	delete gudang_number;
	delete gudang_condition;
	delete gudang_name;
	delete gudang_source;
	delete gudang_amount;
	delete AddGudang;
	delete dump;
	delete ToolbarPanel;
	delete RightPanel;
	delete LeftPanel;
//	delete toolbar1;
//	delete i_nomor;
//	delete i_nama;
//	delete i_asal;
//	delete i_jumlah;
//	delete i_tanggal;
//	delete grid;
	//memset(barangs, 0, sizeof(barangs));
	barangs.Empty();
//	delete barang;
	//delete barangprint;
//	delete searchin;
}
void BarangMenu::OnOpen(wxCommandEvent & WXUNUSED(event))
{
	barangs.Empty();
	barang = new Barang();
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
	if (str != "|")
		barang->SetnomorBarang(str);
	else
		barang->SetnomorBarang("");
	while (!tfile.Eof())
	{
		str = tfile.GetNextLine();
		if (str == "#")
		{
			flag = 0;
			barangs.Add(barang);
			barang = new Barang();
			str = tfile.GetNextLine();
		}
		else if (str == "|")
		{
			flag++;
			str = tfile.GetNextLine();
		}
		else
		{
			flag++;
		}
		if (flag == 0 && str != "")
			barang->SetnomorBarang(str);
		else if (flag == 1 && str != "")
			barang->SettanggalBarang(str);
		else if (flag == 2 && str != "")
			barang->SetnamaBarang(str);
		else if (flag == 3 && str != "")
			barang->SetasalBarang(str);
		else if (flag == 4 && str != "")
			barang->SetjumlahBarang(str);
	}
	for (unsigned int i = 0; i < barangs.GetCount(); i++)
	{
		barangprint = barangs[i];
		grid->SetCellValue(i, 0, barangprint->nomorBarang);
		grid->SetCellValue(i, 1, barangprint->tanggalBarang);
		grid->SetCellValue(i, 2, barangprint->namaBarang);
		grid->SetCellValue(i, 3, barangprint->asalBarang);
		grid->SetCellValue(i, 4, barangprint->jumlahBarang);
		jml_data = i + 1;
	}

	SetStatusText(_("Open File Succesfully"), 0);
	wxMessageBox(wxT("Buka Data Sukses"));
	
	/*barangs.Empty();
	
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
	barang->SetnomorBarang(str);
	while (!tfile.Eof())
	{
		str = tfile.GetNextLine();
		if (str == "#")
		{
			flag = 0;
			barangs.Add(barang);
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
			barang->SetnomorBarang(str);
		else if (flag == 1 && str != "")
			barang->SettanggalBarang(str);
		else if (flag == 2 && str != "")
			barang->SetnamaBarang(str);
		else if (flag == 3 && str != "")
			barang->SetasalBarang(str);
		else if (flag == 4 && str != "")
			barang->SetjumlahBarang(str);
	}
	for (unsigned int i = 0; i < barangs.GetCount(); i++)
	{
		barangprint = barangs[i];
		grid->SetCellValue(i, 0, barang->nomorBarang);
		grid->SetCellValue(i, 1, barang->tanggalBarang);
		grid->SetCellValue(i, 2, barang->namaBarang);
		grid->SetCellValue(i, 3, barang->asalBarang);
		grid->SetCellValue(i, 4, barang->jumlahBarang);
		jml_data = i + 1;
	}
	
	SetStatusText(_("Open File Succesfully"), 0);
	wxMessageBox(wxT("Buka Data Sukses"));*/
	
}
void BarangMenu::OnSave(wxCommandEvent & WXUNUSED(event))
{
	wxFileDialog dlg(this, "Save .txt file...",
		"", "",
		"Save Files (*.txt) | *.txt | All files (*.*)|*.*", wxFD_SAVE);
	if (dlg.ShowModal() == wxID_OK)
	{
		wxFile file(dlg.GetPath(), wxFile::write);
		if (file.IsOpened())
		{
			for (unsigned int i = 0; i < barangs.GetCount(); i++)
			{
				barangprint = barangs[i];
				for (unsigned int j = 0; j < 5; j++)
				{
					if (j == 0)
					{
						file.Write(barangprint->nomorBarang + "\r\n|\r\n");
					}
					else if (j == 1)
					{
						file.Write(barangprint->tanggalBarang + "\r\n|\r\n");
					}
					else if (j == 2)
					{
						file.Write(barangprint->namaBarang + "\r\n|\r\n");
					}
					else if (j == 3)
					{
						file.Write(barangprint->asalBarang + "\r\n|\r\n");
					}
					else if (j == 4)
					{
						file.Write(barangprint->jumlahBarang + "\r\n");
					}
				}
				file.Write("#\r\n");
			}
			file.Close();
		}
	}
	SetStatusText(_("Save File Succesfully"), 0);
	wxMessageBox(wxT("Data Telah Disimpan"));
}
void BarangMenu::OnEdit(wxCommandEvent & WXUNUSED(event))
{
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 4;j++) {
			grid->SetReadOnly(i, j, false);
		}
	}
	SetStatusText(_("Grid Editable"), 0);
}
void BarangMenu::OnSearch(wxCommandEvent & WXUNUSED(event))
{
	searchin = new SearchBarang();
	
	for (unsigned int i = 0; i < barangs.GetCount();i++)
	{
		searchin->SetSearchArray(barangs[i]->nomorBarang, barangs[i]->tanggalBarang, barangs[i]->namaBarang,
			barangs[i]->asalBarang, barangs[i]->jumlahBarang);
	}
	searchin->Show(true);
	
	//grid->SelectRow(searchin->GetBaris());
}

void BarangMenu::OnSort(wxCommandEvent & WXUNUSED(event))
{
	grid->ClearGrid();
	int flag = 1;    // set flag to 1 to start first pass
	Barang *temp;             // holding variable
	for (int i = 1; (i <= barangs.GetCount()) && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < (barangs.GetCount() - 1); j++)
		{
			if (barangs[j + 1]->nomorBarang < barangs[j]->nomorBarang)      // ascending order simply changes to <
			{
				temp = barangs[j];             // swap elements
				barangs[j] = barangs[j + 1];
				barangs[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}

	for (unsigned int i = 0; i < barangs.GetCount();i++)
	{
		grid->SetCellValue(i, 0, barangs[i]->nomorBarang);
		grid->SetCellValue(i, 1, barangs[i]->tanggalBarang);
		grid->SetCellValue(i, 2, barangs[i]->namaBarang);
		grid->SetCellValue(i, 3, barangs[i]->asalBarang);
		grid->SetCellValue(i, 4, barangs[i]->jumlahBarang);
	}
}
void BarangMenu::OnAddClick(wxCommandEvent & event)
{
	barang = new Barang();
	wxString s = i_nomor->GetValue();
	wxString s1 = i_tanggal->GetValue();
	wxString s2 = i_nama->GetValue();
	wxString s3 = i_asal->GetValue();
	wxString s4 = i_jumlah->GetValue();
	barang->SetnomorBarang(s);
	barang->SettanggalBarang(s1);
	barang->SetnamaBarang(s2);
	barang->SetasalBarang(s3);
	barang->SetjumlahBarang(s4);
	barangs.Add(barang);
	grid->SetCellValue(jml_data, 0, s);
	grid->SetCellValue(jml_data, 1, s1);
	grid->SetCellValue(jml_data, 2, s2);
	grid->SetCellValue(jml_data, 3, s3);
	grid->SetCellValue(jml_data, 4, s4);
	
	jml_data += 1;
	
	wxMessageBox(wxT("Input Data Berhasil"));
}
void BarangMenu::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}