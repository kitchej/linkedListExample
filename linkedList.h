#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// This Node will hold our data and the memory address of the next node in the list
struct Node{
    int data;
    struct Node *next;
};

// Linked List that holds non-zero, positive integers (for simplicity)
struct LinkedList{
    struct Node *head;
    int count;
};

// Creates a linked list and returns a pointer to a LinkedList struct. Returns NULL if unsuccessful
struct LinkedList* createLinkedList();

// Appends a value to the end of the list. Returns 0 if successful
int appendData(struct LinkedList *list, int data);

// Inserts data at the given index. Returns -1 if the index is out of range, returns 0 if successful
int insertData(struct LinkedList *list, int data, int index);

// Deletes the first node that contains the value passed to data. Returns -1 if the item is not in the list, returns 0 if successful
int deleteData(struct LinkedList *list, int data);

// Deletes the node at the specified index. Returns -1 if the index is out of range, returns 0 if successful
int deleteNode(struct LinkedList *list, int index);

// Deletes all items in the list
void clearList(struct LinkedList *list);

// Prints out the values contained in the list to the console. If the list is empty, prints "List is empty" to the console
void printList(struct LinkedList *list);

// Returns the value at the specifed index. Returns -1 if the index is out of range
int getItemAt(struct LinkedList *list, int index);

// Returns the index of the the first instance of target. Returns -1 if the target is not in the list
int indexOf(struct LinkedList *list, int target);

#endif