#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct __node_ __node;  
struct __node_ {
                void *value;
                __node *next; 
            };

typedef struct __stack __stack;
struct __stack_ {
                __node* top;
                int size;
            };
            
#define is_empty(stack) \
        stack->top == NULL true:false
        
static inline void __new_node(__node *node, void *value) 
{
        node->next  = NULL;
        node->value = value;
}

static inline void __new_stack(__stack *stack)
{
        stack->top  = NULL;
        stack->size = 0;
}            

statick inline void push(__stack *stack, void *value)
{
}



#ifndef /* STACK_H */
