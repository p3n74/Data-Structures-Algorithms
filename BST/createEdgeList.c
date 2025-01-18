#include <stdio.h>
#include <stdlib.h>

#include "back.c"
#include "back.h"

#define infinity 9
#define MAX 10

typedef int LabelAdjMat[MAX][MAX];

typedef struct {
	int u;
	int v;
	int weight;
} edgetype;

typedef struct edgenode {

	edgetype n;
	struct edgenode* next;
} *edgeList;

typedef struct {
	edgeList L;
	int cost;
} MST_Kruskal;

void initEdgeList(edgeList* L){
	*L = NULL;
}

void initMat(LabelAdjMat Mat){

	int x,y;
	
	for(x = 0; x < MAX; x++){
		for(y = 0; y < MAX; y++){

			if(y > x){

				if(genRand(3,0) != 0){
					Mat[x][y] = genRand(8,1);
				} else {
					Mat[x][y] = infinity;
				}
			} else {
				Mat[x][y] = infinity;
			}

		}
	}
}

void printMatrix(LabelAdjMat Mat){

	int x,y;

	for(x = 0; x < MAX; x++){
		for(y = 0; y < MAX; y++){
			printf("%d ", Mat[x][y]);
		}
		printf("\n");
	}
}

edgeList createEdgeList(LabelAdjMat Mat){
	
	edgeList result;
	initEdgeList(&result);
	edgeList* trav;
	int x,y;

	for(x = 0; x < MAX; x++){
		for(y = (x + 1); y < MAX; y++){

			if(Mat[x][y] != infinity){

				edgeList temp = (edgeList)malloc(sizeof(struct edgenode));
				temp->next = NULL;
				temp->n.u = x;
				temp->n.v = y;
				temp->n.weight = Mat[x][y];

				for(trav = &result; *trav != NULL; trav = &(*trav)->next){}
				temp->next = *trav;
				*trav = temp;
			}
		}
	}
	return result;
}

void printEdgeList(edgeList L){

	edgeList trav;

	for(trav = L; trav != NULL; trav = trav->next){
		printf("[%d, %d] = %d\n", trav->n.u, trav->n.v, trav->n.weight);
	}
}

int main(){
	srand(time(NULL));
	LabelAdjMat Mat;

	initMat(Mat);
	printMatrix(Mat);
	
	edgeList L = createEdgeList(Mat);
	printEdgeList(L);
	
	return 0;

}
