#pragma once

#include "Convert.hpp"
#include <string.h>
#include <map>

class MorsetoString : public Convert
{
    public:
    MorsetoString();
    void translate(wxTextCtrl *output_text, wxTextCtrl *textbox);
    wxString wxTranslate(wxString input);
    void parseWhiteSpace(wxString input);

    private:
    void mapCreate();
    wxString mLetter[500];
    wxString output;
    std::map<std::string,int> StringIntMap;

};