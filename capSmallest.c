#include <stdio.h>
#include "files.h"

int capSmallest(int cap, knapsack *items){

	int i;
	for(i=0; i < ITEMS-1; i++){
		if(cap >= items[i].weight)
			return 0;
	}

	return 1;
}
