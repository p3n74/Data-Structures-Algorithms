#ifndef DELETEALL_H
#define DELETEALL_H

#include <time.h>
#include "back.c"
#include "back.h"

void deleteall(List* L, int elem){
	
	List* trav;
	for(trav = L; *trav != NULL;){

		if((*trav)->data == elem){
			List temp = *trav;
			*trav = (*trav)->next;
			free(temp);
		} else {
			trav = &(*trav)->next;
		}

}



#endif	
