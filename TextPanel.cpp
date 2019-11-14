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
	output_text = new wxStaticText(textOutput_panel, wxID_ANY, "[Morse Code Here]");
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
	output_text->SetLabelText(textbox->GetValue());
}