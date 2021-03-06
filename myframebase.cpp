///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "myframebase.h"

///////////////////////////////////////////////////////////////////////////

MyFrameBase::MyFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* vertSizer1;
	vertSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* horzSizer1;
	horzSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( mainPanel, wxID_ANY, wxT("Input Directory") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	inDirPicker = new wxDirPickerCtrl( mainPanel, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	gbSizer2->Add( inDirPicker, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	inDirTextCtrl = new wxTextCtrl( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	gbSizer2->Add( inDirTextCtrl, wxGBPosition( 1, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	
	gbSizer2->AddGrowableCol( 0 );
	gbSizer2->AddGrowableRow( 1 );
	
	sbSizer1->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	
	horzSizer1->Add( sbSizer1, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( mainPanel, wxID_ANY, wxT("Output Directory") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 0, 0 );
	gbSizer3->SetFlexibleDirection( wxBOTH );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	outDirPicker = new wxDirPickerCtrl( mainPanel, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	gbSizer3->Add( outDirPicker, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	outDirTextCtrl = new wxTextCtrl( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	gbSizer3->Add( outDirTextCtrl, wxGBPosition( 1, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	
	gbSizer3->AddGrowableCol( 0 );
	gbSizer3->AddGrowableRow( 1 );
	
	sbSizer2->Add( gbSizer3, 1, wxEXPAND, 5 );
	
	
	horzSizer1->Add( sbSizer2, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	vertSizer1->Add( horzSizer1, 3, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	vertSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( mainPanel, wxID_ANY, wxT("Debug") ), wxVERTICAL );
	
	debugTextCtrl = new wxTextCtrl( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	sbSizer3->Add( debugTextCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	vertSizer1->Add( sbSizer3, 2, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	mainPanel->SetSizer( vertSizer1 );
	mainPanel->Layout();
	vertSizer1->Fit( mainPanel );
	mainSizer->Add( mainPanel, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	menuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* unusedItem;
	unusedItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Unused") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( unusedItem );
	
	wxMenuItem* closeItem;
	closeItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( closeItem );
	
	menuBar->Append( fileMenu, wxT("&File") ); 
	
	runMenu = new wxMenu();
	wxMenuItem* runMenuItem;
	runMenuItem = new wxMenuItem( runMenu, wxID_ANY, wxString( wxT("RUN!") ) , wxEmptyString, wxITEM_NORMAL );
	runMenu->Append( runMenuItem );
	

	wxMenuItem* clearMenu;
	clearMenu = new wxMenuItem( runMenu, wxID_ANY, wxString( wxT("Clear") ) , wxEmptyString, wxITEM_NORMAL );
	runMenu->Append( clearMenu );
	
	wxMenuItem* copyMenuItem;
	copyMenuItem = new wxMenuItem( runMenu, COPY_FILE, wxString( wxT("Copy Files") ) , wxEmptyString, wxITEM_CHECK );
	runMenu->Append( copyMenuItem );
	
	menuBar->Append( runMenu, wxT("&Run") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* aboutItem;
	aboutItem = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( aboutItem );
	
	menuBar->Append( helpMenu, wxT("&Help") ); 
	
	this->SetMenuBar( menuBar );
	
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	inDirPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrameBase::onInputSelect ), NULL, this );
	outDirPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrameBase::onOutputSelect ), NULL, this );
	this->Connect( unusedItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onUnused ) );
	this->Connect( closeItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onClose ) );
	this->Connect( runMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onRun ) );
	this->Connect( clearMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onClear ) );
	this->Connect( aboutItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onAbout ) );
}

MyFrameBase::~MyFrameBase()
{
	// Disconnect Events
	inDirPicker->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrameBase::onInputSelect ), NULL, this );
	outDirPicker->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrameBase::onOutputSelect ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onUnused ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onRun ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onClear ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::onAbout ) );
	
}

ProgressBase::ProgressBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxBOTH );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Progress"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gbSizer4->Add( m_staticText9, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 ); 
	gbSizer4->Add( m_gauge1, wxGBPosition( 1, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer32->Add( m_staticText12, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("%d"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer32->Add( m_staticText13, 0, wxTOP|wxBOTTOM, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("of"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer32->Add( m_staticText14, 0, wxALL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("%d"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer32->Add( m_staticText15, 0, wxTOP|wxBOTTOM, 5 );
	
	
	gbSizer4->Add( bSizer32, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	gbSizer4->AddGrowableCol( 0 );
	
	this->SetSizer( gbSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ProgressBase::~ProgressBase()
{
}
