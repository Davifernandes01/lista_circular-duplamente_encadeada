#include "circ_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _circ_node {
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
} Circ_node;

typedef struct _circ_list{

     Circ_node *begin;
     Circ_node *end;
    size_t size;
    
} Circ_list;


//criar um node
Circ_node *create_node(int val){

    Circ_node *node = (Circ_node*) calloc(1, sizeof(Circ_node));
    node->val = val;
    node->prev = node;
    node->next = node;

}


Circ_node destroy_node(Circ_node **ref_node){

    Circ_node *node = *ref_node;
    free(node);
    *ref_node = NULL;

}

Circ_list *create_list(){

    Circ_list *list = (Circ_list*) calloc(1, sizeof(Circ_list));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}


void destroy_list(Circ_list **ref_list){

    Circ_list *list = *ref_list;
    Circ_node *node = list->begin;
    Circ_node *aux = NULL;

    while(node != list->end){
        
        aux = node;
        node = node->next;
        destroy_node(&aux);

    }
        destroy_node(&node);
        free(list);
        *ref_list = NULL;

}


void destroy_list_v2(Circ_list **ref_list){

    Circ_list *list = *ref_list;
    Circ_node *node = list->begin;
    Circ_node *aux = NULL;


    for(int i = 0; i < list->size; i++){
        aux = node;
        node = node->next;

        destroy_node(&aux);
    }

    free(list);
    *ref_list = NULL;

}

//ver se a lista esta vazio ou não
bool list_is_empty(const Circ_list *list){

    return list->size ==0;
}


void circ_list_add_first(Circ_list *list, int val){
    Circ_node *node = create_node(val);
    
    if(list_is_empty(list)){
    
        list->begin = node;
        list->end = node;


    }else{

        node->next = list->begin; //elemento proximo do node, aponta para o começo da lista
        list->begin->prev = node;//elemento anterior ao começo da lista, aponta para o node
        node->prev = list->end;//meu elemento anterior do node é o elemento final da list
        list->end->next = node;// proximo elemento do ultimo nó, aponta para o primeiro elemento
    }

    list->begin = node; //meu novo primeiro elemento da lista é o node 
    list->size++;
}


void print_list(const Circ_list *list ){

    if(list_is_empty(list)){
        printf("list.begin > null\n");
        printf("list.end > null\n");
    }else{


        Circ_node *node = list->begin;

        do
        {
           printf("%d <-> ", node->val);
           node = node->next;
           
        } while (node != list->begin);
        printf("\nlist.end -> %d\n", list->end->val);
        
    }

    printf("\nsize > %lu\n", list->size);
}


void print_list_v2(const Circ_list *list){
    if(list_is_empty(list)){
        printf("list.begin > null\n");
        printf("list.end > null\n");
    }else{
        Circ_node *node = list->begin;

        for(int i = 0; i < list->size; i++){
           printf("%d <-> ", node->val);
           node = node->next;
        
        }
        printf("\nlist.end -> %d\n", list->end->val);
        printf("\nsize > %lu\n", list->size);
    }

}



void print_list_inverted(const Circ_list *list ){

    if(list_is_empty(list)){
        printf("list.begin > null\n");
        printf("list.end > null\n");
    }else{


        Circ_node *node = list->end;

        do
        {
           printf("%d <-> ", node->val);
           node = node->prev;
           
        } while (node != list->end);
        printf("\nlist.end -> %d\n", list->end->val);
        
    }

    printf("\nsize > %lu\n", list->size);
}


void print_list_v2_inverted(const Circ_list *list){
    if(list_is_empty(list)){
        printf("list.begin > null\n");
        printf("list.end > null\n");
    }else{
        Circ_node *node = list->end;

        for(int i = 0; i < list->size; i++){
           printf("%d <-> ", node->val);
           node = node->prev;
        
        }
        printf("\nlist.end -> %d\n", list->end->val);
        printf("\nsize > %lu\n", list->size);
    }

}