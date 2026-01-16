#include <graphics.h>
#include <math.h>
#include <stdio.h>

// DDA Algorithm Implementation
void drawLineDDA(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float step;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);

    float x_inc = dx / step;
    float y_inc = dy / step;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= step; i++) {
        putpixel((int)round(x), (int)round(y), WHITE);
        
        x = x + x_inc;
        y = y + y_inc;
    }
}

int main() {
    initwindow(900, 600);

    int x1 = 100, y1 = 100;
    int x2 = 600, y2 = 500;

    drawLineDDA(x1, y1, x2, y2);
    
    outtextxy(x1, y1 - 20, "Start");
    outtextxy(x2, y2 + 20, "End");

    getch();
    closegraph();
    
    return 0;
}