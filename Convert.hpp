#pragma once
#include "wx/wx.h"
#include <iostream>
#include <string>

class Convert
{
    public:
    virtual void translate(wxTextCtrl *output_text, wxTextCtrl *textbox) = 0;
    virtual wxString wxTranslate(wxString input) = 0;

};