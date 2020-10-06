#include<stdio.h>
int a[20][20], q[20], visited[20], f = 0, r = -1;

void bfs(int v, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (a[v][i] && !visited[i]) {
			q[++r] = i;
		}
	}
	if (f <= r) {
		visited[q[f]] = 1;
		bfs(q[f++], n);
	}
}

void main() {
	int source, n, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		q[i] = 0;
		visited[i] = 0;
	}

	printf("Enter adjacency matrix : \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter the starting vertex : ");
	scanf("%d", &source);
	bfs(source, n);
	printf("The node which are reachable are : \n");

	for (i = 0; i < n; i++) {
		if (visited[i]) {
			printf("%d\t", i + 1);
		}
		else {
			printf("\nBfs is not possible. Not all nodes are reachable");
			break;
		}
	}
}