#include "App.h"
#include "MainFrame.h"
#include <wx-3.2/wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("C++ GUI");
    mainFrame->Show();
    return true;
}


