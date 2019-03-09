#include <stdio.h>
#include "files.h"


void sums(int *counts, int *form){

//copy form to counts
	for(int i=0; i<=ITEMS ; i++)
	  counts[i] = form[i] + counts[i];

}


