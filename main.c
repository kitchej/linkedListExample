#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

#define TEST int

int main(int argc, char **argv){
    struct LinkedList *myList = createLinkedList();

    appendData(myList, 25);
    appendData(myList, 26);
    appendData(myList, 27);
    appendData(myList, 28);
    appendData(myList, 29);
    appendData(myList, 30);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    int result = deleteData(myList, 25);
    printf("Result: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    result = deleteData(myList, 27);
    printf("Result: %d\n", result);
    printList(myList);
    printf("Count: %d\n\n", myList->count);

    free(myList);

    return 0;
}