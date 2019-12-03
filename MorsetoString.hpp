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
    wxString clear();
    void parseWhiteSpace(wxString input);

    private:
    void mapCreate();
    wxString mLetter;
    wxString output;
    std::map<std::string,int> StringIntMap;

};