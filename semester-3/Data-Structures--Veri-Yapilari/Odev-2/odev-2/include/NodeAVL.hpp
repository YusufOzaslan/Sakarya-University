#ifndef NODEAVL_HPP
#define NODEAVL_HPP
#include "DogruKuyrugu.hpp"
#include <iostream>
using namespace std;

class NodeAVL
{
public:
    DogruKuyrugu dataQueue;
    NodeAVL *left;
    NodeAVL *right;
    int yukseklik;
    NodeAVL(const DogruKuyrugu &veri, NodeAVL *sol = NULL, NodeAVL *sag = NULL);
};
#endif