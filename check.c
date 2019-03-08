#include <stdio.h>
#include "files.h"

int check(knapsack *items){

	int flag = 0, j;
	int i = (CAP%items[0].weight);
	if(i == 0) return 1;

	for(j = 0; j < ITEMS-1; j++){
		if(i == items[j].weight){
			flag = 1;
			break;
		}
	}

	if(flag == 1){
		int sum = items[0].value + items[j].value;
		for(j = 1; j<ITEMS-1;j++){
			if(sum < (2*items[j].value))
				return 0;
		}
	return 1;
	}
}

