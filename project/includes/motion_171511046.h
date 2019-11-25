#ifndef MOTION_171511046_H_INCLUDED
#define MOTION_171511046_H_INCLUDED

#define MAXWIDTH  700
#define MAXHEIGHT 700

//header
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// sumber: https://code.cheraus.com/codes/cgraphics/dda_circle.php
void dda_circle(int xCenter, int yCenter, int rad);
void line_circle(int xCenter, int yCenter, int rad);

// sumber: https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void draw_line_bresenham(int x1, int y1, int x2, int y2, int color);

#endif
