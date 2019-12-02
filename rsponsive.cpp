#include "includes/motion_171511046.h"
#include <stdio.h>

int main() {
	srand(time(NULL));

	// init radius
	int radius = 100;
	
	// input radius awal
	printf("Masukkan besar radius: "); scanf("%d", &radius);

	// render window
    initwindow( 800 , 700 , "ETS_171511046", 200);

	int MAXWIDTH, MAXHEIGHT, HALFWIDTH, HALFHEIGHT;
	POINT CENTER;
	
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
        
		MAXWIDTH = _MAXWIDTH;
		MAXHEIGHT = _MAXHEIGHT;
		HALFWIDTH =	_HALFWIDTH;
		HALFHEIGHT = _HALFHEIGHT;
		
//		printf("%d %d\n", MAXWIDTH, HALFWIDTH);

	/* ===========================================================CIRCLE ANIMATION=================================================================== */
	
	// init point center screen
		CENTER.x = HALFWIDTH;
		CENTER.y = HALFHEIGHT;

		inc_scale = scale*cos(PI_PER_RADIAN * inc_rotate * speed); // big to small scale, use sin function for otherwise

		delay(DELAY10);
		draw_pattern(CENTER, abs(inc_scale), random_color, inc_rotate*10, DELAY100);
		
		random_color = rand() % 14 + 1; //random from 1 s.d 14
		inc_rotate += 0.15;
        page = 1-page;
	 
		scale = MAXWIDTH/4;
	}

	getch();
	
	// deallocate memory allocated for graphics screen 
	closegraph();
	
	return 0;
}
