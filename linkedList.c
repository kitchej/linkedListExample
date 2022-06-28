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
    struct Node *curr = list->head;
    while (curr != NULL){
        printf("%f\n", curr->data);
        curr = curr->next;
    }
}

double getItem(struct LinkedList *list, double target){
    struct Node *curr = list->head;
    while (curr != NULL){
        if(curr->data == target){
            break;
        }
        curr = curr->next;
    }

    if (curr == NULL){
        return -1;
    }
    else{
        return curr->data;
    }
}

int indexOf(struct LinkedList *list, double target){
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

int appendData(struct LinkedList *list, double data){
    // Create node struct, set data to data and next to null
    // if head is NULL, then append to head
    // else, loop till next is NULL, then set next to new node

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

int insertData(struct LinkedList *list, double data, int index){
/* 
if index > count - 1, return -1
    if index == 0 and count == 0, head = data
else if index == count - 1, append to tail
else,
    1.) Traverse till 1 node before the index (this node will be x)
    2.) Store ref to x->next (this ref will be y)
    3.) Set x->next to new node
    4.) Set new_node->y
*/
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (index < 0){
        return -1;
    }
    else if (index > (list->count - 1)){
        // Index out of range
        if (index == 0 && list->count == 0){
            // Append data if list is empty
            int result = appendData(list, data);
            return result;
        }
        return -1;
    }
    else if(index == 0){
        // Insert at head
        new->next = list->head;
        list->head = new;
        list->count++;
        return 0;
    }
    else if(index == list->count - 1){
        // Insert at tail
        int result = appendData(list, data);
        return result;
    }
    else{
        struct Node *curr = list->head;
        for (int i=0; i != (index - 1); i++){
            curr = curr->next;
        }
        // printf("AT: %f\n", temp->data);
        struct Node *old = curr->next;
        curr->next = new;
        new->next = old;
        return 0;
    }
}     

int deleteData(struct LinkedList *list, double data){
    int index = indexOf(list, data);
    int result = deleteNode(list, index);
    return result;
}

int deleteNode(struct LinkedList *list, int index){
    if (index < -1){
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

