#pragma once
#include <wx-3.2/wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    //Main Components
    wxStaticText* headLine;
    // Search Components
    wxPanel* searchPanel;
    wxPanel* sPaneld1;
    wxPanel* sPaneld2;
    wxTextCtrl* searchBar;
    wxButton* submitSearchButton;
    wxRadioBox* radioBox;
    wxString choices[3] = {"igual", "mayor igual", "menor igual"};
    wxListBox* searchResults;
    wxButton* s_deleteMode;
    wxButton* s_insertMode;
    wxBoxSizer* s_panelBoxSizer;
    wxBoxSizer* sBoxSizer1;
    wxBoxSizer* sBoxSizer2;

    wxPanel* addPanel;
    wxPanel* deletePanel;
private:
    void initSearchPanel();
};
