#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
void printll();

void ins_beg()
{
    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        new_node->next = start;
        start = new_node;
        temp->next = start;
    }
    printll();
}

void ins_bef()
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *ptr, *preptr;
    int pos;
    printf("Enter the data of node after which you need to insert the new node;\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    ptr = start;
    if (start->data == pos)
    {
        ins_beg();
        return;
    }
    while (ptr->next != start && ptr->data != pos)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->data == pos)
    {
        new_node->next = ptr;
        preptr->next = new_node;
    }
    printll();
}

void ins_aft()
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *ptr,*preptr;
    int pos;
    printf("Enter the data of the node before which you need to insert the new node\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    preptr=start;
    ptr=preptr->next;
    while(ptr->next->data!=pos){
        preptr = preptr->next;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    preptr->next=new_node;
    printll();
}

void ins_end()
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *ptr;
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    new_node->next = start;
    ptr->next = new_node;
    printll();
}

void del_beg()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    struct node *temp = start;
    start = start->next;
    ptr->next = start;
    free(temp);
    printll();
}

void del_mid()
{
    struct node *ptr, *preptr;
    int data;
    printf("Enter the data of the node to be deleted\n");
    scanf("%d", &data);
    ptr = start;
    if (ptr->data == data)
    {
        del_beg();
        return;
    }
    while (ptr->next != start && ptr->next->data != data)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->next->data == data)
    {
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    printll();
}

void del_end()
{
    struct node *ptr, *preptr;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);
    printll();
}

void printll()
{
    if (start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node *ptr = start;
    printf("The list is \n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

int main()
{
    int opt;
    while (opt != 9)
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
            printll();
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
