#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node *next;
	Node *prev;
	Node(const string &, Node *next = NULL, Node *prev = NULL);
};
#endif