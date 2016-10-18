#include <wx/wx.h>
#include "MainMenu.h"

class MyApp : public wxApp
{
	wxFrame *frame;
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	wxInitAllImageHandlers();
	frame = new MainMenu();
	frame->Show(true);

	return true;
}
