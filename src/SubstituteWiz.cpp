/*
 *  Copyright (C) 2004-2005 Andrej Vodopivec <andrejv@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */



#include "SubstituteWiz.h"


SubstituteWiz::SubstituteWiz(wxWindow* parent, int id, const wxString& title,
                             const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE)
{
  label_1 = new wxStaticText(this, -1, _("Substitute"));
  label_2 = new wxStaticText(this, -1, _("Substitute:"));
  text_ctrl_1 = new BTextCtrl(this, -1, wxT(""), wxDefaultPosition,
                              wxSize(230,-1));
  label_3 = new wxStaticText(this, -1, _("with:"));
  text_ctrl_2 = new BTextCtrl(this, -1, wxT(""), wxDefaultPosition,
                              wxSize(230,-1));
  label_4 = new wxStaticText(this, -1, _("in:"));
  text_ctrl_3 = new BTextCtrl(this, -1, wxT(""), wxDefaultPosition,
                              wxSize(230,-1));
  checkbox_1 = new wxCheckBox(this, -1, _("Rational"));
  static_line_1 = new wxStaticLine(this, -1);
  button_1 = new wxButton(this, wxID_OK, _("OK"));
  button_2 = new wxButton(this, wxID_CANCEL, _("Cancel"));
  
  set_properties();
  do_layout();
}


void SubstituteWiz::set_properties()
{
  SetTitle(_("Substitution"));
  label_1->SetFont(wxFont(22, wxROMAN, wxITALIC, wxNORMAL, 0, wxT("")));
  button_1->SetDefault();
}


void SubstituteWiz::do_layout()
{
  wxFlexGridSizer* grid_sizer_1 = new wxFlexGridSizer(3, 1, 3, 3);
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxHORIZONTAL);
  wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(4, 2, 3, 3);
  grid_sizer_1->Add(label_1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);
  grid_sizer_2->Add(label_2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 2);
  grid_sizer_2->Add(text_ctrl_1, 0, wxALL|wxEXPAND, 2);
  grid_sizer_2->Add(label_3, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 2);
  grid_sizer_2->Add(text_ctrl_2, 0, wxALL|wxEXPAND, 2);
  grid_sizer_2->Add(label_4, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 2);
  grid_sizer_2->Add(text_ctrl_3, 0, wxALL|wxEXPAND, 2);
  grid_sizer_2->Add(20, 20, 0, 0);
  grid_sizer_2->Add(checkbox_1, 0, wxALL, 2);
  grid_sizer_2->AddGrowableCol(1);
  grid_sizer_1->Add(grid_sizer_2, 1, wxEXPAND, 0);
  grid_sizer_1->Add(static_line_1, 0, wxEXPAND|wxLEFT|wxRIGHT, 2);
  sizer_1->Add(button_2, 0, wxALL, 2);
  sizer_1->Add(button_1, 0, wxALL, 2);
  grid_sizer_1->Add(sizer_1, 1, wxALIGN_RIGHT|wxBOTTOM, 2);
  SetAutoLayout(true);
  SetSizer(grid_sizer_1);
  grid_sizer_1->Fit(this);
  grid_sizer_1->SetSizeHints(this);
  grid_sizer_1->AddGrowableCol(0);
  Layout();
}

wxString SubstituteWiz::GetValue()
{
  wxString val;
  if (checkbox_1->IsChecked())
    val = wxT("ratsubst(");
  else
    val = wxT("subst(");
  val.Append(text_ctrl_2->GetValue());
  val.Append(wxT(", "));
  val.Append(text_ctrl_1->GetValue());
  val.Append(wxT(", "));
  val.Append(text_ctrl_3->GetValue());
  val.Append(wxT(");"));
  return val;
}
