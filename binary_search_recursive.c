# include <stdio.h>

int binary_search(int arr[], int u, int l, int x){
	int mid;
	if(u >= l){
		mid = (u + l) / 2;
		if (arr[mid] == x){
			return 1;
		}
		else if (x > arr[mid])
			l = mid + 1;
		else
			u = mid - 1;
		binary_search(arr, u, l, x);
	}
	else
		return -1;
}

int main(){
	int n, x;
	printf("Enter length of array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements of array : ");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter element to search : ");
	scanf("%d", &x);
	int f = binary_search(arr, n, 0, x);
	if (f == 1)
		printf("Found");
	else
		printf("Not Found");
}
