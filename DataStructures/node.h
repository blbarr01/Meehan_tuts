#ifndef Node_H
#define Node_H

struct node
{
    // a void pointer really just points to an address 
    // and it can be cast to anything !!
    /**
     * but data type has to be allocated on the heap w/ malloc. 
     * before inserting. supposedly this takes more processing power
     * and requires a bit more c procedures, casting and dereferencing
     * but this allows for generic datastructures to be used with 
     * any kind of data: think about the possibilities w/ structs
     * 
     * refer to main.c for reference  
     * */ 
    void *data;
    struct node *next; 
    
};


#endif // !Node_H