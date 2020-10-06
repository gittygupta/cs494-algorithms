# include <stdio.h>

void main(){
	int n;		// number of jobs
	int i, j, temp, max_deadline = -1, profit = 0, previous_deadline = -1, random = -1;
	
	// Inputs
	printf("Enter number of jobs : ");
	scanf("%d", &n);
	int p[n], d[n], index[n];		// profit, deadline, index
	printf("Enter profits and deadlines : \n");
	for(i = 0; i < n; i++)
		scanf("%d %d", &p[i], &d[i]);
	
	// Index
	for(i = 0; i < n; i++)
		index[i] = i;
		
	// Data display
	/*
	for(i = 0; i < n; i++)
		printf("%d \t %d \t %d \n", index[i], p[i], d[i]);
	*/
	
	// Sorting by non increasing order of profit
	for(i = 0; i < n-1; i++){
		for(j = 0; j < (n - i - 1); j++){
			if(p[j] < p[j + 1]){
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
				temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
		}
		if(d[i] > max_deadline){
				max_deadline = d[i];
		}
	}
	if(d[n - 1] > max_deadline)
		max_deadline = d[n - 1];
	
	// Sort display
	/*for(i = 0; i < n; i++)
		printf("%d\t%d\t%d\n", index[i], p[i], d[i]);
	*/
	//printf("%d", max_deadline);
	
	int job[max_deadline], job_deadline[max_deadline];
	for(i = 0; i < max_deadline; i++)
		job_deadline[i] = -1;
	
	
	// Sequencing
	/*
	job[0] = index[0];
	job_deadline[0] = d[0];
	profit += p[0];
	for(i = 0; i < max_deadline; i++){
		if(job_deadline[i] != -1){
			continue;
		}
		if (job_deadline[i-1] <= d[i]){
			job_deadline[i] =d[i];
			job[i] = index[i];
			profit += p[i];
		}
		else if (job_deadline[i-1] > d[i]){
		random = max_deadline - 1;
			while(random != (i - 1)){
				job_deadline[random] = job_deadline[random-1];
				job[random] = job[random-1];
				/*job_deadline[i-1] = d[i];
				job_deadline = index[i]*/
				/*random--;
			}
			job_deadline[i - 1] = d[i];
			job[i - 1] = index[i];
			profit += p[i];
		}
		else if (job_deadline[i] == -1){
			job_deadline[i] = d[i];
			job[i] = index[i];
			profit += p[i];
		}
	}
	*/
	
	
	
	// Sequencing
	// Hash table method
	for (i = 0; i < n; i++){
		if(job_deadline[d[i] - 1] == -1){
			job_deadline[d[i] - 1] = d[i];
			job[d[i] - 1] = index[i];
			//profit += p[i];
		}
		else{
			random = d[i] - 1;
			while(random >= 0){
				random--;
				if(job_deadline[random] == -1){
					job_deadline[random] = d[i];
					job[random] = index[i];
					break;
				}
			}
			//profit += p[i];
		}
	}
	
	
	// Display
	printf("Jobs : ");
	//printf("%d", max_deadline);
	for(i = 0; i < max_deadline; i++)
		printf("%d  ", job[i] + 1);
	
	// Profit calculation
	for(i = 0; i < max_deadline; i++)
		profit += p[job[i]];
		
	printf("\nNet Profit : %d", profit);
}
