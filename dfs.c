# include <stdio.h>
# include <stdlib.h>

int visited[20], a[20][20];

void DFS(int i, int n) {
	int j;
	visited[i] = 1;
	printf(" %d\t", i + 1);
	for (j = 0; j < V; j++) {
		if (a[i][j] == 1 && visited[j] == 0)
			DFS(j, n);
	}
}
int main() {
	int i, j, n, source;
	printf("Enter the no of vertices : ");
	scanf("%d", &V);
	printf("Enter adjacency matrix : \n");
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the source : ");
	scanf("%d", &source);
	printf("\nThe vertices that can be reached : \n");
	DFS(source - 1, n);
	return 0;
}