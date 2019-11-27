#ifndef MOTION_171511046_H_INCLUDED
#define MOTION_171511046_H_INCLUDED

#define MAXWIDTH  800
#define MAXHEIGHT 700
#define HALFWIDTH  (MAXWIDTH/2)
#define	HALFHEIGHT (MAXHEIGHT/2)

// Using macros to convert degree to radian 
// and call sin() and cos() as these functions 
// take input in radians 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 

//header
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#define ROUND(a) ((int) (a+0.5))
#define PI 3.14159265
#define CREAM (RGB(128, 103, 9))



void rotate_line_360(int x1, int y1, int r, int n);

POINT rotate_cw(POINT center, POINT pivot, double angle);
POINT rotate_ccw(POINT center, POINT pivot, double angle);


POINT pointRotation(int xpusat, int ypusat, int x, int y, int deg);

// POINT line_rotate(int x1, int y1, int x2, int y2, int ang);

void draw_cartesian_axis();

// sumber: https://code.cheraus.com/codes/cgraphics/dda_circle.php
void dda_circle(int xCenter, int yCenter, int rad, int color);
void circle_bresenham(int xc, int yc, int r, int color);
void filled_circle_bresenham(int xc, int yc, int r, int color);

// sumber: https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay);

POINT dotted_line_circle(int xCenter, int yCenter, int rad);
POINT solid_line_circle(int xCenter, int yCenter, int rad);

#endif
