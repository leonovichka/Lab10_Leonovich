#include "Header.h"

Deque::Deque()
{
	head = tail = nullptr;
	count = 0;
}


Deque::Deque(int a)
{
	head = tail = new Node();
	head->prev = nullptr;
	head->next = nullptr;
	head->data = a;
}

Deque& Deque::operator=(Deque &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}


int Deque::GetSize()
{
	return count;
}


void  Deque::pushFront(const int a)
{
	Node* newNode = new Node();
	newNode->data = a;
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	count++;
};


void Deque::pushBack(const int a)
{
	Node* newNode = new Node();
	newNode->data = a;
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;

	}
	count++;
};

void Deque::popFront(int& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = head->data;
		Node* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
	}
};

void Deque::popBack(int& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
	a = tail->data;
	Node* temp = tail;
	tail = tail->prev;
	if (tail == nullptr) {
		head = nullptr;
	}
	else
	{
		tail->next = nullptr;
	}
	count--;
	}
};

void Deque::peekFront(int& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = head->data;
	}
}

void Deque::peekBack(int& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = tail->data;
	}
}