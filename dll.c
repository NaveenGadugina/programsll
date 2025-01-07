#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start;

void printll();

void ins_beg(){
    int data;
    struct node *new_node=(struct node*)malloc (sizeof(struct node));
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    new_node->prev= NULL;
    new_node->next= start;
    start=new_node;

    printll();
}

void ins_end(){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    printf("Enter the data of the new node\n");
    scanf("%d",new_node->data);
    ptr=start;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }   
    new_node->next=NULL;
    new_node->prev=ptr;
    ptr->next =new_node;

    printll();
}

void ins_aft(){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    struct node*ptr;
    int pos;
    ptr=start;
    printf("Enter the data of the node afte which new node has to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    while(ptr->data!=pos){
        ptr=ptr->next;
    }
    new_node->next=ptr->next;\
    new_node->prev=ptr;
    ptr->next->prev=new_node;
    ptr->next=new_node;

    printll();

}

void ins_bef(){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    int pos;
    printf("Enter the data of the node before which the new node is inserted\n");
    scanf("%d",&pos);
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    while(ptr->data!=pos){
        ptr=ptr->next;
    }
    new_node->next= ptr;
    new_node->prev= ptr->prev;
    ptr->prev->next=new_node;
    ptr->prev=new_node;

    printll();
}

void del_beg(){
    if(start==NULL){
        printf("The list is emtpy");
        return;
    }
    struct node *ptr;
    ptr=start;
    start->next->prev =NULL;
    start=ptr->next;

    free(ptr);
}

void del_end(){
    if(start==NULL){
        printf("The list is emtpy");
        return;
    }
    struct node *ptr;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next =NULL;
    
    free(ptr);
}

void del_mid(){
    if(start==NULL){
        printf("The list is emtpy");
        return;
    }
    struct node *ptr = start;
    int data;
    printf("Enter the data of the node to be deleted\n");
    scanf("%d",&data);
    while(ptr->data!=data){
        ptr=ptr->next;
    }
    ptr->next->prev=ptr->prev;
    ptr->prev->next=ptr->next;
    free(ptr);
}

void printll(){
    struct node *ptr;
    ptr=start;
    if(start==NULL){
        printf("The list is empty");
        return;
    }
    while(ptr->next!=NULL){
        printf("The list is: ");
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}


int main()
{
    int opt;
    while (opt!=9)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_aft();
            break;
        case 4:
            ins_bef();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_mid();
            break;
        case 7:
            del_end();
            break;
        case 8:
            printll(start);
            break;
        case 9:
            return 0;
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}