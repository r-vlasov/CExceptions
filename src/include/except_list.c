#ifndef __LIST_H
#define __LIST_H

#include <setjmp.h>
#include <stdlib.h>
struct list_node {
    jmp_buf* data;
    struct list_node* prev;
};

struct list {
    struct list_node* head;
};

struct list* jmp_list;

/* methods */
struct list* list_create() {
    struct list* l = malloc(sizeof(struct list));
    l->head = NULL;
    return l;
}

struct list_node* list_node_create(void* _data) {
    struct list_node* ret = malloc(sizeof(struct list_node));
    ret->data = _data;
    return ret;
}

void list_add (void* _data) {
    struct list_node* ret = list_node_create(_data);
    ret->prev = jmp_list->head;
    jmp_list->head = ret;
}

void list_remove() {
    if (jmp_list->head) {
        struct list_node* tmp = jmp_list->head->prev;
        free(jmp_list->head->data);
        free(jmp_list->head);
        jmp_list->head = tmp;
    }
}

struct list_node* list_search(  void* _data ,
                                int *(comparator(void*, void*))) 
{
    if (jmp_list->head) {
        for (struct list_node* i = jmp_list->head; i != NULL; i = i->prev) 
            if (comparator(_data, i->data))
                return i;
    }
    // if we don't find we return NULL
    return NULL;
}
#endif