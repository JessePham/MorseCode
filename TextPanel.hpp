#include "wx/wx.h"
#include "MyApp.hpp"
#include <iostream>
#include <string>
#include "StringtoMorse.hpp"
#include "MorsetoString.hpp"
#include <wx/textentry.h>

class TextPanel : public wxPanel
{
public:
	TextPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

	void onClickTranslate(wxCommandEvent& event);
	void setMorseCoutOutput(bool);
private:
	wxTextCtrl *textbox;
	wxTextCtrl *output_text;
	StringtoMorse S2M;
	MorsetoString M2S;
	wxString stringToMorse(wxString);
	wxString morseToString(wxString);
	
	bool morseCodeOutput = true;
	
	void init();
};