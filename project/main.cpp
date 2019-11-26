#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	
    initwindow( MAXWIDTH , MAXHEIGHT , "ETS_171511046", 200);
	
	setcolor(10);
	
	//drawing the co-ordinate axes
	int center_width_screen  = MAXWIDTH/2;
	int center_height_screen = MAXHEIGHT/2;
	
	line(0,center_height_screen, MAXWIDTH, center_height_screen); 	//horizontal
	line(center_width_screen, 0, center_width_screen, MAXHEIGHT);	//vertical
	
	setcolor(5);
	
	//converting the screen co-ordinates to more user friendly co-ordinates
	// with respect to the centre of the screen.
	int xc=0, yc=0, r=0; 
	r = 100;
	xc = center_width_screen  - r;
	yc = center_height_screen + r;
	
	//set init pixel
	POINT next_line_point;
	next_line_point = line_circle(xc,yc,r);
	
	
	draw_line_bresenham(xc, yc, next_line_point.x, next_line_point.y, BLACK, 0);
	xc = next_line_point.x + r;
	yc = next_line_point.y ;
	
	draw_line_bresenham(next_line_point.x, next_line_point.y, xc, yc, YELLOW, 5);
	next_line_point = line_circle(xc,yc,r);
	
	//	draw_line_bresenham(xCenter, yCenter, xCenter+xCenter2, yCenter-yCenter2);
	getch();
	
	/* deallocate memory allocated for graphics screen */
	closegraph();
	
	return 0;
}
