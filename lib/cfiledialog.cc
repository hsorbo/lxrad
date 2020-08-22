/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2018  Luis Claudio Gamboa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */


#include"../include/cfiledialog.h"


// CFileDialog__________________________________________________________

CFileDialog::CFileDialog (void)
{
  //  CanFocus = false;
  CanVisible = false;
  FileName = wxT ("untitled.txt");
  Dir = wxGetCwd ();
  SetVisible (false);
  SetName (wxT ("FileDialog"));
  SetClass (wxT ("CFileDialog"));
  Type = wxFD_OPEN | wxFD_CHANGE_DIR;
  CanExecuteEvent = false;
  SetFilter (wxT ("All Files (*.*)|*.*"));
  EvOnClose = NULL;
};

CFileDialog::~CFileDialog (void) { };

int
CFileDialog::Create (CControl * control)
{
  //disabled because gtk bug

  //Widget =  new wxFileDialog(((CWindow *)control)->GetWWidget (), wxT("Choose a file"),Dir,wxT(""), Filter, Type);
  //SetFileName (FileName);
  //((wxFileDialog*)Widget)->SetDirectory(wxGetCwd());

  //return 0;

  Widget = NULL;

  return CControl::Create (control);
};

lxString
CFileDialog::GetFileName (void)
{
  if (Widget != NULL)
    FileName = ((wxFileDialog*) Widget)->GetPath ();
  //     FileName=((wxFileDialog*)Widget)->GetFilename();

  return FileName;
};

lxString
CFileDialog::GetDir (void)
{
  if (Widget != NULL)
    Dir = ((wxFileDialog*) Widget)->GetDirectory ();

  return Dir;
};

void
CFileDialog::SetFileName (lxString filename)
{
  FileName = filename;
  if(SetDir (dirname (filename)))
  {
    if (Widget != NULL)
      ((wxFileDialog*) Widget)->SetFilename (basename (filename));
  }
}

bool
CFileDialog::SetDir (lxString dir)
{
  bool ret=false;

  Dir = dir;
  if (wxDirExists (dir))
    if(wxSetWorkingDirectory (dir))
    {
     ret=true;	    
     if (Widget != NULL)
       ((wxFileDialog*) Widget)->SetDirectory (dir);
    }
  return ret;
}

void
CFileDialog::Run (void)
{
  int run = 0;

  Widget = new wxFileDialog (((CWindow *) GetOwner ())->GetWWidget (), wxT ("Choose a file"), Dir, basename (FileName), Filter, Type);
  //SetFileName (FileName);
  //((wxFileDialog*)Widget)->SetDirectory(wxGetCwd());
  //((wxFileDialog*)Widget)->Bind(wxEVT_CLOSE_WINDOW,&CFileDialog::on_close,this,GetWid());

  if (((wxFileDialog*) Widget)->ShowModal () == wxID_OK)
    {
      run = 1;
      FileName = ((wxFileDialog*) Widget)->GetPath ();
      Dir = ((wxFileDialog*) Widget)->GetDirectory ();
    }

  delete Widget;

  Widget = NULL;


  if ((FOwner) && (EvOnClose))
    (FOwner->*EvOnClose) (run);
}

lxStringList
CFileDialog::GetContext (void)
{
  //  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT ("FileName"), wxT ("lxString"), GetFileName ()));
  Context.AddLine (xml_out (wxT ("Filter"), wxT ("lxString"), GetFilter ()));
  Context.AddLine (xml_out (wxT ("Type"), wxT ("int"), itoa (GetType ())));
  Context.AddLine (xml_out (wxT ("EvOnClose"), wxT ("Event"), btoa (GetEv (true))));
  return Context;
};

void
CFileDialog::SetContext (lxStringList context)
{
  lxString name, type, value;
  //  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT ("Filter")) == 0)
        SetFilter (value);
      if (name.compare (wxT ("Type")) == 0)
        SetType (atoi (value));
      if (name.compare (wxT ("FileName")) == 0)
        SetFileName (value);
      if (name.compare (wxT ("EvOnClose")) == 0)
        SetEv (atob (value), true);
    };
};

long
CFileDialog::GetType (void)
{
  return Type;
};

void
CFileDialog::SetType (long type)
{
  Type = type;

  if (Widget)
    ((wxFileDialog*) Widget)->SetWindowStyle (Type);
  //    ((wxFileDialog*)Widget)->SetStyle(Type);
};

lxString
CFileDialog::GetFilter (void)
{
  return Filter;
};

void
CFileDialog::SetFilter (lxString filter)
{
  Filter = filter;

  if (Widget)
    ((wxFileDialog*) Widget)->SetWildcard (Filter);
};


