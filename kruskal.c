# include <stdio.h>
# define MAX 999

int cost[MAX][MAX], parent[MAX];

int find(int i) {
	while (parent[i]) {
		i = parent[i];
	}
	return i;
}

int uni(int i, int j) {
	if (i != j) {
		parent[j] = i;
		return 1;
	}
	return 0;
}

void main() {
	int i, j, k, a, b, u, v, n, num_edge = 1, min, mincost = 0;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix : \n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0) {
				cost[i][j] = MAX;
			}
		}
	}

	printf("\n");
	while (num_edge < n) {
		min = MAX;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (cost[i][j] < min) {
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if (uni(u, v)) {
			printf(" edge %d : (%d,%d), weight : %d\n", num_edge++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = MAX;
	}
	printf("Minimum cost : %d\n", mincost);
}