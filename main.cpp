
#include <wx/wx.h>
#include "myframe.h"
 
class MyApp : public wxApp
{
	virtual bool OnInit();
	wxString test;
};

IMPLEMENT_APP(MyApp)


enum
{
	ID_Quit = 1,
	ID_About
};

bool MyApp::OnInit()
{
	

	MyFrame *frame = new MyFrame(_("Program Line Counter"), wxPoint(50, 50),wxSize(850, 450));
	frame->stealStdin();	

	frame->Show(true);
	SetTopWindow(frame);

	return true;
}
