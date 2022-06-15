#include "NodeAVL.hpp"
/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

NodeAVL::NodeAVL(const DogruKuyrugu &veri, NodeAVL *sol, NodeAVL *sag)
{
    this->dataQueue = veri;
    this->left = sol;
    this->right = sag;
    this->yukseklik = 0;
}