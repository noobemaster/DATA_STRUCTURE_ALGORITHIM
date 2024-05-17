#include<stdio.h>
#include<stdlib.h>
int Choice,Exit;
void Arrays() {
    int MJ[] = {1,3,5,7,8,11,30},y =4, x =7,i,j,m=0,k=8;
    printf("\tThe original array is :\n\tMJ={");
    for(i = 0; i<x; i++) {printf("%d, ",MJ[i]);}
     //delition operation
    j = y;
    while(j<x) {MJ[j-1] = MJ[j];++j ;}
    --x ;
    printf("}\n\n\tThe array elements after deletion :\n\tMJ={");
    for(i = 0; i<x; i++) printf("%d, ", MJ[i]);
    //insertion
    j=x++;
    while(j>=y) {MJ[j+1] = MJ[j];--j;}
    MJ[y]=9;
    printf("}\n\n\tThe array elements after insertion:\n\tMJ={");
    for(i = 0; i<x; i++) printf("%d ,",MJ[i]);
    //searching
    while(m<x){if(MJ[m]==k)break;++m;}
    printf("}\n\n\tThe value %d was found on MJ[%d]\n",k,m);
    //updating
    while(m<x){if(MJ[m]==k){MJ[m]=687;break;}m+=1;}
    printf("\n\tupdating MJ[%d] to %d\n\tMJ={",m,MJ[m]);
    for(i = 0; i<x; i++) {printf("%d ,",MJ[i]);}
    printf("}\n\n");
}
//simple linked list
struct simple_linked{
    int data;
    struct simple_linked *link ;
};struct simple_linked *head=NULL;
void show_list(){
    struct simple_linked *temp=head;
    int len=0;
    while (temp!=NULL){len++;temp=temp->link;}
    temp=head;
    printf("\tYou have %d items on your list\n",len);
    printf("\tYour list is {");
    while (temp!=NULL){
        printf(" %d,",temp->data);
        temp=temp->link;
    }
    printf("}\n");
}
void push_item(){
    int w,lim;
    printf("\tHow many values do you want:  ");scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        printf("\tEnter value%d :  ",i);scanf("%d",&w);
        struct simple_linked *tmp= malloc(sizeof(struct simple_linked));
        tmp->data=w;
        tmp->link=head;
        head=tmp;
    }
}
void pop_item(){
    if(head!=NULL){
        struct simple_linked *temp=head;
        head=temp->link;
        printf("\t%d was removed",temp->data);
        free(temp);
    }
}
void search_item(){
    int lim;
    struct simple_linked *temp=head;
    printf("\tEnter value to search :   ");scanf("%d",&lim);
    while(temp!=NULL){
        if(temp->data ==lim){
            printf("\t%d is in the list\n",temp->data);
            return;
        }
        temp=temp->link;
    }
    printf("\t%d was not found!\n",lim);
}
void delet_index(){
    int n;
    printf("\tEnter the index to delete : ");scanf("%d",&n);
    struct simple_linked* temp=head;
    if(n==1){head=temp->link;printf("\tYou deleted %d",temp->data);free(temp);return;}
    struct simple_linked* temp1=temp->link;
    for(int i=0;i<n-2;i++){
        if (temp==NULL){printf("\t-------!!!!out of range!!!!!--------\n");printf("\a");return;}
        else temp=temp->link;}
    temp->link=temp1->link;
    printf("\tYou deleted %d",temp1->data);
    free(temp1);
}
void reverse_list(){
    struct simple_linked* prev=NULL,*current=head,*next=NULL;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("\treverse was successfull print to view");
}
void simplelinked_exe(){
    printf(" ------------------SIMPLE LINKED LIST--------------------------\n");
    printf("  1.Create a list and add items\n  2.Print out the list\n  3.Delete the first item\n  4.Delete a specific index\n  5.Search a value in a list\n  6.Reverse the list\n");
    printf("     #Chose one operation:_ ");scanf("%d",&Choice);
    switch(Choice){
        case 1:push_item();break;
        case 2:show_list();break;
        case 3:pop_item();break;
        case 4:delet_index();break;
        case 5:search_item();break;
        case 6:reverse_list();break;
        default: printf("\t!!!!!!!!!!!!%d is an invalid choice !!!!!!!!!\n",Choice);simplelinked_exe();
    }
    printf(" \n\t->To exit simple linked list enter 0  ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    else {simplelinked_exe();}
}
//Doubly linked list
struct doubly_linked{
    struct doubly_linked *prev ;
    int data;
    struct doubly_linked *next ;
};struct doubly_linked *dhead=NULL;
void show_dlist(){
     struct doubly_linked *tmp=dhead;
     printf("\tYour list is {");
     while(tmp!=NULL){
        printf("%d, ",tmp->data);
        tmp=tmp->next;
     }
     printf("}\n");
}
void push_ditem(){
    int w,lim;
    printf("\tHow many values do you want:  ");scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        printf("\tEnter value%d :  ",i);scanf("%d",&w);
        struct doubly_linked *tmp= malloc(sizeof(struct doubly_linked));
        tmp->prev=NULL;
        tmp->data=w;
        tmp->next=dhead;
        if(dhead!=NULL)dhead->prev=tmp;
        dhead=tmp;
    }
}
void pop_ditem(){
    if(dhead==NULL)return;
     struct doubly_linked *tmp=dhead,*tmp1=tmp->next;
     tmp1->prev=NULL;
     dhead=tmp1;
     printf("\tYou have deleted %d\n",tmp->data);
     free(tmp);
}
void search_ditem(){
    int lim;
    struct simple_linked *temp=head;
    printf("\tEnter value to search :   ");scanf("%d",&lim);
    struct doubly_linked *tmp=dhead;
    while (tmp!=NULL){
        if(tmp->data==lim){printf("%d  found\n",tmp->data);return;}
        tmp=tmp->next;
    }
    printf("\t%d not found",lim);
}
void delete_dindex(){
    if(dhead==NULL)return;
    int n,i;
    printf("\tEnter the index to delete : ");scanf("%d",&n);
    struct doubly_linked* prev=dhead,*current,*next;
    if(n==1){dhead=prev->next;printf("\tYou deleted %d\n",prev->data);free(prev);return;}
    for(i=0;i<n-2;i++){
        prev=prev->next;
        if (prev==NULL){printf("\t-------out of range!!!!!--------\n");printf("\a");return;}
    }
    current=prev->next;
    next=current->next;
    prev->next=next;
    if(next!=NULL)next->prev=prev;
    printf("\tYou deleted %d\n",current->data);
    free(current);
}
void show_reverse(){
    struct doubly_linked *tmp=dhead;
    if(dhead==NULL)return;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    printf("\tYour list is {");
     while(tmp!=NULL){
        printf("%d, ",tmp->data);
        tmp=tmp->prev;
     }
     printf("}\n");
}
void insert_end(){
    struct doubly_linked *prev=dhead;
    int w,lim;
    printf("\tHow many values do you want:  ");scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        printf("\tEnter a value%d :  ",i);scanf("%d",&w);
        while(prev->next!=NULL){
            prev=prev->next;
        }
        struct doubly_linked *current= malloc(sizeof(struct doubly_linked));
        prev->next=current;
        current->prev=prev;
        current->data=w;
        current->next=NULL;
       }
}
void doublylinked_exe(){
    printf(" ------------------DOUBLY LINKED LIST--------------------------\n");
    printf("  1.Create a list and add items\n  2.Add item at the end\n  3.Print out the list\n  4.Print out the list in reverse\n  5.Delete the first item\n  6.Delete a specific index\n  7.Search a value in a list\n");
    printf("     #Chose one operation: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:push_ditem();break;
        case 2:insert_end();break;
        case 3:show_dlist();break;
        case 4:show_reverse();break;
        case 5:pop_ditem();break;
        case 6:delete_dindex();break;
        case 7:search_ditem();break;
        default: printf("\t!!!!!!!%d is an invalid choice!!!!!!! \n",Choice);doublylinked_exe();
    }
    printf(" \n\t->To exit doubly linked list enter 0  ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    doublylinked_exe();
}
//circular linked list
    //using simple linked list
struct simple_linked *chead;
void push_citem(){
    struct simple_linked *last;
    int w,lim;
    printf("\tHow many values do you want:  ");scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        printf("\tEnter a value :  ");scanf("%d",&w);
        struct simple_linked *current= malloc(sizeof(struct simple_linked));
        if(chead==NULL){
                current->data=w;
                chead=current;
                current->link=chead;
            }
        else{
            last=chead;
            while(last->link !=chead)last=last->link;
            current->data=w;
            current->link=chead;
            chead=current;
            last->link=current;
        }
    }

}
void show_clist(){
    if(chead==NULL)return;
    struct simple_linked *tmp=chead;
    printf("\tYour list is{");
    while(tmp->link!=chead){
        printf("%d, ",tmp->data);
        tmp=tmp->link;
     }
    printf("%d }\n",tmp->data);
}
void pop_citem(){
    if(chead==NULL)return;
    struct simple_linked *current=chead,*last=current;
    while(last->link !=chead)last=last->link;
    chead=current->link;
    last->link=current->link;
    printf("\t You have deleted: %d",current->data);
    free(current);
}
    //using doubly linked list
struct doubly_linked *cdhead;
void push_cditem(){
    struct doubly_linked *prev,*next;
    int w,lim;
    printf("\tHow many values do you want:  ");scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        printf("\tEnter a value :  ");scanf("%d",&w);
        struct doubly_linked *current= malloc(sizeof(struct doubly_linked));
        if(cdhead==NULL){
                current->data=w;
                cdhead=current;
                current->prev=cdhead;
                current->next=cdhead;
            }
        else{
            next=cdhead;
            prev=cdhead->prev;
            current->data=w;
            current->next=next;
            current->prev=prev;
            cdhead=current;
            next->prev=current;
            prev->next=current;

        }
    }
}
void show_cdlist(){
    if(cdhead==NULL)return;
    struct doubly_linked *tmp=cdhead;
    printf("\tYour list is {");
    while(tmp->next!=cdhead){
        printf("%d, ",tmp->data);
        tmp=tmp->next;
     }
     printf("%d}\n",tmp->data);
}
void pop_cditem(){
    if(cdhead==NULL)return;
    struct doubly_linked *prev=cdhead->prev,*current=cdhead,*next=cdhead->next;
    cdhead=current->next;
    next->prev=current->prev;
    prev->next=current->next;
    printf("\t You have deleted: %d",current->data);
    free(current);

}
void circularlinked_exe(){
    printf(" ------------------CIRCULAR LINKED LIST--------------------------\n");
    printf("\t--Using simple linked list--\n  1.Create a list and add items\n  2.Print out the list\n  3.Delete the first item\n\t--Using doubly linked list--\n  4.Create a list and add items\n  5.Print out the list\n  6.Delete the first item\n");
    printf("     #Chose one operation: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:push_citem();break;
        case 2:show_clist();break;
        case 3:pop_citem();break;
        case 4:push_cditem();break;
        case 5:show_cdlist();break;
        case 6:pop_cditem();break;
        default: printf("\t!!!!!!%d is an invalid choice !!!!!!\n",Choice);circularlinked_exe();
    }
    printf(" \n\t->To exit circular linked list enter 0  ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    circularlinked_exe();
}
//Stack
int MAXSIZE;
struct stack{
    int data;
    struct stack * next ;
};struct stack *top=NULL;
void push_s(){
    int len=0,w;
    struct stack *temp=top;
    while(temp!=NULL){len++;temp=temp->next;}
    if(len<MAXSIZE){
        printf("\tEnter a value :  ");scanf("%d",&w);
        struct stack *tmp= malloc(sizeof(struct stack));
        tmp->data=w;
        tmp->next=top;
        top=tmp;
        return;
    }
    printf("\tStack is full\n");
}
int pop_s(){
    int val;
    if(top!=NULL){
        struct stack *temp=top;
        top=temp->next;
        val= temp->data;
        free(temp);
    }
    else{printf("\tno value to pop\n"); return 0;}
    printf("\tYou popped %d\n",val);
    return val;
}
void peek(){
    if(top==NULL){printf("\tThe stack is empty\n");return;}
    printf("\tThe item at the top of the stack is %d\n",top->data);
}
int isfull(){
    int len=0;
    struct stack *temp=top;
    while(temp!=NULL){len++;temp=temp->next;}
    if(len==MAXSIZE){
        printf("\tThe stack is full. You have %d items\n",MAXSIZE);
        return 1;
    }
    printf("\tYou still have %d space left\n",MAXSIZE-len);
    return 0;
}
int stack_exe(){
    printf(" ------------------STACK--------------------------\n");
    printf("  1.Push an item at the top of stack\n  2.Pop the item at the top of the stack\n  3.See the top of the stack\n  4.Check if stack is full\n");
    printf("     #Chose one operation: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:push_s();break;
        case 2:pop_s();break;
        case 3:peek();break;
        case 4:isfull();break;
        default: printf("\t!!!!!%d is an invalid choice!!!!! \n",Choice);stack_exe();
    }
    printf(" \n\t->To exit Stacks enter 0");
    scanf("%d",&Exit);
    if (Exit==0)return 0;
    stack_exe();
}
//queue
struct que{
    struct que *prev ;
    int data;
    struct que*next ;
};struct que*front=NULL,*rear=NULL;
void enque(){
        int w;
        printf("\tEnter a value :  ");scanf("%d",&w);
        struct que *tmp= malloc(sizeof(struct que));
        if(front==NULL)rear=tmp;
        tmp->prev=NULL;
        tmp->data=w;
        tmp->next=front;
        if(front!=NULL)front->prev=tmp;
        front=tmp;
    }
int deque(){
    if(front==NULL)return -1;
    int val;
    struct que *current=rear,*prev=rear->prev;
    if(rear==front){
        rear=NULL;
        front=NULL;
        val=current->data;
    }
    else{
        rear=prev;
        prev->next=NULL;
        val=current->data;
    }
    free(current);
    printf("\tYou removed %d\n",val);
    return val;
}
void peak_q(){
    if(front==NULL){printf("\tQueue is empty!\n");return;}
    printf("\tfront = %d \trear = %d\n",front->data,rear->data);
}
int isempty(){
    int len=0,val;
    struct que *temp=front;
    while(temp!=NULL){len++;temp=temp->next;}
    val=(front==NULL?0:1);
    printf("\tThe queue has %d items\n",len);
    return val;
}
void que_exe(){
    int *max=&MAXSIZE;
    printf(" ------------------QUEUE--------------------------\n");
    printf("  1.Enqueue an item \n  2.Dequeue an item \n  3.See the top and bottom of the stack\n  4.Check if queue is empty\n");
    printf("     #Chose one operation: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:enque();break;
        case 2:deque();break;
        case 3:peak_q();break;
        case 4:isempty();break;
        default: printf("\t!!!!!!%d is an invalid choice !!!!!!!\n",Choice);que_exe();
    }
    printf(" \n\t->To exit Stacks enter 0 ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    que_exe();
}
//binary search tree(bst)
struct bst_node{
    struct bst_node*l_child;
    int data;
    struct bst_node*r_child;
};struct bst_node*bst_root=NULL;
void insert_bst(int Data){
    struct bst_node *htmp=bst_root;
    struct bst_node *temp=malloc(sizeof(struct bst_node));
    temp->l_child=NULL;
    temp->data=Data;
    temp->r_child=NULL;
    if(bst_root==NULL){bst_root=temp;return;}
    while(htmp!=NULL){
        if(htmp->l_child!=NULL&&htmp->r_child !=NULL){
            if(htmp->data>Data){htmp=htmp->l_child;continue;}
            if(htmp->data<Data){htmp=htmp->r_child;continue;}
        }
        if(htmp->data>Data){
            if(htmp->l_child!=NULL){htmp=htmp->r_child;continue;}
            htmp->l_child=temp;break;
        }
        if(htmp->data<Data){
            if(htmp->r_child!=NULL){htmp=htmp->r_child;continue;}
            htmp->r_child=temp;break;
        }
    }
}
int search_bst(){
    int found=-1,Data;
    if(bst_root==NULL){printf("\tEmpy list!");return 0;}
    printf("\tEnter value to search:  ");scanf("%d",&Data);
    void left_first(struct bst_node *ptr){
        while(ptr!=NULL){
            if(ptr->data==Data){found=ptr->data;break;}
            if(ptr->data<Data){ ptr=ptr->r_child;continue;}
            ptr=ptr->l_child;
        }
    }
    void right_first(struct bst_node *ptr){
        while(ptr!=NULL){
            if(ptr->data==Data){found=ptr->data;break;}
            if(ptr->data>Data){ ptr=ptr->l_child;continue;}
            ptr=ptr->r_child;
        }
        if(ptr!=NULL)found=ptr->data;
    }
    if(bst_root->data<Data)right_first(bst_root);
    else left_first(bst_root);
    printf("\t %d is in the list",found);
    return found;
}
void depth_first(struct bst_node *root){
    void left_first(struct bst_node *ptr){//post order
        if(ptr==NULL)return;
        printf("%d, ",ptr->data);
        left_first(ptr->l_child);
        left_first(ptr->r_child);
    }
    void right_first(struct bst_node *ptr){
        if(ptr==NULL)return;
        printf("%d, ",ptr->data);
        right_first(ptr->r_child);
        right_first(ptr->l_child);
    }
    printf("\nleft-fist travers { ");left_first(root);printf("}\n");
    printf("\nright-first travers  { ");right_first(root);printf("}\n");
}
void travers(){
    void inorder(struct bst_node *ptr){
        if(ptr==NULL)return;
         inorder(ptr->l_child);
         printf("%d, ",ptr->data);
         inorder(ptr->r_child);
    }
    void preorder(struct bst_node *ptr){
        if(ptr==NULL)return;
         printf("%d, ",ptr->data);
         preorder(ptr->l_child);
         preorder(ptr->r_child);
    }
    void postorder(struct bst_node *ptr){
        if(ptr==NULL)return;
         postorder(ptr->l_child);
         postorder(ptr->r_child);
         printf("%d, ",ptr->data);
    }
    printf("\tpreorder tree travers  { ");preorder(bst_root); printf("}\n");
    printf("\tinorder tree travers   { ");inorder(bst_root); printf("}\n");
    printf("\tpostorder tree travers { ");postorder(bst_root); printf("}\n");
}
void bst_exe(){
    printf(" ---------------------BINARY SEARCH TREE---------------------------\n");
    printf("  1.Create a tree and add items\n  2.View the different traversal\n  3.Search a value in a list\n");
    printf("     #Chose one operation: ");scanf("%d",&Choice);
    int D;
    switch(Choice){
        case 1:
        printf("\tEnter value :  ");scanf("%d",&D);
        insert_bst(D);break;
        case 2:travers();break;
        case 3:search_bst();break;
        default: printf("\t!!!!!!!%d is an invalid choice!!!!!!! \n",Choice);bst_exe();
    }
    printf(" \n\t->To exit binary tree list enter 0  ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    bst_exe();
}

int main(){
    printf("\t\t---------------------------------------WELCOME TO DATA STRACTURES------------------------------------\n");
    printf("1.ARRAYS\n2.SIMPLE LINKED LIST\n3.DOUBLY LINKED LIST\n4.CIRCULAR LINKED LIST\n5.STACKS\n6.QUEUE\n7.BINARY SEARCH TREE\n");
    printf("##SELECT A DATA STRUCTURE TO VIEW _");scanf("%d",&Choice);
    int *max;
    switch(Choice ){
    case 1:
        printf("//Arrays are containers of a fixed number of items of the same type\n//it is intitialized as:  type identifier[size]={ list , the , elements }; \n");
        printf("//each element is assessed using index,i.e. identifier[index]=10;\n\n");
        Arrays();
        break;
    case 2:
        printf("//simple linked list is a list of nodes that has data and the address of the next node in the list\n// it can be demonstrated as: \n");
        printf("//\t____________________\n//\t| data | next node |\n//it has a root node(head)  that holds the address of the top most node\n");
        printf("//the root node is used to travers the linked list\n\n");
        simplelinked_exe();
        break;
    case 3:
        printf("//doubly linked list is simillar to simple linked list but the nodes are interconnected i.e. the next node is connected to the current node and vise verser\n");
        printf("//the interconnection between the node enables both forward and backward traversal of the nodes\n");
        printf("//it can be demonstrated as:\n//\t___________________________________\n//\t|previous node | data | next node |\n\n");
        doublylinked_exe();
        break;
    case 4:
        printf("//circular linked list can be either doubly linked or simply linked\n//the difference is that the last node and the first node are interconnected\n");
        printf("//it can be demonstrated using simple linked list as:\n//\t____________________    ____________________    ____________________    _____________________\n//\t| data | next node |    | data | next node |    | data | next node |    | data | first node |\n\n");
        circularlinked_exe();
        break;
    case 5:
        printf("//stack is a data structure that utilizes  last in first out(LIFO) flow sequence\n//data that is at the top of the list is the only one that can be accessed and manipulated\n");
        printf("//push(add element in stack) and pop(remove the element from the stack) are the major function associated with it\n//the others are peek(view top of stack) isFull(checks if the stack is full)\n\n");
        max=&MAXSIZE;
        printf("\nEnter size of stack: ");scanf("%d",max);
        stack_exe();
        break;
    case 6:
        printf("//queue is a lot like stack the difference is that queue uses First in first out(FIFO)\n//enuque reffers to additition of data to the quue and deque referes to when data is removed\n\n ");
        que_exe();
        break;
    case 7:
        printf("//binary search tree uses the graph architecture of nodes and vertices\n//it consists of parent node and child nodes \n//a parents has a maximum of two children and a child had only one parent\n");
        printf("//\t\t\t\t     parent\n//\t\t\t\t     /   \\ \n//\t\t\t\tchild1  child2\n in binary search tree the left child should be less than the parent and the right child should be greater than the parent\n\n");
        bst_exe();
        break;
    default :
        printf("\n!!!!!!!!!!!Your Choice is out of range!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        main();
 }
    printf(" \n->To exit Data structures enter 0  ");
    scanf("%d",&Exit);
    if (Exit==0)return 0;
    main();
}
