#include <stdio.h>
#include "files.h"

extern Save store;
int zeroFlag = 0;

result maxVal(int cap, knapsack *items) {

//Initialize a best struct and set the value to zero
  result best;
  best.value = 0;

//if the max value for the current weight exists
  if(store[cap].flag != 0){
    sums(best.counts,store[cap].form);	//Copy the number of items it took to get the max value of the current weight
    best.value = store[cap].value;  //set the best.value to the max value of the current weight
    return(best);
  }

//Check if the current weight is smaller than the rest of the weight (can't add any more items)
  if(capSmallest(cap,items)){
	//if so then we have reached the end of this current recursion so return zero array and zero value
    for(int j=0; j < ITEMS; j++)
      best.counts[j] = 0;
		if(check(items) == 1)		//check if the current max is the best max
      zeroFlag = 1;		//if so set zeroFlag and crawl out of recurrsion to the finish
      return (best);
  }

//traverse through each item on the list
  for(int i=0 ; i< ITEMS-1; i++) {
    if(cap >= items[i].weight) {	//if the item can fit
      result temp = maxVal((cap - items[i].weight), items);		//get the maximum value of the left over weight
      if((items[i].value + temp.value) > best.value) {	//if the max value is better than the already stored max value then update best max
        best = temp;
        best.value += items[i].value;
        best.counts[i]++;
      }
      if(zeroFlag == 1)		//if zero flag is set the keep crawling out of the recursion
        return(best);
    }
  }

		//otherwise store the best values into the global max array of best values
      store[cap].value = best.value;
      store[cap].flag = 1;
      sums(store[cap].form, best.counts);
  return(best);
}

