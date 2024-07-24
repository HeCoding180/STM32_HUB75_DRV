/*
 * DisplayUtil.h
 *
 *  Created on: Jul 24, 2024
 *      Author: timow
 */

#ifndef INC_DISPLAYUTIL_H_
#define INC_DISPLAYUTIL_H_

#include <stdint.h>

#include "LibConfig.h"

#if COLOR_DEPTH == 1
    #define USE_SINGLE_BIT_COLOR
#elif COLOR_DEPTH <= 8
    #define COLOR_TYPE uint8_t
#elif COLOR_DEPTH <= 16
    #define COLOR_TYPE uint16_t
#elif COLOR_DEPTH <= 32
    #define COLOR_TYPE uint32_t
#elif COLOR_DEPTH <= 64
    #define COLOR_TYPE uint64_t
#else
    #error "COLOR_DEPTH must be within the range of 1 to 64"
#endif

#ifdef USE_SINGLE_BIT_COLOR
    typedef union Color
    {
        struct
        {
            uint8_t R   :1;
            uint8_t G   :1;
            uint8_t B   :1;
        };
        uint8_t cData;
    } Color_t;
#else
    typedef struct Color
    {
        COLOR_TYPE R;
        COLOR_TYPE G;
        COLOR_TYPE B;
    } Color_t;
#endif

typedef struct Vector2D
{
    uint32_t x;
    uint32_t y;
}; 

typedef struct ImageBuffer
{
    uint32_t Width;
    uint32_t Height;
    Color_t *Data
} ImageBuffer_t;

#endif /* INC_DISPLAYUTIL_H_ */
