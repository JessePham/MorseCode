#include "MorsetoString.hpp"

MorsetoString::MorsetoString()
{
    mapCreate();
}

void MorsetoString::translate(wxTextCtrl *output_text, wxTextCtrl *textbox)
{
        wxString input = textbox->GetValue();
        mLetter = "";
        for(int i = 0; i<input.length(); i++)
        {
            if(input[i] == ' ')
            {
             output += wxTranslate(mLetter);
             output_text->ChangeValue(output); 
             mLetter = "";
            }
            else
            {
                mLetter += input[i];
            }
        }
        // output = wxTranslate(input[0]);
        // output_text->ChangeValue(output);
}


void MorsetoString::mapCreate()
{
    std::string dot = ".";
    std::string ddot = dot+dot;
    std::string tdot = dot + dot + dot;
    std::string dash = "-";
    std::string ddash = dash + dash;
    std::string tdash = dash + dash + dash;
    std::string temp = dot + dash;
    temp = dash + dot + dot + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,1));
    temp = dash + dot + dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,2));
    temp = dash + dot + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,3));
    temp = dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,4));
    temp = dot + dot + dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,5));
    temp = dash + dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,6));
    temp = dot + dot + dot  + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,7));
    temp = dot + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,8));
    temp = dot + dash + dash + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,9));
    temp = dash + dot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,10));
    temp = dot + dash + dot + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,11));
    temp = ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,12));
    temp = dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,13));
    temp = tdash;
    StringIntMap.insert(std::pair<std::string, int>(temp,14));
    temp = dot + ddash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,15));
    temp = ddash + dot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,16));
    temp = dot + dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,17));
    temp = tdot;
    StringIntMap.insert(std::pair<std::string, int>(temp,18));
    temp = dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,19));
    temp = ddot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,20));
    temp = tdot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,21));
    temp = dot + ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,22));
    temp = dash + ddot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,23));
    temp = dash + dot + ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,24));
    temp = ddash + ddot;
    StringIntMap.insert(std::pair<std::string, int>(temp,25));
    temp = tdash + ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,26));
    temp = dot + ddash + ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,27));
    temp = ddot + tdash;
    StringIntMap.insert(std::pair<std::string, int>(temp,28));
    temp = tdot + ddash;
    StringIntMap.insert(std::pair<std::string, int>(temp,29));
    temp = tdot + dot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,30));
    temp = "/";
    StringIntMap.insert(std::pair<std::string, int>(temp,31));
    temp = ddot + tdot;
    StringIntMap.insert(std::pair<std::string, int>(temp,32));
    temp = dash + ddot + ddot;
    StringIntMap.insert(std::pair<std::string, int>(temp,33));
    temp = ddash + tdot;
    StringIntMap.insert(std::pair<std::string, int>(temp,34));
    temp = tdash + ddot;
    StringIntMap.insert(std::pair<std::string, int>(temp,35));
    temp = tdash + dash + dot;
    StringIntMap.insert(std::pair<std::string, int>(temp,36));
    temp = dot + dash + dot +dash + dot + dash;         // .
    StringIntMap.insert(std::pair<std::string, int>(temp,37));
    temp = ddash + ddot + ddash;                        // ,
    StringIntMap.insert(std::pair<std::string, int>(temp,38));
    temp = ddot + ddash + ddot;                         // ?
    StringIntMap.insert(std::pair<std::string, int>(temp,39));
    temp = dot + tdash + dash + dot;                    // '
    StringIntMap.insert(std::pair<std::string, int>(temp,40));
    temp = dash + dot + dash + dot + ddash;             // !
    StringIntMap.insert(std::pair<std::string, int>(temp,41));
    temp = dash + ddot + dash + dot;                    // /
    StringIntMap.insert(std::pair<std::string, int>(temp,42));
    temp = dash + dot + ddash + dot + dash;             // )
    StringIntMap.insert(std::pair<std::string, int>(temp,43));
    temp = dot + dash + tdot;                         //&              // NOTE add "(" and look at wikipedia for complete guide to follow
    StringIntMap.insert(std::pair<std::string, int>(temp,44));
    temp = tdash + tdot;                              // :
    StringIntMap.insert(std::pair<std::string, int>(temp,45));
    temp = dash + dot + dash + dot + dash + dot;        // ;
    StringIntMap.insert(std::pair<std::string, int>(temp,46));
    temp = dash + tdot + dash;                      //=
    StringIntMap.insert(std::pair<std::string, int>(temp,47));
    temp = dot + dash + dot + dash + dot;           // +
    StringIntMap.insert(std::pair<std::string, int>(temp,48));
    temp = dash + tdot + dot + dash;                //-
    StringIntMap.insert(std::pair<std::string, int>(temp,49));
    temp = ddot + ddash + dot + dash;               //_
    StringIntMap.insert(std::pair<std::string, int>(temp,50));
    temp = dot + dash + ddot + dash + dot;          // "
    StringIntMap.insert(std::pair<std::string, int>(temp,51));
    temp = tdot + dash + ddot + dash;               // $
    StringIntMap.insert(std::pair<std::string, int>(temp,52));
    temp = dot + ddash + dot + dash + dot;          //@
    StringIntMap.insert(std::pair<std::string, int>(temp,53));
    temp = dash + dot + ddash + dot;                //(
    StringIntMap.insert(std::pair<std::string, int>(temp,54));
    temp = dot + dash;
    StringIntMap.insert(std::pair<std::string, int>(temp,55));
    temp = "";
    StringIntMap.insert(std::pair<std::string, int>(temp,56));
   

}
wxString MorsetoString::clear()
{
    output = "";
    return output;
}
wxString MorsetoString::wxTranslate(wxString input)
{
   wxString output = "";
    switch(StringIntMap[std::string(input.mb_str())])
    {
        
        case 1: output = "B"; break; 
        case 2: output = "C"; break; 
        case 3: output = "D"; break; 
        case 4: output = "E"; break; 
        case 5: output = "F"; break; 
        case 6: output = "G"; break; 
        case 7: output = "H"; break; 
        case 8: output = "I"; break; 
        case 9: output = "J"; break; 
        case 10: output = "K"; break; 
        case 11: output = "L"; break; 
        case 12: output = "M"; break; 
        case 13: output = "N"; break; 
        case 14: output = "O"; break; 
        case 15: output = "P"; break; 
        case 16: output = "Q"; break; 
        case 17: output = "R"; break; 
        case 18: output = "S"; break; 
        case 19: output = "T"; break; 
        case 20: output = "U"; break; 
        case 21: output = "V"; break; 
        case 22: output = "W"; break; 
        case 23: output = "X"; break; 
        case 24: output = "Y"; break; 
        case 25: output = "Z"; break; 
        case 26: output = "0"; break; 
        case 27: output = "1"; break; 
        case 28: output = "2"; break; 
        case 29: output = "3"; break; 
        case 30: output = "4"; break; 
        case 31: output = " "; break; 
        case 32: output = "5"; break; 
        case 33: output = "6"; break; 
        case 34: output = "7"; break; 
        case 35: output = "8"; break; 
        case 36: output = "9"; break; 
        case 37: output = "."; break; 
        case 38: output = ","; break; 
        case 39: output = "?"; break; 
        case 40: output = "\'"; break; 
        case 41: output = "!"; break; 
        case 42: output = "/"; break; 
        case 43: output = ")"; break;
        case 44: output = "&"; break; 
        case 45: output = ":"; break; 
        case 46: output = ";"; break; 
        case 47: output = "="; break; 
        case 48: output = "+"; break; 
        case 49: output = "-"; break; 
        case 50: output = "_"; break; 
        case 51: output = "\""; break; 
        case 52: output = "$"; break; 
        case 53: output = "@"; break; 
        case 54: output = "("; break;  
        case 55: output = "A"; break;  
        case 56: output = ""; break;
        default: output = "Invalid Code "; break;
    }
    return output;
}
