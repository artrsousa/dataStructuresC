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
                __pop(stack);
                __pop(stack);
                __pop(stack);
                
                __push(stack, (void*) 340);
                __push(stack, (void*) 530);
                __push(stack, (void*) 120);
               
                        
                if (__top(stack))
                        printf("top: %d\n", (int*) __top(stack));
                
                __runs(stack);
                __clean_all(stack);
        }
}
