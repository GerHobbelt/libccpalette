
#pragma once

#ifndef LIBCCPALETTE_API_H
#define LIBCCPALETTE_API_H

#if defined(__cplusplus)

///////////// C++ API ///////////////

namespace ccpalette {

/*
 * Features:
 *
 * - color palettes of arbitrary size (i.e. number of colors)
 * - API: integer index picks a color from the selected palette
 * - API: floating point index interpolates between colors from the selected palette
 * - colorspace conversions use lcms2 a.k.a. LittleCMS
 * - colors include an optional transparency value ("alpha channel")
 * - built-in color palette database to chose from
 * - supports loading and saving Photoshop and other major graphics applications' swashes & palette files (ASE, ACO, ACT, ...)
 */

enum ColorType : int {
	CCPT_UNKNOWN = 0,
	CCPT_RGB,
	CCPT_HSV,
	CCPT_YUV,
	CCPT_XYZ,
	CCPT_OKLab,
	CCPT_CMYK,
};

// Design Decision: keep the Color classes tight, so no virtual functions, etc. which grow the memory footprint of the Color instance:

#define CCPAL_DEF_I3_COLOR_TYPE(RGB, r, g, b)                \
class RGB##i3Color {                                           \
public:                                                      \
	RGB##i3Color();                                            \
	~RGB##i3Color();                                           \
                                                             \
  static inline ColorType type() { return CCPT_##RGB; }       \
                                                             \
	int r, g, b;                                               \
};                                                           \
                                                             \
class RGB##Ai4Color {                                          \
public:                                                      \
	RGB##Ai4Color();                                           \
	~RGB##Ai4Color();                                          \
                                                             \
  static inline ColorType type() { return CCPT_##RGB; }       \
                                                             \
	int r, g, b, alpha;                                        \
}


#define CCPAL_DEF_F3_COLOR_TYPE(RGB, r, g, b)                \
class RGB##f3Color {                                           \
public:                                                      \
	RGB##f3Color();                                            \
	~RGB##f3Color();                                           \
                                                             \
  static inline ColorType type() { return CCPT_##RGB; }       \
                                                             \
	float r, g, b;                                             \
};                                                           \
                                                             \
class RGB##Af4Color {                                          \
public:                                                      \
	RGB##Af4Color();                                           \
	~RGB##Af4Color();                                          \
                                                             \
  static inline ColorType type() { return CCPT_##RGB; }       \
                                                             \
	float r, g, b, alpha;                                      \
}


CCPAL_DEF_I3_COLOR_TYPE(RGB, r, g, b);
CCPAL_DEF_F3_COLOR_TYPE(RGB, r, g, b);

CCPAL_DEF_I3_COLOR_TYPE(HSV, h, s, v);
CCPAL_DEF_F3_COLOR_TYPE(HSV, h, s, v);

CCPAL_DEF_I3_COLOR_TYPE(YUV, y, u, v);
CCPAL_DEF_F3_COLOR_TYPE(YUV, y, u, v);

CCPAL_DEF_I3_COLOR_TYPE(XYZ, x, y, z);
CCPAL_DEF_F3_COLOR_TYPE(XYZ, x, y, z);

//CCPAL_DEF_I3_COLOR_TYPE(OKLab, x, a, b);
CCPAL_DEF_F3_COLOR_TYPE(OKLab, x, a, b);



// TODO: macros for 4-dim/var color spaces, e.g. CMYK

//CCPAL_DEF_I4_COLOR_TYPE(CMYK, c, m, y, k);
//CCPAL_DEF_F4_COLOR_TYPE(CMYK, c, m, y, k);



}

#else

///////////// C API ///////////////



#endif


#endif
