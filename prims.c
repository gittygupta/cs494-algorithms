# include <stdio.h>
# define MAX 999

void main() {
	int a, b, u, v, n, i, j, min, mincost = 0, num_edge = 1;
	int visited[MAX] = { 0 };
	int weight[MAX][MAX];

	printf("Enter the number of nodes : ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix : \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &weight[i][j]);
			if (weight[i][j] == 0) {
				weight[i][j] = MAX;
			}
		}
	}

	visited[1] = 1;
	printf("\n");
	while (num_edge < n) {
		min = MAX;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (weight[i][j] < min) {
					if (visited[i] != 0) {
						min = weight[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
		}
		if ((visited[u] == 0) || (visited[v] == 0)) {
			printf("\n Edge %d : (%d %d), weight : %d", num_edge++, a + 1, b + 1, min);
			mincost += min;
			visited[b] = 1;
		}
		weight[a][b] = weight[b][a] = MAX;
	}

	printf("\n Minimum Cost = %d", mincost);
}