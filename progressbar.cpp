#include "progressbar.h"

ProgressBar::ProgressBar( wxWindow* parent )
:
ProgressBase( parent )
{

}


void ProgressBar::setProgressRange(unsigned int fileCount){
	m_gauge1->SetRange(fileCount);
	m_staticText15->SetLabel(wxString::Format(_("%d"), fileCount));
	bSizer32->Layout();
}

void ProgressBar::setProgressValue(unsigned int fileCount){
	m_gauge1->SetValue(fileCount);
	m_staticText13->SetLabel(wxString::Format(_("%d"), fileCount));
	bSizer32->Layout();
	Update();
}