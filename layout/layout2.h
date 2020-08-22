/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2010 Luis Claudio Gamboa Lopes

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



#ifndef CPWINDOW2 
#define CPWINDOW2

#include<lxrad/lxrad.h>

class CPWindow2:public CPWindow
{
  public:
  /*#Controls*/
  /*#Events*/
  void _EvMouseMove(CControl * control, uint button, uint x, uint y,uint state);
  void _EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void _EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  void _EvKeyboardPress(CControl * control, uint key, uint x, uint y,uint mask);
  void _EvOnDraw(CControl * control);
  void _EvOnShow(CControl * control);

  /*#Others*/
  CControl *Mcontrol;
  int Create (CControl * control);
  CControl *GetControlOnFocus (void);
//  CCanvas Canvas;
//  virtual bool WEvent (wxWindow *widget, wxEvent *event);
  lxString getalign (CAlign align);
  CControl *NewControl (lxString cclass, uint x, uint y);
  lxString WriteEvents (lxString name, lxString event);
  lxString WriteControlEvents (lxString name, lxString event);
  lxStringList linesbak;
// void Draw(void);
  void Reset (void);
  void MakeOrUpdateFiles (bool prompt);
  bool testline(lxString line);
  void MakeProject (lxString basename);
  bool LoadProject (lxString dirname, lxString filename);
  bool ReLoadProject (void);
  void ListPropierties (CControl * control);
  void SCreateChild(CControl * control);
  
  CPWindow2(void);
  ~CPWindow2(void);
};

extern CPWindow2 Window2 ;

lxString spacestrip(lxString sstr);

#endif /*#CPWINDOW2*/

