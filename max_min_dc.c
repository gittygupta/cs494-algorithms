# include <stdio.h>
# define MAX -999999
# define MIN 999999

void maxmin(int* a, int i, int j, int *max, int *min){
	if (i == j){
		if ((*max) < a[i]){
			(*max) = a[i];
		}
		if ((*min) > a[i]){
			(*min) = a[i];
		}
	}
	else{
		int mid = (i + j) / 2;
		maxmin(a, i, mid, max, min);
		maxmin(a, mid + 1, j, max, min);
	}
}

void main(){
	int a[] = {1, 4, 2, 6, 3, 8}, min = MIN, max = MAX;
	maxmin(a, 0, 5, &max, &min);
	printf("%d, %d", max, min);
}
