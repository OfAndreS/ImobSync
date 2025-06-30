#include <wx/wx.h>
#include <wx/sizer.h>

#include "test.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    myTestClass t;
    MyFrame *frame = new MyFrame(t.myTestPrint(), wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    new wxStaticText(this, wxID_ANY, "Hello my love!"); // no need to delete - the parent will do it automatically
}
