#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(int argc, char **argv){
    struct LinkedList *myList = createLinkedList();
    if (myList == NULL){
        printf("List could not be created\n");
        return -1;
    }
    int result;
    printf("Appending 25, 26, 27, 28, 29, 30, 31, 32, 33, and 34 to the list\n");
    appendData(myList, 25);
    appendData(myList, 26);
    appendData(myList, 27);
    appendData(myList, 28);
    appendData(myList, 29);
    appendData(myList, 30);
    appendData(myList, 31);
    appendData(myList, 32);
    appendData(myList, 33);
    appendData(myList, 34);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Deleting 27 from the list.\n");
    result = deleteData(myList, 27);
    printf("Result of deleteData: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Deleting 50 from the list.\n");
    result = deleteData(myList, 50);
    printf("Result of deleteData: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Deleting Node at index 2.\n");
    result = deleteNode(myList, 2);
    printf("Result of deleteNode: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Deleting Node at index 12.\n");
    result = deleteNode(myList, 12);
    printf("Result of deleteNode: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Inserting 42 at index 4\n");
    result = insertData(myList, 42, 4);
    printf("Result of insertData: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Inserting 59 at index 21\n");
    result = insertData(myList, 59, 21);
    printf("Result of insertData: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    printf("Getting the index of the value 30.\n");
    printList(myList);
    result = indexOf(myList, 30);
    printf("Result of indexOf: %d\n\n", result);

    printf("Getting the index of the value 69.\n");
    printList(myList);
    result = indexOf(myList, 69);
    printf("Result of indexOf: %d\n\n", result);

    printf("Getting the value at index 5.\n");
    printList(myList);
    result = getItemAt(myList, 5);
    printf("Result of getItemAt: %d\n\n", result);

    printf("Getting the value at index 15.\n");
    printList(myList);
    result = getItemAt(myList, 15);
    printf("Result of getItemAt: %d\n\n", result);

    printf("Clearing the list\n");
    clearList(myList);
    printList(myList);

    free(myList);

    return 0;
}