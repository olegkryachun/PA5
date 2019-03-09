#include <stdio.h>
#include "files.h"

int capSmallest(int cap, knapsack *items){

	int i;
	//Check if the capacity, if there is a weight in the list equal to or greater than the current capcity then return 0
	for(i=0; i < ITEMS-1; i++){
		if(cap >= items[i].weight)
			return 0;
	}

//if current cap is smaller then the rest of weights then return 1 to notify that no more things can be added
	return 1;
}
