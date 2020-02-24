#include "gop.hpp"
#include "graphic.hpp"

void boxfill(GOPMODE* mode, int x1, int y1, int x2, int y2, const COLOR& c){
    for(int ix = x1; ix<x2; ix++){
        for(int iy=y1; iy<y2; iy++){
            BLTPIXEL* p = (BLTPIXEL*)(mode->FrameBufferBase + (ix + mode->Info->Hr * iy)*sizeof(BLTPIXEL));
            p->Blue  =c.Blue;
            p->Green =c.Green;
            p->Red   =c.Red;
        }
    }
    return;
}

void init_screen(GOPMODE* mode){
    int hr = mode->Info->Hr;
    int vr = mode->Info->Vr;
    boxfill(mode, 0, 0, hr, vr, main_color);

    boxfill(mode, 0, vr-36, hr, vr, white);
    boxfill(mode, 0, vr-35, hr, vr, pannel);

    boxfill(mode, 3, vr-31, 51, vr-3, black);
    boxfill(mode, 3, vr-31, 50, vr-4, white) ;
    boxfill(mode, 4, vr-30, 50, vr-4, pannel);
    
    boxfill(mode, hr-50, vr-32, hr-2, vr-3, white);
    boxfill(mode, hr-50, vr-32, hr-3, vr-4, pannel_shadow);
    boxfill(mode, hr-49, vr-31, hr-3, vr-4, pannel);
    return;
}