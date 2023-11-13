#include "Ejercicio02.h"

Node<char>* reverseSublist(Node<char>* start, Node<char>* end) {
    Node<char>* prev = nullptr;
    Node<char>* curr = start;

    while (curr != end) {
        Node<char>* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev;
}

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k) {
    Node<char>* curr = head;
    int count = 0;

    while (curr != nullptr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) {
        return head;
    }

    Node<char>* newHead = reverseSublist(head, curr);
    head->next = reverseKGroup(curr, k);


    return newHead;
}