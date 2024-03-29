#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	srand(time(NULL));
	
    
	// render window
    initwindow( 800 , 700 , "ETS_171511046", 200);

	int MAXWIDTH, MAXHEIGHT, HALFWIDTH, HALFHEIGHT;
	int scale = radius;		// initiate scale
    int inc_scale = scale;	// increment scale
	int speed = 5;
	float inc_rotate = 0;	// increment rotate
	float enhancer_inc_rotate = 0.15;

	int random_color = LIGHTCLAY;
	bool _true = true;
    int page = 0;
    
	while(1)
	{
		
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
		
		MAXWIDTH = getmaxx();
		MAXHEIGHT = getmaxy();
		HALFWIDTH =	round(MAXWIDTH/2);
		HALFHEIGHT = round(MAXHEIGHT/2);
		
		

	/* ===========================================================CIRCLE ANIMATION=================================================================== */
	// init radius
	int radius = 100;
	
	// init point center screen
	POINT CENTER;
	CENTER.x = HALFWIDTH;
	CENTER.y = HALFHEIGHT;

	// declarating dynamic x y axis for next line
	POINT next_line_point;
		
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, WHITE); delay(DELAY2);
	// draw center circle
	next_line_point = solid_line_circle(HALFWIDTH, HALFHEIGHT, radius);
	// remove last line of circle
	line_bresenham(next_line_point.x, next_line_point.y, HALFWIDTH, HALFHEIGHT, BLACK);
	// put center point
	filled_circle_bresenham(HALFWIDTH, HALFHEIGHT, 2, WHITE); delay(DELAY2);
	
	//  initiating 4 center point for animating circle
	POINT circle_center_point[4];
		circle_center_point[0].x = HALFWIDTH  - radius;
		circle_center_point[0].y = HALFHEIGHT + radius;
		
		circle_center_point[1].x = HALFWIDTH  + radius;
		circle_center_point[1].y = HALFHEIGHT + radius;
		
		circle_center_point[2].x = HALFWIDTH  + radius;
		circle_center_point[2].y = HALFHEIGHT - radius;
		
		circle_center_point[3].x = HALFWIDTH  - radius;
		circle_center_point[3].y = HALFHEIGHT - radius;
		

	 // put 1st point
	 filled_circle_bresenham(circle_center_point[0].x, circle_center_point[0].y, 2, WHITE); delay(DELAY2);
	 // draw 1st circle
	 next_line_point = dotted_line_circle(circle_center_point[0].x,circle_center_point[0].y,radius);
	 // remove last line in 1ST circle
	 line_bresenham(circle_center_point[0].x, circle_center_point[0].y, next_line_point.x, next_line_point.y, BLACK);
	 // put 1st point
	 filled_circle_bresenham(circle_center_point[0].x, circle_center_point[0].y, 2, WHITE); delay(DELAY2);
	
	 // draw connected line
	 delayed_line_bresenham(circle_center_point[0].x, circle_center_point[0].y, circle_center_point[1].x, circle_center_point[1].y, WHITE, 1);
	 // put 2nd point
	 filled_circle_bresenham(circle_center_point[1].x, circle_center_point[1].y, 2, WHITE); delay(DELAY2);
	 // remove connected line
	 line_bresenham(circle_center_point[0].x, circle_center_point[0].y, circle_center_point[1].x, circle_center_point[1].y, BLACK);
	 // draw 2nd circle
	 next_line_point = dotted_line_circle(circle_center_point[1].x,circle_center_point[1].y,radius);
	 // remove last line in 2nd circle
	 line_bresenham(circle_center_point[1].x, circle_center_point[1].y, next_line_point.x, next_line_point.y, BLACK);
	 // put 2nd point
	 filled_circle_bresenham(circle_center_point[1].x, circle_center_point[1].y, 2, WHITE); delay(DELAY2);
	
	 // draw connected line
	 delayed_line_bresenham(circle_center_point[1].x, circle_center_point[1].y, circle_center_point[2].x, circle_center_point[2].y, WHITE, 1);
	 // put 3rd point
	 filled_circle_bresenham(circle_center_point[2].x, circle_center_point[2].y, 2, WHITE); delay(DELAY2);
	 // remove connected line
	 line_bresenham(circle_center_point[1].x, circle_center_point[1].y, circle_center_point[2].x, circle_center_point[2].y, BLACK);
	 // draw 3rd circle
	 next_line_point = dotted_line_circle(circle_center_point[2].x,circle_center_point[2].y,radius);
	 // remove last line in 3rd circle
	 line_bresenham(circle_center_point[2].x, circle_center_point[2].y, next_line_point.x, next_line_point.y, BLACK);
	 // put 3rd point
	 filled_circle_bresenham(circle_center_point[2].x, circle_center_point[2].y, 2, WHITE); delay(DELAY2);
	
	 // draw connected line
	 delayed_line_bresenham(circle_center_point[2].x, circle_center_point[2].y, circle_center_point[3].x, circle_center_point[3].y, WHITE, 1);
	 // put 4th point
	 filled_circle_bresenham(circle_center_point[3].x, circle_center_point[3].y, 2, WHITE); delay(DELAY2);
	 // remove connected line
	 line_bresenham(circle_center_point[2].x, circle_center_point[2].y, circle_center_point[3].x, circle_center_point[3].y, BLACK);
	 // draw 4th circle
	 next_line_point = dotted_line_circle(circle_center_point[3].x,circle_center_point[3].y,radius);
	 // remove last line in 4th circle
	 line_bresenham(circle_center_point[3].x, circle_center_point[3].y, next_line_point.x, next_line_point.y, BLACK);
	 // put 4th point
	 filled_circle_bresenham(circle_center_point[3].x, circle_center_point[3].y, 2, WHITE); delay(DELAY2);

	/* ===================================================================DRAW SQUARE======================================================================== */
	// draw rectangle and remove dotted circle
	delayed_line_bresenham(circle_center_point[0].x, circle_center_point[0].y, circle_center_point[1].x, circle_center_point[1].y, LIGHTCLAY, 1);
	dda_circle(circle_center_point[0].x,circle_center_point[0].y, radius, BLACK);

	delayed_line_bresenham(circle_center_point[1].x, circle_center_point[1].y, circle_center_point[2].x, circle_center_point[2].y, LIGHTCLAY, 1);
	dda_circle(circle_center_point[1].x,circle_center_point[1].y, radius, BLACK);

	delayed_line_bresenham(circle_center_point[2].x, circle_center_point[2].y, circle_center_point[3].x, circle_center_point[3].y, LIGHTCLAY, 1);
	dda_circle(circle_center_point[2].x,circle_center_point[2].y, radius, BLACK);

	delayed_line_bresenham(circle_center_point[3].x, circle_center_point[3].y, circle_center_point[0].x, circle_center_point[0].y, LIGHTCLAY, 1);
	dda_circle(circle_center_point[3].x,circle_center_point[3].y, radius, BLACK);
	
	delay(DELAY200);
	cleardevice();
	
	/* =============================================================DRAW ROTATE SQUARE ANIMATION============================================================= */
	// rotate rectangle 45 degrees
	animate_rotate_rectangle(CENTER, circle_center_point, DEGREE45);
	// animating split up and down rectangle 
	animate_rotate_translation_rectangle(CENTER, circle_center_point, DEGREE45);
	// draw last rotate rectangle
	draw_rotate_rectangle(CENTER, radius+40);

	delay(DELAY200);
	
	/* ==========================================================DRAW POINT CIRCLE ROTATE ANIMATION=========================================================== */
	POINT rotate_point[4];
	
	// rotate point
	for(int i=0; i<4; i++)
		rotate_point[i] = point_rotate_cw(CENTER.x, CENTER.y, circle_center_point[i].x, circle_center_point[i].y, DEGREE45);

	// rotate rectangle back to 0
	animate_rotate_rectangle(CENTER, rotate_point, DEGREE45);
	
	// draw 4 point
	for(int i=0; i<4; i++){
		delay(DELAY300); filled_circle_bresenham(circle_center_point[i].x, circle_center_point[i].y, 2, WHITE);
	}

	// remove rectangle
	delayed_line_bresenham(circle_center_point[0].x, circle_center_point[0].y, circle_center_point[1].x, circle_center_point[1].y, BLACK, 1);
	delayed_line_bresenham(circle_center_point[1].x, circle_center_point[1].y, circle_center_point[2].x, circle_center_point[2].y, BLACK, 1);
	delayed_line_bresenham(circle_center_point[2].x, circle_center_point[2].y, circle_center_point[3].x, circle_center_point[3].y, BLACK, 1);
	delayed_line_bresenham(circle_center_point[3].x, circle_center_point[3].y, circle_center_point[0].x, circle_center_point[0].y, BLACK, 1);

	// rotating point
	animate_rotate_point(CENTER, circle_center_point, DEGREE90);
	draw_two_circle(CENTER.x, CENTER.y, radius, LIGHTCLAY, 1);
	// animating two circle
	delay(DELAY200); animate_translation_two_circle(CENTER, radius, LIGHTCLAY);

/* ======================================================================DRAW INITIATE PATTERN=================================================================== */

	// draw center point
	delay(DELAY200);	filled_circle_bresenham(CENTER.x, CENTER.y, 2, WHITE);
	// draw 6 circle by rotation
	delay(DELAY200);	draw_rotate_translation_circle(CENTER, radius, LIGHTCLAY, DEGREE60, DELAY100);
	// draw 12 line by rotation
	delay(DELAY200);	delayed_draw_rotate_line_360(CENTER.x, CENTER.y, radius*2, 12);
	filled_circle_bresenham(CENTER.x, CENTER.y, 2, WHITE);
	delay(DELAY300);
	
/* =======================================================================ANIMATIE FINAL PATTERN================================================================= */
    // scale used as object radius


	// final pattern animation
//	while(_true) {
		
		inc_scale = scale*cos(PI_PER_RADIAN * inc_rotate * speed); // big to small scale, use sin function for otherwise

		delay(DELAY10);
		draw_pattern(CENTER, abs(inc_scale), random_color, inc_rotate*10, DELAY100);
		
		random_color = rand() % 14 + 1; //random from 1 s.d 14
		inc_rotate += 0.15;
        page = 1-page;
//	 }
	 
	}

	getch();
	
	// deallocate memory allocated for graphics screen 
	closegraph();
	
	return 0;
}
