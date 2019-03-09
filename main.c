/*
Creators: Oleg Kryachun & Nate Kirsh
Date: March 8 2019
Programming Assignment 5
CSE 222
Things We Did Together: We spend several hours brainstorming and piecing the program together, the way the alorithm would would and creating an outline.
												This was very helpful as we were able to view the problem from different perspectives and quickly find flaws and strengths in different proposed solutions

Oleg's Role: Read and Store from file, I got the idea to store the array in order from best value/pound to least, I tackled a lot of the little functions,
						 as well as managed to debug the program to get the final working solution

Nate's Role: Put together the initial outline for the Max functions, wrote the max function that almost worked perfectly,
							edited the main program to adjust output formatting, wrote the bubble sort algarithm, created the Makefile

Summary: This program gets a weight value from the user and finds the maximum value possible to store into the sack that can store a maximum of the given weight
					it does recursively. The list of items gets stored in order by best value/pound to least value/pound allowing the program to decide to either go through
					full recursion of if the weight fits a value such that only the number of best value/pound items will create the best value for the weight.
*/

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

