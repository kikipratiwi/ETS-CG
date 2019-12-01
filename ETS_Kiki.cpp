#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define ROUND(a) ((int) (a+0.5))
#define PI 3.14159265

void drawPattern(int xCenter, int yCenter, int radiusius, float rotate);
POINT pointRotation(int xCenter, int yCenter, int x, int y, float degree);
void circleMidPoint(int xCenter, int yCenter, int radiusius);
void circlePlotPoints(int xCenter, int yCenter, int x,int y);
void lineDDA (int xa, int ya, int xb, int yb);

float rotate = 0;

int main(){
    int page = 0;
    
    initwindow(500, 500, "UTS KOMPUTER GRAFIK 171511046");
    POINT aksen;
    //scale awal
    int scale = 80;
    int inc_scale = scale;
    POINT x;
    x = pointRotation(800, 700, 500, 250, -90);
    printf("%d %d", x.x, x.y);
    while(1){
       setactivepage(page);
       setvisualpage(1-page);
       cleardevice();
       
       //untuk scale
             inc_scale = scale*sin(0.017444 * rotate * 6);
       drawPattern(200, 200, abs(inc_scale), rotate*10);
       
       //untuk rotasi
             rotate  = rotate + 0.15;
       delay(10);
       page = 1-page;
    }

    getch();
    return 0;
}

void drawPattern(int xCenter, int yCenter, int radiusius, float rotate){
     circleMidPoint(xCenter, yCenter, radius);
     //TRANSLASI titik pusat sebesar x=0 y=radius
     int yCenter2 = yCenter + radius;
//     circleMidPoint(xCenter, yCenter2, radius);
     
     //Gambar lingkaran
     POINT p_center;
     float degree = 0+rotate;
     for(int i=0;i<6;i++){
        p_center = pointRotation(xCenter, yCenter, xCenter, yCenter2, deg);
        circleMidPoint(p_center.x, p_center.y, radius);
        deg += 60;
     }
     
     //Gambar Garis
     //lineDDA (xCenter, yCenter, xCenter, yCenter-(2*radius));
     deg = 0+rotate;
     for(int i=0;i<12;i++){
        p_center = pointRotation(xCenter, yCenter, xCenter, yCenter-(2*radius), deg);
             lineDDA (xCenter, yCenter, p_center.x, p_center.y);
        deg += 30;
     }
     
     
     //Gambar lingkaran besar
     circleMidPoint(xCenter, yCenter, 2*radius);
     circleMidPoint(xCenter, yCenter, (2*radius)-(radius/4));
     
     
    //delay(20) ;   
}

//ROTASI
POINT pointRotation(int xCenter, int yCenter, int x, int y, float degree){
     float xaksen , yaksen; 
     POINT aksen;
     
     float xtrans, ytrans;
     double val = PI / 180.0;
     //tranlasi awal
     xtrans = x - xCenter;
     ytrans = y - yCenter;

     //cari aksen
     xaksen = xtrans * cos(val * deg) - ytrans * sin(val * deg);
     yaksen = ytrans * cos(val * deg) + xtrans * sin(val * deg);
     //tranlasi akhir  
     xaksen = xaksen + (xCenter);
     yaksen = yaksen + (yCenter);
     
     aksen.x = xaksen+0.5;
     aksen.y = yaksen+0.5;
     
     return aksen; 
}

//CIRCLE MIDPOINTS
void circleMidPoint(int xCenter, int yCenter, int radiusius){
	 int x = 0;
	 int y = radius;
	 int p = 1 - radius;
	 circlePlotPoints(xCenter,yCenter,x,y);

	
	while(x<y){
		x++;
		if(p<0){
			p += 2 * x + 1;
		}
		else{
			y--;
			p += 2 * (x - y) + 1;
		}
		circlePlotPoints(xCenter,yCenter,x,y);

		}
}

void circlePlotPoints(int xCenter, int yCenter, int x,int y){
	putpixel ((xCenter + x), (yCenter + y), WHITE);
    putpixel ((xCenter - x), (yCenter + y), WHITE);
    putpixel ((xCenter + x), (yCenter - y), WHITE);
    putpixel ((xCenter - x), (yCenter - y), WHITE);
    putpixel ((xCenter + y), (yCenter + x), WHITE);
	putpixel ((xCenter - y), (yCenter + x), WHITE);
	putpixel ((xCenter + y), (yCenter - x), WHITE);
    putpixel ((xCenter - y), (yCenter - x), WHITE);
}

//LINE DDA
void lineDDA (int xa, int ya, int xb, int yb){
     int dx = xb - xa, dy = yb - ya, steps, k;
     
     float xIncrement, yIncrement, x = xa, y = ya;
     
     if (abs (dx) > abs  (dy) ) steps = abs (dx);
     else steps = abs (dy);
     
     xIncrement = dx / (float) steps;
     yIncrement = dy / (float) steps;
     
     putpixel((x+0.5), (y+0.5),WHITE);
     
     for (k=0; k<steps; k++) {
         x += xIncrement;
         y += yIncrement;
         putpixel((x+0.5), (y+0.5),WHITE);
     }
     
} 


