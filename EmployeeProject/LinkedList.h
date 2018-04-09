#include<cstddef>
#include<iostream>

template<class T>
class Node
{
	Node<T> *mPrev;
	Node<T> *mNext;
	T mData;
public:
	Node() :mData(NULL), mPrev(NULL), mNext(NULL) {}
	Node(T const& data) : mData(data), mPrev(NULL), mNext(NULL) {}
	Node(const Node<T> *node) : mData(node->mData), mPrev(node->mPrev), mNext(node->mNext) {}

	Node<T>* getNext() {
		return mNext;
	}
	void setNext(Node<T> *next) {
		mNext = next;
	}

	Node<T>* getPrev() {
		return mPrev;
	}

	void setPrev(Node<T> *prev) {
		mPrev = prev;
	}
	
	T& getData() {
		return mData;
	}
	virtual ~Node() {
		delete mData;
	}

};


template<typename T>
class LinkedList
{
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	LinkedList() : head(NULL), tail(NULL), size(0) {}
	LinkedList(const int s) : head(NULL), tail(NULL), size(s)
	{
		Node<T> newNode = new Node;
		Node<T> *node = &newNode;
		for (int i = 0; i < size; i++) {
			node->setNext(new Node<T>);
			node = node->getNext();
		}
		this->head = newNode;
	}


	LinkedList(LinkedList& rhs) {
		LinkedList::operator=(rhs);
	}

	LinkedList<T>& operator=( LinkedList& rhs) {
		deleteList();
		size = rhs.getSize();
		Node<T> temp;
		for (Node<T>* nodePtr = rhs.getHead(), *newList = &temp; nodePtr; nodePtr = nodePtr->getNext()) {
			Node<T> *newNode = new Node<T>(nodePtr->getData());
			newNode->setPrev(newList);
			newList->setNext(newNode);
			newList = newList->getNext();
		}
		this->head = temp.getNext();
		return *this;
	}

	T& operator[](const int index) const {
		Node<T>* nodePtr = head;
		if (index < 0 || index >= this->size) {
			cout << "ERROR: Subscript out of range.\n";
		}
		else {
			for (int i = 0; i < index; i++)
				nodePtr = nodePtr->getNext();
		}
		return nodePtr->getData();
	}


	bool insert( T const& value) {
		Node<T>* newNode = new Node<T>(value);
		if (newNode == NULL)
			return false;

		if (head == NULL)
			head = newNode;
		else {
			Node<T>* nodePtr = head;
			while (nodePtr->getNext() != NULL) {
				nodePtr = nodePtr->getNext();
			}
			nodePtr->setNext(newNode);
			newNode->setPrev(nodePtr);
		}
		++size;
		return true;
	}


	bool insert(const int position, const T& value) {
		if (position>size || position<0)
			return false;

		Node * newNode = new Node(value);
		if (newNode == NULL) {
			return false;
		}
		if (position == 1) {
			if (head != NULL) {
				newNode->setNext(head);
				head->setPrev(newNode);
			}
			head = newNode;
			size++;
			return true;
		}

		Node * prev = head;
		for (int i = 1; i < position - 1; i++) {

			prev = prev->getNext();

			if (prev == NULL) {
				delete newNode;
				return false;
			}
		}

		newNode->setPrev(prev);
		if (prev->getNext()) {
			newNode->setNext(prev->getNext());
			prev->getNext()->setPrev(newNode);
		}
		prev->setNext(newNode);
		size++;
		return true;
	}


	bool remove(const int position) {
		if (position < 0 || head == NULL) {
			return false;
		}
		Node<T> * del = head;
		Node<T> * previousNode = nullptr;
		if (position == 0) {
			head = head->getNext();
			if (head != NULL) {
				head->setPrev(NULL);
			}
			delete del;
			--size;
			return true;
		}

		for (int i = 0; i < position; i++) {
			previousNode = del;
			del = del->getNext();
			if (del == NULL) {
				return false;
			}
		}

		previousNode->setNext(del->getNext());
		if (del->getNext()) {
			del->getNext()->setPrev(previousNode);
		}

		delete del;
		--size;
		return true;
	}


	int getSize() {
		return size;
	}

	Node<T>* getHead() {
		return head;
	}

	void deleteList() {
		Node<T>* nodePtr = head;
		while (nodePtr != NULL) {
			Node<T>* nextNode = nodePtr->getNext();
			delete nodePtr;
			nodePtr = nextNode;
		}
	}

	~LinkedList() {
		deleteList();
	}
};

