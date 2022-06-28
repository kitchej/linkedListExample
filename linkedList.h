#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    double data;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
    int count;
};

struct LinkedList* createLinkedList();

// Appends a value to the end of the list. Returns 0 if successful
int appendData(struct LinkedList *list, double data);

// Inserts data at the given index. Returns 0 if successful
int insertData(struct LinkedList *list, double data, int index);

// Deletes the first node that contains the value passed by data. Returns 0 if successful
int deleteData(struct LinkedList *list, double data);

// Deletes the node at the specified index. Returns 0 if successful.
int deleteNode(struct LinkedList *list, int index);

// Deletes all items in the list
void clearList(struct LinkedList *list);

// Prints out the values contained in the list
void printList(struct LinkedList *list);

// Gets returns the first value in the list matches the target. Returns -1 if the target is not in the list
double getItem(struct LinkedList *list, double target);

// Returns the index of the given target, returns -1 if the target is not in the list
int indexOf(struct LinkedList *list, double target);

#endif