#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; 
  	chocoDesc prodDesc;      //  product description 
 	float prodPrice;         //  product price 
  	int prodQty;             //  product count or quantity   
}product;                   //  product record  

typedef struct pnode {
	product prod; 
	struct pnode *plink;          
}*ProdList;                //Linked List implementation 


 
/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
ProdList populateProdList();
void displayProdList(ProdList L);
void makeListToSet(ProdList L);
 
 
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
 /*----------------------------------------------------------------------------------
 * 	Problem #1 :: 1) Populates the list by calling populateProdList()            *
 *                  2) Displays the product list                                   * 
 *                  3) Calls makeListToSet(), then displayProdList().              *
 *---------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #1:: ");
   printf("\n------------");
   
   //Write your code here
   ProdList L = populateProdList();
   displayProdList(L);

   makeListToSet(L);
   displayProdList(L);
	 
    
 	return 0;
}

int hashFunc(char* name){
	int hash = 0;
	int i;

	for(i = 0; name[i] != '\0'; i++){
		hash = ((name[i]) * (i + 4));
	};
		

	return hash;
}

/************************************************************
 *  Problem1   :: Function Definitions                          *
 ************************************************************/
ProdList populateProdList()
{ 
   int count;
	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20}, {"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35}, {"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20}, {"1201", {"Kitkat", 50}, 97.75, 40},
						{"1201", {"Ferrero", 100},150.50, 50}, {"1701", {"Toblerone", 50}, 90.75, 80},
						{"1701", {"Meiji", 75}, 75.50, 60}, {"1310", {"Nestle", 100}, 124.50, 70},
						{"1807", {"Valor", 120}, 149.50, 90}, {"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60}, {"1688", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35},
					 };
	count = sizeof(data)/sizeof(data[0]);		
			 
	//Write your code here 
	
	// Make it insert sorted
	ProdList list = NULL;
	ProdList* trav; 
	

	int i;

	for(i = 0; i < count; i++){
		
		ProdList temp = (ProdList)malloc(sizeof(struct pnode));
		temp->prod = data[i];
		temp->plink = NULL;
		
		// insert sorted according to the hash of the ID
		
		for(trav = &list; *trav != NULL && hashFunc(data[i].prodDesc.name) < hashFunc((*trav)->prod.prodDesc.name); trav = &(*trav)->plink){};
		temp->plink = *trav;
		*trav = temp;
	}

	return list;


	 
}

void displayProdList(ProdList L)
{
	printf("\n\nDetails of the List :: ");
	printf("\n---------------------");
	printf("\n\n%-7s", "ID");
	printf("%-12s","Choco Name");
	printf("%-15s","Choco Weight");
	printf("\n%-7s%-12s%-15s", "--", "----------", "------------");

   //Write your code here 
   ProdList trav;
   int count = 0;
   for(trav = L; trav != NULL; trav = trav->plink){
	   printf("\n%-7s", trav->prod.prodID);
	   printf("%-12s", trav->prod.prodDesc.name);
	   printf("%-15i", trav->prod.prodDesc.weight);
	   count++;
	}
    
	
	printf("\n\nNo. of elements :: %d", count);   //Complete this line and uncomment
	printf("\n\n"); system("Pause");	       //Keep this statement
}

 
void makeListToSet(ProdList L)
{
	//Write the code of the function a
	
	ProdList* trav;

	for(trav = &L; *trav != NULL && (*trav)->plink != NULL;){
		
		if(hashFunc((*trav)->prod.prodDesc.name) == hashFunc((*trav)->plink->prod.prodDesc.name)){
			
			ProdList temp = *trav;

			(*trav)->plink = (*trav)->plink->plink;
		} else {
			trav = &(*trav)->plink;
		}
	}
	
}
