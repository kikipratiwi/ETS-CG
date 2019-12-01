#ifndef MOTION_171511046_H_INCLUDED
#define MOTION_171511046_H_INCLUDED

//header
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#define MAXWIDTH  800
#define MAXHEIGHT 700
#define HALFWIDTH  (MAXWIDTH/2)
#define	HALFHEIGHT (MAXHEIGHT/2)
#define	FULLDEGREE 360

// Using macros to convert degree to radian 
// and call sin() and cos() as these functions 
// take input in radians 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 
#define ROUND(a) ((int) (a+0.5))
#define PI 3.14159265

#define CREAM (RGB(128, 103, 9))
#define GRAY (RGB(105, 105, 105))
#define MOCCA (RGB(125, 101, 64))

void set_canvas();

/* =========================================WATCH ANIMATION============================================== */
POINT point_rotate_cw(int xCenter, int yCenter, int x, int y, float deg);
POINT point_scale(int xCenter, int yCenter, int x, int y, float scale);
POINT point_translation(int x, int y, int x1, int y1);

// POINT line_rotate(int x1, int y1, int x2, int y2, int degree);

void draw_rotate_line_360(int x1, int y1, int r, int n);
void draw_rotate_point(POINT p_center, POINT p[], int degree);
void draw_rotate_rectangle(POINT p_center, POINT p[], int degree);
void draw_rotate_scale_rectangle(POINT p_center, POINT p[], int degree, float scale);
void draw_scale_rectangle(POINT p_center, int r, float scale);
void draw_rectangle(POINT p[]);
void draw_rotate_translation_circle(POINT p_center, int r, int color, int degree);
void draw_translation_two_circle(POINT p_center, int r, int color);
void draw_cartesian_axis();

void ellipseMidPoint (int xCenter,int yCenter, int Rx,int Ry);

// sumber: https://code.cheraus.com/codes/cgraphics/dda_circle.php
void dda_circle(int xCenter, int yCenter, int rad, int color);
void circle_bresenham(int xc, int yc, int r, int color);
void filled_circle_bresenham(int xc, int yc, int r, int color);

// sumber: https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void line_bresenham(int x1, int y1, int x2, int y2, int color);
void delayed_line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay);

POINT dotted_line_circle(int xCenter, int yCenter, int rad);
POINT solid_line_circle(int xCenter, int yCenter, int rad);

#endif
