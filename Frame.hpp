#ifndef	FRAME_HPP
#define	FRAME_HPP

#include <wx/wx.h>
#include "TextPanel.hpp"

class Frame : public wxFrame
{
public:
	Frame(const wxString& title);
private:
    void OnStringtoMorse(wxCommandEvent& event);
	void OnMorsetoString(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	
    wxDECLARE_EVENT_TABLE();
	TextPanel *text_panel;
	
};

enum
{
	ID_STOMC = 1,
	ID_MCTOS = 2
};

#endif