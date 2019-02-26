#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct __node_ __node;
struct __node_ {
                void *value;
                __node *left;
                __node *right;
        };
        
typedef struct __tree_ __tree;
struct __tree_ {
                __node* root;
                int size;
        };
        


#endif /*TREE_H*/
