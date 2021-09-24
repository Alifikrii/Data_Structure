#include<stdio.h>
#include<stdlib.h> 
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

//Enqueue and Dequeue
struct queue
{
    int item[MAXQUEUE]; 
    int front;
    int rear;
};
 
void init(struct queue *pq);
void insert(struct queue *pq,int x); 
int remov(struct queue *pq);
int empty(struct queue *pq);

void main()
{
struct queue q; int x,c;
char ch; system("cls");
init(&q); start:
printf("1. Initialise the queue\n"); 
printf("2. Insert in the queue\n"); 
printf("3. Remove from the queue\n"); 
printf("4. exit\n");
printf("===========================\n");
printf("Enter your choice\t"); 
scanf("%d",&c);

switch(c)
{
case 1: init(&q); break;
case 2:  printf("\nEnter the element to be inserted");
scanf("%d",&x); 
insert(&q,x); 
break;
 
case 3: x=remov(&q);
    break;

case 4:exit(1); 

printf("\nRemoved item is:=> \t%d",x); 
    break;
 
default: printf("\nWrong choice"); 
    break;
}

printf("\nDo you wish to continue? (y/n) "); 
fflush(stdin);
scanf("%c",&ch); 
if(ch=='y'||ch=='Y') 
    goto start;
}

void init(struct queue *pq)
{
    pq->rear=-1; pq->front=0;
}
 
void insert(struct queue *pq,int x)
{
    if(pq->rear==MAXQUEUE-1)
    {
        printf("Queue Overflows"); 
        exit(1);
    }
    pq->rear++;
    pq->item[pq->rear]=x;
}

int remov(struct queue *pq)
{
    int x; 
    if(empty(pq))
    {
        printf("Queue Underflows"); 
        exit(1);
    }
    x=pq->item[pq->front]; 
    pq->front++;
    return x; 
}

int empty(struct queue *pq)
{
    if(pq->rear-pq->front+1==0)
        return TRUE; 
    else
        return FALSE;
}
