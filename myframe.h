#ifndef __myFrame__
#define __myFrame__

/**
@file
Subclass of MyFrameBase, which is generated by wxFormBuilder.
*/

#include "myframebase.h"

//// end generated include

#include <iostream>
#include <wx/dir.h>
#include <memory>
#include <map>
#include <vector>
#include "progressbar.h"
#include "fileInfo.h"
#include "wx/msgdlg.h"
//#include "resource.rc"
//#include "wx/msw/wx.rc"



/** Implementing MyFrameBase */
class MyFrame : public MyFrameBase
{
	protected:
		// Handlers for MyFrameBase events.
		void onInputSelect( wxFileDirPickerEvent& event );
		void onOutputSelect( wxFileDirPickerEvent& event );
		void onUnused( wxCommandEvent& event );
		void onClose( wxCommandEvent& event );
		void onRun( wxCommandEvent& event );
		void onClear( wxCommandEvent& event );
		void onAbout( wxCommandEvent& event );
	public:
		/** Constructor */
		MyFrame( wxWindow* parent );
	//// end generated class members


public:
	MyFrame(const wxString& title = wxT("test"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(621, 438) );
	void stealStdin();
	void restoreStdin();
	~MyFrame();

private:
	std::streambuf *sbOld{ nullptr };
	wxFileName inDirName;
	wxFileName outDirName;
	std::map<wxString, FileInfo> inFiles;
	std::map<wxString, FileInfo> outFiles;


protected:

	ProgressBar* progressBar;
	void setProgressParams(unsigned int count, wxString title);
	void hideProgress(){
		progressBar->Hide();
	}
	void setProgress(unsigned int step ){
		progressBar->setProgressValue(step);
	}
	unsigned int createFileList(wxFileName& dirName, wxTextCtrl& outputTextCtrl, std::map<wxString, FileInfo>& files );

	bool copyFiles();

	//void testFunc(std::shared_ptr<wxString>& parentDirIn);





};

#endif // __myFrame__