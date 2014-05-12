#include <wx/string.h>
#include <wx/datetime.h>
#include <memory>
#include <wx/filename.h>

class FileInfo{
public:
	FileInfo() {}

	FileInfo(wxString& parentDir, wxString& filePath) : filePath( filePath) , 
		timeModified(wxFileName(filePath).GetModificationTime() ) , shortPath( filePath) {	
		shortPath.Replace(parentDir, "", false);
	}
	
	bool operator>(const FileInfo& cmp){
		int cmpResult = shortPath.Cmp(cmp.shortPath);
		if (cmpResult > 0)
				return true;

		if (!cmpResult)
			if (timeModified.IsLaterThan(cmp.timeModified))
				return true;
	
		return false;
	}

	bool operator==(const FileInfo& cmp){		
		if (shortPath.IsSameAs(cmp.shortPath)) 
			if (timeModified.IsSameDate(cmp.timeModified))
				return true;

		return false;
	}

	void setCopytoPath(wxString& path){
		copyToPath.Clear();
		copyToPath.append(path).append(shortPath);
	}

	wxString& getFullPath(){
		return filePath;
	}

	wxString& getShortPath(){
		return shortPath;
	}

	wxString& getCopyToPath(){
		return copyToPath;
	}

private:
	wxString filePath;
	wxString shortPath;
	wxString copyToPath;
	wxDateTime timeModified;

};