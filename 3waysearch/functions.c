#include"functions.h"

// Searches value in the node
//done
nodeType* searchInTree(int dataValue, nodeType* root,	int* pos)
{
	nodeType *ptr;
	if (root == NULL)
		return NULL;
	else{
		if(root->value[0] == dataValue){
			*pos = 0;
			return root;
		}
		else if(root->value[0] > dataValue){
			ptr = searchInTree(dataValue , root->child[0] , pos);
		}
		else if(root->count < MAX){
			ptr = searchInTree(dataValue , root->child[1] , pos);
		}
		else if(root->value[1] == dataValue){
			*pos = 1;
			return root;
		}
		else if(root->value[1] > dataValue){
			ptr = searchInTree(dataValue , root->child[1] , pos);
		}
		else{
			ptr = searchInTree(dataValue , root->child[2] , pos);
		}
	}
}

// Inserts a value in the m-Way tree
//done
nodeType* insert(int dataValue, nodeType* root)
{
	if(root == NULL){
		root = (nodeType*) malloc(sizeof(nodeType));
		root->count = 1;
		root->value[0] = dataValue;
		for(int i = 0 ; i <= MAX ; i++)
			root->child[i] = NULL;
	}
	else{
		if(root->value[0] >= dataValue){
			root->child[0] = insert(dataValue , root->child[0]);
		}
		else if(root->count < MAX){
			root->value[1] = dataValue;
			root->count += 1;
		}
		else if(root->value[1] >= dataValue){
			root->child[1] = insert(dataValue , root->child[1]);
		}
		else{
			root->child[2] = insert(dataValue , root->child[2]);
		}
	}
	return root;
}

// Deletes value from the node
nodeType* deleteNode(int dataValue, nodeType* root)
{
	int *pos;
	if(searchInTree(dataValue , root->child[0] , pos) == NULL){
		return NULL;
	}
	else{
		
	}
}

void enter_to_continue(FILE *in)
{	
	//flush
	int ch;
	do
		ch = fgetc ( in ); 
	while ( ch != EOF && ch != '\n' ); 
	clearerr ( in );
	
	//pause
	printf ( "Press [Enter] to continue: " );
	fflush ( stdout );
	getchar();

	system("clear");
}

void display(nodeType* root)
{
	if(root == NULL)
		return;
	if(root->child[0] != NULL)
		display(root->child[0]);
	printf("\t%d," , root->value[0]);
	
	if(root->child[1] != NULL)
		display(root->child[1]);
	if(root->count == 2)
		printf("\t%d," , root->value[1]);
	
	if(root->child[2] != NULL)
		display(root->child[2]);
}
