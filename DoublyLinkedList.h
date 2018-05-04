#include <iostream>

template <class T>
class DoublyLinkedList {

private:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
		Node(const T& data) :data(data), next(nullptr), previous(nullptr) {}
		Node(const T& data, Node* previous, Node* next) :data(data), previous(previous),  next(next) {}
	};

	int nodeCount;
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
	void remove(T data);
	Node* getHead() const;
	class Iterator {
	public:
		Iterator(Node* startingNode) : current(startingNode) {}
		Iterator operator=(Node* rhs) { this->current = rhs; }
		Iterator operator++(int) { 
			if(current != nullptr)
				current = current->next; 
			return *this; 
		};
		Iterator operator--(int) { 
			if(current != nullptr)
				current = current->previous; 
			return *this; 
		};
		T& operator*() { return current->data; }
		bool end() { return current == nullptr; }
	private:
		Node * current;
	};
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() :head(nullptr)
{
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) :head(nullptr)
{
	*this = rhs;
}


template <typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::recursiveCopy(Node* rhsHead)
{
	if (rhsHead == nullptr)
		return nullptr;
	return new Node(rhsHead->data, rhsHead->previous, recursiveCopy(rhsHead->next));
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
	nodeCount++;
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
		if(head != nullptr)
			head->previous = nullptr;
		nodeCount--;
		return retval;
	}
	std::cout << "List was empty! Nothing to remove from head!" << std::endl;
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs)
{
	if (this == &rhs)
		return *this;
	clear();
	head = recursiveCopy(rhs.head);
	this->nodeCount = rhs.nodeCount;
	return *this;
}

template<class T>
int DoublyLinkedList<T>::size() const
{
	return this->nodeCount;
}

template<class T>
void DoublyLinkedList<T>::clear()
{
	while (!isEmpty())
		removeFromHead();
}

template<class T>
inline void DoublyLinkedList<T>::remove(T data)
{
	if (isEmpty())
		return;
	if (head->data == data)
		removeFromHead();
	else {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == data) {
				if (temp->previous != nullptr)
					temp->previous->next = temp->next;
				if(temp->next != nullptr)
					temp->next->previous = temp->previous;
				nodeCount--;
				delete temp;
				return;
			}
			temp = temp->next;
		}
	}

}


template<typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::getHead() const
{
	return this->head;
}
