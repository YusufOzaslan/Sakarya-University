#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "DogruKuyrugu.hpp"
#include "NodeAVL.hpp"
#include <algorithm> // std::max
using namespace std;

class AVL
{
private:
	NodeAVL *root;

	NodeAVL *AraVeEkle(NodeAVL *alt_Dugum, const DogruKuyrugu &yeni);

	NodeAVL *SolCocukIleDegistir(NodeAVL *alt_Dugum);

	NodeAVL *SagCocukIleDegistir(NodeAVL *alt_Dugum);

	void postorder(NodeAVL *alt_Dugum);

	int Yukseklik(NodeAVL *alt_Dugum);

public:
	AVL();

	void Ekle(const DogruKuyrugu &yeni);

	void postorder();

	~AVL();
};

#endif