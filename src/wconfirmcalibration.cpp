/////////////////////////////////////////////////////////////////////////////
// Name:        mouseoutput.h
// Purpose:  
// Author:      Cesar Mauri Loba (cesar at crea-si dot com)
// Modified by: 
// Created:     
// Copyright:   (C) 2008 Cesar Mauri Loba - CREA Software Systems
// 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "wconfirmcalibration.h"
#include <wx/timer.h>
#include <wx/string.h>

////@begin XPM images
////@end XPM images

#define TIMER_ID 1234
#define TOTAL_SECONDS 15
#define BUTTON_OK 1
#define BUTTON_CANCEL 2
#define BUTTON_REPEAT 3

/*!
 * WConfirmCalibration type definition
 */

IMPLEMENT_DYNAMIC_CLASS( WConfirmCalibration, wxDialog )


/*!
 * WConfirmCalibration event table definition
 */

BEGIN_EVENT_TABLE( WConfirmCalibration, wxDialog )

////@begin WConfirmCalibration event table entries
    EVT_BUTTON( ID_BUTTON1, WConfirmCalibration::OnButton1Click )

    EVT_BUTTON( ID_BUTTON2, WConfirmCalibration::OnButton2Click )

    EVT_BUTTON( ID_BUTTON3, WConfirmCalibration::OnButton3Click )

////@end WConfirmCalibration event table entries

	EVT_TIMER(TIMER_ID, WConfirmCalibration::OnTimer)
	
END_EVENT_TABLE()


/*!
 * WConfirmCalibration constructors
 */

WConfirmCalibration::WConfirmCalibration() : m_timer(this, TIMER_ID)
{
    Init();
}

WConfirmCalibration::WConfirmCalibration( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style ) : m_timer(this, TIMER_ID)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * WConfirmCalibration creator
 */

bool WConfirmCalibration::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin WConfirmCalibration creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end WConfirmCalibration creation
    return true;
}


/*!
 * WConfirmCalibration destructor
 */

WConfirmCalibration::~WConfirmCalibration()
{
////@begin WConfirmCalibration destruction
////@end WConfirmCalibration destruction
}


/*!
 * Member initialisation
 */

void WConfirmCalibration::Init()
{
////@begin WConfirmCalibration member initialisation
    m_buttonOk = NULL;
    m_buttonCancel = NULL;
    m_buttonRepeat = NULL;
////@end WConfirmCalibration member initialisation
}


/*!
 * Control creation for WConfirmCalibration
 */

void WConfirmCalibration::CreateControls()
{    
////@begin WConfirmCalibration content construction
    WConfirmCalibration* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("The new calibration will be applied. \nAre you sure?"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_buttonOk = new wxButton( itemDialog1, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_buttonOk, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_buttonCancel = new wxButton( itemDialog1, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_buttonRepeat = new wxButton( itemDialog1, ID_BUTTON3, _("Repeat calibration"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_buttonRepeat, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end WConfirmCalibration content construction

	m_timer.Start(1000);
	m_seconds = TOTAL_SECONDS;
	m_buttonCancel->SetLabel(wxString::Format(wxT("Cancel %i"),TOTAL_SECONDS));
}


/*!
 * Should we show tooltips?
 */

bool WConfirmCalibration::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap WConfirmCalibration::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin WConfirmCalibration bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end WConfirmCalibration bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon WConfirmCalibration::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin WConfirmCalibration icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end WConfirmCalibration icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_OK
 */

void WConfirmCalibration::OnButton1Click( wxCommandEvent& event )
{
	EndModal(BUTTON_OK);
    event.Skip();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CANCEL
 */

void WConfirmCalibration::OnButton2Click( wxCommandEvent& event )
{
	EndModal(BUTTON_CANCEL);
    event.Skip();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_REPEAT
 */

void WConfirmCalibration::OnButton3Click( wxCommandEvent& event )
{
	EndModal(BUTTON_REPEAT);
    event.Skip();
}

void WConfirmCalibration::OnTimer(wxTimerEvent& event)
{
	if (m_seconds == 0) {
		m_timer.Stop();
		EndModal(2);
	} else {
		m_seconds--;
		m_timer.Stop();
		m_timer.Start(1000);
		m_buttonCancel->SetLabel(wxString::Format(wxT("Cancel %i"),m_seconds));
	}	
	event.Skip();
}
