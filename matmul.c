# include <stdio.h>
# include <stdlib.h>

void mul(int a[2][3], int b[3][2], int r1, int c1, int r2, int c2){
	if (c1 != r2){
		printf("Cannot multiply");
		return;
	}
	int c[30][30];
	int sum = 0;
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			for (int k = 0; k < r2; k++){
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
			sum = 0;
		}
	}
	//A
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c1; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//B
	for (int i = 0; i < r2; i++){
		for (int j = 0; j < c2; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

void mul1(int** a, int** b, int r1, int c1, int r2, int c2){
	if (c1 != r2){
		printf("Cannot multiply");
		return;
	}
	int c[30][30];
	int sum = 0;
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			for (int k = 0; k < r2; k++){
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
			sum = 0;
		}
	}
	//A
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c1; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//B
	for (int i = 0; i < r2; i++){
		for (int j = 0; j < c2; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}


void main(){
	int a[][3] = {{1, 2, 3}, {4, 5, 6}}, b[][2] = {{1, 2}, {3, 4}, {5, 6}};
	mul1(a, b, 2, 3, 3, 2);
	
}
