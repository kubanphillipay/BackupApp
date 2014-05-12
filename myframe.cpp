#include "myFrame.h"


//#include "myframe.h"
//#include "progressbar.h"

using std::cout;
using std::endl;
MyFrame::MyFrame(wxWindow* parent)
: MyFrame()

{

}


void MyFrame::onInputSelect( wxFileDirPickerEvent& event )
{
	inDirName = inDirPicker->GetDirName();

	auto count = createFileList(inDirName, *inDirTextCtrl , inFiles );

	*debugTextCtrl << _("Input File Count: ") << (int)count << _("\n");

}

void MyFrame::onOutputSelect( wxFileDirPickerEvent& event )
{
	outDirName = outDirPicker->GetDirName();

	auto count = createFileList(outDirName, *outDirTextCtrl, outFiles );

	*debugTextCtrl << _("Output File Count: ") << (int)count << _("\n");

}

void MyFrame::onUnused( wxCommandEvent& event )
{
	// TODO: Implement onUnused
	std::cout << "On Unused" << std::endl;
}

void MyFrame::onClose( wxCommandEvent& event )
{
	Close(true);
}

void MyFrame::onRun( wxCommandEvent& event )
{

	std::cout << "On Run" << std::endl;

	if (!outDirName.DirExists() || !inDirName.DirExists()) {
		std::cout << "You must select a valid directory" << endl;
		return;
	}

	int addCount = 0, sameCount = 0;
	std::vector<FileInfo*> toAddList;	
	
	for (auto& iterator : inFiles ) {
		FileInfo& cmp1 = iterator.second;
		FileInfo& cmp2 = outFiles[cmp1.getShortPath()];		

		if (cmp1 > cmp2) {
			++addCount;
			cmp1.setCopytoPath(outDirName.GetFullPath());		
			toAddList.push_back(&cmp1);
			*debugTextCtrl << "Adding: " << cmp1.getShortPath() << "\n";
		} else if (cmp1 == cmp2) {
			//*debugTextCtrl << "Same: " << cmp1.getShortPath() << "\n";
			++sameCount;
		}
		else {
			*debugTextCtrl << "Not Sure What's going on" << cmp1.getShortPath() << "\n";
		}

	}

	*debugTextCtrl << "Files added: " << addCount << "\n";
	*debugTextCtrl << "Files same: " << sameCount << "\n";

	if (copyFiles() ){

		setProgressParams(addCount, "Moving Files");

		*debugTextCtrl << "Copy Files\n";
		int step = 0;
		for (auto copyInfo : toAddList){
			
			// Here is where the magic happens
			setProgress(++step);

			bool success = false, dirExists = false;
			wxString dirPath = wxFileName(copyInfo->getCopyToPath()).GetPath();
			dirExists = wxDir::Exists(dirPath);

			if (!dirExists){
				dirExists = wxFileName::Mkdir(dirPath, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);
			}			

			if (dirExists) {
				success = wxCopyFile(copyInfo->getFullPath(), copyInfo->getCopyToPath(), true);
				*debugTextCtrl << "Copy From " << copyInfo->getFullPath() << "\n     to " << copyInfo->getCopyToPath() << " ";
			}
			else {
				*debugTextCtrl << "Error Dir Does not Exist.  ";
			}

			
			if (success)
				*debugTextCtrl << "Successful!\n";
			else
				*debugTextCtrl << "Failed!!\n";

			
		
			// Magic over
		}

		hideProgress();
	}
	else {
		*debugTextCtrl << "No Copy Files\n";
	}


}


void MyFrame::onAbout( wxCommandEvent& event )
{
	wxMessageBox(_("Back up Program.\n"
		"Description:\n"
		"    -Takes two directories, and input directory and and output directory.\n"
		"    -The program compares the files between the two directories and copies any files "
		"that are either missing from the \"output\" directory or have been modified more recently "
		"in the \"input\" directory.\n"
		"    -This program does not compress any files nor does it back up at regular intervals.\n"
		"Notes:\n"				
		"    -This program seems to work pretty well.  I have not tested it thorougly however.\n"
		"    -I did verify that it will create directories in the output folder if they do not exist.\n"
		"    -There are definately improvements that could be made in terms of efficencies but it works well enough.\n"
		),
		_("About Backup App"),
		wxOK | wxICON_INFORMATION, this);
}


void MyFrame::onClear(wxCommandEvent& event){
	inFiles.clear();
	outFiles.clear();

	inDirPicker->SetPath("");
	outDirPicker->SetPath("");

	inDirTextCtrl->Clear();
	outDirTextCtrl->Clear();
	//inDirName

}



MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size ) 
: MyFrameBase(NULL , wxID_ANY, title , pos , size )
{
	progressBar = new ProgressBar(NULL);
	SetIcon(wxICON(myicon));
}

unsigned int MyFrame::createFileList(wxFileName& dirName, wxTextCtrl& outputTextCtrl, std::map<wxString, FileInfo>& files )
{

	wxArrayString dirList;
	wxDir::GetAllFiles(dirName.GetFullPath(), &dirList);

	outputTextCtrl << _("Path:\n");
	outputTextCtrl << dirName.GetFullPath() << _("\n");

	//std::shared_ptr<wxString> parentDirName(new wxString(dirName.GetFullPath()));

	unsigned int count = dirList.GetCount();

	setProgressParams(count, "Process File List");

	for (unsigned int i = 0; i < count; ++i){
		setProgress(i + 1);
		FileInfo fileInfo(dirName.GetFullPath(), dirList[i]);
		files[fileInfo.getShortPath()] = fileInfo;		
		outputTextCtrl << fileInfo.getShortPath() << "\n";
		
	}

	hideProgress();

	return count;

}

MyFrame::~MyFrame()
{
	restoreStdin();
	progressBar->Destroy();
}

void MyFrame::setProgressParams(unsigned int count, wxString title)
{
	progressBar->setProgressRange(count);
	progressBar->setProgressValue(0);
	progressBar->setTitle(title);
	progressBar->Show();
}

void MyFrame::restoreStdin()
{
	if(sbOld)
		std::cout.rdbuf(sbOld);
}

void MyFrame::stealStdin()
{
	sbOld = std::cout.rdbuf();
	std::cout.rdbuf(debugTextCtrl);
}

bool MyFrame::copyFiles(){
	wxMenuItem* copy_files = runMenu->FindItem(COPY_FILE);
	if (copy_files){
		if (copy_files->IsChecked())
			return true;
		return false;
	}

	*debugTextCtrl << "Error copy files menu item not found\n";
	return false;
}