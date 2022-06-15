#ifndef NOKTA_HPP
#define NOKTA_HPP

#include <iostream>
#include <cmath>
using namespace std;

class Nokta
{
public:
    int distanceToOrigin, x, y, z;
    Nokta(int x = 0, int y = 0, int z = 0);
    // Varsayılan yapıcı fonksiyon
    Nokta &operator=(const Nokta &nokta);
    bool operator<(Nokta& nokta);
    bool operator>(Nokta &nokta);
    friend ostream &operator<<(ostream &os, Nokta &nokta);
};
#endif