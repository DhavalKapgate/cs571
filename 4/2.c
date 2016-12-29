#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int index;
    struct Node *next;
}*head,*Ncomphead;
void traverseLL(struct Node *N);
struct Node *splitList(struct Node *input);
int test_prime(int x);

/////////////////////////////////////////////////////////
int main(int argc,char *argv[])
{
	int length,i;
	printf("Enter the length of list\n");
   	scanf("%d",&length);
	while(length<0)
	{
	printf("Enter the valid length of list\n");
        scanf("%d",&length);
	}
    	struct Node *N;	
    	if(length>0)
    	{
        	N=(struct Node *)malloc(sizeof(struct Node));
        	head=(struct Node *)malloc(sizeof(struct Node));
        	N->index=1;
        	N->next=NULL;
        	head=N;
    	}
	for(i=2;i<=length;i++)
   	{
        	N->next=(struct Node *)malloc(sizeof(struct Node));
        	N=N->next;
        	N->index=i;
        	N->next=NULL;
    	}

    	printf("\nThe Linked List:\n");
    	traverseLL(head);

    	struct Node *NPrime,*headPrime;
    	if(length!=0)
    	{
        	NPrime=(struct Node *)malloc(sizeof(struct Node));
       		NPrime->index=head->index;
		NPrime->next=NULL;
		headPrime=NPrime;
    	}

       	NPrime=(struct Node *)splitList(head);
    	printf("\nPrime indexed Node list:\n");
	traverseLL(NPrime);
    	printf("\nComposite List:\n");

	traverseLL(head);
	printf("\n");

	return 0;
}
///////////////////////////////////////////////////////////////////////////
void traverseLL(struct Node *N)
{
	struct Node *Trav;
	Trav=(struct Node *)malloc(sizeof(struct Node));
	Trav=N;
	while(Trav!=NULL && Trav->index!=0)
    	{
        	printf("N%d->",Trav->index);
               	Trav=Trav->next;
	}
		printf("NULL\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////
struct Node *splitList(struct Node *input)
{
    	struct Node *NPrime,*NPrimehead,*Ncomp,*start;
	start=input;				//for bookmarking input LL

	if(input==NULL)				//length=0
		Ncomphead=NULL;

	if(input!=NULL)				//length>0
	{
		if(input->next==NULL)
                	NPrimehead=NULL;
		Ncomp=input;
		Ncomphead=input;
	}
	if(input!=NULL && input->next!=NULL)	//if length is not 0 and 1 respectively
	{
		input=input->next;
		NPrime=input;
    		NPrimehead=NPrime;
	}
	int prime;
   	while(input!=NULL && input->next!=NULL)
    	{
		input=input->next;
        	prime=test_prime(input->index);
        	if(prime==1)
        	{
			NPrime->next=input;
			Ncomp->next=input;
			if(input->next!=NULL)
			NPrime=NPrime->next;
		}
		else
		{
         	        Ncomp->next=input;
			NPrime->next=input;
                        if(input->next!=NULL)
			Ncomp=Ncomp->next;
		}
    	}
	int final_node;
	if(start!=NULL && start->next!=NULL && NPrime->next!=NULL)	//for length 0 and 1 and above 2
	{
		final_node=test_prime(NPrime->next->index);
		printf("\n%d",NPrime->next->index);
		if(final_node==0)NPrime->next=NULL;
		else Ncomp->next=NULL;
    	}
	else if(start!=NULL && start->next!=NULL && NPrime->next==NULL)	//for length=2
                 Ncomp->next=NULL;
	if(NPrimehead!=NULL)
	return NPrimehead;
	else
	return NULL;
}
/////////////////////////////////////////////////////
int test_prime(int no)
{
    int prime=0;
    int count=2;
    if(no!=1)
        while(no%count!=0&&count!=no)
            count++;
    if(count!=no)
        prime=0;
    else
        prime=1;
    return prime;
}

