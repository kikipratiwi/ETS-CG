#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	// render window
    initwindow( MAXWIDTH , MAXHEIGHT , "ETS_171511046", 200);

	// set canvas color and pattern 
    set_canvas();

//	draw_cartesian_axis();
	
	/* =========================================WATCH ANIMATION============================================== */
	// init radius
	int radius = 100;

	// declarating dynamic x y axis for next line
	POINT next_line_point;
		
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, CREAM); delay(2);
	// draw center circle
	next_line_point = solid_line_circle(HALFWIDTH, HALFHEIGHT, r);
	// remove last line of circle
	line_bresenham(next_line_point.x, next_line_point.y, HALFWIDTH, HALFHEIGHT, WHITE);
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, MOCCA); delay(2);
	
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
	filled_circle_bresenham(center_point[0].x, center_point[0].y, 2, MOCCA); delay(2);
	// draw 1st circle
	next_line_point = dotted_line_circle(center_point[0].x,center_point[0].y,r);
	// remove last line in 1ST circle
	line_bresenham(center_point[0].x, center_point[0].y, next_line_point.x, next_line_point.y, WHITE);
	// put 1st point
	filled_circle_bresenham(center_point[0].x, center_point[0].y, 2, MOCCA); delay(2);
	
	// draw connected line
	delayed_line_bresenham(center_point[0].x, center_point[0].y, center_point[1].x, center_point[1].y, MOCCA, 2);
	// put 2nd point
	filled_circle_bresenham(center_point[1].x, center_point[1].y, 2, MOCCA); delay(2);
	// remove connected line
	line_bresenham(center_point[0].x, center_point[0].y, center_point[1].x, center_point[1].y, WHITE);
	// draw 2nd circle
	next_line_point = dotted_line_circle(center_point[1].x,center_point[1].y,r);
	// remove last line in 2nd circle
	line_bresenham(center_point[1].x, center_point[1].y, next_line_point.x, next_line_point.y, WHITE);
	// put 2nd point
	filled_circle_bresenham(center_point[1].x, center_point[1].y, 2, MOCCA); delay(2);
	
	// draw connected line
	delayed_line_bresenham(center_point[1].x, center_point[1].y, center_point[2].x, center_point[2].y, MOCCA, 2);
	// put 3rd point
	filled_circle_bresenham(center_point[2].x, center_point[2].y, 2, MOCCA); delay(2);
	// remove connected line
	line_bresenham(center_point[1].x, center_point[1].y, center_point[2].x, center_point[2].y, WHITE);
	// draw 3rd circle
	next_line_point = dotted_line_circle(center_point[2].x,center_point[2].y,r);
	// remove last line in 3rd circle
	line_bresenham(center_point[2].x, center_point[2].y, next_line_point.x, next_line_point.y, WHITE);
	// put 3rd point
	filled_circle_bresenham(center_point[2].x, center_point[2].y, 2, MOCCA); delay(2);
	
	// draw connected line
	delayed_line_bresenham(center_point[2].x, center_point[2].y, center_point[3].x, center_point[3].y, MOCCA, 2);
	// put 4th point
	filled_circle_bresenham(center_point[3].x, center_point[3].y, 2, MOCCA); delay(2);
	// remove connected line
	line_bresenham(center_point[2].x, center_point[2].y, center_point[3].x, center_point[3].y, WHITE);
	// draw 4th circle
	next_line_point = dotted_line_circle(center_point[3].x,center_point[3].y,r);
	// remove last line in 4th circle
	line_bresenham(center_point[3].x, center_point[3].y, next_line_point.x, next_line_point.y, WHITE);
	// put 4th point
	filled_circle_bresenham(center_point[3].x, center_point[3].y, 2, MOCCA); delay(2);

	/* =========================================SQUARE ANIMATION============================================== */
	
	// draw rectangle and remove dotted circle
	delayed_line_bresenham(center_point[0].x, center_point[0].y, center_point[1].x, center_point[1].y, MOCCA, 2);
	dda_circle(center_point[0].x,center_point[0].y, r, WHITE);

	delayed_line_bresenham(center_point[1].x, center_point[1].y, center_point[2].x, center_point[2].y, MOCCA, 2);
	dda_circle(center_point[1].x,center_point[1].y, r, WHITE);

	delayed_line_bresenham(center_point[2].x, center_point[2].y, center_point[3].x, center_point[3].y, MOCCA, 2);
	dda_circle(center_point[2].x,center_point[2].y, r, WHITE);

	delayed_line_bresenham(center_point[3].x, center_point[3].y, center_point[0].x, center_point[0].y, MOCCA, 2);
	dda_circle(center_point[3].x,center_point[3].y, r, WHITE);
	
	cleardevice();
	set_canvas();

	line_bresenham(center_point[0].x, center_point[0].y, center_point[1].x, center_point[1].y, MOCCA);
	line_bresenham(center_point[1].x, center_point[1].y, center_point[2].x, center_point[2].y, MOCCA);
	line_bresenham(center_point[2].x, center_point[2].y, center_point[3].x, center_point[3].y, MOCCA);
	line_bresenham(center_point[3].x, center_point[3].y, center_point[0].x, center_point[0].y, MOCCA);

	POINT CENTER;
	CENTER.x = HALFWIDTH;
	CENTER.y = HALFHEIGHT;

	 draw_rotate_rectangle(CENTER, center_point, 45);
	 draw_rotate_scale_rectangle(CENTER, center_point, 45, 0.25);
	 draw_scale_rectangle(CENTER, 140, 0);

	POINT pr[4];
	int deg=45;
	int i;
	for(i=0; i<4; i++)
	{
		pr[i] = point_rotate_cw(CENTER.x, CENTER.y, center_point[i].x, center_point[i].y, deg);
	}	

	 draw_rotate_rectangle(CENTER, pr, 45);
	for(i=0; i<4; i++)
	{
		filled_circle_bresenham(center_point[i].x, center_point[i].y, 2, MOCCA); delay(2);
	}	
	
	 delayed_line_bresenham(center_point[0].x, center_point[0].y, center_point[1].x, center_point[1].y, BLACK, 1);
	 delayed_line_bresenham(center_point[1].x, center_point[1].y, center_point[2].x, center_point[2].y, BLACK, 1);
	 delayed_line_bresenham(center_point[2].x, center_point[2].y, center_point[3].x, center_point[3].y, BLACK, 1);
	 delayed_line_bresenham(center_point[3].x, center_point[3].y, center_point[0].x, center_point[0].y, BLACK, 1);
	
	draw_rotate_point(CENTER, center_point, 90);
	cleardevice();
	circle_bresenham(CENTER.x, CENTER.y+100, r, MOCCA);
	circle_bresenham(CENTER.x, CENTER.y-100, r, MOCCA);

	draw_translation_two_circle(CENTER, r, MOCCA);
	filled_circle_bresenham(CENTER.x, CENTER.y, 2, MOCCA);
	draw_rotate_translation_circle(CENTER, r, MOCCA, 60);
	draw_rotate_line_360(CENTER.x, CENTER.y, r*2, 12);
	// cleardevice();

	

	getch();
	
	// deallocate memory allocated for graphics screen 
	closegraph();
	
	return 0;
}
