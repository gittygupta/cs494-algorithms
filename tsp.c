# include <stdio.h>
 
int ary[10][10], completed[10], n, cost = 0;
 
void takeInput() {
	int i, j;

	printf("Enter the number of cities : ");
	scanf("%d", &n);

	printf("Enter the Adajacency Matrix\n");

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &ary[i][j]);
		}
		completed[i] = 0;
	}
}

int least(int c) {
	int i, nc = 999;
	int min = 999, kmin;

	for (i = 0; i < n; i++) {
		if ((ary[c][i] != 0) && (completed[i] == 0)) {
			if (ary[c][i] + ary[i][c] < min) {
				min = ary[i][0] + ary[c][i];
				kmin = ary[c][i];
				nc = i;
			}
		}
	}
	if (min != 999) {
		cost += kmin;
	}
	return nc;
}
 
void mincost(int city) {
	int i, ncity;
	completed[city] = 1;
	printf("%d--->", city + 1);
	ncity = least(city);

	if (ncity == 999) {
		ncity = 0;
		printf("%d", ncity + 1);
		cost += ary[city][ncity];

		return;
	}

	mincost(ncity);
}
 
int main()
{
	takeInput();
	printf("The Path is:\n");
	mincost(0); //passing 0 because starting vertex
	printf("Minimum cost is %d\n ",cost);
 
	return 0;
}