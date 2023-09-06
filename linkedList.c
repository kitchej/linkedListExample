/*
Linked List in C
Written by Joshua Kitchen
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct LinkedList* createLinkedList(){
    struct LinkedList *myList = malloc(sizeof(struct LinkedList));
    if (myList == NULL){
        return NULL;
    }
    myList->head = NULL;
    myList->count = 0;
    return myList;
}

void printList(struct LinkedList *list){ 
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *curr = list->head;
    while (curr != NULL){
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int getItemAt(struct LinkedList *list, int index){
    if (index > (list->count -1)){
        return -1;
    }
    else{
        struct Node *curr = list->head;
        for (int i=0; i != index; i++){
            curr = curr->next;
        }
        return curr->data;
    }
}

int indexOf(struct LinkedList *list, int target){
    struct Node *curr = list->head;
    int i = 0;
    while (curr != NULL){
        if(curr->data == target){
            break;
        }
        curr = curr->next;
        i++;
    }

    if (curr == NULL){
        return -1;
    }
    else{
        return i;
    }
}

int appendData(struct LinkedList *list, int data){
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (list->head == NULL){
        list->head = new;
        list->count++;
        return 0;
    }
    else{
        struct Node *curr = list->head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new;
        list->count++;
        return 0;
    }
}

int insertData(struct LinkedList *list, int data, int index){
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (index < 0){
        return -1;
    }
    else if (index > (list->count - 1)){
        if (index == 0 && list->count == 0){
            int result = appendData(list, data);
            return result;
        }
        return -1;
    }
    else if(index == 0){
        new->next = list->head;
        list->head = new;
        list->count++;
        return 0;
    }
    else{
        struct Node *curr = list->head;
        for (int i=0; i != (index - 1); i++){
            curr = curr->next;
        }
        struct Node *old = curr->next;
        curr->next = new;
        new->next = old;
        return 0;
    }
}     

int deleteNode(struct LinkedList *list, int index){
    if (index < 0){
        return -1;
    }
    else if (index > (list->count - 1)){
        return -1;
    }
    else if (index == 0){
        struct Node *toDelete = list->head;
        list->head = toDelete->next;
        free(toDelete);
        list->count --;
        return 0;
    }
    else{
        struct Node *curr = list->head;
        for (int i=0; i != (index - 1); i++){
            curr = curr->next;
        }
        struct Node *toDelete = curr->next;
        struct Node *next = toDelete->next;
        free(toDelete);
        curr->next = next;
        list->count--;
        return 0;
    }
}

int deleteData(struct LinkedList *list, int data){
    int index = indexOf(list, data);
    int result = deleteNode(list, index);
    return result;
}

void clearList(struct LinkedList *list){
    if (list->count == 0){
        return;
    }
    struct Node *temp = list->head;
    struct Node *toDelete = NULL;
    list->head = NULL;
    list->count = 0;
    while (temp != NULL){
        toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
}
