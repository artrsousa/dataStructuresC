#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct __node_ __node;  
struct __node_ {
                void *value;
                __node *prev;
                __node *next; 
            };
            
typedef struct __list_ __list;
struct __list_ {
                __node *head;
                __node *tail;
                int size;
            };

#define is_empty(list) \
            list->head == NULL ? true:false

static inline void __new_node(void *value, __node *node)
{ 
        node->value = malloc(sizeof(*value));
        node->prev  = node->next = NULL; 
        node->value = value;
}

static inline void __new_list(__list *list) 
{ 
        list->head = list->tail = NULL;
        list->size = 0;
}

static inline void __insert_at_end(__list *list, void *value)
{
        __node *node = malloc(sizeof(*node));
        __new_node(value, node);
        
        if (is_empty(list)) {
                list->head = list->tail = node;
        } else {
                /* double linked */
                list->tail->next = node;
                node->prev = list->tail;
                list->tail = node;
                
                /* make it circular */
                list->tail->next = list->head;
                list->head->prev = list->tail;
        }
        
        ++list->size;
}

static inline void __insert_at_begin(__list *list, void *value)
{
        __node *node = malloc(sizeof(*node));
        __new_node(value, node);
        
        if (is_empty(list)) {
                list->head = list->tail = node;
        } else {
                list->head->prev = node;
                node->next = list->head;
                list->head = node;
                
                list->head->prev = list->tail;
                list->tail->next = list->head;
        }
        
        ++list->size;
}

static inline void __insert_at(__list *list, void *value, int index)
{
        if (index > list->size + 1 || index < 1) {
                fprintf(stderr, "insert_at_mid: index[%d] in size[%d] cant be reached\n", 
                                                                                index, list->size);
                exit(EXIT_FAILURE);
        }
        
        __node *node = malloc(sizeof(*node));
        __new_node(value, node);
        
        if (index == 1) {
                __insert_at_begin(list, value);
        } else if (index == list->size + 1) {
                __insert_at_end(list, value);
        } else {
                __node *walker = list->head;
                __node *prev   = NULL;
                
                for (unsigned int i = 0; i < index - 1; ++i) {
                        prev = walker;
                        walker = walker->next;
                }
                
                node->prev = walker->prev; 
                node->next = walker;
                prev->next = node;
                walker->prev = node;
                
                ++list->size;
        }
}

static inline void __remove_at_begin(__list *list)
{
        if (is_empty(list) == false) {
                 __node *head = list->head;
                 
                if (list->size == 1) {
                        list->head = list->tail = NULL;
                } else {
                        list->tail->next = list->head->next;
                        list->head = list->head->next;
                        list->head->prev = list->tail;
                }
                
                --list->size;
                free(head);
        }
}

static inline void __remove_at_end(__list *list)
{
        if (is_empty(list) == false) {                        
                __node *tail = list->tail;
                
                if (list->size == 1) {
                        list->head = list->tail = NULL;
                } else {
                        list->head->prev = list->tail;
                        list->tail = list->tail->prev;
                        list->tail->next = list->head;
                }
        
                --list->size;
                free(tail);
        }
}

static inline void __remove_at(__list *list, int index)
{
        if (index < 1 || index > list->size) {
                fprintf(stderr, "index cant be removed");
                exit(EXIT_FAILURE);
        }
                
        __node *walker      = list->head;
        __node *prev_walker = NULL;
        
        if (index == 1) {
               __remove_at_begin(list); 
        } else if (index == list->size) {
                __remove_at_end(list);
        } else {
                for (unsigned int i = 0; i < index - 1; ++i) {
                        prev_walker = walker;
                        walker = walker->next;
                }
                        
                prev_walker->next = walker->next;
                walker->next->prev = prev_walker;

                --list->size;
                free(walker);
        }
}

static inline void *__search_for_index(__list *list, int index)
{
        if (index < 1 || index >= list->size) {
                fprintf(stderr, "search_for_index: index cant be reached\n");
                exit(EXIT_FAILURE);
        }
        
        __node *walker = NULL;
        
        if (is_empty(list) == false) {
                walker = list->head;

                for (unsigned int i = 0; i < index - 1; ++i)
                        walker = walker->next;
        } else {
                fprintf(stderr, "list is empty!!");
                exit(EXIT_FAILURE);
        }
        
        return walker->value;
}

static inline __node *__search_for_value(__list *list, void* value)
{
        __node *walker = list->head;
        
        for (unsigned int i = 0; i < list->size; ++i) {
                if (walker->value != value)
                        walker = walker->next;
                else
                        return walker;
        }
        
        return NULL;
}

static inline void __clear_all(__list *list)
{
        while (list->head)
                __remove_at_end(list);
}

static inline void __print_all(__list *list)
{
        __node *head = list->head;
        
        /* adjust the parameter % to your type */
        for (unsigned int i = 0; i < list->size ; ++i, head = head->next) {
                printf("index[%d]: value:%d\n", i, head->value);
        }
}


#endif /*LIST_H*/
