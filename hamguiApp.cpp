/***************************************************************
 * Name:      hamguiApp.cpp
 * Purpose:   Code for Application Class
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

#include "hamguiApp.h"
#include "hamguiMain.h"

IMPLEMENT_APP(hamguiApp);

bool hamguiApp::OnInit()
{
    hamguiFrame* frame = new hamguiFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
