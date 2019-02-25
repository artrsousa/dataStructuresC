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

typedef struct __stack_ __stack;
struct __stack_ {
                __node* base;
                __node* top;
                int size;
            };
            
#define is_empty(stack) \
        stack->top == NULL ? true:false
        
#define __clean_all(stack) \
                while (stack->base != NULL) { \
                        __node *prev = stack->base; \
                        stack->base = stack->base->next; \
                        free(prev); \
                }

static inline void __new_node(__node *node, void *value) 
{
        node->next  = NULL;
        node->value = malloc(sizeof(*value));
        node->value = value;
}

static inline void __new_stack(__stack *stack)
{
        stack->top = stack->base = NULL;
        stack->size = 0;
}            

static inline void __push(__stack *stack, void *value)
{
        __node *node = malloc(sizeof(*node));
        __new_node(node, value);
        
        if (is_empty(stack)) {
                stack->base = stack->top = node;
        } else {
                stack->top->next = node;
                stack->top = node;
        }
        
        ++stack->size;
}

static inline void __pop(__stack *stack)
{
        __node *walker = stack->base;
        __node *prev   = NULL;
        
        while (walker != stack->top) {
                prev = walker;
                walker = walker->next;
        }
        
        stack->top = prev;
        prev->next = NULL;
        
        free(walker);
}

static inline void* __top(__stack *stack)
{
        return stack->top->value;
}

static inline void __runs(__stack *stack)
{
        __node *walker = stack->base;
        
        int count = 0;
        while (walker != NULL) {
                printf("index[%d], value: %d\n", count, walker->value);
                walker = walker->next;
                ++count;
        }
}

#endif /* STACK_H */
