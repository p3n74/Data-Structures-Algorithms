#ifndef DIJK_H
#define DIJK_H

#define MAX_CITIES 6

/* 
 * 
 * Data Structure Definitions
 *
 *
 * */

typedef int adjMat[MAX_CITIES][MAX_CITIES];


typedef struct node{
	int destination;
	struct node* next;
} *Node;

// What the fuck was that implementation
//
// IT was a linked list type of implementation of an
// adj matrix
//
// an array of linked lists where I is a 
// vertex then every succeding node in the list
// is a Connect Di-Graph
//



#endif
