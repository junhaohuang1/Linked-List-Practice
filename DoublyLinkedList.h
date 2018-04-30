#pragma once

template <class T> 
class DoublyLinkedList {

private:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
		Node(const T& data) :data(data), next(nullptr), previous(nullptr) {}
		Node(const T& data, Node* previous, Node* next) :data(data), next(previous), previous(next) {}
	};

	Node* head;
	Node* recursiveCopy(Node* rhsHead);

public:

	DoublyLinkedList<T>();
	~DoublyLinkedList<T>();
	void insertAtHead(const T& data);
	bool isEmpty();
	T removeFromHead();
	DoublyLinkedList<T>(const DoublyLinkedList<T>& rhs);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
	int size() const;
	void clear();

};

