#include "gop.hpp"
#include "graphic.hpp"

extern "C" int MyMain(unsigned long (*edk_print)(const char16_t* format, ...) __attribute__((ms_abi)), 
GOPMODE* f_mode,
void *_fs_start __attribute__ ((unused))){
    edk_print(u"Hello!!\nEnoshimaOS Ver1.0\n");
    edk_print(u"f_mode :%02X\n", f_mode);
    edk_print(u"vr :%02X\n", f_mode->Info->Vr);
    edk_print(u"hr :%02X\n", f_mode->Info->Hr);
    unsigned int x, y;
    uint64_t vr = f_mode->Info->Vr;
    uint64_t hr = f_mode->Info->Hr;
    BLTPIXEL *p;
    for (y = 0; y < vr; y++) {
        for (x = 0; x < hr; x++) {
            p = (BLTPIXEL*)((uint64_t)f_mode->FrameBufferBase + ((hr * y) + x)*sizeof(BLTPIXEL));
            if(x%40>=20){
                p->Red = 0;
                p->Green = 255;
                p->Blue = 0;
            }
            if(x%40<20){
                p->Red = 255;
                p->Green = 0;
                p->Blue = 0;
            }
        }
    }
    edk_print(u"Done\n");
    return 0;   
}
