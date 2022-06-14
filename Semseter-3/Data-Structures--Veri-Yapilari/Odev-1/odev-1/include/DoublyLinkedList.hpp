#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"
#include "Iterator.hpp"
#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
	Node *root;
	int size;
	Iterator previousPosition(int);

public:
	DoublyLinkedList();
	void Add(int, const string &);// Veri adres ile alınır ve gereksiz yere string nesnesi oluşturulmaz.
	void Remove(int);
	friend ostream &operator<<(ostream &, const DoublyLinkedList &);
	~DoublyLinkedList();
};
#endif