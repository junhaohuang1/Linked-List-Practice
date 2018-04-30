#include "DoublyLinkedList.h"


template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList & rhs):head(nullptr)
{
	*this = rhs;
}


template <typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::recursiveCopy(Node* rhsHead) {
	if (rhsHead == nullptr)
		return nullptr;
	return new Node(rhsHead->data, rhsHead, recursiveCopy(rhsHead->next));
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList():head(nullptr)
{
}

template<class T>
inline void DoublyLinkedList<T>::insertAtHead(const T & data)
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
inline bool DoublyLinkedList<T>::isEmpty()
{
	return head == nullptr;
}

template<class T>
inline T DoublyLinkedList<T>::removeFromHead()
{
	if (!isEmpty()) {
		Node* temp = head;
		head = head->next;
		head->previous = nullptr;
		T retval = temp->data;
		delete temp;
		return retval;
	}
}

template<class T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList & rhs)
{
	if (this == rhs)
		return *this;
	clear();
	head = recursiveCopy(rhs.head);
	return *this;
}

template<class T>
inline int DoublyLinkedList<T>::size() const
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
inline void DoublyLinkedList<T>::clear()
{
	while (!isEmpty())
		removeFromHead();
}

