#include "linkedlist.h"

/* 
these functions are only defined within the .c file; thus the user 
cannot directly call them from the import 
*/
struct node* create_node(void* data); 
void destroy_node(struct node *node);
struct node *iterate(int index, struct linkedlist *list);

void insert_node(int index, int data, struct linkedlist *list);
void remove_node(int index, struct linkedlist *list);
int retrieve_data(int index, struct linkedlist *list);


struct linkedlist list_constructor(){
    struct linkedlist newlist; 
    newlist.head = NULL;
    newlist.length = 0;
    // a cool trick where we can assign a function to a member field !
    newlist.remove = remove_node;
    newlist.retrieve = retrieve_data;
    newlist.insert = insert_node;

    return newlist;
}


struct node* create_node(void *data){
    // this should be the equivalent of using new operator in c++ 
    //allocate memory and cast it to type of node 
    struct node *new_node_address = (struct node *)malloc(sizeof(struct node));
    struct node new_node_instance;
    new_node_instance.data = data; 
    new_node_instance.next = NULL;
    // set the values of the new node address = to the values in the field
    *new_node_address = new_node_instance;
    return new_node_address;
}

// a wrapper to make the functionallity clear
void destroy_node(struct node *node_addr){
    free(node_addr->data);
    free(node_addr);
}

struct node *iterate(int index, struct linkedlist *list){
    if (index < 0 || index >= list->length)
    {
        printf("index out of bounds .. ");
        exit(9);
    }
    struct node *cursor = list->head; 
    for (size_t i = 0; i < index; i++)
    {
        if (i == index)
        {
            return cursor;
        }
        
        cursor = cursor->next;
    }
    return cursor;
        
}

void insert_node(int index, int data, struct linkedlist *list){
    struct node *new_node  =  create_node(data);
    if(index ==0){
        new_node->next = list->head; 
        list->head = new_node;
    }else{
    struct node *cursor = iterate(index-1, list);
    new_node->next = cursor->next;
    cursor->next = new_node;
    }

    list->length += 1;
}


void remove_node(int index, struct linkedlist *list){
    if (index == 0)
    {
        struct node  *deletednode = list->head;
        list->head = deletednode->next;
        destroy_node(deletednode);  
    }
    else{
    struct node *cursor = iterate(index-1, list);
    struct node *deletednode =  cursor->next;
    cursor->next = deletednode->next; 
    destroy_node(deletednode);
    }

    list->length -= 1;
    
}

int retrieve_data(int index, struct linkedlist *list){
    struct node *cursor = iterate(index, list);
    return cursor->data;
}