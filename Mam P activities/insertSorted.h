#ifndef INSERTSORTED_H
#define INSERTSORTED_H

#include <time.h>
#include "back.h"
#include "back.c"

void insertSorted(List* a, int elem){
	// Insert into an ascending order list
	List* trav;

	for(trav = a; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next){}

	List temp = (List) malloc (sizeof (node) );
	temp->data = elem;
	temp->next = NULL;

	temp->next = *trav;
	*trav = temp;

}

#endif
