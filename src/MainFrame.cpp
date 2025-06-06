#include "MainFrame.h"
#include "wx/gdicmn.h"
#include "wx/generic/panelg.h"
#include "wx/gtk/button.h"
#include "wx/gtk/stattext.h"
#include "wx/sizer.h"
#include <wx-3.2/wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    //Setting up the window
    this->SetClientSize(800, 500);
    this->Center();
    // Components
    initDeletePanel();
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

void MainFrame::initAddPanel() {
    a_addPanel = new wxPanel(this);
    a_Paneld1 = new wxPanel(a_addPanel);
    a_Paneld2 = new wxPanel(a_addPanel);
    a_Paneld11 = new wxPanel(a_Paneld1);

    a_idLabel = new wxStaticText(a_Paneld1, wxID_ANY, "ID");
    a_idCamp = new wxTextCtrl(a_Paneld1, wxID_ANY, "");

    a_nameLabel = new wxStaticText(a_Paneld1, wxID_ANY, "NOMBRE");
    a_nameCamp = new wxTextCtrl(a_Paneld1, wxID_ANY, "");

    a_emailLabel = new wxStaticText(a_Paneld1, wxID_ANY, "CORREO");
    a_emailCamp = new wxTextCtrl(a_Paneld1, wxID_ANY, "");

    a_insertUserButton = new wxButton(a_Paneld2, wxID_ANY, "Insertar Usuario");
    a_deleteMode = new wxButton(a_Paneld11, wxID_ANY, "Eliminar Usuario");
    a_searchMode = new wxButton(a_Paneld11, wxID_ANY, "Buscar Usuario");

    a_addPanelSizer = new wxBoxSizer(wxHORIZONTAL);
    a_paneld1Sizer = new wxBoxSizer(wxVERTICAL);
    a_paneld2Sizer = new wxBoxSizer(wxVERTICAL);
    a_paneld11Sizer = new wxBoxSizer(wxHORIZONTAL);
    
    a_addPanelSizer->Add(a_Paneld1, 4, wxEXPAND);
    a_addPanelSizer->Add(a_Paneld2, 1, wxEXPAND);
    a_addPanel->SetSizerAndFit(a_addPanelSizer);

    a_paneld1Sizer->Add(a_idLabel, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_idCamp, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_nameLabel, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_nameCamp, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_emailLabel, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_emailCamp, 0, wxEXPAND);
    a_paneld1Sizer->Add(a_Paneld11, 0, wxEXPAND);
    a_Paneld1->SetSizerAndFit(a_paneld1Sizer);

    a_paneld11Sizer->Add(a_deleteMode, 1, wxEXPAND);
    a_paneld11Sizer->Add(a_searchMode, 1, wxEXPAND);
    a_Paneld11->SetSizerAndFit(a_paneld11Sizer);

    a_paneld2Sizer->Add(a_insertUserButton, 0, wxEXPAND);
    a_Paneld2->SetSizerAndFit(a_paneld2Sizer);
}

void MainFrame::initDeletePanel() {
    d_deletePanel = new wxPanel(this, wxID_ANY);
    d_Paneld1 = new wxPanel(d_deletePanel, wxID_ANY);
    d_Paneld2 = new wxPanel(d_deletePanel, wxID_ANY);
    d_searchBar = new wxTextCtrl(d_Paneld1, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 35));
    d_submitSearchButton = new wxButton(d_Paneld2, wxID_ANY, "Buscar");
    d_deleteUserButton = new wxButton(d_Paneld2, wxID_ANY, "Eliminar Usuario");
    d_searchResults = new wxListBox(d_Paneld1, wxID_ANY);

    d_Paneld11 = new wxPanel(d_Paneld1, wxID_ANY);
    d_insertMode = new wxButton(d_Paneld11, wxID_ANY, "Insertar Usuario");
    d_searchMode= new wxButton(d_Paneld11, wxID_ANY, "Buscar Usuario");

    d_BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    d_BoxSizer11->Add(d_insertMode, 1, wxEXPAND);
    d_BoxSizer11->Add(d_searchMode, 1, wxEXPAND);
    d_Paneld11->SetSizerAndFit(d_BoxSizer11);

    d_BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    d_BoxSizer1->Add(d_searchBar, 0, wxEXPAND);
    d_BoxSizer1->Add(d_searchResults, 9, wxEXPAND);
    d_BoxSizer1->Add(d_Paneld11, 1, wxEXPAND);

    d_Paneld1->SetSizerAndFit(d_BoxSizer1);

    d_BoxSizer2 = new wxBoxSizer(wxVERTICAL);

    d_BoxSizer2->Add(d_submitSearchButton, 0, wxEXPAND);
    d_BoxSizer2->Add(d_deleteUserButton, 0, wxEXPAND);
    d_Paneld2->SetSizerAndFit(d_BoxSizer2);

    d_panelBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    d_panelBoxSizer->Add(d_Paneld1, 5, wxEXPAND);
    d_panelBoxSizer->Add(d_Paneld2, 1, wxEXPAND);

    d_deletePanel->SetSizerAndFit(d_panelBoxSizer);
    
}
