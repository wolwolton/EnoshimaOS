#pragma once
#include "gop.hpp"

typedef BLTPIXEL    COLOR;

const COLOR green = {0,255,0};
const COLOR blue  = {255,0,0};
const COLOR red   = {0,0,255};
const COLOR white = {0xff,0xff,0xff};
const COLOR black = {0x00,0x00,0x00};
const COLOR main_color = {64,96,48};
const COLOR pannel = {0xc6,0xc6,0xc6};
const COLOR pannel_shadow = {0x84,0x84,0x84};

void boxfill(GOPMODE* mode,const int x1,const int y1,const int x2,const int y2,const COLOR& c);
void init_screen(GOPMODE* mode);