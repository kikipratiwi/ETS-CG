#include "motion_171511046.h"

/* ==============================================CANVAS================================================= */
void set_canvas()
{
	setfillstyle(SOLID_FILL, BLACK); 
	rectangle(0, 0, MAXWIDTH, MAXHEIGHT); 
    floodfill(1,1, BLACK);
}

void draw_cartesian_axis()
{
	// converting the screen co-ordinates to more user friendly co-ordinates
	// with respect to the centre of the screen.
	// cartesian axis
	line(0,HALFHEIGHT, MAXWIDTH, HALFHEIGHT); 	//horizontal
	line(HALFWIDTH, 0, HALFWIDTH, MAXHEIGHT);	//vertical
	setcolor(5); // green
}

/* =========================================TRANSFORMATION============================================== */
POINT point_rotate_cw(int xCenter, int yCenter, int x, int y, float degree)
{
     float xR , yR; 
     POINT p_rotate;
     
     int xTrans, yTrans;
      

     //tranlasi awal
     xTrans = x - xCenter;
     yTrans = y - yCenter;

     //cari point rotate
     xR = xTrans * cos(PI_PER_RADIAN * degree) - yTrans * sin(PI_PER_RADIAN * degree);
     yR = xTrans * sin(PI_PER_RADIAN * degree) + yTrans * cos(PI_PER_RADIAN * degree);

     //tranlasi akhir  
     xR = xR + (xCenter);
     yR = yR + (yCenter);
     
     p_rotate.x = ROUND(xR);
     p_rotate.y = ROUND(yR);
    //  p_rotate.x = xR+0.5;
    //  p_rotate.y = yR+0.5;
     
     return p_rotate; 
}

POINT point_rotate_ccw(int xCenter, int yCenter, int x, int y, float degree)
{
     float xR , yR; 
     POINT p_rotate;
     
     int xTrans, yTrans;
      

     //tranlasi awal
     xTrans = x - xCenter;
     yTrans = y - yCenter;

     //cari point rotate
     xR = xTrans * cos(PI_PER_RADIAN * degree) 	+ yTrans * sin(PI_PER_RADIAN * degree);
     yR = xTrans * -(sin(PI_PER_RADIAN * degree)) + yTrans * cos(PI_PER_RADIAN * degree);

     //tranlasi akhir  
     xR = xR + (xCenter);
     yR = yR + (yCenter);
     
     p_rotate.x = ROUND(xR);
     p_rotate.y = ROUND(yR);
    //  p_rotate.x = xR+0.5;
    //  p_rotate.y = yR+0.5;
     
     return p_rotate; 
}

POINT point_scale(int xCenter, int yCenter, int x, int y, float scale)
{
      POINT aksen;
        
      aksen.x = (x-xCenter)*scale + xCenter;
      aksen.y = (y-yCenter)*scale + yCenter;  
	  
      return aksen;
}

POINT point_translation(int x, int y, int x1, int y1)
{
     POINT aksen;
     
     aksen.x = x+x1;
     aksen.y = y+y1;
     
     return aksen;
}

/* ======================================DRAW ANIMATED OBJECT========================================== */
void delayed_draw_rotate_line_360(int x1, int y1, int radius, int n)
{
	int x2, y2, xb, yb, x, y, rx, ry;
	double degree, fulldegree ,arg;
	 
	degree = 360/n;
	
	x2 = x1+radius;
	y2 = y1;

	fulldegree = degree;
	while(fulldegree <= FULLDEGREE){
		arg = (fulldegree * 0.01745);
		
		rx = x2-x1;
		ry = y2-y1;
		
		x = (int) (x1 + (rx) * cos(arg) - (ry)*sin(arg));
	    y = (int) (y1 + (rx) * sin(arg) - (ry)*cos(arg));
	    
	    line_bresenham(x1,y1,x,y, LIGHTCLAY);
		filled_circle_bresenham(x, y, 2, WHITE);
	    
	    fulldegree = fulldegree + degree;
	    delay(DELAY100);
	}
}

void draw_rotate_line_360(int x1, int y1, int radius, int n)
{
	int x2, y2, xb, yb, x, y, rx, ry;
	double degree, fulldegree ,arg;
	 
	degree = 360/n;
	
	x2 = x1+radius;
	y2 = y1;

	fulldegree = degree;
	while(fulldegree <= FULLDEGREE){
		arg = (fulldegree * 0.01745);
		
		rx = x2-x1;
		ry = y2-y1;
		
		x = (int) (x1 + (rx) * cos(arg) - (ry)*sin(arg));
	    y = (int) (y1 + (rx) * sin(arg) - (ry)*cos(arg));
	    
	    line_bresenham(x1,y1,x,y, LIGHTCLAY);
		filled_circle_bresenham(x, y, 2, WHITE);
	    
	    fulldegree = fulldegree + degree;
	}
}

void animate_rotate_point(POINT p_center, POINT p[], int degree, int radius)
{
	POINT pr[4];
	
	float _degree = 0;
	while (_degree <= degree)
	{	
		pr[0] = point_rotate_cw(p_center.x, p_center.y+radius, p[0].x, p[0].y, _degree);
		pr[1] = point_rotate_cw(p_center.x, p_center.y+radius, p[1].x, p[1].y, _degree);
		pr[2] = point_rotate_cw(p_center.x, p_center.y-radius, p[2].x, p[2].y, _degree);
		pr[3] = point_rotate_cw(p_center.x, p_center.y-radius, p[3].x, p[3].y, _degree);


		cleardevice();
		filled_circle_bresenham(pr[0].x, pr[0].y, 2, WHITE);
		filled_circle_bresenham(pr[1].x, pr[1].y, 2, WHITE);
		filled_circle_bresenham(pr[2].x, pr[2].y, 2, WHITE);
		filled_circle_bresenham(pr[3].x, pr[3].y, 2, WHITE);

		_degree += 1;
		delay(DELAY10);
	}
}

void animate_rotate_rectangle(POINT p_center, POINT p[], int degree)
{
	POINT pr[4];
	float _degree = 1;

	while (_degree <= degree)
	{
		for(int i=0; i<4; i++)
		{
			pr[i] = point_rotate_cw(p_center.x, p_center.y, p[i].x, p[i].y, _degree);
		}

		cleardevice();
		delay(DELAY10);
		draw_rectangle(pr);
		
		_degree += 1;
	}
		cleardevice();
		draw_rectangle(pr);
}

void draw_rectangle(POINT p[])
{
	for(int i=0; i<3; i++)
		line_bresenham(p[i].x, p[i].y, p[i+1].x, p[i+1].y, LIGHTCLAY);
		
	line_bresenham(p[3].x, p[3].y, p[0].x, p[0].y, LIGHTCLAY);	
}

void animate_rotate_translation_rectangle(POINT p_center, POINT p[], int degree)
{
	POINT pr[4];

	//rotate point
	for(int i=0; i<4; i++)
		pr[i] = point_rotate_cw(p_center.x, p_center.y, p[i].x, p[i].y, degree);

	int t_inc = 1;
	POINT p_center_2 = p_center;
	POINT p_center_3 = p_center;

	int mini_radius = 10;
	int t_inc_mini_rectangle = 3;
	
	draw_rotate_rectangle(p_center_2, mini_radius);
	draw_rotate_rectangle(p_center_3, mini_radius);
	delay(DELAY200);
	
	// split up
	while ( t_inc < RADIUSY)
	{
		t_inc += 1;
		cleardevice();

		// bottom triangle
		line_bresenham(pr[0].x, pr[0].y + t_inc, pr[1].x, pr[1].y + t_inc, LIGHTCLAY);
		line_bresenham(pr[1].x, pr[1].y + t_inc, pr[2].x, pr[2].y + t_inc, LIGHTCLAY);
		
		// top triangle
		line_bresenham(pr[2].x, pr[2].y - t_inc, pr[3].x, pr[3].y - t_inc, LIGHTCLAY);
		line_bresenham(pr[3].x, pr[3].y - t_inc, pr[0].x, pr[0].y - t_inc, LIGHTCLAY);

		// animate mini rectangle
		p_center_2.x += t_inc_mini_rectangle;
		p_center_3.x -= t_inc_mini_rectangle;
		draw_rotate_rectangle(p_center_2, mini_radius);
		draw_rotate_rectangle(p_center_3, mini_radius);

		delay(DELAY10);
	}
	
	delay(DELAY200);
	t_inc = RADIUSY;
	
	// split down
	while ( t_inc > 0)
	{
		t_inc -= 1;
		cleardevice();

		line_bresenham(pr[0].x, pr[0].y + t_inc, pr[1].x, pr[1].y + t_inc, LIGHTCLAY);
		line_bresenham(pr[1].x, pr[1].y + t_inc, pr[2].x, pr[2].y + t_inc, LIGHTCLAY);
		
		line_bresenham(pr[2].x, pr[2].y - t_inc, pr[3].x, pr[3].y - t_inc, LIGHTCLAY);
		line_bresenham(pr[3].x, pr[3].y - t_inc, pr[0].x, pr[0].y - t_inc, LIGHTCLAY);

		// animate mini rectangle
		draw_rotate_rectangle(p_center_2, mini_radius);
		draw_rotate_rectangle(p_center_3, mini_radius);
		p_center_2.x -= t_inc_mini_rectangle;
		p_center_3.x += t_inc_mini_rectangle;

		delay(DELAY10);
	}
}

void draw_rotate_rectangle(POINT p_center, int radius)
{
	line_bresenham(p_center.x, 			p_center.y+radius,	p_center.x-radius,	p_center.y,			LIGHTCLAY);
	line_bresenham(p_center.x-radius,	p_center.y,			p_center.x,			p_center.y-radius,	LIGHTCLAY);
	
	line_bresenham(p_center.x,			p_center.y-radius,	p_center.x+radius,	p_center.y,			LIGHTCLAY);
	line_bresenham(p_center.x+radius,	p_center.y,			p_center.x,			p_center.y+radius,	LIGHTCLAY);
}

void draw_rotate_translation_circle(POINT p_center, int radius, int color, float degree, int _delay)
{
	POINT p_center_top;
	p_center_top.x = p_center.x;
	p_center_top.y = p_center.y+radius;

	POINT pr;
	// int value_added = ang / 5;
	float _degree = 0;
	while (_degree <= FULLDEGREE)
	{
		pr = point_rotate_cw(p_center.x, p_center.y, p_center_top.x, p_center_top.y, _degree);

		circle_bresenham(pr.x, pr.y, radius, LIGHTCLAY);
		filled_circle_bresenham(pr.x, pr.y, 2, WHITE); //for bullet

		_degree += degree;
	}
	circle_bresenham(p_center.x, p_center.y, 2*radius, LIGHTCLAY);
	circle_bresenham(p_center.x, p_center.y, (2*radius)-(radius/4), LIGHTCLAY);

}

void draw_pattern(POINT p_center, int radius, int color, float degree, int _delay)
{
	POINT p_center_top;
	p_center_top.x = p_center.x;
	p_center_top.y = p_center.y+radius;

	POINT pr;
	float _degree = 0+degree;
	
	for(int i=0;i<6;i++){
		pr = point_rotate_cw(p_center.x, p_center.y, p_center_top.x, p_center_top.y, _degree);

		circle_bresenham(pr.x, pr.y, radius, color);
		filled_circle_bresenham(p_center.x, p_center.y, 2, WHITE); //for bullet
		filled_circle_bresenham(pr.x, pr.y, 2, WHITE); //for bullet

		_degree += DEGREE60;
	}
	
	_degree = 0+degree;
	for(int i=0;i<12;i++){
        pr = point_rotate_ccw(p_center.x, p_center.y, p_center.x, p_center.y-(2*radius), _degree);
        
		line_bresenham (p_center.x, p_center.y, pr.x, pr.y, color);
		
		filled_circle_bresenham(p_center.x, p_center.y, 2, WHITE); //for bullet
		filled_circle_bresenham(pr.x, pr.y, 2, WHITE); //for bullet
             
        _degree += DEGREE30;
     }
	
	circle_bresenham(p_center.x, p_center.y, 2*radius, color);
	circle_bresenham(p_center.x, p_center.y, (2*radius)-(radius/4), color);
}

void animate_translation_two_circle(POINT p_center, int radius, int color)
{
	POINT p_center_top;
	POINT p_center_botttom;

	p_center_top.x = p_center.x;
	p_center_top.y = p_center.y+radius;

	p_center_botttom.x = p_center.x;
	p_center_botttom.y = p_center.y-radius;

	int y_inc=1;
	while(y_inc <= radius)
	{
		cleardevice();
		delay(1);
		circle_bresenham(p_center.x, p_center_top.y - y_inc, radius, LIGHTCLAY);
		circle_bresenham(p_center.x, p_center_botttom.y + y_inc, radius, LIGHTCLAY);
		y_inc++;
	}

}

/* =====================================DRAW PRIMITIVE OBJECT========================================== */
void dda_circle(int xCenter, int yCenter, int radius, int color)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = radius;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<radius);
	
	eps = 1/pow(2,i-1);
	
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		// delay(DELAY10);
		putpixel(xCenter+xCenter2,yCenter-yCenter2,	color);
		putpixel(xCenter+xCenter2,yCenter-yCenter2+1,	color);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
}

void draw_two_circle(int xCenter, int yCenter, int radius, int color, int _delay)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = radius;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<radius);
	
	eps = 1/pow(2,i-1);
	
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		delay(_delay);
		putpixel(xCenter+xCenter2,yCenter-yCenter2+radius,	color);
		putpixel(xCenter+xCenter2,yCenter-yCenter2-radius,	color);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
}

void circle_bresenham(int xc, int yc, int radius, int color)
{ 
	void drawCircle(int xc, int yc, int x, int y, int color);
	
    int x = 0, y = radius; 
    int d = 3 - 2 * radius; 
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

void filled_circle_bresenham(int xc, int yc, int radius, int color)
{ 
	void drawFilledCircle(int xc, int yc, int x, int y, int color);
	
    int x = 0, y = radius; 
    int d = 3 - 2 * radius; 
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
	line_bresenham(xc, yc, xc+x, yc+y, color);

    putpixel(xc-x, yc+y, color); 
	line_bresenham(xc, yc, xc-x, yc+y, color);
    
	putpixel(xc+x, yc-y, color); 
	line_bresenham(xc, yc, xc+x, yc-y, color);
    
	putpixel(xc-x, yc-y, color); 
	line_bresenham(xc, yc, xc-x, yc-y, color);

    putpixel(xc+y, yc+x, color); 
	line_bresenham(xc, yc, xc+y, yc+x, color);
    
	putpixel(xc-y, yc+x, color); 
	line_bresenham(xc, yc, xc-y, yc+x, color);
    
	putpixel(xc+y, yc-x, color); 
	line_bresenham(xc, yc, xc+y, yc-x, color);
    
	putpixel(xc-y, yc-x, color);
	line_bresenham(xc, yc, xc-y, yc-x, color);
} 

void line_bresenham(int x1, int y1, int x2, int y2, int color)
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

void delayed_line_bresenham(int x1, int y1, int x2, int y2, int color, int _delay)
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
			
			delay(_delay);
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
			
			delay(_delay);
			putpixel(x, y, color);
		}
	}
}

POINT dotted_line_circle(int xCenter, int yCenter, int radius)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = radius;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<radius);
	
	eps = 1/pow(2,i-1);
	
	int _delay=0;
	int x_bef=xCenter, y_bef=yCenter;

	int x_pivot = xCenter+radius;
	int y_pivot = yCenter;
	int x_rot=0, y_rot=0;
	double degree=10, fulldegree ,arg;
	int x,y;

	fulldegree = degree;
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
		if(_delay == 6){
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,LIGHTCLAY);
			putpixel(xCenter+xCenter2,yCenter-yCenter2+1,LIGHTCLAY);
			_delay = 0;
		}
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, BLACK);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+radius, yCenter, LIGHTCLAY);
	
	POINT last_POINT;
	last_POINT.x = xCenter+radius;
	last_POINT.y = yCenter;
	
	return last_POINT;
}

POINT solid_line_circle(int xCenter, int yCenter, int radius)
{
	float xCenter1, xCenter2, yCenter1, yCenter2, eps, sx, sy;
	int val, i;

	xCenter1 = radius;	
	yCenter1 = 0;
	sx = xCenter1;
	sy = yCenter1;
	
	i=0;
	do{
		val=pow(2,i);
		i++;
	}while(val<radius);
	
	eps = 1/pow(2,i-1);
	
	int _delay=10;
	int x_bef=xCenter, y_bef=yCenter;

	int x_pivot = xCenter+radius;
	int y_pivot = yCenter;
	int x_rot=0, y_rot=0;
	double degree=10, fulldegree ,arg;
	int x,y;

	fulldegree = degree;
	do{
		xCenter2 = xCenter1 + yCenter1*eps;
		yCenter2 = yCenter1 - eps*xCenter2;
		
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,LIGHTCLAY);
			putpixel(xCenter+xCenter2,yCenter-yCenter2+1,LIGHTCLAY);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		if(_delay == DELAY30) _delay = 0;
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, BLACK);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+radius, yCenter, LIGHTCLAY);
	
	POINT last_POINT;
	last_POINT.x = xCenter+radius;
	last_POINT.y = yCenter;
	
	return last_POINT;
}
