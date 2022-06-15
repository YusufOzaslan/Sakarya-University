#include "Nokta.hpp"
/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

Nokta::Nokta(int x, int y, int z)
{ // Nokta sınıfının varsayılan kurucusu
  this->x = x;
  this->y = y;
  this->z = z;
  distanceToOrigin = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  // Orjine olan uzaklık hesaplanır ve Nokta sınıfının içerisndeki distanceToOrigin değişkeninde tutulur
}

// Atama operatörü aşırı yüklenir
Nokta &Nokta::operator=(const Nokta &nokta)
{
  // kopyalama yapılır
  this->x = nokta.x;
  this->y = nokta.y;
  this->z = nokta.z;
  this->distanceToOrigin = nokta.distanceToOrigin;
  return *this;
}

bool Nokta::operator<(Nokta& nokta)
{ // Nokta sınıfı için < operatörü aşırı yüklenir
  return this->distanceToOrigin < nokta.distanceToOrigin;
}
bool Nokta::operator>(Nokta& nokta)
{ // Nokta sınıfı için > operatörü aşırı yüklenir
  return this->distanceToOrigin > nokta.distanceToOrigin;
}
ostream &operator<<(ostream &os, Nokta &nokta)
{ // Nokta sınıfı için << operatörü aşırı yüklenir. Ekrana sadece noktanın orjine olan uzaklığı yazılır.
  os << nokta.distanceToOrigin << "     ";
  return os;
}