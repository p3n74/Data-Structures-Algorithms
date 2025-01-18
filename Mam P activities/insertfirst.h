#ifndef INSERTFIRST_H
#define INSERTFIRST_H

#include "back.h"
#include "back.c"

void insertFirst(List* a, int elem){

	List temp = (List) malloc (sizeof ( node ) );

	temp->data = elem;
	temp->next = NULL;

	temp->next = *a;
	*a = temp;

}

#endif
