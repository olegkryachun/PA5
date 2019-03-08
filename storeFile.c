#include <stdio.h>
#include "files.h"


void storeFile(knapsack *data){

	FILE *fp;
	char string[128];
	int i = 0;
	fp = fopen("knapsack.data","r");

	while(NULL != fgets(string,128,fp)){
		sscanf(string,"%d %d %s",&(data[i].weight),&(data[i].value), &(data[i].name));
		i++;
	}

	ITEMS = i;

	for(int j = 0; j < ITEMS - 1; j++ ) {

		for(i=0; i< ITEMS-j-1 ; i++){
			float v = (float) data[i].value/(float) data[i].weight;
			float v1 = (float) data[i+1].value/ (float) data[i+1].weight;

			if(v < v1){
				knapsack temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
			}
		}
	}
}

