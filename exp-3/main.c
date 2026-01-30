#include <graphics.h>
#include <math.h>
#include <stdio.h>

void drawLineBresenham(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;

    // for the first quadrant
    putpixel(x1, y1, WHITE);
    int p = 2*dy - dx;
    for(int x = x1+1; x <= x2; x++){
        if (p < 0){
            putpixel(x, y1, WHITE);
            p = p + 2*dy;
        }
        else {
            putpixel(x, ++y1, WHITE);
            p = p + 2*dy - 2*dx;
        }
    }
}

int main() {
    initwindow(900, 600);

    // 0 < m < 1
    int x1 = 100, y1 = 100;
    int x2 = 500, y2 = 300;

    // int x1 = 100, y1 = 300;
    // int x2 = 500, y2 = 100;

    drawLineBresenham(x1, y1, x2, y2);
    
    outtextxy(x1, y1 - 20, "Start");
    outtextxy(x2, y2 + 20, "End");

    getch();
    closegraph();
    
    return 0;
}