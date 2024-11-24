#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    struct ListNode *link;
    int data;
} ListNode;

void insertion_sort(ListNode **head) {
    if (*head == NULL || (*head)->link == NULL) {
        return; 
    }

    ListNode *sorted = NULL; 
    ListNode *current = *head; 

    while (current != NULL) {
        ListNode *next = current->link; 
        if (sorted == NULL || sorted->data >= current->data) {
            current->link = sorted;
            sorted = current;
        } else {
            ListNode *temp = sorted;
            while (temp->link != NULL && temp->link->data < current->data) {
                temp = temp->link;
            }
            current->link = temp->link;
            temp->link = current;
        }
        current = next;
    }

    *head = sorted; 
}