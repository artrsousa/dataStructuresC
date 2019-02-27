#include "tree.h"

int
main(void) 
{
        
        {
                
                /*  examples of binary tree  */
                __tree* tree = __new_tree();

                __push(&(tree->root), (void*) 50);
                __push(&(tree->root), (void*) 33);
                __push(&(tree->root), (void*) 21);
                __push(&(tree->root), (void*) 753);
                __push(&(tree->root), (void*) 445);
                __push(&(tree->root), (void*) 223);
                __push(&(tree->root), (void*) 71);
                __push(&(tree->root), (void*) 87);
                        
                __show(tree->root);

                __search_for(tree->root, (void*) 55);

                __clean_all(tree->root);

        }
        
        return 0;
}
