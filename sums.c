#include <stdio.h>
#include "files.h"


void sums(int *counts, int *form){

	for(int i=0; i<=10 ; i++)
	  counts[i] = form[i] + counts[i];
}


