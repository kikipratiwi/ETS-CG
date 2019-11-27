// C Implementation for setfillstyle 
// and floodfill function 
#include <graphics.h> 

// driver code 
int main() 
{ 
	// gm is Graphics mode which is 
	// a computer display mode that 
	// generates image using pixels. 
	// DETECT is a macro defined in 
	// "graphics.h" header file 
	int gd = DETECT, gm; 
	
	// initgraph initializes the 
	// graphics system by loading 
	// a graphics driver from disk 
	
    // location of left, top, right, bottom 
    int left = 150, top = 150; 
    int right = 450, bottom = 450; 
  
    // initgraph initializes the graphics system 
    // by loading a graphics driver from disk 
    initgraph(&gd, &gm, ""); 
  
    

	// center and radius of circle 
	int x_circle = 250; 
	int y_circle = 250; 
	int radius=100; 
	
	// setting border color 
	int border_color = WHITE; 
	
	
	// set color and pattern 
	setfillstyle(SOLID_FILL,WHITE); 
	
	// x and y is a position and 
	// radius is for radius of circle 
//	circle(x_circle,y_circle,radius); 

// rectangle function 
    rectangle(left, top, right, bottom); 
    
	
	// fill the color at location 
	// (x, y) with in border color 
	floodfill(left+1,top+1,border_color); 

	getch(); 
	
	// closegraph function closes the 
	// graphics mode and deallocates 
	// all memory allocated by 
	// graphics system 
	closegraph(); 
	
	return 0; 
} 

