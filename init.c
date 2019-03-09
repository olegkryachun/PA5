#include <stdio.h>
#include "files.h"
#include <string.h>

extern Save store;

void init(){

	int i = 0;

//Initialize the global save array to all 0
	for(i = 0; i < 1024; i++){
		store[i].value = 0;
		(store[i]).form[0] = 0;
		store[i].flag = 0;
	}

}

