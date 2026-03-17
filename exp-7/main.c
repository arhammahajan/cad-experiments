#include <stdio.h>
#include <math.h>
#include <graphics.h>

void bezierCurve(int x[4], int y[4]){
	for(double t = 0.0; t < 1.0; t=t+0.0005){
		double xt = pow((1-t), 3)*x[0] + 3*pow((1-t), 2)*t*x[1] + 3*(1-t)*pow(t, 		2)*x[2] + pow(t, 3)*x[3];
		double yt = pow((1-t), 3)*y[0] + 3*pow((1-t), 2)*t*y[1] + 3*(1-t)*pow(t, 		2)*y[2] + pow(t, 3)*y[3];
		putpixel(xt, yt, WHITE);

	}
}

int main(){
	int x[] = {50, 70, 90, 110};
	int y[] = {100, 150, 125, 115};
	
	initwindow(900, 600, "Bezier Curve");
	bezierCurve(x, y);
	getch();
	closegraph(); 
}
