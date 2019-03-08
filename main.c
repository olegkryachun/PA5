
#include <stdio.h>
#include "files.h"

int CAP;
int ITEMS=0;
Save store;

int main(int argc, char *argv[]){

	int weight;
	result best;
	best.counts[0] = 0;
	knapsack data[128];
	init();

	if(argc == 2 && sscanf(argv[1],"%d",&weight)) {
		if(weight < 0 ){
			printf("No negatives!!!\n");
			return 0;
		}
		CAP = weight;
		storeFile(data);
 		best = maxVal(weight,data);
		printf("The best value you can get in your %d bag is:\n", weight);
		for(int i=0 ; i<=ITEMS ; i++) {
			if(best.counts[i] != 0)
				printf(">%s: %d\n", data[i].name, best.counts[i]);
		}
		printf("All with a final value of %d\n", best.value);
	}else
		printf("A number was not detected\n");

	return 0;
}

