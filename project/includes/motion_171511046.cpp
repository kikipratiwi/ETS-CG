#include "motion_171511046.h"


void set_canvas()
{
	setfillstyle(SOLID_FILL, WHITE); 
	rectangle(0, 0, MAXWIDTH, MAXHEIGHT); 
    floodfill(1,1, WHITE);
}

POINT point_rotate_cw(int xCenter, int yCenter, int x, int y, float deg)
{
     float xaksen , yaksen; 
     POINT aksen;
     
     int xtrans, ytrans;
     double val = PI / 180.0;
     //tranlasi awal
     xtrans = x - xCenter;
     ytrans = y - yCenter;
     //printf("%d %d\n", xtrans, ytrans);
     //cari aksen
     xaksen = xtrans * cos(val * deg) - ytrans * sin(val * deg);
     yaksen = ytrans * cos(val * deg) + xtrans * sin(val * deg);
     //tranlasi akhir  
     xaksen = xaksen + (xCenter);
     yaksen = yaksen + (yCenter);
     
   //  printf("%f %f\n", xaksen, yaksen);
     
     aksen.x = xaksen+0.5;
     aksen.y = yaksen+0.5;
     
     return aksen; 
}

void draw_rotate_rectangle(POINT p_center, POINT p[], int degree)
{
	POINT pr[4];
	// int value_added = ang / 5;
	float deg = 1;
	while (deg <= ang)
	{
		for(int i=0; i<4; i++)
		{
			pr[i] = point_rotate_cw(p_center.x, p_center.y, p[i].x, p[i].y, deg);
		}

		cleardevice();
		draw_rectangle(pr);
		deg += 1;
		delay(10);
	}
		cleardevice();
		draw_rectangle(pr);
}

void draw_rotate_point(POINT p_center, POINT p[], int degree)
{
	POINT pr[4];
	// int value_added = ang / 5;
	float deg = 0;
	while (deg <= ang)
	{	
		pr[0] = point_rotate_cw(p_center.x, p_center.y+100, p[0].x, p[0].y, deg);
		pr[1] = point_rotate_cw(p_center.x, p_center.y+100, p[1].x, p[1].y, deg);
		pr[2] = point_rotate_cw(p_center.x, p_center.y-100, p[2].x, p[2].y, deg);
		pr[3] = point_rotate_cw(p_center.x, p_center.y-100, p[3].x, p[3].y, deg);


		cleardevice();
		filled_circle_bresenham(pr[0].x, pr[0].y, 2, MOCCA);
		filled_circle_bresenham(pr[1].x, pr[1].y, 2, MOCCA);
		filled_circle_bresenham(pr[2].x, pr[2].y, 2, MOCCA);
		filled_circle_bresenham(pr[3].x, pr[3].y, 2, MOCCA);

		deg += 1;
		delay(10);
	}
}

void draw_rotate_scale_rectangle(POINT p_center, POINT p[], int degree, float scale)
{
	POINT pr[4];
	// int value_added = ang / 5;
	float deg = ang;
	for(int i=0; i<4; i++)
	{
		pr[i] = point_rotate_cw(p_center.x, p_center.y, p[i].x, p[i].y, deg);
	}


	int t_inc = 1;
	POINT p_center_2 = p_center;
	POINT p_center_3 = p_center;

	draw_scale_rectangle(p_center_2, 10, 0);
	draw_scale_rectangle(p_center_3, 10, 0);
	delay(200);
	
	while ( t_inc < 100)
	{

		t_inc += 1;
		cleardevice();

		line_bresenham(pr[0].x, pr[0].y + t_inc, pr[1].x, pr[1].y + t_inc, MOCCA);
		line_bresenham(pr[1].x, pr[1].y + t_inc, pr[2].x, pr[2].y + t_inc, MOCCA);
		
		line_bresenham(pr[2].x, pr[2].y - t_inc, pr[3].x, pr[3].y - t_inc, MOCCA);
		line_bresenham(pr[3].x, pr[3].y - t_inc, pr[0].x, pr[0].y - t_inc, MOCCA);

		p_center_2.x += 3;
		p_center_3.x -= 3 ;
		draw_scale_rectangle(p_center_2, 10, 0);
		draw_scale_rectangle(p_center_3, 10, 0);

		delay(10);
	}
	
	delay(200);
	while ( t_inc > 0)
	{

		t_inc -= 1;
		cleardevice();

		line_bresenham(pr[0].x, pr[0].y + t_inc, pr[1].x, pr[1].y + t_inc, MOCCA);
		line_bresenham(pr[1].x, pr[1].y + t_inc, pr[2].x, pr[2].y + t_inc, MOCCA);
		
		line_bresenham(pr[2].x, pr[2].y - t_inc, pr[3].x, pr[3].y - t_inc, MOCCA);
		line_bresenham(pr[3].x, pr[3].y - t_inc, pr[0].x, pr[0].y - t_inc, MOCCA);

		draw_scale_rectangle(p_center_2, 10, 0);
		draw_scale_rectangle(p_center_3, 10, 0);
		p_center_2.x -= 3;
		p_center_3.x += 3 ;

		delay(10);
	}
}

void draw_scale_rectangle(POINT p_center, int r, float scale)
{
	line_bresenham(p_center.x, p_center.y+r, p_center.x-r, p_center.y, MOCCA);
	line_bresenham(p_center.x-r, p_center.y, p_center.x, p_center.y-r, MOCCA);
	line_bresenham(p_center.x, p_center.y-r, p_center.x+r, p_center.y, MOCCA);
	line_bresenham(p_center.x+r, p_center.y, p_center.x, p_center.y+r, MOCCA);
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

void draw_rectangle(POINT p[])
{
	for(int i=0; i<3; i++)
		line_bresenham(p[i].x, p[i].y, p[i+1].x, p[i+1].y, MOCCA);
		
	line_bresenham(p[3].x, p[3].y, p[0].x, p[0].y, MOCCA);
		
}


void draw_rotate_line_360(int x1, int y1, int r, int n)
{
	int x2, y2, xb, yb, x, y, rx, ry;
	double degree, fulldegree ,arg;
	 
	degree = 360/n;
	
	x2 = x1+r;
	y2 = y1;

	fulldegree = degree;
	while(fulldegree <= FULLDEGREE){
		arg = (fulldegree * 0.01745);
		
		rx = x2-x1;
		ry = y2-y1;
		
		x = (int) (x1 + (rx) * cos(arg) - (ry)*sin(arg));
	    y = (int) (y1 + (rx) * sin(arg) - (ry)*cos(arg));
	    
	    line_bresenham(x1,y1,x,y, MOCCA);
		filled_circle_bresenham(x, y, 2, MOCCA);
	    
	    fulldegree = fulldegree + degree;
	    delay(100);
	}
}


void rotate_line_360(int x1, int y1, int r, int n)
{
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
	    
	    line_bresenham(x1,y1,x,y, GREEN);
	    
	    line_bresenham(xb,yb,x,y, RED);
	    
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

// POINT line_rotate(POINT p1, POINT p2, int degree) {
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


void ellipseMidPoint (int xCenter,int yCenter, int Rx,int Ry)
{
	void ellipsePlotPoints(int xCenter, int yCenter, int x, int y);

    int Rx2 = Rx*Rx;
    int Ry2 = Ry*Ry;
    int twoRx2 = 2*Rx2;
    int twoRy2 = 2*Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;
	
    // Plot the first set of points
    ellipsePlotPoints(xCenter,yCenter,x,y);
    
	// Region 1
    p = ROUND(Ry2 - (Rx2 *Ry) + (0.25 * Rx2));
        while (px<py){
            x++;
            px  += twoRy2;
            if( p < 0){
              p += Ry2 + px;
            }
            else{
                y--;
                py -= twoRx2;
                p += Ry2 + px - py;
            }
            ellipsePlotPoints (xCenter,yCenter,x,y);
        }
    
    //Region 2
    p = ROUND (Ry2*(x+0.5)*(x+0.5) + Rx2*(y-1)*(y-1) - Rx2*Ry2);
        while(y>0){
            y--;
            py -= twoRx2;
            if(p>0){
                    p += Rx2 - py;
            }
            else{
                x++;
                px += twoRy2;
                p += Rx2 - py + px;
            }
            ellipsePlotPoints (xCenter,yCenter,x,y);

        }
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
		
	putpixel(xCenter + x, yCenter + y,1);
	putpixel(xCenter - x, yCenter + y,1);
	putpixel(xCenter + x, yCenter - y,1);
	putpixel(xCenter - x, yCenter - y,1);
	
	putpixel(xCenter + x, yCenter + y,2);
	putpixel(xCenter - x, yCenter + y,2);
	putpixel(xCenter + x, yCenter - y,2);
	putpixel(xCenter - x, yCenter - y,2);
}

void draw_rotate_translation_circle(POINT p_center, int r, int color, int degree)
{
	POINT p_center_top;
	p_center_top.x = p_center.x;
	p_center_top.y = p_center.y+r;

	POINT pr;
	// int value_added = ang / 5;
	float deg = 0;
	while (deg <= FULLDEGREE)
	{
		pr = point_rotate_cw(p_center.x, p_center.y, p_center_top.x, p_center_top.y, deg);

		delay(100);
		circle_bresenham(pr.x, pr.y, r, MOCCA);
		filled_circle_bresenham(pr.x, pr.y, 2, MOCCA); //for bullet

		deg += ang;
	}
	dda_circle(p_center.x, p_center.y, 2*r, MOCCA);
	dda_circle(p_center.x, p_center.y, (2*r)-(r/4), MOCCA);

}

void draw_translation_two_circle(POINT p_center, int r, int color)
{
	POINT p_center_top;
	POINT p_center_botttom;

	p_center_top.x = p_center.x;
	p_center_top.y = p_center.y+r;

	p_center_botttom.x = p_center.x;
	p_center_botttom.y = p_center.y-r;

	int y_inc=1;
	while(y_inc <= r)
	{
		cleardevice();
		delay(1);
		circle_bresenham(p_center.x, p_center_top.y - y_inc, r, MOCCA);
		circle_bresenham(p_center.x, p_center_botttom.y + y_inc, r, MOCCA);
		y_inc++;
	}

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
			
			line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE);
			line_bresenham(xCenter, yCenter, x-1, y, MOCCA);
			
			_delay=0;
			x_bef=x-1;
			y_bef=y;
			
		    fulldegree = fulldegree + degree;
		}
		
		if(_delay < 6){
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,MOCCA);
			putpixel(xCenter+xCenter2,yCenter-yCenter2+1,MOCCA);
		}
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		if(_delay == 30) _delay = 0;
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+rad, yCenter, MOCCA);
	
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
			
			line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE);
			line_bresenham(xCenter, yCenter, x-1, y, MOCCA);
			
			_delay=0;
			x_bef=x-1;
			y_bef=y;
			
		    fulldegree = fulldegree + degree;
		}
		
			delay(1);
			putpixel(xCenter+xCenter2,yCenter-yCenter2,MOCCA);
			putpixel(xCenter+xCenter2,yCenter-yCenter2+1,MOCCA);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
		
		if(_delay == 30) _delay = 0;
		_delay++;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
	
	//remove last-1 line in circle
	line_bresenham(xCenter, yCenter, x_bef, y_bef, WHITE);

	//draw last  line
	line_bresenham(xCenter, yCenter, xCenter+rad, yCenter, MOCCA);
	
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
		putpixel(xCenter+xCenter2,yCenter-yCenter2+1,	color);
		
		xCenter1=xCenter2;	
		yCenter1=yCenter2;
	
	}while((yCenter1-sy)<eps || (sx-xCenter1)>eps);
}


    
