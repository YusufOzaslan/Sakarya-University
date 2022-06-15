#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <time.h>
using namespace std;

/**********************************************************************
**                      SAKARYA ÜNÝVERSÝTESÝ
**              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                    PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                  ÖDEV NUMARASI....: 2. Ödev
**                  ÖÐRENCÝ ADI......: Yusuf Özaslan
**                  ÖÐRENCÝ NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. Öðretim B grubu
**********************************************************************/

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati {
protected:

	int genislik;
	int catiYukseklik; // Çatý yüksekliði.
	int evYukseklik; // Zeminden tavana kadar olan yükseklik.
	int x;
	int y;

public:

	char karakterCati = '*';

	void cati(){
		cout << "Geniþlik: ";
		cin >> genislik;
		cout << "\nYükseklik: ";
		cin >> evYukseklik;
		cout << "\nÇatý yüksekliði: ";
		cin >> catiYukseklik;
		cout << "\nx: ";
		cin >> x;
		cout << "\ny: ";
		cin >> y;
		// Çatý çizilir ve gotoxy fonksiyonu ile istenilen kordinatlara gönderilir.
		for (int i = 0; i < catiYukseklik; i++) {
			for (int j = 0; j < catiYukseklik - i - 1; j++) {
				gotoxy(x + j, y + i);
				cout << " ";
			}
			for (int j = 0; j < genislik - 2 * (catiYukseklik - 1 - i); j++) {
				gotoxy(x + j + catiYukseklik - i - 1, y + i);
				cout << karakterCati;
			}
			for (int j = 0; j < catiYukseklik - i - 1; j++) {
				gotoxy(x + j, y + i);
				cout << " ";
			}
			cout << endl;
		}
	}
};

class Kat :public Cati {
public:
	char karakterKat = (char)219;
	//kat() fonksiyonunda çatýnýn altýna gelecek þekilde  kat çizilir.
	void kat() {
		// Evin tavaný çizilir.
		gotoxy(x, y + catiYukseklik);
		for (int i = 0; i < genislik; i++) {			
			cout << karakterKat;
		}
		// Evin zemini çizilir.
		gotoxy(x, y + catiYukseklik + evYukseklik - 1);
		for (int i = 0; i < genislik; i++) {
			cout << karakterKat;
		}
		// Evin sol duvarý çizilir.
		for (int i = 0; i < evYukseklik - 2; i++) {
			gotoxy(x, y + i + catiYukseklik + 1);
			cout << karakterKat;
		}
		// Evin sað duvarý çizilir.
		for (int i = 0; i < evYukseklik - 2; i++) {
			gotoxy(x + genislik - 1, y + i + catiYukseklik + 1);
			cout << karakterKat;
		}		
	}
};

class Kapi :public Kat {
public:	
	char karakterKapi = '#';

		void kapi() {
			int en = rand() % (genislik / 3) + 2;
			int boy = rand() % (evYukseklik / 2) + 3;
			// Kapý çizilir ve olmasý gereken yere yerleþtirilir. 
			for (int i = 0; i < boy; i++) {
				for (int j = 0; j < en; j++) {
					gotoxy(x + j + genislik / 2, y + evYukseklik + catiYukseklik + i - boy);
					cout << karakterKapi;
				}
				cout << endl;
			}
			cout << endl;
		}	
};

class Ev :public Kapi {
public:
	void evCiz() {
		cati();
		kat();
		kapi();
	}
};

int main(){
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	Ev ev;
	ev.evCiz();

	system("pause");
	return 0;
}