#include <math.h>
#include <time.h>
#include <graphics.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define hourAlpha (-90+(hour*360)/12)*(M_PI/180)
#define minuteAlpha (-90+(minute*360)/60)*(M_PI/180)
#define secAlpha (-90+(second*360)/60)*(M_PI/180)

typedef struct{
	double x;
	double y;
}point;

int hour12(int hour);
int abs(int n);

//Algortihm Makeline
void line_DDA(int X0, int Y0, int X1, int Y1,int color);
void bresenham(int x1, int y1, int x2, int y2);
void M2Point(int x1, int y1, int x2, int y2);

//Algorithm Make Circle
void makeCircle(int x, int y,int r);
void makeCircle2(int x, int y, int r);
void makeCircle3(int x, int y, int r);

//Algorithm Make Ellipse
void makeElipse(int x, int y, int r1, int r2);
void makeElipse2(int x, int y, int r1, int r2);

void makeTickTime(point Point_A,point Point_B, int color);

//Set Matrix
float setMatrix1(int degree,int x,int y,int z);
float setMatrix2(int degree,int x,int y,int z);
float setMatrix3(int degree,int x,int y,int z);

int main() {
	
	//Init window
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	//Mengambil Waktu dari sistem Windows
	time_t vTime = time(NULL);
	struct tm currentTime = *localtime(&vTime);
	currentTime = *localtime(&vTime);
	int hour, minute, second;
	hour=hour12(currentTime.tm_hour);
	minute=currentTime.tm_min;
	second=currentTime.tm_sec;	
		
	//Definition Point
	point Point_A;
	point Point_B;
	
	//initial Mid Point
	int point_x, point_y;
	Point_A.x= 200;
	Point_A.y= 200;
	
	//Initial Jarum dan Jari-jari Lingkaran
	int r_clock,r_second, r_minute, r_hour;
	r_clock = 100;
	r_second = 80;
	r_minute = 70;
	r_hour = 60;
	
	while(true){
		while(hour<=12){
			if(minute!=currentTime.tm_min){
				minute = 0;
				printf("masuk");
			}
			while(minute<60){
				if(second!=currentTime.tm_sec){
					second = 0;
					printf("masuk");
				}
				while(second<60){
					//Make Circle
					makeCircle(Point_A.x,Point_A.y,r_clock);
				
					//Make Tick Time Hour
					Point_B.x = Point_A.x+r_hour*cos(hourAlpha);
					Point_B.y= Point_A.y+r_hour*sin(hourAlpha);
					makeTickTime(Point_A, Point_B, 10);
					
					//Make Tick Time Minute
					Point_B.x = Point_A.x+r_minute*cos(minuteAlpha);
					Point_B.y= Point_A.y+r_minute*sin(minuteAlpha);
					makeTickTime(Point_A, Point_B, 3);
					
					//Make Tick Time Second
					Point_B.x = Point_A.x+r_second*cos(secAlpha);
					Point_B.y= Point_A.y+r_second*sin(secAlpha);
					makeTickTime(Point_A, Point_B, 5);
	
					delay(1000);
					cleardevice();
					second++;
				}
				minute++;
			}
			hour++;
		}
	}
	
	getch();
	return 0;
}


int hour12(int hour){
	return ((hour > 12) ? hour-12 : hour);
}

 
//Absolute
int abs(int n){
	return ((n>0) ? n : (n*(-1)));
}

//Make Line
void line_DDA(int X0, int Y0, int X1, int Y1, int color){
	// calculate dx & dy
	 int dx = X1 - X0;
	 int dy = Y1 - Y0;
	 
	 // calculate steps required for generating pixels
	 int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	 
	 // calculate increment in x & y for each steps
	 float Xinc = dx / (float) steps;
	 float Yinc = dy / (float) steps;
	 
	 // Put pixel for each step
	 float X = X0;
	 float Y = Y0;
	 
	 for (int i = 0; i <= steps; i++)
	 {
		 putpixel (X,Y,color); // put pixel at (X,Y)
		 X += Xinc; // increment in x at each step
		 Y += Yinc; // increment in y at each step
		 // generation step by step
	 }
}

void makeTickTime(point Point_A, point Point_B, int color){
	// calculate dx & dy
	 int dx = Point_B.x - Point_A.x;
	 int dy = Point_B.y - Point_A.y;
	 
	 // calculate steps required for generating pixels
	 int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	 
	 // calculate increment in x & y for each steps
	 float Xinc = dx / (float) steps;
	 float Yinc = dy / (float) steps;
	 
	 // Put pixel for each step
	 float X = Point_A.x;
	 float Y = Point_A.y;
	 
	 for (int i = 0; i <= steps; i++)
	 {
		 putpixel (X,Y,color); // put pixel at (X,Y)
		 X += Xinc; // increment in x at each step
		 Y += Yinc; // increment in y at each step
		 // generation step by step
	 }
}

void bresenham(int x1, int y1, int x2, int y2){
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		printf("(%d,%d)\n",x,y);
		putpixel(x,y,GREEN);
		delay(50);
		// Add slope to increment angle formed
		slope_error_new += m_new;
		// Slope error reached limit, time to
		// increment y and update slope error.
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}

void M2Point(int x1, int y1, int x2, int y2){
	//Initial State
	int dy, dx;
	float d, x, y;
	
	dy = y2-y1;
	dx = x2-x1;
	
	d=dy-(dy/2);
	printf("%f",d);
	x=x1;
	y=y1;
	
	//Menyimpan titik awal
	putpixel(x,y,YELLOW);
	
	while(x<x2){
		x = x+1;
		if(d<0){
			d=d+dy;
		}else{
			d=d+dy-dx;
			y=y+1;
		}
		putpixel(x,y,YELLOW);
		printf("(%f,%f)\n",x,y);
		delay(50);
	}
}

//Make Cirle
void makeCircle(int x, int y,int r){
	int i;
	float a,b;
	for(i=0;i<=360;i++){
		a=r*cos(i*(M_PI/180));
		b=r*sin(i*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
	}
}


void drawClock(int Px, int Py, int r) {
	int x, y,index;
	makeCircle(Px, Py, r);
		
	x = Px+r*cos(-90+(1*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(1*360)/12*(M_PI/180));
	outtextxy(x, y, "12");
	
	x = Px+r*cos(-90+(2*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(2*360)/12*(M_PI/180));
	outtextxy(x, y, "1");
	
	x = Px+r*cos(-90+(3*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(3*360)/12*(M_PI/180));
	outtextxy(x, y, "2");
	
	x = Px+r*cos(-90+(4*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(4*360)/12*(M_PI/180));
	outtextxy(x, y, "3");
	
	x = Px+r*cos(-90+(5*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(5*360)/12*(M_PI/180));
	outtextxy(x, y, "4");
	
	x = Px+r*cos(-90+(6*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(6*360)/12*(M_PI/180));
	outtextxy(x, y, "5");
	
	x = Px+r*cos(-90+(7*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(7*360)/12*(M_PI/180));
	outtextxy(x, y, "6");
	
	x = Px+r*cos(-90+(8*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(8*360)/12*(M_PI/180));
	outtextxy(x, y, "7");
	
	x = Px+r*cos(-90+(9*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(9*360)/12*(M_PI/180));
	outtextxy(x, y, "8");
	
	x = Px+r*cos(-90+(10*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(10*360)/12*(M_PI/180));
	outtextxy(x, y, "9");
	
	x = Px+r*cos(-90+(11*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(11*360)/12*(M_PI/180));
	outtextxy(x, y, "10");
	
	x = Px+r*cos(-90+(12*360)/12*(M_PI/180));
	y = Py+r*sin(-90+(12*360)/12*(M_PI/180));
	outtextxy(x, y, "11");
	
	
}

void makeCircle2(int x, int y, int r){
	int i,j;
	int a,b;
	for(i=0; i<=90 ; i++){
			a = r*cos(i*(M_PI/180)) ;
			b = r*sin(i*(M_PI/180)) ;
			putpixel(x+a,y+b,YELLOW);
			
			a = r*cos((i+90)*(M_PI/180)) ;
			b = r*sin((i+90)*(M_PI/180)) ;
			putpixel(x+a,y+b,GREEN);
			
			a = r*cos((i+180)*(M_PI/180)) ;
			b = r*sin((i+180)*(M_PI/180)) ;
			putpixel(x+a,y+b,BLUE);
	
			a = r*cos((i+270)*(M_PI/180)) ;
			b = r*sin((i+270)*(M_PI/180)) ;
			putpixel(x+a,y+b,WHITE);
	
			delay(50);
	}
}

void makeCircle3(int x, int y, int r){
	int i,j;
	int a,b;
	for(j=0;j<=45;j++){
		a = r*cos(j*(M_PI/180)) ;
		b = r*sin(j*(M_PI/180)) ;
		putpixel(x+a,y+b,WHITE);
		putpixel(x+b,y+a,YELLOW);
		
		a = r*cos((j+90)*(M_PI/180)) ;
		b = r*sin((j+90)*(M_PI/180)) ;
		putpixel(x+a,y+b,LIGHTGRAY);
		putpixel(x+b,y+a,GREEN);
		
		a = r*cos((j+180)*(M_PI/180)) ;
		b = r*sin((j+180)*(M_PI/180)) ;
		putpixel(x+a,y+b,LIGHTGREEN);
		putpixel(x+b,y+a,YELLOW);
		
		a = r*cos((j+270)*(M_PI/180)) ;
		b = r*sin((j+270)*(M_PI/180)) ;
		putpixel(x+a,y+b,BLUE);
		putpixel(x+b,y+a,LIGHTRED);
		delay(50);
	}
}

//Make Ellipse
void makeElipse(int x, int y, int r1, int r2){
	int i;
	float a,b;
	for(i=0;i<=360;i++){
		a=r1*cos(i*(M_PI/180));
		b=r2*sin(i*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
	}
}

void makeElipse2(int x, int y, int r1, int r2){
	int i;
	float a,b;
	for(i=0;i<=90;i++){
		a=r1*cos(i*(M_PI/180));
		b=r2*sin(i*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
		
		a=r1*cos((i+90)*(M_PI/180));
		b=r2*sin((i+90)*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
		
		a=r1*cos((i+180)*(M_PI/180));
		b=r2*sin((i+180)*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
		
		a=r1*cos((i+270)*(M_PI/180));
		b=r2*sin((i+270)*(M_PI/180));
		putpixel(x+a,y+b,WHITE);
	}	
}

float setMatrix1(int degree, int x, int y, int z){
	
}

