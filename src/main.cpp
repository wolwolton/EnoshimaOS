#include "gop.hpp"
#include "graphic.hpp"

extern "C" int MyMain(unsigned long (*edk_print)(const char16_t* format, ...) __attribute__((ms_abi)), 
GOPMODE* f_mode,
void *_fs_start __attribute__ ((unused))){
    init_screen(f_mode);
    edk_print(u"Hello!!\nEnoshimaOS Ver1.0\n");
    edk_print(u"Done\n");
    return 0;
}
