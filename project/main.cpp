#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	int xc,yc,r,gd,gm; 
	
    initwindow( MAXWIDTH , MAXHEIGHT , "ETS_171511046");
	
	setcolor(10);
	
	//drawing the co-ordinate axes
	int center_width_screen  = MAXWIDTH/2;
	int center_height_screen = MAXHEIGHT/2;
	
	line(0,center_height_screen, MAXWIDTH, center_height_screen); 	//horizontal
	line(center_width_screen, 0, MAXHEIGHT, MAXHEIGHT);	//vertical
	
	printf("%i %i %i %i", MAXHEIGHT, MAXWIDTH, center_width_screen, center_height_screen);
	setcolor(5);
	
	//converting the screen co-ordinates to more user friendly co-ordinates
	// with respect to the centre of the screen.
	xc = 320 + xc;
	yc = 240 - yc;
	r = 200;
	//function call for DDA circle.
	
//	setpixel
	
//	line_circle(xc,yc,r);
	//	draw_line_bresenham(xCenter, yCenter, xCenter+xCenter2, yCenter-yCenter2);
	getch();
	
	/* deallocate memory allocated for graphics screen */
	closegraph();
	
	return 0;
}
