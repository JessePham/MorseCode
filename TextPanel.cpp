#include "TextPanel.hpp"

void TextPanel::init()
{
	// ------------------------------------------------------------------------------------
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);
	
	wxPanel *textInput_panel = new wxPanel(this, wxID_ANY);
	wxSizer *textInput_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText *choose_text = new wxStaticText(textInput_panel, wxID_ANY,
                                                 "Enter Text:");
												 
	textbox = new wxTextCtrl(textInput_panel, wxID_ANY, "");
	textbox->SetSizeHints(200,40);
	
	wxButton *translate_button     = new wxButton(textInput_panel, wxID_ANY,
                                             textbox->GetValue());
	translate_button->Bind    (wxEVT_BUTTON, &TextPanel::onClickTranslate, this);
	translate_button->SetLabel("Translate");
	
	textInput_sizer->Add(choose_text, 0, wxALIGN_CENTER, 0);
	textInput_sizer->AddSpacer(10);
	textInput_sizer->Add(textbox, 0, wxALIGN_CENTER, 0);
	textInput_sizer->AddSpacer(10);
	textInput_sizer->Add(translate_button, 0, wxALIGN_CENTER, 0);
	textInput_panel->SetSizer(textInput_sizer);
	// ------------------------------------------------------------------------------------
	wxPanel *textOutput_panel = new wxPanel(this, wxID_ANY);
	wxSizer *textOutput_sizer = new wxBoxSizer(wxHORIZONTAL);
	
	wxStaticText *out = new wxStaticText(textOutput_panel, wxID_ANY,
                                                 "Output:");
	output_text = new wxTextCtrl(textOutput_panel, wxID_ANY, "");
	output_text->SetEditable(false);
	output_text->SetSizeHints(350,40);
    output_text->SetFont(output_text->GetFont().Larger());
	
	textOutput_sizer->Add(out, 0, wxALIGN_CENTER, 0);
	textOutput_sizer->AddSpacer(10);
    textOutput_sizer->Add(output_text, 0, wxALIGN_CENTER, 0);
    textOutput_sizer->AddSpacer(10);
	
    textOutput_panel->SetSizer(textOutput_sizer);
	// ------------------------------------------------------------------------------------
	
	main_sizer->Add(textInput_panel, 0, wxALIGN_CENTER, 0);
	main_sizer->AddSpacer(10);
	main_sizer->Add(textOutput_panel, 0, wxALIGN_CENTER, 0);

    SetSizer(main_sizer);
}

void TextPanel::onClickTranslate(wxCommandEvent& event)
{
    translate();
}

void TextPanel::translate()
{
	if (morseCodeOutput)
		output_text->ChangeValue(stringToMorse(textbox->GetValue()));
	else
	{
		//output_text->ChangeValue(morseToString(textbox->GetValue()));
		output_text->ChangeValue("Not implemented yet");
	}
}

void TextPanel::setMorseCoutOutput(bool in)
{
	morseCodeOutput = in;
}

/*====CHANGE THIS IMPLEMENTATION!!!====*/
wxString TextPanel::stringToMorse(wxString input)
{
	input.MakeLower();
	wxString output = "";
	
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'a')
			output += ".- ";
		else if (input[i] == 'b')
			output += "-... ";
		else if (input[i] == 'c')
			output += "-.-. ";
		else if (input[i] == 'd')
			output += "-.. ";
		else if (input[i] == 'e')
			output += ". ";
		else if (input[i] == 'f')
			output += "..-. ";
		else if (input[i] == 'g')
			output += "--. ";
		else if (input[i] == 'h')
			output += ".... ";
		else if (input[i] == 'i')
			output += ".. ";
		else if (input[i] == 'j')
			output += ".--- ";
		else if (input[i] == 'k')
			output += "-.- ";
		else if (input[i] == 'l')
			output += ".-.. ";
		else if (input[i] == 'm')
			output += "-- ";
		else if (input[i] == 'n')
			output += "-. ";
		else if (input[i] == 'o')
			output += "--- ";
		else if (input[i] == 'p')
			output += ".--. ";
		else if (input[i] == 'q')
			output += "--.- ";
		else if (input[i] == 'r')
			output += ".-. ";
		else if (input[i] == 's')
			output += "... ";
		else if (input[i] == 't')
			output += "- ";
		else if (input[i] == 'u')
			output += "..- ";
		else if (input[i] == 'v')
			output += "...- ";
		else if (input[i] == 'w')
			output += ".-- ";
		else if (input[i] == 'x')
			output += "-..- ";
		else if (input[i] == 'y')
			output += "-.-- ";
		else if (input[i] == 'z')
			output += "--.. ";
		else if (input[i] == ' ')
			output += "/ ";
	}
	
	return output;
}