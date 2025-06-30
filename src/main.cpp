#include "main.h"

wxIMPLEMENT_APP(myApp);

bool myApp::OnInit()
{
    MainFrame *mainFrame = new MainFrame("C++ Gui");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}