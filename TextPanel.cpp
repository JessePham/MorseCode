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
	//translate_button->Hide();
	
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
	
	output_text->ChangeValue(S2M.clear());
	S2M.translate(output_text,textbox);
}

void TextPanel::translate()
{
	// if (morseCodeOutput)
	// 	output_text->ChangeValue(stringToMorse(textbox->GetValue()));
	// else
	// {
	// 	output_text->ChangeValue(morseToString(textbox->GetValue()));
	// 	//output_text->ChangeValue("Not implemented yet");
	// }
	

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
		else if (input[i] == '1')
			output += ".---- ";
		else if (input[i] == '2')
			output += "..--- ";
		else if (input[i] == '3')
			output += "...-- ";
		else if (input[i] == '4')
			output += "....- ";
		else if (input[i] == '5')
			output += "..... ";
		else if (input[i] == '6')
			output += "-.... ";
		else if (input[i] == '7')
			output += "--... ";
		else if (input[i] == '8')
			output += "---.. ";
		else if (input[i] == '9')
			output += "----. ";
		else if (input[i] == '0')
			output += "----- ";
	}
	
	return output;
}

wxString TextPanel::morseToString(wxString input)
{
	wxString output_string = "";
	int i = 0;
	
	while (i < input.length())
	{
		if (input[i] == '.')	// First dot
		{
			i++;
			if (input[i] == ' ')
			{
				output_string += 'e';
				i++;
				continue;
			}
			else if (input[i] == '.')	// Second dot
			{
				i++;
				if (input[i] == ' ')
				{
					output_string += 'i';
					i++;
					continue;
				}
				else if (input[i] == '.')	// Third dot
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 's';
						i++;
						continue;
					}
					else if (input[i] == '.')	// Fourth dot
					{
						i++;
						if (input[i] == ' ')
						{
							output_string += 'h';
							i++;
							continue;
						}
						else if (input[i] == '.')
						{
							output_string += '5';
							i++;
							continue;
						}
						else if (input[i] == '-')
						{
							output_string += '4';
							i++;
							continue;
						}
					}
					else if (input[i] == '-')
					{
						i++;
						if (input[i] == ' ')
						{
							output_string += 'v';
							i++;
							continue;
						}
						else if (input[i] == '-')
						{
							output_string += '3';
							i++;
							continue;
						}
					}
				}
				else if (input[i] == '-')
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'u';
						i++;
						continue;
					}
					else if (input[i] == '.')
					{
						output_string += 'f';
						i++;
						continue;
					}
					else if (input[i] == '-')
					{
						i++;
						if (input[i] == '-')
						{
							output_string += '2';
							i++;
							continue;
						}
						
						else
						{
							output_string = "Invalid";
							break;
						}
					}
				}
				
			}
			
			else if (input[i] == '-')
			{
				i++;
				if (input[i] == ' ')
				{
					output_string += 'a';
						i++;
					continue;
				}
				else if (input[i] == '.')
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'r';
						i++;
						continue;
					}
					else if (input[i] == '.')
					{
						output_string += 'l';
						i++;
						continue;
					}
				}
				else if (input[i] == '-')
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'w';
						i++;
						continue;
					}
					else if (input[i] == '.')
					{
						output_string += 'p';
						i++;
						continue;
					}
					else if (input[i] == '-')
					{
						i++;
						if (input[i] == ' ')
						{
							output_string += 'j';
							i++;
							continue;
						}
						else if (input[i] == '-')
						{
							output_string += '1';
							i++;
							continue;
						}
					}
				}
			}
		}
		
		else if (input[i] == '-') // STARTS WITH DASH
		{
			i++;
			if (input[i] == ' ')
			{
				output_string += 't';
				i++;
				continue;
			}
			else if (input[i] == '.')	// Second
			{
				i++;
				if (input[i] == ' ')
				{
					output_string += 'n';
					i++;
					continue;
				}
				else if (input[i] == '.')	// Third
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'd';
						i++;
						continue;
					}
					else if (input[i] == '.')	// Fourth
					{
						i++;
						if (input[i] == ' ')
						{
							output_string += 'b';
							i++;
							continue;
						}
						else if (input[i] == '.')
						{
							output_string += '6';
							i++;
							continue;
						}
					}
					else if (input[i] == '-')
					{
						output_string += 'x';
						i++;
						continue;
					}
				}
				else if (input[i] == '-')
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'k';
						i++;
						continue;
					}
					else if (input[i] == '.')
					{
						output_string += 'c';
						i++;
						continue;
					}
					else if (input[i] == '-')
					{
						output_string += 'y';
						i++;
						continue;
					}
				}
				
			}
			
			else if (input[i] == '-')		// SECOND
			{
				i++;
				if (input[i] == ' ')
				{
					output_string += 'm';
						i++;
					continue;
				}
				else if (input[i] == '.')		// THIRD
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'g';
						i++;
						continue;
					}
					else if (input[i] == '.')		// FOURTH
					{
						i++;
						if (input[i] == ' ')
						{
							output_string += 'z';
							i++;
							continue;
						}
						
						else if (input[i] == '.')
						{
							output_string += '7';
							i++;
							continue;
						}
					}
					else if (input[i] == '-')
					{
						output_string += 'q';
						i++;
						continue;
					}
				}
				else if (input[i] == '-')
				{
					i++;
					if (input[i] == ' ')
					{
						output_string += 'o';
						i++;
						continue;
					}
					else if (input[i] == '.')
					{
						i++;
						if (input[i] == '.')
						{
							output_string += '8';
							i++;
							continue;
						}
						
						else
						{
							output_string = "Invalid";
							break;
						}
					}
					else if (input[i] == '-')
					{
						i++;
						if (input[i] == '.')
						{
							output_string += '9';
							i++;
							continue;
						}
						else if (input[i] == '-')
						{
							output_string += '0';
							i++;
							continue;
						}
					}
				}
			}
		}
		else if (input[i] == '/')
		{
			output_string += ' ';
			i++;
		}
		else if (input[i] == ' ')
		{
			i++;
		}
		else
		{
			output_string = "Invalid Morse Code";
			break;
		}
	}
	
	return output_string;
}