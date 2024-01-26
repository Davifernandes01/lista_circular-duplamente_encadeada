#include "circ_list.h"
#include <stdio.h>


int main(){

    Circ_list *list = create_list();

    circ_list_add_last(list, 7);
    circ_list_add_last(list, 5);
    circ_list_add_last(list, 4);
    circ_list_add_last(list, 2);
    circ_list_add_last(list, 10);


    print_list_v2(list);


    return 0;
}
