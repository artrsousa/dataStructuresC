#include "stack.h"

int
main(void) 
{
        {
                /* examples of push, pop and top */
                __stack *stack = malloc(sizeof(*stack));
                __new_stack(stack);
                
                __push(stack, (void*) 10);
                __push(stack, (void*) 20);
                __push(stack, (void*) 30);
                __push(stack, (void*) 40);
                __push(stack, (void*) 50);
                __push(stack, (void*) 60);
                
                __pop(stack);
                __pop(stack);
                __pop(stack);
                
                printf("top: %d\n", __top(stack));
                __runs(stack);
                
                __clean_all(stack);
        }
}
