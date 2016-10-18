#include "MainMenu.h"

MainMenu::MainMenu()
	: wxFrame(NULL, -1, _("Menu Barang"), wxDefaultPosition, wxDefaultSize, wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
	this->SetInitialSize(wxSize(1366, 738));
	SetIcon(wxICON(ivt));
	toolbar = new wxPanel(this); //panel untuk toolbar
	right = new wxPanel(this); //panel sebelah kanan 
	left= new wxPanel(this); //panel sebelah kiri

	toolbar->SetBackgroundColour(wxColour(0, 162, 232));
	right->SetBackgroundColour(wxColour(0, 162, 232));
	left->SetBackgroundColour(wxColour(0, 162, 232));
	
	wxBoxSizer *bottom;
	wxBoxSizer *juduls;
	wxBoxSizer *bottom_middle;
	wxBoxSizer *mainn;
	bottom = new wxBoxSizer(wxHORIZONTAL);//sizer untuk left,right dan bottom_middle
	juduls = new wxBoxSizer(wxVERTICAL); //sizer untuk judul
	bottom_middle = new wxBoxSizer(wxVERTICAL); // sizer untuk 2 toolbar
	mainn = new wxBoxSizer(wxVERTICAL); //sizer dasar

	toolbar1 = new wxToolBar(toolbar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_NODIVIDER | wxTB_NOALIGN); // untuk icon barang dana pembukuan
	toolbar2 = new wxToolBar(toolbar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_NODIVIDER | wxTB_NOALIGN);// untuk ikon tentang dan keluar

	wxBitmap barang;
	wxBitmap pembukuan;
	wxBitmap tentang;
	wxBitmap keluar;
	wxBitmap judul;
	barang= wxBitmap(wxT("barang.png"), wxBITMAP_TYPE_PNG);
	pembukuan= wxBitmap(wxT("pembukuan.png"), wxBITMAP_TYPE_PNG);
	tentang= wxBitmap(wxT("tentang.png"), wxBITMAP_TYPE_PNG);
	keluar= wxBitmap(wxT("keluar.png"), wxBITMAP_TYPE_PNG);
	judul= wxBitmap(wxT("Judul.png"), wxBITMAP_TYPE_PNG);
	
	staticBitmap = new wxStaticBitmap(this, -1,judul);
	
	juduls->Add(staticBitmap);//judul
	toolbar1->SetBackgroundColour(wxColour(0, 162, 232));
	toolbar2->SetBackgroundColour(wxColour(0, 162, 232));
	toolbar1->AddTool(ID_BARANG, barang, wxT("")); //masukkan ikon baranag
	toolbar1->AddTool(ID_PEMBUKUAN, pembukuan, wxT(""));//masukkan ikon pembukuan
	toolbar2->AddTool(ID_TENTANG, tentang, wxT("")); // masukkan ikon tentang
	toolbar2->AddTool(ID_KELUAR, keluar, wxT(""));//masukkan ikon keluar
	toolbar1->Realize();
	toolbar2->Realize();
	bottom_middle->Add(toolbar1, 0, wxEXPAND);
	bottom_middle->Add(toolbar2, 0, wxEXPAND);
	toolbar->SetSizer(bottom_middle);
	bottom->Add(right, 1, wxEXPAND | wxALL);
	bottom->Add(toolbar, 4, wxEXPAND | wxALL);
	bottom->Add(left, 1, wxEXPAND | wxALL);
	mainn->Add(juduls,1,wxEXPAND|wxALL);
	mainn->Add(bottom, 4, wxEXPAND | wxALL);
	this->SetSizer(mainn);
	Connect(ID_BARANG, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainMenu::Barang));
	Connect(ID_PEMBUKUAN, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainMenu::Pembukuan));
	Connect(ID_TENTANG, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainMenu::Tentang));
	Connect(ID_KELUAR, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainMenu::Keluar));
	Centre();
}
MainMenu::~MainMenu() {
	delete toolbar1;
	delete toolbar2;
	delete staticBitmap;
	delete toolbar;
	delete right;
	delete left;
}
void MainMenu::Barang(wxCommandEvent & WXUNUSED(event))
{
	barangframe = new BarangMenu();
	barangframe->Show(true);
}
void MainMenu::Pembukuan(wxCommandEvent & WXUNUSED(event))
{
	pembukuanframe = new PembukuanMenu();
	pembukuanframe->Show(true);
}
void MainMenu::Keluar(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}

void MainMenu::Tentang(wxCommandEvent & WXUNUSED(event))
{
	tentangframe = new TentangMenu();
	tentangframe->Show(true);
}