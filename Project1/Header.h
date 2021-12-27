#include <iostream>

using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};


struct Node
{
	int data;
	Node* prev, * next;
};

class Deque
{
public:
	Deque();
	Deque(int count);
	Deque& operator=(Deque&& other);
	int GetSize();
	void pushFront(const int a);
	void pushBack(const int a);
	void popFront(int& a);
	void popBack(int& a);
	void peekFront(int& a);
	void peekBack(int& a);
private:
	Node* head;
	Node* tail;
	int count;
};

