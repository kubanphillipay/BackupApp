#pragma once

#include <wx/wx.h>
#include <vector>
#include "filedir.h"
#include "userstring.h"
#include "calclines.h"

class MainPanel : public wxPanel {

public:
	MainPanel(wxFrame* parent);

	void onRun(wxEvent& event);
	void onOutBrowse(wxEvent& event);
	void onInBrowse(wxEvent& event);
	void stealCout();
	//void onUnBind(wxEvent& event);
	//void unBind();

private:
	void addInterface();
	
	//wxButton* Button2;
	

	wxStaticText* inputDirText;
	wxTextCtrl* inputDirTextCtrl;
	wxButton* inputDirButton;
	wxTextCtrl* inputDirListTextCtrl;

	wxStaticText* outputDirText;
	wxTextCtrl* outputDirTextCtrl;
	wxButton* outputDirButton;
	wxTextCtrl* outputDirListTextCtrl;

	//wxTextCtrl* debugTextCtrl;

	//wxButton* runButton;
	//wxCheckBox* cppCheckBox;
	//wxCheckBox* hCheckBox;
	//wxTextCtrl* directoryTextCtrl;
	//wxButton* browseButton;

	enum BUTTONS { BUTTON1, BUTTON2 };


};