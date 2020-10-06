# include <stdio.h>

int distance[100][100];
void floydWarshall (int n) {
	int i, j, k;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
}
int main() {
	int i, j, n;
	printf("enter no of vertices : ");
	scanf("%d", &n);
	printf("Enter distances, 9999->no connection\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("distance between vertices [%d] and [%d] : ", i, j);
			scanf("%d", &distance[i][j]);
		}
	}
	floydWarshall(n);
	printf (" \nAdjacency Matrix : \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", distance[i][j]);
		}
		printf("\n");
	}
	return 0;
}