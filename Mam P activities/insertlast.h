#ifndef INSERTLAST_H
#define INSERTLAST_H

#include "back.h"
#include "back.c"

void insertLast(List* a, int elem){

	List* trav;

	for(trav = a, *trav != NULL; trav = &(*trav)->next){}

	List temp = (List) malloc (sizeof( node ));

	temp->data = elem;
	temp->next = NULL;

	*trav = temp;

}

#endif
