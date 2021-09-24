#include<stdio.h> 
#include<stdlib.h> 

//PUSH and POP

#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

struct stack
{
    int item[STACKSIZE]; 
    int top;
};

void init(struct stack*);
void push(struct stack*,int x); 
int pop(struct stack*);
int empty(struct stack*); 
int stacktop(struct stack s);



void main()
{
    struct stack s; 
    int c,x;
    char ch; 
    system("cls");

start:
    printf("1. Initialisation of stack\n"); 
    printf("2. Insertion in the stack\n"); 
    printf("3. Removal from the stack\n");
    printf("4. Displaying the top Element of the stack\n"); 
    printf("5. exit\n"); 
    printf("===========================\n");
    printf("Enter your choice\t"); 
    scanf("%d",&c);
 
switch(c)
{
    case 1: init(&s); 
            break;
    case 2: printf("\nEnter the element to be inserted"); 
            scanf("%d",&x);
            push(&s,x); 
            break;

    case 3: x=pop(&s);
        printf("\nRemoved item is:=> \t%d",x); 
        break;

    case 4: x=stacktop(s);
        printf("\nStacktop item is:=> \t%d",x); 
        break; 
        
    case 5: exit(1);

    default: printf("\nWrong choice"); 
    break;
    }

    printf("\nDo you wish to continue? (y/n) "); 
    fflush(stdin);
    scanf("%c",&ch); 
    if(ch=='y'||ch=='Y') 
        goto start;

}

void init(struct stack *s)
{
    s->top =-1;
}

int empty(struct stack *s)
{
    if(s->top==-1)
        return TRUE; 
    else
        return FALSE;
}

void push(struct stack *s,int x)
{
    if(s->top==STACKSIZE-1)
    {
        printf("stack overflow"); 
        exit(1);
    }
    s->top++;
    s->item[s->top]=x;
}

int pop(struct stack *s)
{
    int y; 
    if(empty(s))
    {
        printf("Stack Underflows"); 
        exit(1);
    }
    y=s->item[s->top];
    s->top--;
    return(y);
}

int stacktop(struct stack s)
{
    int y; 
    y=s.item[s.top]; 
    return(y);
}
