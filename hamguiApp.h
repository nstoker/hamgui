/***************************************************************
 * Name:      hamguiApp.h
 * Purpose:   Defines Application Class
 * Author:    Neil Stoker (neil.stoker@gmail.com)
 * Created:   2013-06-28
 * Copyright: Neil Stoker (https://sites.google.com/site/neilstoker/)
 * License:
 **************************************************************/

#ifndef HAMGUIAPP_H
#define HAMGUIAPP_H

#include <wx/app.h>

class hamguiApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // HAMGUIAPP_H
