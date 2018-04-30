#include "DoublyLinkedList.h"
#include <iostream>

template<class T>
 DoublyLinkedList<T>::DoublyLinkedList():head(nullptr)
{
}

template<class T>
 DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs):head(nullptr)
{
	*this = rhs;
}


template <typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::recursiveCopy(Node* rhsHead)
{
	if (rhsHead == nullptr)
		return nullptr;
	return new Node(rhsHead->data, rhsHead, recursiveCopy(rhsHead->next));
}


template<class T>
 void DoublyLinkedList<T>::insertAtHead(const T & data)
{
	Node* newNode = new Node(data);
	if (isEmpty()) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}


template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return head == nullptr;
}


template<class T>
T DoublyLinkedList<T>::removeFromHead()
{
	if (!isEmpty()) {
		Node* temp = head;
		head = head->next;
		T retval = temp->data;
		delete temp;
		head->previous = nullptr;
		return retval;
	}
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs)
{
	if (this == rhs)
		return *this;
	clear();
	head = recursiveCopy(rhs.head);
	return *this;
}

template<class T>
int DoublyLinkedList<T>::size() const
{
	Node* temp = head;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

template<class T>
void DoublyLinkedList<T>::clear()
{
	while (!isEmpty())
		removeFromHead();
}
