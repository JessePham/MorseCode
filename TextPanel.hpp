#include "wx/wx.h"
#include "MyApp.hpp"
#include <iostream>
#include <wx/textentry.h>

class TextPanel : public wxPanel
{
public:
	TextPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

	void onClickTranslate(wxCommandEvent& event);
private:
	wxTextCtrl* textbox;
	wxStaticText *output_text;
	
	void translate();
	void init();
};