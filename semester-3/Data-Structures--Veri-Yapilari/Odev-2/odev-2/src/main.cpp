#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include "DogruKuyrugu.hpp"
#include "AVL.hpp"
#include "Nokta.hpp"
using namespace std;

/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

int main()
{
	ifstream file("doc/Noktalar.txt");
	ifstream file2("doc/Noktalar.txt");
	string str;
	int x, y, z, i = 0, numberOfQueues = 0;
	while (getline(file2, str))
	{ // Kuyruklar ile dinamik dizisi oluşturmak için satır sayısı hesaplanır.
		numberOfQueues++;
	}

	DogruKuyrugu **queueArray = new DogruKuyrugu *[numberOfQueues];
	// Kuyruk sayısı kadar referans dizisi oluşturulur. Kuyruk nesnesi oluşmaz
	AVL avlTree;

	while (getline(file, str))
	{
		queueArray[i] = new DogruKuyrugu(); // i numaralı satır için kuyruk oluşturulur
		istringstream ss(str);
		while (ss >> x >> y >> z)
		{ // x, y ve z noktaları ile Nokta nesnesi oluşturulur
			Nokta n(x, y, z);
			queueArray[i]->Enqueue(n);
		}
		queueArray[i]->CalculateSumOfLengths();
		// Her kuyruk oluşturlulduktan sonra toplam uzunluğu hesaplayan fonksiyon çağrılır
		avlTree.Ekle(*queueArray[i]);
		i++;
	}
	avlTree.postorder();
	cout << "\n\n		*************	POSTORDER	*************\n"
		 << endl;

	// Referans dizisi için ayrılan yer boşaltılır.
	delete[] queueArray;
	return 0;
}