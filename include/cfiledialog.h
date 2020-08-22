/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001  Luis Claudio Gamboa Lopes

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

/**
 * \file cfiledialog.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CFILEDIALOG
#define CFILEDIALOG

#include"ccontrol.h"
#include"cwindow.h"

/** \brief File Dialog Control.
 *
 * Generic File Dialog Control Class.
 */

class CFileDialog:public CControl
{
private:
  lxString FileName;
  lxString Dir;
  lxString Filter;
  long Type;
public:
  CFileDialog (void);
   ~CFileDialog (void);
  int Create (CControl * control);
  void Run (void);
  //propriedades
  lxString GetFileName (void);
  void SetFileName (lxString filename);
  lxString GetDir (void);
  bool SetDir(lxString dir);
  long GetType(void);
  void SetType(long type);
  lxString GetFilter(void);
  void SetFilter(lxString filter);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //events
  void (CControl::*EvOnClose) (int retId);
};

#endif
