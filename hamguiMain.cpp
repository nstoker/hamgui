/***************************************************************
 * Name:      hamguiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Neil Stoker (neil.stoker@gmail.com)
 * Created:   2013-06-28
 * Copyright: Neil Stoker (https://sites.google.com/site/neilstoker/)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "hamguiMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(hamguiFrame, wxFrame)
    EVT_CLOSE(hamguiFrame::OnClose)
    EVT_MENU(idMenuQuit, hamguiFrame::OnQuit)
    EVT_MENU(idMenuAbout, hamguiFrame::OnAbout)
END_EVENT_TABLE()

hamguiFrame::hamguiFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


hamguiFrame::~hamguiFrame()
{
}

void hamguiFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void hamguiFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void hamguiFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
