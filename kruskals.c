/************************************************************************
 * Kruskal's Algorithm : It finds a Minimum Spanning Tree (MST)         *
 * by choosing edges in ascending order of weight.                      *
 * Given:                                                               *
 *   1) Graph G = (V, E)                                                *
 *   2) V = {0, 1, 2, 3, 4}                                             *
 *                                                                      *
 * Steps of Kruskal's Algorithm:                                        *
 *   1) Initialize T = ∅                                                *
 *      //T will contain the edges in the MST                           *
 *   2) Sort all edges in E by ascending weight                         *
 *   3) For each edge (u, v) ∈ E in sorted order                        *
 *       a) If adding (u, v) does not form a cycle in T:                *
 *            Add (u, v) to T                                           *
 *            //Use a Union-Find (Disjoint Set) structure to check      *
 *            //whether u and v are in the same connected component.    *
 *   4) Stop when T contains exactly |V| - 1 edges.                     *
 *                                                                      *
 * Output: Minimum Spanning Tree T                                      *
 ************************************************************************/
 
#include <unistd.h>    // for sleep(), to add in code if display leaves blank screen  
#include <stdio.h> 
#include <string.h>   
#include <stdlib.h>
                 
#define MAX  6              // Number of vertices in the graph  
#define INFINITY  0XFFFFa
#define HEAPMAX 20
   
/***** Data Structure Definition *****/  
typedef int graphType[MAX][MAX];    // A[x][y] = INFINITY  if there is not edge ;  A[x][y] = weight of the edge (x,y)
typedef int set[MAX];               // Bit-vector implementation of Set

typedef struct {
	int u, v;     // (u,v) represents the edge  
	int weight;   // weight of the edge
}edgetype;

typedef struct edgeNode {
	edgetype n;
	struct edgeNode* next;
} *edgelist;

typedef struct {
	edgetype heap[HEAPMAX];
	int count;
} minHeap;

typedef struct {
    edgetype edges[MAX];
	int minCost;	 //Cost of the MST
	int count;
}kruskMST;
/***** Heaps Functions     *****/

int parent(int i) {
	return (i - 1) / 2;
}

int leftChild(int i){
	return (i * 2) + 1;
}
int rightChild(int i){
	return (i * 2) + 2;
}

void minHeapify(minHeap* heap, int i){
	int smallest = i;;
	int left = leftChild(i);
	int right = rightChild(i);

	if(left < heap->count && heap->heap[left].weight < heap->heap[smallest].weight){
		smallest = left;
	} 
	if(right < heap->count && heap->heap[right].weight < heap->heap[smallest].weight){
		smallest = right;
	}

	if(smallest != i){
		edgetype temp = heap->heap[i];
		heap->heap[i] = heap->heap[smallest];
		heap->heap[smallest] = temp;
		minHeapify(heap, smallest);
	}
}

void initMinHeap(minHeap* heap, graphType g){

	edgelist l = NULL;
	edgelist* trav;
	int x, y;

	for(x = 0; x < MAX; x++){
		for(y = x + 1; y < MAX; y++){
			if(g[x][y] != INFINITY){
				edgelist temp = (edgelist)malloc(sizeof(struct edgeNode));
				temp->n.u = x;
				temp->n.v = y;
				temp->n.weight = g[x][y];
				
				for(trav = &l; *trav != NULL && g[x][y] > (*trav)->n.weight; trav = &(*trav)->next){}
				temp->next = *trav;
				*trav = temp;
			}
		}
	}

	for(x = 0, trav = &l, heap->count = 0; x < HEAPMAX && *trav != NULL; x++, trav = &(*trav)->next){
		heap->heap[x] = (*trav)->n;
		heap->count++;
	}


}

edgetype deleteMin(minHeap* heap){
	edgetype result = {.weight = INFINITY};

	 if (heap->count <= 0) {
        printf("Heap is empty\n");
    } else {
        result = heap->heap[0];
        heap->heap[0] = heap->heap[heap->count - 1];
        heap->count--;  // Decrement count before calling minHeapify
        minHeapify(heap, 0);
    }

	return result;
}




/***** Function Prototypes *****/

void populateGraph(graphType G);
kruskMST kruskAlgo(minHeap* heap);
void displayKruskMST(kruskMST tree);
void getStartVertex(int* a);

void displayMatrix(graphType a);
void printHeap(minHeap heap);

int main() 
{ 
     /*---------------------------------------------------------------------------------
    * 	Problem #2 ::  a) Allows user to input from keyboard the starting vertex      *
    *                  b) Calls populateGraph() to populate the given graph           *
    *                  c) Calls primAlgo() and displayPrimMST()                       *
    *                                                                                 *
    * printf("\n\n\nProblem #2:: ");                                                  *  
    * printf("\n------------");                                                       *
    *---------------------------------------------------------------------------------*/
 	printf("\n\n\nProblem #2:: "); 
	printf("\n------------"); 
	int startvertex;
	
	graphType G;
	populateGraph(G);
	displayMatrix(G);

	minHeap heap;

	initMinHeap(&heap, G);
	printHeap(heap);

	kruskMST k = kruskAlgo(&heap);
	displayKruskMST(k);

    return 0; 
} 

/************************************************************
 * Function Definitions                                     *
 ************************************************************/
void printHeap(minHeap heap){

	int i;
	for(i = 0; i < heap.count; i++){
		printf("\n%d, %d = %d", heap.heap[i].u, heap.heap[i].v, heap.heap[i].weight);
	}
}

void displayMatrix(graphType a){
	int x, y;
	printf("\n");
	for(x = 0; x < MAX; x++){
		for(y = 0; y < MAX; y++){
			if(a[x][y] == INFINITY){
				printf("~ ");
			} else {
				printf("%d ", a[x][y]);
			}
		} printf("\n");
	}
}

void getStartVertex(int *a){
	printf("Enter Starting Vertex: ");
	scanf("%d", a);
}

void populateGraph(graphType G)
{
	graphType graph = {  INFINITY, 1, 5, 4, 6, 5, 1, INFINITY, 5, INFINITY, INFINITY, 6, 5, 5, INFINITY, 2, INFINITY, INFINITY, 4,
                             INFINITY, 2, INFINITY, 1, INFINITY, 6, INFINITY,INFINITY, 1, INFINITY, 3, 5, 6, INFINITY, INFINITY, 3, INFINITY} ;   //5

	memcpy(G, graph, sizeof(graph));
}

 

kruskMST kruskAlgo(minHeap* heap)
{
	 
	kruskMST k = {.minCost = 0, .count = 0};

	int comp[6];
	
	int i;
	for(i = 0; i < MAX; i++){
		comp[i] = i;
	}

	while(heap->count > 0){
		edgetype min = deleteMin(heap);
		
		if(comp[min.u] != comp[min.v]){
			int change = comp[min.u];

			for(int i = 0; i < MAX; i++){

				if(comp[i] == change){
					comp[i] = comp[min.v];
				}
			}
			
			k.edges[k.count++] = min;
			k.minCost += min.weight;


		}
	}
	
	return k;

}

void displayKruskMST(kruskMST T)
{
	int x;
		
	printf("\n%5s%5s", "Edge", "Cost");
 
    //Write code here
	int i;
	for(i = 0; i < T.count; i++){
		printf("\n%5d,%d %5d", T.edges[i].u, T.edges[i].v, T.edges[i].weight);
	}

	printf("\nCost: %d", T.minCost);
}





