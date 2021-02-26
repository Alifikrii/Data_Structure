#include <stdio.h>
#include <stdlib.h>

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
int delbeg();
int delafter(int); 
int delend(); 
void traverse();
void inserttoK(int,int); /* JAWABAN NOMOR 1*/
void cetak_ganjil(); /* JAWABAN NOMOR 2 */

/*Main Function*/ 
void main()
{
    NODEPTR p;

    int x,c,y;
    
    char ch;

    begin:
        printf("1. Insert in the beginning\n"); 
        printf("2. Insert after a node\n"); 
        printf("3. Insert in the end\n");
        printf("4. Delete from the beginning\n"); 
        printf("5. Delete after a node\n"); 
        printf("6. Delete from the end\n"); 
        printf("7. Traverse\n");
        printf("8. Insert to specific position\n");
        printf("9. Traverse odd\n");
        printf("10. exit\n"); 
        printf("===========================\n");
        printf("Enter your choice\t"); 
        scanf("%d",&c);

    switch(c)
    {
        case 1:  
            printf("\nEnter the element to be inserted"); 
            scanf("%d",&x);
            insbeg(x); 
            break;

        case 2:  
            printf("\nEnter the element to be inserted after which node"); 
            scanf("%d",&y);
            printf("\nEnter the element to be inserted"); 
            scanf("%d",&x);
            insafter(y,x); 
            break;

        case 3: 
            printf("\nEnter the element to be inserted"); 
            scanf("%d",&x);
            insend(x); 
            break;

        case 4: 
            printf("The deleted item is:=> %d",delbeg()); 
            break;

        case 5: 
            printf("\nEnter the element to be inserted after which node"); 
            scanf("%d",&y);
            printf("The deleted item is:=> %d",delafter(y)); 
            break; 
        
        case 6:  
            printf("The deleted item is:=> %d",delend()); 
            break;

        case 7:  
            traverse(); 
            break; 
            
        case 8: 
            printf("\nEnter which position you want to insert the element "); 
            scanf("%d",&y);
            printf("\nEnter the element to be inserted "); 
            scanf("%d",&x);
            inserttoK(y,x); 
            break; 
        case 9:
            cetak_ganjil();
            break;

        case 10:  
            exit(1);

        default: printf("\nWrong choice"); 
        break;
    }

    printf(" Do you wish to continue? (y/n)"); 
    fflush(stdin);
    scanf("%c",&ch);
    
    if(ch=='y'||ch=='Y') 
        goto begin;
}

/*****/ 
NODEPTR getnode(void)
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node)); 
    return p;
}

/*****/ 
void freenode(NODEPTR p)
{
    free(p);
}

/*****/     
void traverse()
{
    NODEPTR p=list; 
    printf("\nThe Linked List is\n"); 
    while(p!=NULL)
    {
        printf("\t%d",p->info); 
        p=p->next;
    }
}


/*****/     
void insafter(int y,int x)
{
    NODEPTR p,q;
    q=getnode(); 
    q->info=x;
    for(p=list;p->info!=y&&p!=NULL;p=p->next);
    q->next=p->next; 
    p->next=q;
}

/*****/
void insbeg(int x)
{
    NODEPTR p;
    p=getnode(); 
    p->info=x;
    p->next=list; 
    list=p;
}

/*****/
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

/*****/
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

/*****/
int delafter(int y)
{
    NODEPTR p=list,q; 
    int x;
    for(p=list;p->info!=y&&p!=NULL;p=p->next);
    q=p->next;
    p->next=q->next;
    x=q->info;
    freenode(q);
    return x;
}

/*****/
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


/*SOAL 1. memasukkan elemen pada list ke-K*/
void inserttoK(int y,int x)
{
    NODEPTR p=list, q, r;
    int i;
    r=getnode(); 
    r->info=x;
    for(i=2 ;i<y;i++)
        {p = p->next;}
    r->next=p->next; 
    p->next=r;
}
 
 /*SOAL 2. memprint elemen yang berisi nilai ganjil*/
void cetak_ganjil()
{
    NODEPTR p=list; 
    int i;
    printf("\nThe Linked List is\n"); 
 /*SOAL 2. memprint elemen yang berisi nilai ganjil*/
void cetak_ganjil()
{
    NODEPTR p=list; 
    int i;
    printf("\nThe Linked List is\n"); 
    
    while(p!=NULL)
    {
        i= p -> info;
        if(i%2!=0)
        {printf("\t%d",p->info); }
        p=p->next;
    }
}
    
    while(p!=NULL)
    {
        i= p -> info;
        if(i%2!=0)
        {printf("\t%d",p->info); }
        p=p->next;
    }
}