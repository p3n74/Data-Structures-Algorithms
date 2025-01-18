#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "back.h"



int main(){
	srand(time(NULL));
	root tree;

	tree = NULL;
	initRoot(&tree);
	treeArray* initData = createArray();
	printArray(*initData);
	sortArray(initData);
	printArray(*initData);

	treefy(initData, &tree);

	int treeDepth = findDepth(tree);
	printf("Tree Depth = %d\n", treeDepth); 
	printTree(tree);


}
