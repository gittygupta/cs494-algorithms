# include <stdio.h>

void main(){
	int n;		// number of jobs
	int i, j, temp, count = 0;
	
	// Inputs
	printf("Enter number of events : ");
	scanf("%d", &n);
	int s[n], f[n], index[n], schedule[n], schedule_start[n], schedule_end[n];		// start, finish time, index, schedule
	printf("Enter start and finish times : \n");
	for(i = 0; i < n; i++)
		scanf("%d %d", &s[i], &f[i]);
	
	// Index
	for(i = 0; i < n; i++)
		index[i] = i;
		
	// Data display
	/*
	for(i = 0; i < n; i++)
		printf("%d \t %d \t %d \n", index[i], s[i], f[i]);
	*/
	
	// Sorting by non decreasing order of finish time
	for(i = 0; i < n-1; i++){
		for(j = 0; j < (n - i - 1); j++){
			if(f[j] > f[j + 1]){
				temp = f[j];
				f[j] = f[j + 1];
				f[j + 1] = temp;
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
				temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
		}
	}
	
	// Sort display
	/*
	for(i = 0; i < n; i++)
		printf("%d\t%d\t%d\n", index[i], s[i], f[i]);
	*/
	
	// Scheduling
	/*
	for(i = 0; i < n; i++){
		schedule[i] = -1;
		schedule_start[i] = -1;
		schedule_end[i] = -1;
	}
	*/
	schedule[0] = index[0];
	schedule_start[0] = s[0];
	schedule_end[0] = f[0];
	count++;
	//printf("%d\t%d\t%d\n", schedule[i], schedule_start[i], schedule_end[i]);
	for(i = 1; i < n; i++){
		if (schedule_end[count - 1] < s[i]){
			schedule_start[count] = s[i];
			schedule_end[count] = f[i];
			schedule[count] = index[i];
			count++;
		}
	}
	
	// Display schedule
	//printf("\nCount : %d\n", count);
	printf("Schedule : ");
	for(i = 0; i < count; i++)
		printf("%d  ", schedule[i] + 1);
}
