#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLOSE_DSIZE 0XF    //size of Close Hash Table
#define SET_SIZE   0XE    //size of the array implementation of Set
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; EMPTY or DELETED   
  	chocoDesc prodDesc;      //  product description 
 	float prodPrice;         //  product price 
  	int prodQty;             //  product count or quantity   
}product;                   //  product record  

typedef struct pSet {
	product prod[SET_SIZE];
	int last;          //index of the last element; -1 if list is empty	
}ProdSet;

/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY   "empty"         // stored in product ID field  
#define DELETED  "deleted"      // stored in product ID field * 
 
typedef product closeDic[CLOSE_DSIZE];   //Definition of the closed hash dictionary
  
/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
ProdSet populateProdSet();

int closeHash(char *ID);     
void initCloseDict(closeDic CD);
closeDic * createCloseDict(ProdSet S);	
void displayCloseDict(closeDic CD);

/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/
 int main( ) 
 {	
 /*------------------------------------------------------------------------------------
 * 	Problem #2  :: 1) Populate the set by calling populateProdSet                  *
 *                   2) Calls createCloseDict()                                     *
 *---------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #2 :: ");
   printf("\n------------");
    
  //Write your code here
	ProdSet set = populateProdSet();
	closeDic* CD = createCloseDict(set);
	displayCloseDict(*CD);


	return 0;
}

/************************************************************
 *  Problem  :: Function Definitions                          *
 ************************************************************/
ProdSet populateProdSet()
{ 
 	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20}, {"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35}, {"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20}, {"1201", {"Kitkat", 50}, 97.75, 40},
						{"1450", {"Ferrero", 100},150.50, 50}, {"1601", {"Meiji", 75}, 75.50, 60},
						{"1310", {"Nestle", 100}, 124.50, 70}, {"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60}, {"1284", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35}, {"1107", {"Valor", 120}, 149.50, 90}
					     };
   int count = sizeof(data)/sizeof(data[0]);
   
   ProdSet Set = {.last = SET_SIZE - 1};
	memcpy(Set.prod, data, sizeof(data[0]) * SET_SIZE);
 	
   return Set;  
}
 
int closeHash(char *ID)
{
    //Write your code here
	int hash = 0; int i;
	for(i = 0; ID[i] != '\0' && ID[i] >= 48 && ID[i] <= 57; i++){
		
		hash += ((ID[i] - 48) * (i + 1));

	}

	hash %= CLOSE_DSIZE;

	return hash;

} 
 
void initCloseDict(closeDic CD)
{
    //Write your code here

	int i;
	for(i = 0; i < CLOSE_DSIZE; i++){
		strcpy(CD[i].prodID, EMPTY);
	}
}


closeDic * createCloseDict(ProdSet L)
{
	// Uncomment these lines and put before a call to displayCloseDict()
      //  printf("\n\n----- Empty Dictionary ------");
      //  printf("\n\n----- Dictionary without the Synonyms ------");
 	   // printf("\n\n----- Dictionary with ALL the Synonyms -----");
 		 
	//Write your code here 
	
	closeDic* CD = (closeDic*) malloc (CLOSE_DSIZE * sizeof(product));
	initCloseDict(*CD);

	int i, hash, y;
	for(i = 0; i < SET_SIZE; i++){
	
		hash = closeHash(L.prod[i].prodID);
		
		for(y = 0; y < CLOSE_DSIZE; y++){
			int x = (y + hash) % CLOSE_DSIZE;
			
			printf("Inserting %s, y = %d, x = %d\n", L.prod[i].prodID, y, x);

			if(strcmp((*CD)[x].prodID, EMPTY) == 0){
				memcpy(&(*CD)[x], &L.prod[i], sizeof(product));
				break;
			}

		}
			

	}
    
	return CD;
}	

void displayCloseDict(closeDic CD)
{
	printf("\n\n%-6s", "Index");
	printf("%-10s", "ChocoID");
	printf("%-15s", "Choco Name");
	printf("%-20s", "Hashvalue");
	printf("\n%-6s%-10s%-15s", "-----", "-------", "----------"); 
	
	//write your code here!!
	
	int i;
	for(i = 0; i < CLOSE_DSIZE; i++){
		printf("\n%-10s", CD[i].prodID);
		printf("%-15s", CD[i].prodDesc.name);
		printf("%-20d", closeHash(CD[i].prodID));
	}
	 
	printf("\n\n"); system("Pause");  //keep this statement
 
}
