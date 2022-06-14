#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Node.hpp"
#include <iostream>
using namespace std;

class Iterator
{
public:
    Node *current;
    Iterator();
    Iterator(Node *node);
    bool hasNext();
    void Next();
    void Previous();
    const string Retrieve();
};

#endif