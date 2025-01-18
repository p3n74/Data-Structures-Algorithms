#ifndef DELETELAST_H 
#define DELETELAST_H

#include <time.h>
#include "back.h"
#include "back.c"

void deleteLast(List* L){
		if(L != NULL && *L != NULL){

			List* trav;
			for(trav = L; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
			List temp = *trav;
			*trav = NULL;

			free(temp);
the
		}
}

#endif
