CPWindow1::CPWindow1(void)
{
  SetFOwner(this);
  SetClass(lxT("CPWindow"));
  SetName(lxT("window1"));
  SetTag(0);
  SetX(344);
  SetY(133);
  SetWidth(736);
  SetHeight(442);
  SetHint(lxT(""));
  SetEnable(1);
  SetVisible(1);
  SetPopupMenu(NULL);
  SetTitle(lxT("LCDfont"));
  SetOverrideRedirect(0);
  EvOnCreate=EVONCREATE & CPWindow1::_EvOnCreate;
  EvOnShow=EVONSHOW & CPWindow1::_EvOnShow;
  //draw1
  draw1.SetFOwner(this);
  draw1.SetClass(lxT("CDraw"));
  draw1.SetName(lxT("draw1"));
  draw1.SetTag(0);
  draw1.SetX(50);
  draw1.SetY(20);
  draw1.SetWidth(180);
  draw1.SetHeight(288);
  draw1.SetHint(lxT(""));
  draw1.SetEnable(1);
  draw1.SetVisible(1);
  draw1.SetPopupMenu(NULL);
  draw1.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::draw1_EvMouseButtonPress;
  draw1.EvOnDraw=EVONDRAW & CPWindow1::draw1_EvOnDraw;
  draw1.SetTransparent(0);
  draw1.SetImgFileName(lxT(""));
  CreateChild(&draw1);
  //edit1
  edit1.SetFOwner(this);
  edit1.SetClass(lxT("CEdit"));
  edit1.SetName(lxT("edit1"));
  edit1.SetTag(0);
  edit1.SetX(276);
  edit1.SetY(64);
  edit1.SetWidth(219);
  edit1.SetHeight(27);
  edit1.SetHint(lxT(""));
  edit1.SetEnable(1);
  edit1.SetVisible(1);
  edit1.SetPopupMenu(NULL);
  edit1.SetText(lxT(""));
  edit1.SetReadOnly(0);
  CreateChild(&edit1);
  //text1
  text1.SetFOwner(this);
  text1.SetClass(lxT("CText"));
  text1.SetName(lxT("text1"));
  text1.SetTag(0);
  text1.SetX(275);
  text1.SetY(108);
  text1.SetWidth(322);
  text1.SetHeight(215);
  text1.SetHint(lxT(""));
  text1.SetEnable(1);
  text1.SetVisible(1);
  text1.SetPopupMenu(NULL);
  text1.SetReadOnly(0);
  CreateChild(&text1);
  //button1
  button1.SetFOwner(this);
  button1.SetClass(lxT("CButton"));
  button1.SetName(lxT("button1"));
  button1.SetTag(0);
  button1.SetX(513);
  button1.SetY(64);
  button1.SetWidth(65);
  button1.SetHeight(28);
  button1.SetHint(lxT(""));
  button1.SetEnable(1);
  button1.SetVisible(1);
  button1.SetPopupMenu(NULL);
  button1.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button1_EvMouseButtonClick;
  button1.SetText(lxT("Add"));
  CreateChild(&button1);
  //button2
  button2.SetFOwner(this);
  button2.SetClass(lxT("CButton"));
  button2.SetName(lxT("button2"));
  button2.SetTag(0);
  button2.SetX(374);
  button2.SetY(341);
  button2.SetWidth(131);
  button2.SetHeight(28);
  button2.SetHint(lxT(""));
  button2.SetEnable(1);
  button2.SetVisible(1);
  button2.SetPopupMenu(NULL);
  button2.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button2_EvMouseButtonClick;
  button2.SetText(lxT("Save to File"));
  CreateChild(&button2);
  //button3
  button3.SetFOwner(this);
  button3.SetClass(lxT("CButton"));
  button3.SetName(lxT("button3"));
  button3.SetTag(0);
  button3.SetX(102);
  button3.SetY(326);
  button3.SetWidth(65);
  button3.SetHeight(28);
  button3.SetHint(lxT(""));
  button3.SetEnable(1);
  button3.SetVisible(1);
  button3.SetPopupMenu(NULL);
  button3.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button3_EvMouseButtonClick;
  button3.SetText(lxT("Clear"));
  CreateChild(&button3);
  //filedialog1
  filedialog1.SetFOwner(this);
  filedialog1.SetClass(lxT("CFileDialog"));
  filedialog1.SetName(lxT("filedialog1"));
  filedialog1.SetTag(0);
  filedialog1.SetFileName(lxT("untitled.txt"));
  filedialog1.SetFilter(lxT("All Files (*.*)|*.*"));
  filedialog1.SetType(129);
  CreateChild(&filedialog1);
  /*#Others*/
}
