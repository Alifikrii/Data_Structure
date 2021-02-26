#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};

typedef struct node* NODEPTR; 
NODEPTR list=NULL;

/* Function Prototyping */
NODEPTR getnode(void);
void freenode(NODEPTR);
void insbeg(int);
void insafter(int,int);
void insend(int);
void inserttOK(int,int);
void cetak_ganjil();
int delbeg();
int delafter(int);
int delend();
int delbeforend();
int countAll();
void traverse();

/*Main Function*/


int main()
{
	NODEPTR p;

	int x,c,y,pos;
	 
	char ch;

	begin:
	printf("1. Insert in the beginning\n"); 
	printf("2. Insert after a node\n"); 
	printf("3. Insert in the end\n");
	printf("4. Delete from the beginning\n"); 
	printf("5. Delete after a node\n"); 
	printf("6. Delete from the end\n"); 
	printf("7. Traverse\n");
	printf("8. Insert at position\n");
	printf("9. Traverse odds\n");
	printf("10. Delete before end\n");
	printf("11. Count all nodes\n");
	printf("0. exit\n"); 
	printf("===========================\n");
	printf("Enter your choice\t"); 
	scanf("%d",&c);

	switch(c)
	{
		case 1:  printf("\nEnter the element to be inserted: "); 
			scanf("%d",&x);
			printf("%d\n",x);
			insbeg(x); 
			break;

		case 2:  printf("\nEnter the element to be inserted after which node: "); 
			scanf("%d",&y);
			printf("\nEnter the element to be inserted: "); 
			scanf("%d",&x);
			insafter(y,x); 
			break;

		case 3: printf("\nEnter the element to be inserted: "); 
			scanf("%d",&x);
			insend(x); 
			break;

		case 4: printf("The deleted item is:=> %d\n",delbeg()); 
			break;

		case 5: printf("\nEnter the element to be deleted after which node: "); 
			scanf("%d",&y);
			printf("The deleted item is:=> %d\n",delafter(y)); break; 

		case 6:  printf("The deleted item is:=> %d\n",delend()); break;

		case 7:  traverse(); break; 

		case 8: printf("\nEnter the position to be inserted: ");
			scanf("%d",&pos);
			printf("\nEnter the element to be inserted: ");
			scanf("%d",&x);
			inserttOK(pos,x);
			break;

		case 9: cetak_ganjil(); break;

		case 10: printf("The deleted item is:=> %d\n",delbeforend()); break;

		case 11:  printf("Sum of nodes is: %d\n", countAll()); break;

		case 0:  exit(1);


		default: printf("\nWrong choice"); break;
	}

	printf("Do you wish to continue? (y/n): "); 
	fflush(stdin);
	scanf(" %c",&ch);
	getchar();
	printf("%c\n",ch);
	if(ch=='y'||ch=='Y') 
		goto begin;
}

/*********************************************/ 
NODEPTR getnode(void)
{
	NODEPTR p;
	p=(NODEPTR)malloc(sizeof(struct node)); 
	return p;
}

/*********************************************/     
void freenode(NODEPTR p)
{
	free(p);
}

/*********************************************/     
void traverse()
{
	NODEPTR p=list; printf("\nThe Linked List is\n"); 
	while(p!=NULL)
		{
			printf("%d\t",p->info); 
			p=p->next;
		}
	printf("\n");
}
/*********************************************/     
void insafter(int y,int x)
{
	NODEPTR p,q;
	q=getnode(); q->info=x;
	for(p=list;p->info!=y&&p!=NULL;p=p->next)
	;
	q->next=p->next; 
	p->next=q;
}
 

/*********************************************/
void insbeg(int x)
{
	NODEPTR p;
	p=getnode();
	p->info=x;
	p->next=list; 
	list=p;
}

/*********************************************/
void insend(int x)
{
	NODEPTR p=list,q; 
	q=getnode();
	q->info=x;
	q->next=NULL; 
	while(p->next!=NULL) 
		p=p->next;
	p->next=q;
}

/*********************************************/
int delbeg()
{
	NODEPTR p;
	int x; 
	p=list;
	list=p->next; 
	x=p->info; 
	freenode(p); 
	return x;
}

/*********************************************/
int delafter(int y)
{
	NODEPTR p=list,q; 
	int x;
	for(p=list;p->info!=y&&p!=NULL;p=p->next)
	;
	q = p->next;
	p -> next = q -> next; 
	x = q->info; 
	freenode(q); 
	return x;
}
/*********************************************/
int delend()
{
	NODEPTR p=list,q=NULL;
	int x;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL; 
	x=p->info; 
	freenode(p);
	q->next=NULL; 
	return x;
}


int countAll()
{
	int count = 0;
	NODEPTR p = list;
	while(p != NULL){
		count++;
		p = p -> next;
	}
	return count;
}

void inserttOK(int pos, int x)
{
	int size = countAll(list);
	NODEPTR p,temp;
	p = list; //head
	int counter = 2;
	if(pos < 1 || pos > size + 1) printf("Invalid Position!\n");
	else{
		while(p != NULL){
			if(counter == pos){
				temp = getnode(); temp -> info = x;
				temp -> next = p -> next;
				p -> next = temp;
			}
			counter++;
			p = p -> next;
		}
	}

}

void cetak_ganjil(){
	NODEPTR p=list; printf("\nThe Odd Element Linked List is\n"); 
	while(p!=NULL)
		{
			if((p -> info) %2 != 0) printf("%d\t",p->info); 
			p=p->next;
		}
	printf("\n");
}

int delbeforend(){
	int x;
	NODEPTR p = list,q,r;

	if(p == NULL || p -> next == NULL) return -1;

	while(p != NULL){
		//1 2 3 4
		if(p -> next -> next -> next == NULL){
			q = p -> next -> next; // q = 4
			x = p -> next -> info;
			p -> next = q; //1 2 4
			q = NULL;
			break;
		}
		p = p -> next;
	}
	freenode(q);
	return x;
}