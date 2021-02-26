struct SinglyLinkedListNode 
  {
        int data;
        SinglyLinkedListNode* next;
  };

    SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    int i = 0;
    SinglyLinkedListNode *temp1, *pcurr, *prev;
    temp1 = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    prev = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    if(position == 0&&head!=NULL)
    {
        temp1->data = data;
        temp1->next = head;     //new node's next will point to head and new node will become the new head
        head = temp1;          //since the insertion is made at start, new node(temp1) will becomes the new head.
        return head;
    }
    else if(head == NULL)      //if linked list is empty
    {
        temp1->data = data;    
        temp1->next = NULL;
        head = temp1;         //just set the new node as head of linked list and return the head node
        return head; 
    }
    else
    {
        int i=0;         //for iterating to the required position
        temp->data = data;

        //store 2 nodes, one node which will store prev node and another to store current node. The temp node will go between these 
        prev = head,pcurr = head->next; 
        while(i != position-1 && pcurr != NULL){  //traverse the linked list till you reached the insertion position
            i++;
            prev = pcurr;
            pcurr = pcurr->next;
        }
        if(i != position-1){
            return head;     //can't insert at the specified position
        }
        prev->next = temp;   //point the node preceding the insertion position to new node to be inserted
        temp->next = pcurr; //point the new node to the next node to maintain the linked list
        return head;
    }  
}
