#include <stdio.h>
#include "files.h"

int zeroFlag = 0;

result maxVal(int cap, knapsack *items) {
	result best;
	best.value = 0;

	printf("%d\n",cap);

	if(cap == 0){
		for(int j=0; j < 128; j++)
			best.counts[j] = 0;
		if(check(items) == 1)
			zeroFlag = 1;
			return (best);
	}

	for(int i=0 ; i< ITEMS; i++) {
		if(cap >= items[i].weight) {
			result temp = maxVal((cap - items[i].weight), items);
			if((items[i].value + temp.value) > best.value) {
				best = temp;
				best.value += items[i].value;
				best.counts[i]++;
			}
			if(zeroFlag == 1)
				return(best);
		}
	}
}

