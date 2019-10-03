#ifndef __LIST_H
#define __LIST_H

#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

struct list_node {
    jmp_buf data;
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

struct list_node* list_node_create(jmp_buf* _data) {
    struct list_node* ret = malloc(sizeof(struct list_node));
    memcpy(&(ret->data), _data, sizeof(jmp_buf));
    return ret;
}

void list_add (jmp_buf* _data) {
    struct list_node* ret = list_node_create(_data);
    ret->prev = jmp_list->head;
    jmp_list->head = ret;
}

void list_remove() {
    if (jmp_list->head) {
        struct list_node* tmp = jmp_list->head->prev;
        free(jmp_list->head);
        jmp_list->head = tmp;
    }
}

struct list_node* list_search(  jmp_buf _data ,
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