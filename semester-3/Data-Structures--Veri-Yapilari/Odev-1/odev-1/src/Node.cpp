#include "Node.hpp"

Node::Node(const string &data, Node *next, Node *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}