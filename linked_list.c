#include "linked_list.h"

Node* createNode(const char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, const char* name)
{
    Node* newNode = createNode(name);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, const char* name)
{
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }   
    temp->next = newNode;
}

void insertAtPosition(Node** head, const char* name, int position)
{
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, name);
        return;
    }
    Node* newNode = createNode(name);
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node** head, const char* name)
{
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient not found!\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Patient %s deleted.\n", name);
}

void deleteByPosition(Node** head, int position)
{
    if (*head == NULL || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(Node* head)
{
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Patient List: ");
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}
