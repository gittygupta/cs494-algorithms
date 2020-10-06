# include <stdio.h>

int N;
int board[100][100];

// check placement
int place(int i, int j) {
	int k, l;
	for (k = 0; k < N; k++) {
		if ((board[i][k] == 1) || (board[k][j] == 1))
			return 1;
	}
	// diagonals
	for (k = 0; k < N; k++) {
		for (l = 0; l < N; l++) {
			if (((k + l) == (i + j)) || ((k - l) == (i - j))) {
				if (board[k][l] == 1)
					return 1;
			}
		}
	}
	return 0;
}

int queen(int n) {
	int i, j;
	if (n == 0)
		return 1;	// found
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if ((!place(i, j)) && (board[i][j] != 1))
			{
				board[i][j] = 1;
				if (queen(n - 1) == 1)
				{
					return 1;
				}
				board[i][j] = 0;
			}
		}
	}
	return 0;
}

int main() {
	printf("Enter number of queens : ");
	scanf("%d", &N);

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	queen(N);

	//printing 
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}

}