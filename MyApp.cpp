#include "Frame.hpp"
#include "MyApp.hpp"

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(ID_Hello,   Frame::OnHello)
    EVT_MENU(wxID_EXIT,  Frame::OnExit)
    EVT_MENU(wxID_ABOUT, Frame::OnAbout)
wxEND_EVENT_TABLE()

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Frame *frame = new Frame(wxT("Hello World"));
    frame->Show( true );
    return true;
}