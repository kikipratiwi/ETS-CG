#include "motion_171511046.h"

void draw_line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	
	if (x2 < x1) incx = -1;
	incy = 1;
	
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	
	if (dx > dy) {
		delay(_delay);
		putpixel(x, y, color);
		
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			
			putpixel(x, y, color);
		}
	} else {
		delay(_delay);
		putpixel(x, y, color);
		
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			
			putpixel(x, y, color);
		}
	}
}

POINT line_circle(int xCenter, int yCenter, int rad)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = rad;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<rad);
	
	eps = 1/pow(2,i-1);
	
	int l_delay=0;
	int _delay=10;
	int x_bef=0, y_bef=0;
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		if(_delay == 21){
			draw_line_bresenham(xCenter, yCenter, x_bef, y_bef, BLACK, 0);
			draw_line_bresenham(xCenter, yCenter, xCenter+xCenter2-1, yCenter-yCenter2, YELLOW, 0);
			
			_delay=0;
			x_bef=xCenter+xCenter2-1;
			y_bef=yCenter-yCenter2;
		}
		
		if(_delay < 6){
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,3);
		}
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		if(_delay == 30) _delay = 0;
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	draw_line_bresenham(xCenter, yCenter, x_bef, y_bef, BLACK, 0);
	draw_line_bresenham(xCenter, yCenter, xCenter+rad, yCenter, YELLOW, 0);
	delay(200);
	
	POINT last_point;
	last_point.x = xCenter+rad;
	last_point.y = yCenter;
	
	return last_point;
}

void dda_circle(int xCenter, int yCenter, int rad)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = rad;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<rad);
	
	eps = 1/pow(2,i-1);
	
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		delay(10);
		putpixel(xCenter+xCenter2,yCenter-yCenter2,3);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
}


    
