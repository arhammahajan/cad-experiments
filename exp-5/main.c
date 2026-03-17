#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159265358979323846
typedef struct {
	int data[3][3];
} Matrix;

float degRad (float deg){
	return (deg * PI)/180;
}

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

Matrix printMat(Matrix m1){
	printf("[ ");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", m1.data[i][j]);
		}
		if(i!=2){
			printf("\n  ");
		}
		
	}
	printf(" ]\n");
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
	Matrix t = {{ {1, shx, 0}, {shy, 1, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result; 
}

Matrix reflectionX(Matrix x){
	Matrix t = {{ {1, 0, 0}, {0, -1, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

Matrix reflectionY(Matrix x){
	Matrix t = {{ {-1, 0, 0}, {0, 1, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

Matrix reflectionO(Matrix x){
	Matrix t = {{ {-1, 0, 0}, {0, -1, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

Matrix reflectionYX(Matrix x){
	Matrix t = {{ {0, 1, 0}, {1, 0, 0}, {0, 0, 1} }};
	Matrix result = matMul(t, x);
	return result;
}

Matrix rotationZ(Matrix x, int alph){
	int rad = degRad(alph);
	Matrix r = {{ {cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1} }};
} 

int main(){
	Matrix m1 = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
	Matrix result = scaling(m1, 5, 4);
	printMat(result);
}
