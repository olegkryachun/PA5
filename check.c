#include <stdio.h>
#include "files.h"

int check(knapsack *items){

	int flag = 0, j, i, rem;

	for(i=0; i<ITEMS-1; i++){
		if(CAP >= items[i].weight)
			break;
	}

	rem = (CAP%items[i].weight);	//take the initial capcity and check the remainder with the weight of the best value/pound item
	if(rem == 0) return 1;		//if the remainder is zero then the best solution is to fill the bag with only the best value/pound item

//check if there is a matching weight to the remainder that would be added next
	for(j = 0; j < ITEMS-1; j++){
		if(rem == items[j].weight){
			flag = 1;
			break;	//if there is then break out of this loop and set the flag
		}
	}

//we found a matching weight value to the remainder
	if(flag == 1){
		int sum = items[0].value + items[j].value;  //add the value of the best value/pound item to the value of the thing we could potentially grab
		for(j = 1; j<ITEMS-1;j++){
			if(sum < (2*items[j].value))
				return 0;		//if there is a better value with a combination of two of some other items then return 0
		}
	return 1;	//if the combination of the best value/pound value plus the value of the last thing that can fit is better
					 //than any other dual combo of values then return 1
	}
}

