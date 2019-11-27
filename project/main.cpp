#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	// render window
    initwindow( MAXWIDTH , MAXHEIGHT , "ETS_171511046", 200);
int Orange = RGB(241,175,1);
setcolor    (Orange);

	// set canvas color and pattern 
    setfillstyle(SOLID_FILL, Orange); 
	rectangle(0, 0, MAXWIDTH, MAXHEIGHT); 
    floodfill(1,1, CREAM);

	draw_cartesian_axis();
	
	/* =========================================WATCH ANIMATION============================================== */
	// init radius
	int r = 100;

	// declarating dynamic x y axis for next line
	POINT next_line_point;
		
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, YELLOW); delay(2);
	// draw center circle
	next_line_point = solid_line_circle(HALFWIDTH, HALFHEIGHT, r);
	// remove last line of circle
	line_bresenham(next_line_point.x, next_line_point.y, HALFWIDTH, HALFHEIGHT, WHITE, 2);
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, YELLOW); delay(2);
	
	//  initiating 4 center point for animating circle
	POINT center_point[4];
		center_point[0].x = HALFWIDTH  - r;
		center_point[0].y = HALFHEIGHT + r;
		
		center_point[1].x = HALFWIDTH  + r;
		center_point[1].y = HALFHEIGHT + r;
		
		center_point[2].x = HALFWIDTH  + r;
		center_point[2].y = HALFHEIGHT - r;
		
		center_point[3].x = HALFWIDTH  - r;
		center_point[3].y = HALFHEIGHT - r;
		

	// put 1st point
	filled_circle_bresenham(center_point[0].x, center_point[0].y, 2, YELLOW); delay(2);
	// draw 1st circle
	next_line_point = dotted_line_circle(center_point[0].x,center_point[0].y,r);
	// put 1st point
	filled_circle_bresenham(center_point[0].x, center_point[0].y, 2, YELLOW); delay(2);

	// draw connected line
	line_bresenham(next_line_point.x, next_line_point.y, center_point[1].x, center_point[1].y, YELLOW, 5);
	// put 2nd point
	filled_circle_bresenham(center_point[1].x, center_point[1].y, 2, YELLOW); delay(2);

	// remove connected line
	line_bresenham(next_line_point.x, next_line_point.y, center_point[1].x, center_point[1].y, WHITE, 2);
	// remove last line in 1st circle
	line_bresenham(next_line_point.x, next_line_point.y, center_point[0].x, center_point[0].y, WHITE, 2);

	// draw 2nd circle
	next_line_point = dotted_line_circle(center_point[1].x,center_point[1].y,r);
	// remove last line in 2nd circle
	line_bresenham(center_point[1].x, center_point[1].y, next_line_point.x, next_line_point.y, WHITE, 0);
	// put 2nd point
	filled_circle_bresenham(center_point[1].x, center_point[1].y, 2, YELLOW); delay(2);
	


	getch();
	
	// deallocate memory allocated for graphics screen 
	closegraph();
	
	return 0;
}
