#include "StringtoMorse.hpp"

StringtoMorse::StringtoMorse()
{
    mapCreate();
    output = "";
}
void StringtoMorse::translate(wxTextCtrl *output_text, wxTextCtrl *textbox)
{
    wxString input = textbox->GetValue();
  
    for(int i = 0; i<input.length(); i++)
    {
        output += wxTranslate(input[i]);
        output_text->ChangeValue(output);
    
    }
}
wxString StringtoMorse::clear()
{
    output = "";
    return output;
}
void StringtoMorse::mapCreate()
{
    std::string a = "a";
    for(int i = 1 ; i<27;i++)
    {
        //Maps a-z equal to 1-26
        StringIntMap.insert(std::pair<std::string, int>(a,i));
        (int)a[0]++;
    }
    std::string ampersand = "&";
    for(int i = 27 ; i<48;i++)
    {
        //Maps & - : in Ascii equal to 27-47
        StringIntMap.insert(std::pair<std::string, int>(ampersand,i));
        (int)ampersand[0]++;
    }
    StringIntMap.insert(std::pair<std::string, int>("!",48));
    StringIntMap.insert(std::pair<std::string, int>("?",49));
    StringIntMap.insert(std::pair<std::string, int>("=",50));
    StringIntMap.insert(std::pair<std::string, int>("_",51));
    StringIntMap.insert(std::pair<std::string, int>("\"",52));
    StringIntMap.insert(std::pair<std::string, int>("$",53));
    StringIntMap.insert(std::pair<std::string, int>("@",54));
    StringIntMap.insert(std::pair<std::string, int>(" ",55));
    StringIntMap.insert(std::pair<std::string, int>("",56));

    



}
wxString StringtoMorse::wxTranslate(wxString input)
{
    
    input.MakeLower();

    wxString output = "";
    switch(StringIntMap[std::string(input.mb_str())])
    {
        case 1: output = ".- "; break;
        case 2: output = "-... "; break;
        case 3: output = "-.-. "; break;
        case 4: output = "-.. "; break;
        case 5: output = ". "; break;
        case 6: output = "..-. "; break;
        case 7: output = "--. "; break;
        case 8: output = ".... "; break;
        case 9: output = ".. "; break;
        case 10: output = ".--- "; break;
        case 11: output = "-.- "; break;
        case 12: output = ".-.. "; break;
        case 13: output = "-- "; break;
        case 14: output = "-. "; break;
        case 15: output = "--- "; break;
        case 16: output = ".--. "; break;
        case 17: output = "--.- "; break;
        case 18: output = ".-. ";break;
        case 19: output = "... ";break;
        case 20: output = "- "; break;
        case 21: output = "..- "; break;
        case 22: output = "...- "; break;
        case 23: output = ".-- "; break;
        case 24: output = "-..- "; break;
        case 25: output = "-.-- "; break;
        case 26: output = "--.. "; break;
        case 27: output = ".-... "; break;
        case 28: output = ".----. "; break;
        case 29: output = "-.--. "; break;
        case 30: output = "-.--.- "; break;
        case 31: output = "? "; break;
        case 32: output = ".-.-. "; break;
        case 33: output = "--..-- "; break;
        case 34: output = "-....- "; break;
        case 35: output = ".-.-.- "; break;
        case 36: output = "-..-. "; break;
        case 37: output = "----- "; break;
        case 38: output = ".---- "; break;
        case 39: output = "..--- "; break;
        case 40: output = "...-- "; break;
        case 41: output = "....- "; break;
        case 42: output = "..... "; break;
        case 43: output = "-.... "; break;
        case 44: output = "--... "; break;
        case 45: output = "---.. "; break;
        case 46: output = "----. "; break;
        case 47: output = "-.-.-. "; break;
        case 48: output = "-.-.-- "; break;
        case 49: output = "..--.. "; break;
        case 50: output = "-...- "; break;
        case 51: output = "..--.- "; break;
        case 52: output = ".-..-. "; break;
        case 53: output = "...-..- "; break;
        case 54: output = ".--.-. "; break;
        case 55: output = "/ "; break;
        case 56: output = " "; break;
        default: output = "? "; break;
    }
    return output;
}