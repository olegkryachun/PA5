//Structures

typedef struct{		//General input struct from file
	int weight;
	int value;
	char name[32];
	int item;
}knapsack;

typedef struct{		//maxVal struct for storing best result
	int value;
	int counts[128];
}result;

typedef struct{
	int value;
	int form[128];
	int flag;
}Save[1024];

extern int ITEMS;
extern int CAP;

//Prototypes

result maxVal(int, knapsack *);

void storeFile(knapsack *); 

void init();

void sums(int *,int *);
int check(knapsack *);
int capSmallest(int, knapsack *);
