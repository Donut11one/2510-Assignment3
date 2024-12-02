#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct to represent a patient node in the linked list.
 */
typedef struct Node {
    char name[50]; // Patient's name
    struct Node *next; // Pointer to the next node
} Node;

// Function prototypes
Node* createNode(const char* name);
void insertAtBeginning(Node** head, const char* name);
void insertAtEnd(Node** head, const char* name);
void insertAtPosition(Node** head, const char* name, int position);
void deleteByValue(Node** head, const char* name);
void deleteByPosition(Node** head, int position);
void displayList(Node* head);

#endif // LINKED_LIST_H
