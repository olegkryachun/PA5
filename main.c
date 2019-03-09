
#include <stdio.h>
#include "files.h"

//GLobal variables to for initial capacity, number of items in the knapsack, and the array where the best values get stored
int CAP;
int ITEMS=0;
Save store;

int main(int argc, char *argv[]){

	int weight;
	result best;
	best.counts[0] = 0;
	knapsack data[128];		//initialize the array for the knapsack list
	init();		//clears the global 'store' array that will store max values

	if(argc == 2 && sscanf(argv[1],"%d",&weight)) {

	//if a negative weight is entered then tell user and exit
	if(weight < 0 ){
			printf("No negatives!!!\n");
			return 0;
		}

		CAP = weight;		//initialize global capacity variable
		storeFile(data);	//read from file and store in knapsack stucture 'data'
 		best = maxVal(weight,data);		//get the maximum value of the given capacity

//Print the items and number of items it took to get the max value for the given capacity
		printf("The best value you can get in your %d bag is:\n", weight);
		for(int i=0 ; i<=ITEMS ; i++) {
			if(best.counts[i] != 0)
				printf(">%s: %d\n", data[i].name, best.counts[i]);
		}
		printf("All with a final value of %d\n", best.value);
	}else
		printf("A number was not detected\n");		//if a number was not entered then notify and exit

	return 0;
}

