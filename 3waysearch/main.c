
#include"functions.h"

void main()
{
	system("clear");
	char ch;
	int value;
	nodeType *root = NULL;
	do
	{
		system("clear");
		char c;
		printf("\n\n\n\tEnter your choice\n\t\t1 -> Insert\n\t\t2 -> Search\n\t\t3 -> Delete\n\t\t4 -> Exit\n\t");
		scanf(" %c" , &ch);
		
		switch(ch)
		{
			case '1':
				printf("\n\n\tEnter the value to be inserted\n\t\t");
				scanf("%d" , &value);
				root = insert(value , root);
				printf("\n\n\nTree elements now are:\n");
				display(root);
				break;
				
			case '2':
				if(root == NULL)
					printf("\n\n\tTree is empty\n");
				else
				{
					printf("\n\n\tEnter the value to be searched\n\t\t");
					scanf("%d" , &value);
					int position , res;
					if(searchInTree(value , root , &position) != NULL)
						printf("\n\n\t%d is present\n" , value);
					else
						printf("\n\n\t%d not present\n" , value);
				}
				break;
				
			case '3':
				if(root == NULL)
					printf("\n\n\tTree is empty already\n");
				else
				{
					printf("\n\n\tEnter the value to be deleted\n\t\t");
					scanf("%d" , &value);
					nodeType *tempRoot = deleteNode(value , root);
					if(tempRoot == NULL)
						printf("\n\n\t%d is not present\n" , value);
					else{
						root = tempRoot;
						printf("\n\n\nTree elements now are:\n");
					}
					display(root);
				}
				break;
				
			case '4':
				printf("\n\n\tThe program is being terminated!\n");
				break;
				
			default:
				printf("\n\n\tInvalid Input!! Please re-enter\n");
				sleep(2);
		}
		printf("\n\n");
		enter_to_continue(stdin);
		
	}while(ch != '4');
}
