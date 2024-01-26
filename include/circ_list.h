#ifndef CIRC_LIST_H
#define CIRC_LIST_H
#include <stdbool.h>


typedef struct _circ_node Circ_node;
typedef struct _circ_list Circ_list;


Circ_node *create_node(int val);
Circ_node destroy_node(Circ_node **ref_node);

Circ_list *create_list();
void destroy_list(Circ_list **ref_list);
void destroy_list_v2(Circ_list **ref_list);
bool list_is_empty(const Circ_list *list);
void circ_list_add_first(Circ_list *list, int val);
void circ_list_add_last(Circ_list *list, int val);
void print_list(const Circ_list *list);
void print_list_v2(const Circ_list *list);
void print_list_inverted(const Circ_list *list);
void print_list_v2_inverted(const Circ_list *list);

void circ_list_remove(Circ_list *list, int val);



#endif