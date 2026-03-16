#include <stdio.h>
#include <graphics.h>
#include <math.h>

typedef struct {
	int data[3][3];
} Matrix;

Matrix  matMul(Matrix m1, Matrix m2){
	Matrix result = {{{0,0,0}, {0,0,0}, {0,0,0}}};
	for(int i = 0; i<3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				result.data[i][j] = result.data[i][j] + m1.data[i][k]*m2.data[k][j];
			}
		}
	}
	return result;
}
Matrix initMat(Matrix m1, int c){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			m1.data[i][j] = c;
		}	
	}
}


Matrix translation(Matrix x, int tx, int ty){
	Matrix t = {{ {1, 0, tx}, {0 ,1, ty}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

Matrix scaling(Matrix x, int sx, int sy){
	Matrix t = {{ {sx, 0, 0}, {0, sy, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	
	return result;
}

Matrix shearing(Matrix x, int shx, int shy){
	Matrix t = {{ {1, Shx, 0}, {Shy, 1, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result; 
}


int main(){
	Matrix m1 = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
	Matrix result = scaling(m1, 5, 4);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d", result.data[i][j]);
		}
	}
}
