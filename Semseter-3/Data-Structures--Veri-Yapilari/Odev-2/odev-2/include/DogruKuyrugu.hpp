#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP
#include <iostream>
#include "NodeNokta.hpp"
#include "Nokta.hpp"
#include <iomanip>
using namespace std;

class DogruKuyrugu
{
private:
	NodeNokta *front;
	NodeNokta *back;
	int lengthOfQueue;
	int sumOfLengths;
	// Noktalar arası toplam uzaklık sumOfLengths değişkeninde tutulur
	NodeNokta *previousMinNodeNokta() const;

public:
	DogruKuyrugu();
	void CalculateSumOfLengths();
	void Enqueue(const Nokta &);
	void Dequeue();
	void dequeueMin();
	DogruKuyrugu &operator=(const DogruKuyrugu &dogruKuyrugu);
	bool operator<(DogruKuyrugu &dogruKuyrugus) const;
	bool operator>(DogruKuyrugu &dogruKuyrugus) const;
	friend bool operator==(const DogruKuyrugu &dogruKuyrugu1, const DogruKuyrugu &dogruKuyrugu2);
	~DogruKuyrugu();
};

#endif