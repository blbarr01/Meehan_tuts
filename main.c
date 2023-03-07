#include <stdio.h>
#include "DataStructures/linkedlist.h"


int main(){
    struct linkedlist list = list_constructor();
    for (size_t i = 0; i <10; i++)
    {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        list.insert(i, x, &list); 
    }
    
    list.remove(2, &list);
    list.remove(4, &list);

    for (size_t i = 0; i < 8; i++)
    {
        /*
         * since the list is generic the returned thing needs to be cast
         * and dereferenced 
        */
        printf("%d\n", *(int*)list.retrieve(i, &list));
    }
    
}