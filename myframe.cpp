#include "myframe.h"

using std::cout;
using std::endl;

MyFrame::MyFrame( wxWindow* parent )
:
MyFrameBase( parent )
{

}

void MyFrame::onInputSelect( wxFileDirPickerEvent& event )
{
	inDirName = inDirPicker->GetDirName();
	
	wxArrayString dirList;
	wxDir::GetAllFiles(inDirName.GetFullPath(), &dirList);

	*inDirTextCtrl << _("Path:\n");
	*inDirTextCtrl << inDirName.GetFullPath() << _("\n");

	int inFileCount = 0;

	for (unsigned int i = 0; i < dirList.GetCount(); ++i){
		*inDirTextCtrl << dirList[i] << _("\n");
		++inFileCount;
	}

	*debugTextCtrl << _("Input File Count: ") << inFileCount << _("\n");

}

void MyFrame::onOutputSelect( wxFileDirPickerEvent& event )
{
	outDirName = outDirPicker->GetDirName();

	wxArrayString dirList;
	wxDir::GetAllFiles(outDirName.GetFullPath(), &dirList);

	*outDirTextCtrl << _("Path");
	*outDirTextCtrl << outDirName.GetFullPath();

	int outFileCount = 0;

	for (unsigned int i = 0; i < dirList.GetCount(); ++i){
		*outDirTextCtrl << dirList[i] << _("\n");
		++outFileCount;
	}

	*debugTextCtrl << _("Output File Count: ") << outFileCount << _("\n");


}

void MyFrame::onUnused( wxCommandEvent& event )
{
// TODO: Implement onUnused
std::cout << "On Unused" << std::endl;
}

void MyFrame::onClose( wxCommandEvent& event )
{
// TODO: Implement onClose
std::cout << "On Close" << std::endl;
}

void MyFrame::onRun(wxCommandEvent& event)
{	
	std::cout << "On Run" << std::endl;

	if (outDirName.DirExists() && inDirName.DirExists())
		cout << "Dir Exists" << endl;
	

}

void MyFrame::onAbout( wxCommandEvent& event )
{
// TODO: Implement onAbout
std::cout << "On About" << std::endl;
}


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size ) 
: MyFrameBase(NULL , wxID_ANY, title , pos , size )
{

}

MyFrame::~MyFrame(){
	restoreStdin();
}


void MyFrame::stealStdin()
{
	sbOld = std::cout.rdbuf();
	std::cout.rdbuf(debugTextCtrl);
}

void MyFrame::restoreStdin()
{
	if(sbOld)
		std::cout.rdbuf(sbOld);
}


