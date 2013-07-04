/***************************************************************
 * Name:      hamguiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Neil Stoker (neil.stoker@gmail.com)
 * Created:   2013-06-28
 * Copyright: Neil Stoker (https://sites.google.com/site/neilstoker/)
 * License:
 **************************************************************/

#ifndef HAMGUIMAIN_H
#define HAMGUIMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "hamguiApp.h"

class hamguiFrame: public wxFrame
{
    public:
        hamguiFrame(wxFrame *frame, const wxString& title);
        ~hamguiFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // HAMGUIMAIN_H
