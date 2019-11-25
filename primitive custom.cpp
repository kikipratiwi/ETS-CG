#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#define ROUND(a) ((int) (a+0.5))

#include <stdio.h>

#include <time.h>


void ellipseMidPoint (int xCenterenter,int yCenterenter, int Rx,int Ry, int x1, int y1);
void ellipsePlotPoints(int xCenterenter, int yCenterenter, int x, int y, int x1, int y1);
void translasiTitik(int x, int y, int x1, int y1);
void bungaEllipse(int xCenterenter, int yCenterenter, int x, int y, int x1, int y1);
void lineDDA (int xa, int ya, int xb, int yb);
void bujurSangkar(int xa, int ya, int jarak);
void translasiBSangkar(int xa, int ya, int jarak);
void bungaBSangkar(int xa, int ya, int jarak);
void fungsiRandom(int x, int y);


POINT pointRotation(int xpusat, int ypusat, int x, int y, int deg);

int main( )
{
    int x , y;
    int rx, ry, x1, y1, xCenterenter, yCenterenter;
    
    printf("Masukan Height = ");
    scanf("%d", &y);
    printf("Masukan Width = ");
    scanf("%d", &x);
    initwindow(x, y, "PRAKTIKUM KOMPUTER GRAFIK 171511023");
    
    
    printf("Masukan koordinat x dan koordinat y = ");
    scanf("%d", &rx);
    scanf("%d", &ry);
    putpixel(rx, ry, WHITE);
    
    
    POINT aksen = pointRotation(rx, ry, int x, int y, int deg)
    
    //2
//    printf("Masukan koordinat x dan koordinat y = ");
//    scanf("%d", &rx);
//    scanf("%d", &ry);
//    printf("Masukan x translasi dan y translasi  ");
//    scanf("%d", &x1);
//    scanf("%d", &y1);
//    translasiTitik(rx, ry, x1, y1);
//    getch();
//    cleardevice();
//
//    //3        
    printf("Masukan Titik Tengah = ");
    scanf("%d", &xCenterenter);
    scanf("%d", &yCenterenter);
    printf("Masukan x dan y = ");
    scanf("%d", &rx);
    scanf("%d", &ry);
    ellipseMidPoint(xCenterenter, yCenterenter, rx, ry, 0, 0);
    getch();
    cleardevice();
//    
//    //4
//    printf("Masukan x dan y = ");
//    scanf("%d", &rx);
//    scanf("%d", &ry);
//    printf("Masukan x translasi dan y translasi ");
//    scanf("%d", &x1);
//    scanf("%d", &y1);
//    ellipseMidPoint(xCenterenter, yCenterenter, rx, ry, x1, y1);
//    getch();
//    cleardevice();
//    
//    //5
//    printf("Masukan titik x , titik y, dan jarak = ");
//    scanf("%d", &rx);
//    scanf("%d", &ry);
//    scanf("%d", &x1);
//    bujurSangkar(rx, ry, x1);
//    
//    getch();
//    cleardevice();
    
    //6
//    printf("Masukan Titik Tengah = ");
//    scanf("%d", &xCenterenter);
//    scanf("%d", &yCenterenter);
//    printf("Masukan x dan y = ");
//    scanf("%d", &rx);
//    scanf("%d", &ry);
//    bungaEllipse(xCenterenter,yCenterenter, rx, ry, 0, 0);
//    getch();
//    cleardevice();
    
    //7
    printf("Masukan titik x , titik y, dan jarak = ");
    scanf("%d", &rx);
    scanf("%d", &ry);
    scanf("%d", &x1);
    bungaBSangkar(rx, ry, x1);
    
    getch();
    cleardevice();        
    
    //8
    fungsiRandom(x, y);

    
    getch();
    return 0;
}    


POINT pointRotation(int xpusat, int ypusat, int x, int y, int deg){
     int xaksen , yaksen; 
     POINT aksen;
     
     int xtrans, ytrans;
     double val = PI / 180.0;
     //tranlasi awal
     xtrans = x + (-1 * xpusat);
     ytrans = y + (-1 * ypusat);
     //cari aksen
     xaksen = xtrans * cos(val * deg) - ytrans * sin(val * deg);
     yaksen = ytrans * cos(val * deg) + xtrans * sin(val * deg);
     //tranlasi akhir  
     xaksen = xaksen + (xpusat);
     yaksen = yaksen + (ypusat);
     printf("%d %d\n", xaksen, yaksen);
     
     aksen.x = xaksen;
     aksen.y = yaksen;
     
     return aksen; 
}


void translasiTitik(int x, int y, int x1, int y1){
     putpixel(x, y ,1);
     putpixel(x+x1, y+y1 ,2);
}

void ellipseMidPoint (int xCenterenter,int yCenterenter, int Rx,int Ry, int x1, int y1){
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
    ellipsePlotPoints(xCenterenter,yCenterenter,x,y, x1,y1);
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
            ellipsePlotPoints (xCenterenter,yCenterenter,x,y, x1, y1);
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
            ellipsePlotPoints (xCenterenter,yCenterenter,x,y,x1, y1);

        }
    }
    
    void ellipsePlotPoints(int xCenterenter, int yCenterenter, int x, int y, int x1, int y1){
         
        putpixel(xCenterenter + x, yCenterenter + y,1);
        putpixel(xCenterenter - x, yCenterenter + y,1);
        putpixel(xCenterenter + x, yCenterenter - y,1);
        putpixel(xCenterenter - x, yCenterenter - y,1);
        
        putpixel(xCenterenter + x +x1, yCenterenter + y + y1,2);
        putpixel(xCenterenter - x +x1, yCenterenter + y +y1,2);
        putpixel(xCenterenter + x +x1, yCenterenter - y+y1,2);
        putpixel(xCenterenter - x +x1, yCenterenter - y+y1,2);
    }
    
    void bungaEllipse(int xCenterenter, int yCenterenter, int x, int y, int x1, int y1){
         if(x > y){
              ellipseMidPoint(xCenterenter,yCenterenter, x,y, x*2, 0);
              ellipseMidPoint(xCenterenter+x, yCenterenter-x, y,x, 0, (x*2));
         }
         else{
              ellipseMidPoint(xCenterenter,yCenterenter, x,y, 0, y*2);
              ellipseMidPoint(xCenterenter-y, yCenterenter+y, y,x, y*2, 0);
         }
    }
    
    void lineDDA (int xa, int ya, int xb, int yb){
         int dx = xb - xa, dy = yb - ya, steps, k;
         float xIncrement, yIncrement, x = xa, y = ya;
         
         bool isHorizontal = (abs(dx) > abs(dy)) ? true : false;
         
         if (abs (dx) > abs  (dy) ) steps = abs (dx);
         else steps = abs (dy);
         
         xIncrement = dx / (float) steps;
         yIncrement = dy / (float) steps;
         
         putpixel (ROUND (x), ROUND(y) , WHITE) ;
         
         for (k=0; k<steps; k++) {
             x += xIncrement;
             y += yIncrement;
             
             putpixel (ROUND (x), ROUND(y) , WHITE) ;
             if(isHorizontal)
               putpixel (ROUND (x), ya+dx , WHITE) ;                 
             else
               putpixel (xa+dy, ROUND(y) , WHITE) ;        
         }
     }
     
     void bujurSangkar(int xa, int ya, int jarak){
        lineDDA (xa, ya, xa+jarak, ya);
        lineDDA (xa, ya, xa, ya+jarak);
     }
     
     void translasiBSangkar(int xa, int ya, int jarak){
          bujurSangkar(xa, ya, jarak);
          bujurSangkar(xa+jarak, ya+jarak, jarak);
     }
     
     void bungaBSangkar(int xa, int ya, int jarak){
          translasiBSangkar(xa, ya, jarak);
          translasiBSangkar(xa+jarak, ya-jarak, jarak);
     }
     
     void fungsiRandom(int x, int y){
          srand(time(0));
          for(int i=0;i<20;i++){
             bungaBSangkar(rand()%x, rand()%x, rand()%50);
             bungaEllipse(rand()%500 ,rand()%500, rand()%30, rand()%30, 0, 0);  
          }
     }
