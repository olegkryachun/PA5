#include <stdio.h>
#include "files.h"

extern Save store;
int zeroFlag = 0;

result maxVal(int cap, knapsack *items) {
  result best;
  best.value = 0;


  if(store[cap].flag != 0){
    sums(best.counts,store[cap].form);
    best.value = store[cap].value;
    return(best);
  }

	printf("%d\n",cap);

  if(cap == 0){
    for(int j=0; j < 10; j++)
      best.counts[j] = 0;
		if(check(items) == 1)
      zeroFlag = 1;
      return (best);
  }

  for(int i=0 ; i< ITEMS-1; i++) {
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
      store[cap].value = best.value;
      store[cap].flag = 1;
      sums(store[cap].form, best.counts);
  return(best);
}

