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
        };
        
static inline void __clean_all(__node *root)
{
        if (root != NULL)
        {        
                __clean_all(root->left);
                __clean_all(root->right);
                free(root);
        }
        
}
                
static inline __node *__new_node(void *value)
{
        __node *node = (__node*) malloc(sizeof(__node));
        node->left  = node->right = NULL;
        node->value = (void*) malloc(sizeof(*value));
        node->value = value;
        
        return node;
}

static inline __tree *__new_tree(void)
{
        __tree *tree = malloc(sizeof(__tree));
        tree->root   = NULL;
        
        return tree;
}

static inline void __push(__node **node, void *value)
{
        if (*node == NULL) 
        { 
                *node = __new_node(value);
        }
        else if (value < (*node)->value)
        {
                __push(&(*node)->left, value);
        }
        else if (value >= (*node)->value)
        {
                __push(&(*node)->right, value);
        }
}

static inline void __show(__node *node)
{
        if (node != NULL) {
                __show(node->left);
                printf("node value: %d\n", node->value);
                __show(node->right);
        }
}

static inline void __search_for(__node *root, void *value)
{
        if (root != NULL) 
        {
                if (root->value == value) {
                        printf("[%d] FOUND!! \n", value);
                }
                else 
                {
                        if (value < root->value)
                                __search_for(root->left, value);
                        else if (value > root->value)
                                __search_for(root->right, value);
                }
        }
}

#endif /*TREE_H*/
