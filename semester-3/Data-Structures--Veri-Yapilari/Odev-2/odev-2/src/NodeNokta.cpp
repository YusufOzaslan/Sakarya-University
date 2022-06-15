#include "NodeNokta.hpp"
/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

NodeNokta::NodeNokta(const Nokta &data, NodeNokta *next)
{
    this->data = data;
    this->next = next;
}