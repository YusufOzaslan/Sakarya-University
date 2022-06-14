#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <time.h>
using namespace std;

/**********************************************************************
**                      SAKARYA �N�VERS�TES�
**              B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                  B�LG�SAYAR M�HEND�SL��� B�L�M�
**                    PROGRAMLAMAYA G�R��� DERS�
**
**                  �DEV NUMARASI....: 2. �dev
**                  ��RENC� ADI......: Yusuf �zaslan
**                  ��RENC� NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. ��retim B grubu
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
	int catiYukseklik; // �at� y�ksekli�i.
	int evYukseklik; // Zeminden tavana kadar olan y�kseklik.
	int x;
	int y;

public:

	char karakterCati = '*';

	void cati(){
		cout << "Geni�lik: ";
		cin >> genislik;
		cout << "\nY�kseklik: ";
		cin >> evYukseklik;
		cout << "\n�at� y�ksekli�i: ";
		cin >> catiYukseklik;
		cout << "\nx: ";
		cin >> x;
		cout << "\ny: ";
		cin >> y;
		// �at� �izilir ve gotoxy fonksiyonu ile istenilen kordinatlara g�nderilir.
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
	//kat() fonksiyonunda �at�n�n alt�na gelecek �ekilde  kat �izilir.
	void kat() {
		// Evin tavan� �izilir.
		gotoxy(x, y + catiYukseklik);
		for (int i = 0; i < genislik; i++) {			
			cout << karakterKat;
		}
		// Evin zemini �izilir.
		gotoxy(x, y + catiYukseklik + evYukseklik - 1);
		for (int i = 0; i < genislik; i++) {
			cout << karakterKat;
		}
		// Evin sol duvar� �izilir.
		for (int i = 0; i < evYukseklik - 2; i++) {
			gotoxy(x, y + i + catiYukseklik + 1);
			cout << karakterKat;
		}
		// Evin sa� duvar� �izilir.
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
			// Kap� �izilir ve olmas� gereken yere yerle�tirilir. 
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