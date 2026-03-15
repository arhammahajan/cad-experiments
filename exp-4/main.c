#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600 
void drawCircleBresenham(int cx, int cy, int r){
	int x = 0;
	int y = r;
	float p = (5/4) - r;
	while(x<=y){	
		putpixel(cx + x, cy + y, WHITE); 
		putpixel(cx + y, cy + x, WHITE);
		putpixel(cx + x, cy - y, WHITE);
		putpixel(cx + y, cy - x, WHITE); 
		putpixel(cx - x, cy - y, WHITE);
		putpixel(cx - y, cy - x, WHITE);
		putpixel(cx - x, cy + y, WHITE);
		putpixel(cx - y, cy + x, WHITE);
		x++;
		if(p < 0){
			p = p + 2*x + 1;
		}
		else {
			y--;
			p = p + 2*x + 1 - 2*y;
		}
			
	}	
}

int main() {
	initwindow(WIDTH, HEIGHT);
	drawCircleBresenham(200, 300, 100);
	getch(); // takes one character input from the keyboard and returns the ascii value without waiting for the return key 
	closegraph();

}
