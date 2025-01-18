#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int data;
	struct node* LC;
	struct node* RC;
} node, *bnode;



bnode makeNode(int data){
	
	bnode temp = (bnode) malloc (sizeof(node));
	temp->data = data;
	temp->RC = NULL;
	temp->LC = NULL;

	return temp;
}


void initTree(bnode* tree, int root){
	
	bnode temp = (bnode)malloc(sizeof(node));
	temp->data = root;
	temp->LC = NULL;
	temp->RC = NULL;
	*tree = temp;

}


void insertSorted(int data, bnode* tree){

	if(!(*tree)){
		*tree = makeNode(data);
	} else if ( data < (*tree)->data) {
		insertSorted(data, &(*tree)->LC);
	} else {
		insertSorted(data, &(*tree)->RC);
	}

}

void inOrder(bnode tree){
	if(tree){
		inOrder(tree->LC);
		printf("%d ", tree->data);
		inOrder(tree->RC);
	}
}

void preOrder(bnode tree){
	if(tree){
		printf("%d ", tree->data);
		preOrder(tree->LC);
		preOrder(tree->RC);
	}
}

void postOrder(bnode tree){
	if(tree){
		postOrder(tree->LC);
		postOrder(tree->RC);
		printf("%d ", tree->data);
	}
}

int main(){
	
	bnode tree;
	initTree(&tree, 5);

	insertSorted(4, &tree);
	insertSorted(6, &tree);
	insertSorted(11, &tree);
	insertSorted(9, &tree);
	insertSorted(1, &tree);
	insertSorted(8, &tree);
	insertSorted(7, &tree);
	insertSorted(2, &tree);
	insertSorted(3, &tree);

	inOrder(tree);
	printf("\n");
	preOrder(tree);
	printf("\n");
	postOrder(tree);

	return 0;
}
