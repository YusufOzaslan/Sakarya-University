#include <iostream>
#include <locale.h>
using namespace std;

/**********************************************************************
**                      SAKARYA ÜNÝVERSÝTESÝ
**              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                    PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                  ÖDEV NUMARASI....: 1. Ödev
**                  ÖÐRENCÝ ADI......: Yusuf Özaslan
**                  ÖÐRENCÝ NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. Öðretim B grubu
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
    cout << "Saat:Dakika:Saniye þeklinde zamaný giriniz: ";
    cin >> girilenZaman;

    zaman.saat = atoi(girilenZaman);
    int sayac1 = 0;
    int sayac2;

    //Girilen saatteki ilk girilen iki noktanýn kaçýncý eleman olduðu bulunur.
    while (girilenZaman[sayac1] != ':') {
        sayac1 += 1;
    }

    sayac2 = sayac1 + 1;

    //Girilen saatteki ikinci girilen iki noktanýn kaçýncý eleman olduðu bulunur.
    while (girilenZaman[sayac2] != ':') {
        sayac2 += 1;
    }
    // sayac1 1. iki nokta nýn yeridir. sayac2 2. iki noktanýn yeridir.

    char diziDakika[20];

    //girilenZaman dizisindeki 1. iki noktadan sonraki elemanlar diziDakikaya aktarýlýr.
    for (int i = 0; i < 20; i++) {
        diziDakika[i] = girilenZaman[sayac1 + 1];
        sayac1 += 1;
    }

    zaman.dakika = atoi(diziDakika);
    char diziSaniye[20];

    //girilenZaman dizisindeki 2. iki noktadan sonraki elemanlar diziSaniyeye aktarýlýr.
    for (int i = 0; i < 20; i++) {
        diziSaniye[i] = girilenZaman[sayac2 + 1];
        sayac2 += 1;
    }

    zaman.saniye = atoi(diziSaniye);

    //Üç koþul da doðruysa toplam saniye hesaplanýr.
    if (zaman.saat < 24 && zaman.saat >= 0) {
        if (zaman.dakika < 60 && zaman.dakika >= 0) {
            if (zaman.saniye < 60 && zaman.saniye >= 0) {
                zaman.toplam_saniye = zaman.saat * 3600 + zaman.dakika * 60 + zaman.saniye;
                cout << "\nSaniye olarak hesaplanan deðer: " << zaman.toplam_saniye << endl;
            }
        }
    }
    cout << endl;
    //Girilen saatin uygun aralýkta olup olmadýðna bakýlýr.
    if (zaman.saat >= 24 || zaman.saat < 0)
        cout << "Girilen saat deðeri: " << zaman.saat << " yanlýþ girilmiþtir. \n" << endl;

    //Girilen dakikanýn uygun aralýkta olup olmadýðna bakýlýr.
    if (zaman.dakika >= 60 || zaman.dakika < 0)
        cout << "Girilen dakika deðeri: " << zaman.dakika << " yanlýþ girilmiþtir. \n" << endl;

    //Girilen saniyenin uygun aralýkta olup olmadýðna bakýlýr.
    if (zaman.saniye >= 60 || zaman.saniye < 0)
        cout << "Girilen saniye deðeri: " << zaman.saniye << " yanlýþ girilmiþtir. \n" << endl;

    cout << "PROGRAM SONU" << endl;


    system("pause");
    return 0;
}