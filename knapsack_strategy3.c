# include <stdio.h>

// non increasing profit/weight ratio

void main(){
	int i, j, n;
	printf("Enter number of objects : ");
	scanf("%d", &n);
	float w[n], p[n], temp, temp1, amount, w_list[n], p_list[n], v_list[n], new_vector, ratio[n], r_list[n], temp2;
	printf("Enter the weights : ");
	for(i = 0; i < n; i++){
		scanf("%f", &w[i]);
	}
	printf("Enter prices : ");
	for(i = 0; i < n; i++){
		scanf("%f", &p[i]);
	}
	printf("Enter capacity of sack : ");
	scanf("%f", &amount);
	
	// Ratio array
	for(i = 0; i < n; i++){
		ratio[i] = p[i] / w[i];
	}
	
	/*
	printf("Weights : ");
	for (i = 0; i < n; i++)
		printf("%f ", w[i]);
	printf("\nPrices : ");
	for (i = 0; i < n; i++)
		printf("%f ", p[i]);
	*/
	
	// Sorting ratio
	for(i = 0; i < n-1; i++){
		for(j = 0; j < (n - i - 1); j++){
			if(ratio[j] < ratio[j + 1]){
				temp = ratio[j];
				temp1 = p[j];
				temp2 = w[j];
				ratio[j] = ratio[j + 1];
				p[j] = p[j + 1];
				w[j] = w[j+1];
				ratio[j + 1] = temp;
				p[j + 1] = temp1;
				w[j + 1] = temp2;
			}
		}
	}
	
	/*
	printf("Sorted Weights : ");
	for (i = 0; i < n; i++)
		printf("%f ", w[i]);
	printf("\nSorted Prices : ");
	for (i = 0; i < n; i++)
		printf("%f ", p[i]);
	*/
	
	// Filling the sack
	int object_count = 0;
	for(i = 0; i < n; i++){
		amount -= w[i];
		object_count += 1;
		if(amount == 0.0){
			w_list[object_count - 1] = w[i];
			p_list[object_count - 1] = p[i];
			r_list[object_count - 1] = ratio[i];
			v_list[object_count - 1] = 1;
			
			break;
		}
		else if(amount < 0.0){
			object_count -= 1;
			amount += w[i];
			continue;
		}
		
		w_list[object_count - 1] = w[i];
		p_list[object_count - 1] = p[i];
		v_list[object_count - 1] = 1;
		r_list[object_count - 1] = ratio[i];
	}
	
	// fraction checking
	if (amount != 0.0){
		new_vector = amount / w[object_count];
		w_list[object_count] = w[object_count];
		p_list[object_count] = p[object_count] * new_vector;
		v_list[object_count] = new_vector;
		r_list[object_count] = ratio[object_count];
		object_count += 1;
	}
	
	float total_price = 0.0;
	printf("weights and prices and vectors and ratios : \n");
	for (i = 0; i < object_count; i++){
		printf("weight : %f and profit : %f and vector : %f and ratio : %f \n", w_list[i], p_list[i], v_list[i], r_list[i]);
		total_price += p_list[i];
	}
	
	printf("\n\nTotal price : %f", total_price);
	printf("\n\nSolution Vector : \n");
	for (i = 0; i < object_count; i++){
		printf("%f \n", v_list[i]);
		total_price += p_list[i];
	}
}
