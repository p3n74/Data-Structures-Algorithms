#include <stdio.h>
#include <stdlib.h>

#include "healper.h"
#include "back.h"
#include "back.c"

#define infi 999



void givenAdjMat(labelAdjMat Mat) {
    Mat[0][0] = 0;    Mat[0][1] = 1;    Mat[0][2] = 5;    Mat[0][3] = 4;    Mat[0][4] = 6;    Mat[0][5] = 5;
    Mat[1][0] = 1;    Mat[1][1] = 0;    Mat[1][2] = 5;    Mat[1][3] = infi; Mat[1][4] = infi; Mat[1][5] = 6;
    Mat[2][0] = 5;    Mat[2][1] = 5;    Mat[2][2] = 0;    Mat[2][3] = 2;    Mat[2][4] = infi; Mat[2][5] = infi;
    Mat[3][0] = 4;    Mat[3][1] = infi; Mat[3][2] = 2;    Mat[3][3] = 0;    Mat[3][4] = 1;    Mat[3][5] = infi;
    Mat[4][0] = 6;    Mat[4][1] = infi; Mat[4][2] = infi; Mat[4][3] = infi; Mat[4][4] = 0;    Mat[4][5] = 3;
    Mat[5][0] = 5;    Mat[5][1] = 6;    Mat[5][2] = infi; Mat[5][3] = infi; Mat[5][4] = 3;    Mat[5][5] = 0;
}

edgeList createEdgeList(labelAdjMat Mat){
	
	edgeList result;
	result = NULL;

	edgeList* trav;
	int x,y;
	for(x = 0; x < MAX_SMALL; x++){
		for(y = x + 1; y < MAX_SMALL; y++){

			if(Mat[x][y] != infi && Mat[x][y] != 0){
				
				edgeList temp = (edgeList)malloc(sizeof (struct edgeNode));
				temp->n.u = x; temp->n.v = y; temp->n.weight = Mat[x][y];
				
				for(trav = &result; *trav != NULL && (*trav)->n.weight < Mat[x][y]; trav = &(*trav)->next){}
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

void createMinHeap(edgeList L, MinHeap* heap){

	edgeList trav;
	heap->size = 0;

	for(trav = L; trav != NULL; trav = trav->next){

		insert(heap, trav->n);	

	}

}

void printMinHeap(MinHeap* heap){

	int i;

	printf("\nX :");
	for(i = 0; i < heap->size; i++){

		printf("%d ", heap->edges[i].u);

	}
	printf("\nY :");
	for(i = 0; i < heap->size; i++){

		printf("%d ", heap->edges[i].v);

	}
	printf("\nW :");
	for(i = 0; i < heap->size; i++){

		printf("%d ", heap->edges[i].weight);

	}
}

void printEdgeData(edgetype e){

	printf("\n\n X : %d", e.u);
	printf("\n Y : %d", e.v);
	printf("\n W : %d\n", e.weight);
}



int main(){

	labelAdjMat Mat;
	givenAdjMat(Mat);
	
	edgeList L = createEdgeList(Mat);
	printEdgeList(L);

	MinHeap heap;
	createMinHeap(L, &heap);
	printMinHeap(&heap);

	minHeapify(&heap, 0);
	printMinHeap(&heap);

	edgetype deleted1 = deleteMin(&heap);
	edgetype deleted2 = deleteMin(&heap);

	printEdgeData(deleted1);
	printEdgeData(deleted2);

	printMinHeap(&heap);



}
