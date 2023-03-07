#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

struct linkedlist
{
    struct node *head; 
    int length;
    // pointers to functions declared w/in the struct 
    // function pointer do not need paramater names;
    // void(*insert)(int, int, struct linkedlist*) == void(*insert)(int index, int data, struct linkedlist *list);
    void(*insert)(int index, int data, struct linkedlist *list);
    void(*remove)(int index, struct linkedlist *list);
    int (*retrieve)(int index, struct linkedlist *list);
};






struct linkedlist list_constructor();


#endif // LINKEDLIST_H
