#ifndef DELETEFIRST_H
#define DELETEFIRST_H

#include <time.h>
#include "back.h"
#include "back.c"

void deleteFirst(List* L){
	
	if(L != NULL && *L != NULL){
		*L = (*L)->next;
	}
}

#endif
