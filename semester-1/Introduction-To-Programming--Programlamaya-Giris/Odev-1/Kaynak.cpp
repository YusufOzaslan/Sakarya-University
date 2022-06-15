#include <iostream>
#include <locale.h>
using namespace std;

/**********************************************************************
**                      SAKARYA �N�VERS�TES�
**              B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                  B�LG�SAYAR M�HEND�SL��� B�L�M�
**                    PROGRAMLAMAYA G�R��� DERS�
**
**                  �DEV NUMARASI....: 1. �dev
**                  ��RENC� ADI......: Yusuf �zaslan
**                  ��RENC� NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. ��retim B grubu
**********************************************************************/

struct Zaman {
    int saat;
    int dakika;
    int saniye;
    long toplam_saniye;
};

int main()
{
    setlocale(LC_ALL, "Turkish");

    Zaman zaman;
    char girilenZaman[20];
    cout << "Saat:Dakika:Saniye �eklinde zaman� giriniz: ";
    cin >> girilenZaman;

    zaman.saat = atoi(girilenZaman);
    int sayac1 = 0;
    int sayac2;

    //Girilen saatteki ilk girilen iki noktan�n ka��nc� eleman oldu�u bulunur.
    while (girilenZaman[sayac1] != ':') {
        sayac1 += 1;
    }

    sayac2 = sayac1 + 1;

    //Girilen saatteki ikinci girilen iki noktan�n ka��nc� eleman oldu�u bulunur.
    while (girilenZaman[sayac2] != ':') {
        sayac2 += 1;
    }
    // sayac1 1. iki nokta n�n yeridir. sayac2 2. iki noktan�n yeridir.

    char diziDakika[20];

    //girilenZaman dizisindeki 1. iki noktadan sonraki elemanlar diziDakikaya aktar�l�r.
    for (int i = 0; i < 20; i++) {
        diziDakika[i] = girilenZaman[sayac1 + 1];
        sayac1 += 1;
    }

    zaman.dakika = atoi(diziDakika);
    char diziSaniye[20];

    //girilenZaman dizisindeki 2. iki noktadan sonraki elemanlar diziSaniyeye aktar�l�r.
    for (int i = 0; i < 20; i++) {
        diziSaniye[i] = girilenZaman[sayac2 + 1];
        sayac2 += 1;
    }

    zaman.saniye = atoi(diziSaniye);

    //�� ko�ul da do�ruysa toplam saniye hesaplan�r.
    if (zaman.saat < 24 && zaman.saat >= 0) {
        if (zaman.dakika < 60 && zaman.dakika >= 0) {
            if (zaman.saniye < 60 && zaman.saniye >= 0) {
                zaman.toplam_saniye = zaman.saat * 3600 + zaman.dakika * 60 + zaman.saniye;
                cout << "\nSaniye olarak hesaplanan de�er: " << zaman.toplam_saniye << endl;
            }
        }
    }
    cout << endl;
    //Girilen saatin uygun aral�kta olup olmad��na bak�l�r.
    if (zaman.saat >= 24 || zaman.saat < 0)
        cout << "Girilen saat de�eri: " << zaman.saat << " yanl�� girilmi�tir. \n" << endl;

    //Girilen dakikan�n uygun aral�kta olup olmad��na bak�l�r.
    if (zaman.dakika >= 60 || zaman.dakika < 0)
        cout << "Girilen dakika de�eri: " << zaman.dakika << " yanl�� girilmi�tir. \n" << endl;

    //Girilen saniyenin uygun aral�kta olup olmad��na bak�l�r.
    if (zaman.saniye >= 60 || zaman.saniye < 0)
        cout << "Girilen saniye de�eri: " << zaman.saniye << " yanl�� girilmi�tir. \n" << endl;

    cout << "PROGRAM SONU" << endl;


    system("pause");
    return 0;
}