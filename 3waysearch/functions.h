#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 2
#define MIN 1

typedef struct node {
	int count;
	int value[MAX];
	struct node* child[MAX + 1];
}nodeType;

nodeType* searchInTree(int val, nodeType* root,	int* pos);

nodeType* insert(int val, nodeType* root);

nodeType* deleteNode(int val, nodeType* root);

void enter_to_continue(FILE *in);

void display(nodeType* root);
