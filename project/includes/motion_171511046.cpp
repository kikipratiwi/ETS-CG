#include "motion_171511046.h"

void rotate_line_360(int x1, int y1, int r, int n) {
	int x2, y2, xb, yb, x, y, rx, ry;
	double degree, fulldegree ,arg;
	 
	degree = 360/n;
	
	x2 = x1+r;
	y2 = y1;
	
	xb = x2;
	yb = y2;
	fulldegree = degree;
	while(fulldegree <= 360){
		arg = (fulldegree * 0.01745);
		
		rx = x2-x1;
		ry = y2-y1;
		
		x = (int) (x1 + (rx) * cos(arg) - (ry)*sin(arg));
	    y = (int) (y1 + (rx) * sin(arg) - (ry)*cos(arg));
	    
	    line_bresenham(x1,y1,x,y, GREEN, 0);
	    
	    line_bresenham(xb,yb,x,y, RED, 0);
	    
	    xb = x;
	    yb = y;
	    
	    fulldegree = fulldegree + degree;
	    delay(10);
	}
}

POINT rotate_cw(POINT center, POINT pivot, double angle){
	POINT p1;
	double radian=angle*(-0.01745);
	
	p1.x=abs(pivot.x +((center.x-pivot.x)*cos(radian)-(center.y-pivot.y)*sin(radian)));
	p1.y=abs(pivot.y +((center.x-pivot.x)*sin(radian)+(center.y-pivot.y)*cos(radian)));
	
	return p1;
}

POINT rotate_ccw(POINT center, POINT pivot, double angle){
	POINT p1;
	double radian=angle*(-0.01745);
	
	p1.x=abs(pivot.x +((center.x-pivot.x)*  cos(radian) +(center.y-pivot.y)*sin(radian)));
	p1.y=abs(pivot.y +((center.x-pivot.x)*(-sin(radian))+(center.y-pivot.y)*cos(radian)));
	
	return p1;
}

// POINT line_rotate(POINT p1, POINT p2, int ang) {
// 	POINT pr;
    
// 	pr = rotate_ccw();
    
//     //draw rotate line
//     line_bresenham(x2, y2, pr.x, pr.y, GREEN);  
    
//     return pr;
// }

void draw_cartesian_axis()
{
	// converting the screen co-ordinates to more user friendly co-ordinates
	// with respect to the centre of the screen.
	// cartesian axis
	line(0,HALFHEIGHT, MAXWIDTH, HALFHEIGHT); 	//horizontal
	line(HALFWIDTH, 0, HALFWIDTH, MAXHEIGHT);	//vertical
	setcolor(5); // green
}

void circle_bresenham(int xc, int yc, int r, int color)
{ 
	void drawCircle(int xc, int yc, int x, int y, int color);
	
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, color); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y, color); 
    } 
} 

void drawCircle(int xc, int yc, int x, int y, int color)
{
    putpixel(xc+x, yc+y, color); 
    putpixel(xc-x, yc+y, color); 
	putpixel(xc+x, yc-y, color); 
	putpixel(xc-x, yc-y, color); 
    putpixel(xc+y, yc+x, color); 
	putpixel(xc-y, yc+x, color); 
	putpixel(xc+y, yc-x, color); 
	putpixel(xc-y, yc-x, color);
} 

void filled_circle_bresenham(int xc, int yc, int r, int color)
{ 
	void drawFilledCircle(int xc, int yc, int x, int y, int color);
	
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawFilledCircle(xc, yc, x, y, color); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawFilledCircle(xc, yc, x, y, color);
    } 
} 

void drawFilledCircle(int xc, int yc, int x, int y, int color)
{
    putpixel(xc+x, yc+y, color); 
	line_bresenham(xc, yc, xc+x, yc+y, color, 0);

    putpixel(xc-x, yc+y, color); 
	line_bresenham(xc, yc, xc-x, yc+y, color, 0);
    
	putpixel(xc+x, yc-y, color); 
	line_bresenham(xc, yc, xc+x, yc-y, color, 0);
    
	putpixel(xc-x, yc-y, color); 
	line_bresenham(xc, yc, xc-x, yc-y, color, 0);

    putpixel(xc+y, yc+x, color); 
	line_bresenham(xc, yc, xc+y, yc+x, color, 0);
    
	putpixel(xc-y, yc+x, color); 
	line_bresenham(xc, yc, xc-y, yc+x, color, 0);
    
	putpixel(xc+y, yc-x, color); 
	line_bresenham(xc, yc, xc+y, yc-x, color, 0);
    
	putpixel(xc-y, yc-x, color);
	line_bresenham(xc, yc, xc-y, yc-x, color, 0);
} 

void line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay)
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

POINT dotted_line_circle(int xCenter, int yCenter, int rad)
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
	
	int _delay=10;
	int x_bef=xCenter, y_bef=yCenter;

	int x_pivot = xCenter+rad;
	int y_pivot = yCenter;
	int x_rot=0, y_rot=0;
	double degree=10, fulldegree ,arg;
	int x,y;

	fulldegree = degree;
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		if(_delay == 22){
			arg = (fulldegree * 0.01745);
		
			x_rot = x_pivot-xCenter;
			y_rot = y_pivot-yCenter;
			
			x = (int) (xCenter + (x_rot) * cos(arg) - (y_rot)*sin(arg));
			y = (int) (yCenter + (x_rot) * sin(arg) - (y_rot)*cos(arg));
			
			line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE, 0);
			line_bresenham(xCenter, yCenter, x-1, y, YELLOW, 0);
			
			_delay=0;
			x_bef=x-1;
			y_bef=y;
			
		    fulldegree = fulldegree + degree;
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
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE, 0);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+rad, yCenter, YELLOW, 5);
	
	POINT last_POINT;
	last_POINT.x = xCenter+rad;
	last_POINT.y = yCenter;
	
	return last_POINT;
}


POINT solid_line_circle(int xCenter, int yCenter, int rad)
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
	
	int _delay=10;
	int x_bef=xCenter, y_bef=yCenter;

	int x_pivot = xCenter+rad;
	int y_pivot = yCenter;
	int x_rot=0, y_rot=0;
	double degree=10, fulldegree ,arg;
	int x,y;

	fulldegree = degree;
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		if(_delay == 22){
			arg = (fulldegree * 0.01745);
		
			x_rot = x_pivot-xCenter;
			y_rot = y_pivot-yCenter;
			
			x = (int) (xCenter + (x_rot) * cos(arg) - (y_rot)*sin(arg));
			y = (int) (yCenter + (x_rot) * sin(arg) - (y_rot)*cos(arg));
			
			line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE, 0);
			line_bresenham(xCenter, yCenter, x-1, y, YELLOW, 0);
			
			_delay=0;
			x_bef=x-1;
			y_bef=y;
			
		    fulldegree = fulldegree + degree;
		}
		
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,3);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		if(_delay == 30) _delay = 0;
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE, 0);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+rad, yCenter, YELLOW, 5);
	
	POINT last_POINT;
	last_POINT.x = xCenter+rad;
	last_POINT.y = yCenter;
	
	return last_POINT;
}

void dda_circle(int xCenter, int yCenter, int rad, int color)
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
		
		// delay(10);
		putpixel(xCenter+xCenter2,yCenter-yCenter2,	color);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
}


    
