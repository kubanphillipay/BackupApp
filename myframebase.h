///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MYFRAMEBASE_H__
#define __MYFRAMEBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/filepicker.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/gauge.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameBase
///////////////////////////////////////////////////////////////////////////////
class MyFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxPanel* mainPanel;
		wxDirPickerCtrl* inDirPicker;
		wxTextCtrl* inDirTextCtrl;
		wxDirPickerCtrl* outDirPicker;
		wxTextCtrl* outDirTextCtrl;
		wxStaticLine* m_staticline1;
		wxTextCtrl* debugTextCtrl;
		wxMenuBar* menuBar;
		wxMenu* fileMenu;
		wxMenu* runMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onInputSelect( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void onOutputSelect( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void onUnused( wxCommandEvent& event ) { event.Skip(); }
		virtual void onClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void onRun( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("test"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 621,438 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ProgressBase
///////////////////////////////////////////////////////////////////////////////
class ProgressBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText9;
		wxGauge* m_gauge1;
		wxBoxSizer* bSizer32;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
	
	public:
		
		ProgressBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 375,169 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ProgressBase();
	
};

#endif //__MYFRAMEBASE_H__
