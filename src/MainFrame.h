#pragma once
#include <wx-3.2/wx/wx.h>
#include <wx-3.2/wx/simplebook.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    //Main Components
    wxStaticText* headLine;
    wxSimplebook* book;
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
    wxPanel* a_Paneld11;
    wxStaticText* a_idLabel;
    wxStaticText* a_nameLabel;
    wxStaticText* a_emailLabel;
    wxTextCtrl* a_idCamp;
    wxTextCtrl* a_nameCamp;
    wxTextCtrl* a_emailCamp;
    wxButton* a_insertUserButton;
    wxButton* a_deleteMode;
    wxButton* a_searchMode;
    wxBoxSizer* a_addPanelSizer;
    wxBoxSizer* a_paneld1Sizer;
    wxBoxSizer* a_paneld2Sizer;
    wxBoxSizer* a_paneld11Sizer;
    // Delete User Components
    wxPanel* d_deletePanel;
    wxPanel* d_Paneld1;
    wxPanel* d_Paneld2;
    wxPanel* d_Paneld11;
    wxTextCtrl* d_searchBar;
    wxButton* d_submitSearchButton;
    wxButton* d_deleteUserButton;
    wxListBox* d_searchResults;
    wxButton* d_searchMode;
    wxButton* d_insertMode;
    wxBoxSizer* d_panelBoxSizer;
    wxBoxSizer* d_BoxSizer1;
    wxBoxSizer* d_BoxSizer2;
    wxBoxSizer* d_BoxSizer11;
private:
    //Initializers
    void initSearchPanel();
    void initAddPanel();
    void initDeletePanel();
    // Event handlers
    void setAddView(wxCommandEvent& evt);
    void setSearchView(wxCommandEvent& evt);
    void setDeleteView(wxCommandEvent& evt);
};
