#include "circ_list.h"
#include <stddef.h>


typedef struct _circ_node {
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
} Circ_node;

typedef struct _circ_list{

    struct _circ_list *begin;
    struct _circ_list *end;
    size_t size;
    
} Circ_list;