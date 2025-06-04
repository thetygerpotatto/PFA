#include "MainFrame.h"
#include "wx/gdicmn.h"
#include "wx/generic/panelg.h"
#include "wx/gtk/button.h"
#include "wx/sizer.h"
#include <wx-3.2/wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    //Setting up the window
    this->SetClientSize(800, 500);
    this->Center();
    // Components
    initSearchPanel();
}

void MainFrame::initSearchPanel() {
    //wxStatusBar();

    s_searchPanel = new wxPanel(this, wxID_ANY);
    s_Paneld1 = new wxPanel(s_searchPanel, wxID_ANY);
    s_Paneld2 = new wxPanel(s_searchPanel, wxID_ANY);
    s_searchBar = new wxTextCtrl(s_Paneld1, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 35));
    s_submitSearchButton = new wxButton(s_Paneld2, wxID_ANY, "buscar");
    s_radioBox = new wxRadioBox(s_Paneld2, wxID_ANY, "modo", wxDefaultPosition, wxDefaultSize, 3, choices, 2, wxRA_VERTICAL);
    s_searchResults = new wxListBox(s_Paneld1, wxID_ANY);

    s_Paneld11 = new wxPanel(s_Paneld1, wxID_ANY);
    s_insertMode = new wxButton(s_Paneld11, wxID_ANY, "Insertar Usuario");
    s_deleteMode= new wxButton(s_Paneld11, wxID_ANY, "Eliminar Usuario");

    s_BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    s_BoxSizer11->Add(s_insertMode, 1, wxEXPAND);
    s_BoxSizer11->Add(s_deleteMode, 1, wxEXPAND);
    s_Paneld11->SetSizerAndFit(s_BoxSizer11);

    s_BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    s_BoxSizer1->Add(s_searchBar, 0, wxEXPAND);
    s_BoxSizer1->Add(s_searchResults, 9, wxEXPAND);
    s_BoxSizer1->Add(s_Paneld11, 1, wxEXPAND);

    s_Paneld1->SetSizerAndFit(s_BoxSizer1);

    s_BoxSizer2 = new wxBoxSizer(wxVERTICAL);

    s_BoxSizer2->Add(s_submitSearchButton, 0, wxEXPAND);
    s_BoxSizer2->Add(s_radioBox, 1);
    s_Paneld2->SetSizerAndFit(s_BoxSizer2);

    s_panelBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    s_panelBoxSizer->Add(s_Paneld1, 5, wxEXPAND);
    s_panelBoxSizer->Add(s_Paneld2, 1, wxEXPAND);

    s_searchPanel->SetSizerAndFit(s_panelBoxSizer);
}
