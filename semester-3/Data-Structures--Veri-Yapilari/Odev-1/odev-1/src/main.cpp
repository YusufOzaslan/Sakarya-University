#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "DoublyLinkedList.hpp"
using namespace std;

/*
 * @file			B201210033
 * @description		Iki yönlü bağlı liste ile dizi benzeri veri yapısı oluşturan program
 * @course			1. Ogretim C grubu
 * @assignment 		1. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

void ReadText(DoublyLinkedList &);

int main()
{
	DoublyLinkedList *names = new DoublyLinkedList();
	ReadText(*names);
	cout << "\n" << *names << "\n" << endl;
	delete names;
	// Çift yönlü listenin yıkıcı fonksiyonu çağrılır
	return 0;
}

void ReadText(DoublyLinkedList &names)
{
	ifstream file("doc/Veri.txt");
	string str, name;
	int index;
	bool check;

	while (getline(file, str))
	{
		check = true;					   // her satır okumada indexin bir kere seçilmesini kontrol eder
		if (str[0] == 69 || str[0] == 101) // 'E' veya 'e'
		{								   // Ekleme işlemi yapılır
			for (int i = 0; i < str.length(); i++)
			{
				if (isdigit(str[i]) && check)
				{ // index bulunur
					index = stoi(str.substr(i));
					check = false;
				}

				if (str[i] == 35) // 35 => #
				{				  // isim değişkene aktarılır
					name = str.substr(i + 1, str.length() - i - 2);
					break;
				}
			}
			names.Add(index, name);
		}

		if (str[0] == 83 || str[0] == 115) // 'S' veya 's'
		{								   // Silme işlemi yapılır
			for (int i = 0; i < str.length(); i++)
			{
				if (isdigit(str[i]))
				{
					index = stoi(str.substr(i));
					names.Remove(index);
					break;
				}
			}
		}
	}
}