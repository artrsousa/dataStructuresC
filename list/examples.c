#include "list.h"

int
main(void)
{
        {
                /* Examples of insertions and removes*/
                __list *list = malloc(sizeof(*list));
                
                __insert_at_begin(list, (void*) 3);
                __insert_at_begin(list, (void*) 2);
                __insert_at_begin(list, (void*) 1);
                
                __insert_at_end(list, (void*) 4);
                __insert_at_end(list, (void*) 8);
                __insert_at_end(list, (void*) 9);
                
                __insert_at(list, (void*) 5, 5);
                __insert_at(list, (void*) 6, 6);
                __insert_at(list, (void*) 7, 7);
                
                __insert_at(list, (void*) 10, 10);

                __remove_at_begin(list);
                __remove_at_begin(list);
                
                __remove_at_end(list);
                __remove_at_end(list);
                
                __remove_at(list, 3);
                __remove_at(list, 3);
                
                __print_all(list);
                __clear_all(list);
        }

        {
                /* 
                void *value = 20;       
                __node *test = __search_for_value(list, value);

                fflush(stdout);
                if (test)
                        printf("value: %d found!!\n", value);
                else 
                        printf("value: %d not found\n", value);

                //__insert_at_mid(list, (void*) 666, 3);
                */                        
        }

        return 0;
}
