#ifndef	FRAME_HPP
#define	FRAME_HPP

#include <wx/wx.h>
#include "TextPanel.hpp"

class Frame : public wxFrame
{
public:
	Frame(const wxString& title);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	
    wxDECLARE_EVENT_TABLE();
	TextPanel *text_panel;
	
};

enum
{
	ID_Hello = 2
};

#endif