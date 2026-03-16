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

Matrix translation(Matrix x, int tx, int ty){
	Matrix t = {{ {1, 0, tx}, {0 ,1, ty}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

int main(){
	Matrix m1 = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
	Matrix result = translation(m1, 5, 4);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d", result.data[i][j]);
		}
	}
}
