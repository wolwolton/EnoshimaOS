#include <stdint.h>

#pragma once

typedef int PIXELFORMAT;

typedef struct{
    uint8_t    Blue;
    uint8_t    Green;
    uint8_t    Red;
    uint8_t    Reserved;
}BLTPIXEL;

typedef struct{
    uint32_t    Red;
    uint32_t    Green;
    uint32_t    Blue;
    uint32_t    Reserved;
}PIXELBITMASK;

typedef struct 
{
    uint32_t    Version;
    uint32_t    Hr;
    uint32_t    Vr;
    PIXELFORMAT     PixelFormat;
    PIXELBITMASK    PixelInfo;
    uint32_t    PixelsPerScanLine;
}GOPINFO;

typedef struct {
    uint32_t    MaxMode;
    uint32_t    Mode;
    GOPINFO    *Info;
    uint64_t    SizeOfInfo;
    uint64_t    FrameBufferBase;
    uint64_t    FrameBufferSize;
}GOPMODE;

#define BG_RED 0
#define BG_GREEN 255
#define BG_BLUE 0