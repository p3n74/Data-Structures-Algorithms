/************************************************************************
 * Prim's Algorithm : It grows a spanning tree, one edge at a time.     *
 * Given:                                                               *
 *   1)  Graph G = (V, E)                                               *
 *   2)  V = {0, 1, 2, 3, 4}                                            *
 *                                                                      *
 * Steps of Prim's Algorithm:                                        *
 *   1) Initialize set U to contain { 0 }                               *
 *      //In the program, starting vertex will be inputted by the user  *
 *   2) While (U != V)                                                  *
 *       a) Find the minimum cost edge (u, v) such that                 *
 *          u is an element  U and   v is not yet in U                  *
 *       b)  Add v to U                                                 *
 ************************************************************************/
 
#include <unistd.h>    // for sleep(), to add in code if display leaves blank screen  
#include <stdio.h> 
#include <string.h>   

                 
#define MAX  6              // Number of vertices in the graph  
#define INFINITY  0XFFFF    
   
/***** Data Structure Definition *****/  
typedef int graphType[MAX][MAX];    // A[x][y] = INFINITY  if there is not edge ;  A[x][y] = weight of the edge (x,y)
typedef int set[MAX];               // Bit-vector implementation of Set

typedef struct {
	int u, v;     // (u,v) represents the edge  
	int weight;   // weight of the edge
}edgetype;

typedef struct {
    edgetype edges[MAX];
    int edgeCount;   //actual number of edges
	int minCost;	 //Cost of the MST
}primMST;


/***** Function Prototypes *****/

void populateGraph(graphType G);
primMST primAlgo(graphType graph, int startVertex);
void displayPrimMST(primMST tree);
void getStartVertex(int* a);

void displayMatrix(graphType a);

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

	getStartVertex(&startvertex);
	
	primMST p = primAlgo(G, startvertex);
	displayPrimMST(p);
 	
    return 0; 
} 

/************************************************************
 * Function Definitions                                     *
 ************************************************************/
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

 

primMST primAlgo(graphType graph, int startVertex)
{
	 //Write code here

	primMST p = {.edgeCount = 0, .minCost = 0};
	set visited = {};
	visited[startVertex] = 1;

	int i, j;

	while(p.edgeCount < MAX - 1){
		
		edgetype minEdge = {.weight = INFINITY};

		for(i = 0; i < MAX; i++){
			if(visited[i] == 1){
			
				for(j = 0; j < MAX; j++){
					if(visited[j] == 0 && graph[i][j] < minEdge.weight){
						edgetype temp = {i, j, graph[i][j]};
						minEdge = temp;
					}
				}
			}
		}

		p.minCost += minEdge.weight;
		
		if(minEdge.weight != INFINITY){
			p.edges[p.edgeCount++] = minEdge;
			visited[minEdge.v] = 1;
		} else {
			printf("Graph is not connected");
		}

	
	}






	return p;
}

void displayPrimMST(primMST T)
{
	int x;
		
	printf("\n%5s%5s", "Edge", "Cost");
 
    //Write code here
	int i;
	for(i = 0; i < T.edgeCount; i++){
		printf("\n%5d,%d %5d", T.edges[i].u, T.edges[i].v, T.edges[i].weight);
	}
}





