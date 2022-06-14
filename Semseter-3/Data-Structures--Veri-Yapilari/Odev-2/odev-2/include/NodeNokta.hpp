#ifndef NODENOKTA_HPP
#define NODENOKTA_HPP
#include "Nokta.hpp"
#include <iostream>
using namespace std;

class NodeNokta
{
public:
	Nokta data;
	NodeNokta *next;
	NodeNokta(const Nokta &, NodeNokta *next = NULL);
};
#endif