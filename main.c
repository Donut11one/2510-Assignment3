#include "linked_list.h"

int main()
{
    Node* head = NULL;

    insertAtEnd(&head, "Patient1");
    insertAtEnd(&head, "Patient2");
    insertAtBeginning(&head, "Patient0");
    insertAtPosition(&head, "Patient1.5", 2);

    displayList(head);

    deleteByValue(&head, "Patient1");
    deleteByPosition(&head, 1);

    displayList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
