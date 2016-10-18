#pragma once
#include <wx/wx.h>
class wxImagePanel : public wxPanel
{
protected:
	wxImage image;
	wxBitmap resized;
	int w, h;
	wxFrame *parent_pointer;
public:
	wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	void OnSize(wxSizeEvent& event);
	void render(wxDC& dc);

	DECLARE_EVENT_TABLE()
};

