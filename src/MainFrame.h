#pragma once
#include "wx/sizer.h"
#include <wx-3.2/wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    //Main Components
    wxStaticText* headLine;

    // Search Components
    wxPanel* s_searchPanel;
    wxPanel* s_Paneld1;
    wxPanel* s_Paneld2;
    wxPanel* s_Paneld11;
    wxTextCtrl* s_searchBar;
    wxButton* s_submitSearchButton;
    wxRadioBox* s_radioBox;
    wxString choices[3] = {"igual", "mayor igual", "menor igual"};
    wxListBox* s_searchResults;
    wxButton* s_deleteMode;
    wxButton* s_insertMode;
    wxBoxSizer* s_panelBoxSizer;
    wxBoxSizer* s_BoxSizer1;
    wxBoxSizer* s_BoxSizer2;
    wxBoxSizer* s_BoxSizer11;
    // Add User Components
    wxPanel* a_addPanel;
    wxPanel* a_Paneld1;
    wxPanel* a_Paneld2;
    wxTextCtrl* a_idCamp;
    wxTextCtrl* a_nameCamp;
    wxTextCtrl* a_emailCamp;
    wxButton* a_insertUserButton;
    wxButton* a_deleteMode;
    wxButton* a_searchMode;
    wxBoxSizer* a_panelBoxSizer;
    wxBoxSizer* a_BoxSizer1;
    wxBoxSizer* a_BoxSizer2;
    // Delete User Components
    wxPanel* a_deletePanel;
private:
    void initSearchPanel();
    void initAddPanel();
};
