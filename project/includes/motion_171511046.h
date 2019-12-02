#ifndef MOTION_171511046_H_INCLUDED
#define MOTION_171511046_H_INCLUDED

//header
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/* ==============================================CANVAS================================================= */
#define MAXWIDTH  800
#define MAXHEIGHT 700
#define HALFWIDTH  (MAXWIDTH/2)
#define	HALFHEIGHT (MAXHEIGHT/2)
#define	FULLDEGREE 360

/* =========================================TRANSFORMATION============================================== */
// Using macros to convert degree to radian 
// and call sin() and cos() as these functions 
// take input in radians 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 
#define ROUND(a) ((int) (a+0.5))
#define PI 3.14159265
#define DEGREE45 45
#define DEGREE60 60
#define DEGREE30 30
#define DEGREE90 90

/* ==============================================COLOR================================================= */
#define CREAM   (RGB(128, 103, 9))
#define GRAY    (RGB(105, 105, 105))
#define MOCCA   (RGB(235, 104, 75))

/* ==============================================CANVAS================================================= */
void set_canvas(); //not used
void draw_cartesian_axis(); //not used

/* =========================================TRANSFORMATION============================================== */
POINT point_rotate_cw(int xCenter, int yCenter, int x, int y, float degree);
POINT point_scale(int xCenter, int yCenter, int x, int y, float scale); //not used
POINT point_translation(int x, int y, int x1, int y1); //not used

/* ======================================DRAW ANIMATED OBJECT========================================== */
void delayed_draw_rotate_line_360(int x1, int y1, int radius, int n);
void draw_rotate_line_360(int x1, int y1, int radius, int n);
void animate_rotate_point(POINT p_center, POINT p[], int degree);
void animate_rotate_rectangle(POINT p_center, POINT p[], int degree);
void draw_rectangle(POINT p[]);
void animate_rotate_translation_rectangle(POINT p_center, POINT p[], int degree);
void draw_rotate_rectangle(POINT p_center, int radius);
void draw_rotate_translation_circle(POINT p_center, int radius, int color, float degree, int _delay);
void draw_pattern(POINT p_center, int radius, int color, float degree, int _delay);
void animate_translation_two_circle(POINT p_center, int radius, int color);

/* =====================================DRAW PRIMITIVE OBJECT========================================== */
// sumber: https://code.cheraus.com/codes/cgraphics/dda_circle.php
void dda_circle(int xCenter, int yCenter, int radius, int color);
void draw_two_circle(int xCenter, int yCenter, int radius, int color, int _delay); //not used
void circle_bresenham(int xc, int yc, int radius, int color);
void filled_circle_bresenham(int xc, int yc, int radius, int color);

// sumber: https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void line_bresenham(int x1, int y1, int x2, int y2, int color);
void delayed_line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay);

POINT dotted_line_circle(int xCenter, int yCenter, int radius);
POINT solid_line_circle(int xCenter, int yCenter, int radius);

#endif
