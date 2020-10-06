# include <stdio.h>

// non decreasing weights

void main(){
	int i, j, n;
	printf("Enter number of objects : ");
	scanf("%d", &n);
	float w[n], p[n], temp, temp1, amount, w_list[n], p_list[n], v_list[n], new_vector;
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
	/*
	printf("Weights : ");
	for (i = 0; i < n; i++)
		printf("%f ", w[i]);
	printf("\nPrices : ");
	for (i = 0; i < n; i++)
		printf("%f ", p[i]);
	*/
	// Sorting weights and arranging prices
	
	for(i = 0; i < n-1; i++){
		for(j = 0; j < (n - i - 1); j++){
			if(w[j] > w[j + 1]){
				temp = w[j];
				temp1 = p[j];
				w[j] = w[j + 1];
				p[j] = p[j + 1];
				w[j + 1] = temp;
				p[j + 1] = temp1;
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
	}
	
	// fraction checking
	if (amount != 0.0){
		new_vector = amount / w[object_count];
		w_list[object_count] = w[object_count];
		p_list[object_count] = p[object_count] * new_vector;
		v_list[object_count] = new_vector;
		object_count += 1;
	}
	
	float total_price = 0.0;
	printf("weights and prices and vectors : \n");
	for (i = 0; i < object_count; i++){
		printf("weight : %f and profit : %f and vector : %f \n", w_list[i], p_list[i], v_list[i]);
		total_price += p_list[i];
	}
	
	printf("\n\nTotal price : %f", total_price);
	printf("\n\nSolution Vector : ");
	for (i = 0; i < object_count; i++){
		printf("%f \n", v_list[i]);
		total_price += p_list[i];
	}
}
