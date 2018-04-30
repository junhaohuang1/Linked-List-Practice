#pragma once

template<class T> class DoublyLinkedList
{
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

	DoublyLinkedList();
	~DoublyLinkedList();
	void insertAtHead(const T& data);
	bool isEmpty();
	T removeFromHead();
	DoublyLinkedList(const DoublyLinkedList& rhs);
	DoublyLinkedList& operator=(const DoublyLinkedList& rhs);
	int size() const;
	void clear();
};