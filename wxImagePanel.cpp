#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
EVT_PAINT(wxImagePanel::paintEvent)
EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()
wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format)
	: wxPanel(parent)
{
	image.LoadFile(file, format);
	w = -1;
	h = -1;
	parent_pointer = parent;
}
void wxImagePanel::paintEvent(wxPaintEvent & evt)
{
	wxMessageOutputDebug().Printf("PAINT..");
	wxPaintDC dc(this);
	render(dc);
}
void wxImagePanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}
void wxImagePanel::render(wxDC&  dc)
{
	int neww, newh;
	dc.GetSize(&neww, &newh);

	if (neww != w || newh != h)
	{
		resized = wxBitmap(image.Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/));
		w = neww;
		h = newh;
		dc.DrawBitmap(resized, 0, 0, false);
	}
	else {
		dc.DrawBitmap(resized, 0, 0, false);
	}
}
void wxImagePanel::OnSize(wxSizeEvent& event) {
	Refresh();
	event.Skip();
}
