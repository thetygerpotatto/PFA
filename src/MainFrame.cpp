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

    searchPanel = new wxPanel(this, wxID_ANY);
    sPaneld1 = new wxPanel(searchPanel, wxID_ANY);
    sPaneld2 = new wxPanel(searchPanel, wxID_ANY);
    searchBar = new wxTextCtrl(sPaneld1, wxID_ANY, "", wxDefaultPosition, wxSize(500, 25));
    submitSearchButton = new wxButton(sPaneld2, wxID_ANY, "buscar");
    radioBox = new wxRadioBox(sPaneld2, wxID_ANY, "modo", wxDefaultPosition, wxDefaultSize, 3, choices);
    searchResults = new wxListBox(sPaneld1, wxID_ANY);
    s_insertMode = new wxButton(sPaneld1, wxID_ANY, "Insert Mode");
    s_deleteMode= new wxButton(sPaneld1, wxID_ANY, "delete Mode");

    sBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    sBoxSizer1->Add(searchBar,1);
    sBoxSizer1->Add(searchResults, 1);
    sBoxSizer1->Add(s_insertMode, 1);
    sBoxSizer1->Add(s_deleteMode, 1);

    sPaneld1->SetSizerAndFit(sBoxSizer1);

    sBoxSizer2 = new wxBoxSizer(wxVERTICAL);

    sBoxSizer2->Add(submitSearchButton);
    sBoxSizer2->Add(radioBox);
    sPaneld2->SetSizerAndFit(sBoxSizer2);

    s_panelBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    s_panelBoxSizer->Add(sPaneld1, 1);
    s_panelBoxSizer->Add(sPaneld2, 1);

    searchPanel->SetSizerAndFit(s_panelBoxSizer);
}
