# libccpalette

C++ library to load, save, pick and interpolate colors from any color palette.

## Features

- color palettes of arbitrary size (i.e. number of colors)
- API: integer index picks a color from the selected palette
- API: floating point index interpolates between colors from the selected palette
- colorspace conversions use lcms2 a.k.a. LittleCMS
- colors include an optional transparancy value ("alpha channel")
- built-in color palette database to chose from
- supports loading and saving Photoshop and other major graphics applications' swashes & palette files (ASE, ACO, ACT, ...)

