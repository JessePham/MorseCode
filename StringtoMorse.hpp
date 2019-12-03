#pragma once
#include "Convert.hpp"
#include <string.h>
#include <map>

class StringtoMorse : public Convert
{
    public:
    StringtoMorse();
    void translate(wxTextCtrl *output_text, wxTextCtrl *textbox);
    wxString clear();
    wxString wxTranslate(wxString input);
    
    private:
    void mapCreate();
    wxString output;
    std::map<std::string,int> StringIntMap;
 
    
    
};

