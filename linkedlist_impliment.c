/*
*  c program to impliment linked list ,(insertion,deletion at front and dispaly)
*  author:prashant satyal
* reference: Data structure and algorithm (pearson),class
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int info;
	struct node *next;
	};
typedef struct node *nodeptr;
nodeptr getnode();
void insertatfront(nodeptr*,int);
int removefromfront(nodeptr*);
void freenode(nodeptr);
void displaylist(nodeptr);

int main()
{
	nodeptr p;
	p=NULL;
	insertatfront(&p,111);
	insertatfront(&p,222);
	insertatfront(&p,333); //comment out these 3 for underflow check
	displaylist(p);
	printf("\n now printing after removing \n");
	removefromfront(&p);//removes 333
	removefromfront(&p);//removes 222
	displaylist(p);
	
}

nodeptr getnode()
{
return(nodeptr)malloc(sizeof(nodeptr));
}
void freenode(nodeptr p)
{
	free(p);
}
void insertatfront(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}
void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
}

int removefromfront(nodeptr*p)
{
	int x;
	if(*p==NULL)
	{
		printf("list underflow!\n");
		exit (0);
	}
	else
	{
		nodeptr ptr;
		ptr=*p;
		*p=ptr->next;
		x=ptr->info;
		free(ptr);
		return x;
		
	}
}

