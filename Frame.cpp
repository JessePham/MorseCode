#include "Frame.hpp"

const int SIDE_MARGINS = 400;

Frame::Frame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)), 
            text_panel(new TextPanel(this))
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_STOMC, "&String to Morse Code\tCtrl-S",
                     "String to Morse Code");
    menuFile->AppendSeparator();
	menuFile->Append(ID_MCTOS, "&Morse Code to String\tCtrl-M",
					 "Morse Code to String");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Morse Code Generator" );
	
	wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);
	
    frame_sizer->AddSpacer(20);
    frame_sizer->Add(text_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);

    // Init size
    wxSize best_size = GetBestSize();
    SetMinClientSize(best_size);

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

void Frame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This application translates characters into morse code.",
                  "About Morse Code Generator", wxOK | wxICON_INFORMATION );
}

void Frame::OnStringtoMorse(wxCommandEvent& event)
{
	text_panel->setMorseCoutOutput(true);
    wxLogMessage("Switched to String to Morse Code");
}

void Frame::OnMorsetoString(wxCommandEvent& event)
{
	text_panel->setMorseCoutOutput(false);
	wxLogMessage("Switched to Morse Code to String");
}