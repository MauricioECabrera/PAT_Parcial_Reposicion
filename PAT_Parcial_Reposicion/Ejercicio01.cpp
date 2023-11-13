#include "Ejercicio01.h"

Node<int>* Ejercicio01::reverseList(Node<int>* head)
{
	Node<int>* prev = nullptr;
	Node<int>* next = nullptr;
	Node<int>* actual = head;
	while (actual != nullptr) {
		next = actual->next;
		actual->next = prev;
		prev = actual;
		actual = next;
	}
	return prev;
}
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
	Node<int>* l1n = reverseList(l1);
	Node<int>* l2n = reverseList(l2);
	Node<int>* l3 = new Node<int>{ 0 };
	Node<int>* l3n = l3;
	int carry = 0;
	while (l1n != nullptr || l2n != nullptr) {
		int sum = carry;
		if (l1n != nullptr) {
			sum += l1n->value;
			l1n = l1n->next;
		}
		if (l2n != nullptr) {
			sum += l2n->value;
			l2n = l2n->next;
		}
		l3n->next = new Node<int>{ sum % 10 };
		l3n = l3n->next;
		carry = sum / 10;
	}
	if (carry > 0) {
		l3n->next = new Node<int>{ carry };
	}
	return reverseList(l3->next);
}