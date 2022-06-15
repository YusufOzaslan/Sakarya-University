#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h>
#include <iomanip>
using namespace std;

/**********************************************************************
**                      SAKARYA �N�VERS�TES�
**              B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                  B�LG�SAYAR M�HEND�SL��� B�L�M�
**                    PROGRAMLAMAYA G�R��� DERS�
**
**                  �DEV NUMARASI....: Proje �devi
**                  ��RENC� ADI......: Yusuf �zaslan
**                  ��RENC� NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. ��retim B grubu
**********************************************************************/


int main(){
	setlocale(LC_ALL, "Turkish");	

	string kullanici;             
	string sifre;
	char girisSaat[10];
	char dakika[5];
	int girisSaatt;
	int girisdakika;
	string sifreKontrol;
	string idKontrol;

	ofstream yazmaDosyasi;
	ifstream okumaDosyasi;

	yazmaDosyasi.open("Kullanicilar.txt");
	yazmaDosyasi << "sakarya ";//kullan�c� ad� 1
	yazmaDosyasi << "universitesi\n";//parola 1
	yazmaDosyasi << "bilgisayar	";//kullan�c� ad� 2
	yazmaDosyasi << "muhendisligi\n";//parola 2
	yazmaDosyasi << "yusuf	";//kullan�c� ad� 3
	yazmaDosyasi << "ozaslan\n";//parola 3
	yazmaDosyasi.close();
	int deger = 1;
	// Sisteme giri� yapabilmesi i�in kullan�c�dan bilgi istenir.
	do {
		cout << "   Kullan�c� ad�.....................: ";
		cin >> kullanici;
		cout << endl;
		cout << "   Kullan�c� �ifre ..................: ";
		cin >> sifre;
		cout << endl;
		okumaDosyasi.open("Kullanicilar.txt");
		// �ifre ve kullan�c� ad� kontrol edilir.
		while (!okumaDosyasi.eof())
		{
			okumaDosyasi >> sifreKontrol >> idKontrol;
			if (kullanici == sifreKontrol && sifre == idKontrol) {
				deger = 0;
			}
		}
		okumaDosyasi.close();

		if (deger != 0) {// �ifre kontrol�
			cout << " Kullan�c� ad� veya �ifre hatal�\n " << endl;
		}if (!deger) {
			do {
				do {// Sisteme giri� saati saat:dakika �eklinde girilmeli
					cout << "   Sisteme giri� saati(saat:dakika)..: ";
					cin >> girisSaat;
				} while (!(girisSaat[2] == ':' && girisSaat[5] == '\0'));
				girisSaatt = atoi(girisSaat);
				dakika[0] = girisSaat[3];
				dakika[1] = girisSaat[4];
				girisdakika = atoi(dakika);
				if (!(girisSaatt < 24 && girisdakika < 60)) {
					cout << "   *HATALI SAAT G�R���* " << endl;
				}
			} while (!(girisSaatt < 24 && girisdakika < 60));
			cout << endl;
		}
	} while (deger);// �ifre ve kullan�c� ad� do�ru girildiyse d�ng�den ��kar

	cout << endl;

	char devam = 'e';
	do {// ��lem bittikten sonra kullan�c�ya tekrar men�ye gidip gitmeyece�i sorulur.
		int secim;
		// Yap�lmak istenen i�lem se�ilir.
		do
		{
			cout << "   -----------MEN�-----------\n " << endl;
			cout << "   1) Okuyucu kayd� " << endl;
			cout << "   2) Okuyucu kayd� g�ncelleme  " << endl;
			cout << "   3) Okuyucu silme " << endl;
			cout << "   4) Okuyucu �zerindeki kitaplar listesi " << endl;
			cout << "   5) Okuyucu kitap �d�n� alma  " << endl;
			cout << "   6) Okuyucu kitap geri d�nd�rme " << endl;
			cout << "   7) Kitap ekleme " << endl;
			cout << "   8) Kitap silme " << endl;
			cout << "   9) Kitap d�zeltme " << endl;
			cout << "   0) programdan ��k�� " << endl;
			cin >> secim;
			// yukar�da verilenlerden farkl� bir se�enek se�ilmesine izin verilmez.
			if (secim != 1
				&& secim != 2 && secim != 3
				&& secim != 4 && secim != 5
				&& secim != 6 && secim != 7
				&& secim != 8 && secim != 9
				&& secim != 0) {
				cout << " \n\n		GE�ERL� SE�ENEKLERDEN B�R�N� SE��N�Z\n " << endl;
			}

		} while (secim != 1	&& secim != 2 && secim != 3 && secim != 4 && secim != 5
			&& secim != 6 && secim != 7 && secim != 8 && secim != 9 && secim != 0);

		string TC; 
		string isim;
		string soyIsim;
		string uyeNo;
		string telefon;
		string dTarih;
		string gorev;
		string kSayisi;		


		if (secim == 1) {// Okuyucu kayd�
			cout << endl;
			do {
				cout << "   TC NO...................: ";
				cin >> TC;
				if (TC.length() != 11)
					cout << "\n	*G�R�LEN TC NO HATALI* \n " << endl;
			} while (TC.length() != 11);
			cout << endl;
			cout << "   ADI.....................: ";
			cin >> isim;
			cout << endl;
			cout << "   SOYADI..................: ";
			cin >> soyIsim;
			cout << endl;
			cout << "   �YE NO..................: ";
			cin >> uyeNo;
			cout << endl;
			cout << "   TELEFON.................: ";
			cin >> telefon;
			cout << endl;
			cout << "   DO�UM TAR�H�............: ";
			cin >> dTarih;
			cout << endl;
			cout << "   G�REV�..................: ";
			cin >> gorev;
			cout << endl;
			cout << "   ALAB�LECE�� K�TAP SAYISI.: ";
			cin >> kSayisi;
			cout << endl;
			cout << "\n		*KAYIT YAPILDI*\n " << endl;

			yazmaDosyasi.open("Okuyucular.txt", ios::app);
			yazmaDosyasi << TC << ' ' << isim << ' '
				<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
				<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
			yazmaDosyasi.close();
		}

		if (secim == 2) {// Okuyucu kayd� g�ncelleme.
			int guncellendiMi = 1;
			string arananString;
			cout << "   Kayd� g�ncellenecek ki�inin TC no: ";
			cin >> arananString;
			okumaDosyasi.open("Okuyucular.txt");
			yazmaDosyasi.open("gecici.txt");
			// Okuyucu listesini tarar.
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {

				if (arananString == TC) { // D�zeltilecek kay�t aranan string ise
					cout << "\n   Kay�tl� Olan Bilgiler " << endl;
					cout << endl;
					cout << "   TC NO...................: " << TC;
					cout << endl;
					cout << "   ADI.....................: " << isim;
					cout << endl;
					cout << "   SOYADI..................: " << soyIsim;
					cout << endl;
					cout << "   �YE NO..................: " << uyeNo;
					cout << endl;
					cout << "   TELEFON.................: " << telefon;
					cout << endl;
					cout << "   DO�UM TAR�H�............: " << dTarih;
					cout << endl;
					cout << "   G�REV�..................: " << gorev;
					cout << endl;
					cout << "   ALAB�LECE�� K�TA SAYISI.: " << kSayisi;
					cout << endl;
					cout << "   \nG�ncelleme i�in yeni bilgileri giriniz " << endl;
					cout << endl;
					do {
						cout << "   TC NO...................: ";
						cin >> TC;
						if (TC.length() != 11)// TC numaras�n�n 11 haneden farkl� girilmesini engeller
							cout << "\n	*G�R�LEN TC NO HATALI* \n " << endl;
					} while (TC.length() != 11);
					cout << endl;
					cout << "   ADI.....................: "; cin >> isim;					
					cout << endl;
					cout << "   SOYADI..................: "; cin >> soyIsim;				
					cout << endl;
					cout << "   �YE NO..................: "; cin >> uyeNo;					
					cout << endl;
					cout << "   TELEFON.................: "; cin >> telefon;					
					cout << endl;
					cout << "   DO�UM TAR�H�............: "; cin >> dTarih;					
					cout << endl;
					cout << "   G�REV�..................: "; cin >> gorev;					
					cout << endl;
					cout << "   ALAB�LECE�� K�TA SAYISI.: "; cin >> kSayisi;					
					cout << endl;
					// G�ncellenen bilgi ge�ici dosyaya yaz�l�r
					yazmaDosyasi << TC << ' ' << isim << ' '
						<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
						<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
					// G�ncelleme ba�ar�l� olursa ekrana yazd�r�r
					if (yazmaDosyasi.is_open()) {
						cout << "\n		*G�NCELLEME BA�ARIYLA TAMAMLANDI*\n " << endl;
						guncellendiMi = 0;
					}
				}
				else {// G�ncelleme yap�lmayan okuyucu kay�tlar� ge�ici listeye aktar�l�r
					yazmaDosyasi << TC << ' ' << isim << ' '
						<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
						<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("Okuyucular.txt");
			rename("gecici.txt", "Okuyucular.txt");
			// G�ncelleme yap�lacak ki�inin kayd� kontrol edilir
			if (guncellendiMi) {
				cout << "\n		*E�LE�ME BULUNAMADI*\n	" << endl;
			}
		}
		string ISBN;
		string kitapIsmi;
		string yazarAd;
		string yazarSoyad;
		string konu;
		string tur;
		string sayfaSayisi;

		string onducTarih;
		string donusTarih;

		ofstream yazmaDosyasi2;
		ifstream okumaDosyasi2;

		if (secim == 3) {// Okuyucu silme. E�er �d�n� al�nan kitaplar varsa ekrana yazd�r�r ve �d�n� listesinden silinir
			int silindiMi = 1;
			string aranan;
			string Tc;
			cout << "   Silinecek ki�inin TC no: ";
			cin >> aranan;
			okumaDosyasi.open("Okuyucular.txt");
			okumaDosyasi2.open("Odunc.txt");
			yazmaDosyasi.open("geciciOkuyucu.txt");
			yazmaDosyasi2.open("geciciOdunc.txt");
			// Okuyucu listesini tarar
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {

				if (aranan == TC) {// Aranan ki�inin TC numaras� okuyucu listesinden biriyle e�le�ir ise...
					cout << "\n   Okuyucuya kay�tl� kitaplar�n ISBN numaralar� " << endl;
					int sayac = 1;
					// �d�n� listesini tarar
					while (okumaDosyasi2 >> Tc >> ISBN >> onducTarih >> donusTarih) {
						if (aranan == Tc) {
							cout << sayac << ". " << ISBN << endl;
							sayac += 1;
						}
						else {
							yazmaDosyasi2 << Tc << ' ' << ISBN << ' ' << onducTarih << ' ' << donusTarih << endl;
						}
					}
				}
				// Aranan ki�inin TC si e�le�ir ise okuyucu, Okuyucu listesinden silinir
				if (aranan == TC) {
					cout << "\n		*OKUYUCU S�L�ND�*\n ";
					silindiMi = 0;
				}
				// E�le�mesi bulunmayan okuyucular ge�ici dosyaya yaz�l�r
				else {
					yazmaDosyasi << TC << ' ' << isim << ' '
						<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
						<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			okumaDosyasi2.close();
			yazmaDosyasi2.close();
			remove("Okuyucular.txt");
			rename("geciciOkuyucu.txt", "Okuyucular.txt");
			remove("Odunc.txt");
			rename("geciciOdunc.txt", "Odunc.txt");
			//Aranan okuyucu kayd� yok ise
			if (silindiMi) {
				cout << "\n		*E�LE�ME BULUNAMADI*\n	" << endl;
			}
		}		

		if (secim == 4) {// Okuyucu �zerindeki kitap listesini g�sterir.
			int kntrl = 1;
			string aarananTC;
			cout << "\n   Okuyucu TC no: "; cin >> aarananTC;
			okumaDosyasi.open("Odunc.txt");
			// �d�n� verilen kitaplar listesi taran�r ve kay�tl�ysa bilgilerini ekrana ��kar�r
			while (okumaDosyasi >> TC >> ISBN >> onducTarih >> donusTarih) {
				if (aarananTC == TC) {
					kntrl = 0;
					cout << endl;
					cout << "   Okuyucunun TC no..............: " << TC;
					cout << endl;
					cout << "   Okuyucudaki kitab�n ISBN NO...: " << ISBN;
					cout << endl;
					cout << "   �d�n� Tarihi..................: " << onducTarih;
					cout << endl;
					cout << "   D�n�� Tarihi..................: " << donusTarih;
					cout << endl;
				}
			}
			okumaDosyasi.close();
			// Kay�t bulunamazsa ekran ��kt�s� d�nd�r�r
			if (kntrl) {
				cout << "\n		*KAYIT BULUNAMADI*\n	" << endl;
			}
		}

		if (secim == 5) {// Kitap �d�n� verme.
			string araniyorTc;
			string araniyorIsbn;
			int dogrulamaTc = 1;
			int dogrulamaIsbn = 1;
			cout << "\n   Kitab� alacak olan �yenini TC no: "; cin >> araniyorTc;
			cout << "\n   Al�nacak kitab�n ISBN: "; cin >> araniyorIsbn;
			okumaDosyasi.open("Okuyucular.txt");
			okumaDosyasi2.open("Kitaplar.txt");
			yazmaDosyasi.open("Odunc.txt",ios::app);
			// Okuyucular listesi taran�r e�er okuyucu listede kay�tl� ise ISBN numaras�n� girilir
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {
				if (araniyorTc == TC) {
					dogrulamaTc = 0;
					// Kitaplar listesi taran�r girilen ISBN numaras� kay�tl� ise �d�n� listesine eklenir
					while (okumaDosyasi2 >> ISBN >> kitapIsmi >> yazarAd >>
						yazarSoyad >> konu >> tur >> sayfaSayisi) {
						if (araniyorIsbn == ISBN) {
							dogrulamaIsbn = 0;
							cout << "\n   Kitab�n verili� tarihi giriniz: "; cin >> onducTarih;
							cout << "\n   Kitab�n d�n�� tarihini giriniz: "; cin >> donusTarih;
							// Ki�i bilgisi kitap bilgisi, �d�n� ve iade tarihleri kay�t edilir.
							yazmaDosyasi << TC << ' ' << ISBN << ' ' << onducTarih << ' ' << donusTarih << endl;
							cout << "\n\n		*KAYIT ALINDI*\n	" << endl;
						}
					}					
				}
			}
			// TC kay�tl� de�il ise e�le�me bulunamad� yaz�s�n� d�nd�r�r
			if (dogrulamaTc) {
				dogrulamaIsbn = 0;
				cout << "\n		*TC NO E�LE�MES� BULUNAMADI*\n	" << endl;
			}
			// TC kay�tl� fakat ISBN numaras� kay�tl� kitap yoksa sadece kitab�n bulunamad��� yaz�s�n� d�nd�r�r
			if (dogrulamaIsbn) {
				cout << "\n		*BU K�TAP K�T�PHANEDE BULUNMAMAKTADIR*\n	" << endl;
			}
			okumaDosyasi.close();
			okumaDosyasi2.close();
			yazmaDosyasi.close();
		}

		if (secim == 6) {//Kitap geri d�nd�rme
			int kontrol = 1;
			string araniyorTc2;
			string araniyorIsbn2;
			int dogrulamaTc2 = 1;
			int dogrulamaIsbn2 = 1;
			cout << "\n   Kitap alan �yenini TC no: "; cin >> araniyorTc2;
			cout << "\n   Getirilen kitab�n ISBN: "; cin >> araniyorIsbn2;
			okumaDosyasi.open("Odunc.txt");
			yazmaDosyasi.open("geciciOdunc.txt");
			// �d�n� listesi taran�r, okuyucunun TC numaras� ve �d�n� al�nan ISBN numaras� ile kay�tl� olan kitap varsa �d�n� listesinden silinir
			while (okumaDosyasi >> TC >> ISBN >> onducTarih >> donusTarih) {
				if (araniyorTc2 == TC && araniyorIsbn2 == ISBN) {
					cout << "\n		*K�TAP �ADES� ALINDI*\n	" << endl;
					kontrol = 0;
				}
				else {
					yazmaDosyasi << TC << ' ' << ISBN << ' ' << onducTarih << ' ' << donusTarih << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			// Kay�t bulunamazsa
			if (kontrol) {
				cout << "\n		*KAYIT BULUNAMADI*\n	" << endl;
			}
			remove("Odunc.txt");
			rename("geciciOdunc.txt", "Odunc.txt");
		}

		if (secim == 7) {// Kitap kayd�
			cout << endl;
			cout << "   ISBN NO............: ";
			cin >> ISBN;
			cout << endl;
			cout << "   K�TAP ADI..........: ";
			cin >> kitapIsmi;
			cout << endl;
			cout << "   YAZAR ADI..........: ";
			cin >> yazarAd;
			cout << endl;
			cout << "   YAZAR SOYAD........: ";
			cin >> yazarSoyad;
			cout << endl;
			cout << "   KONU...............: ";
			cin >> konu;
			cout << endl;
			cout << "   K�TABIN T�R�.......: ";
			cin >> tur;
			cout << endl;
			cout << "   SAYFA SAYISI.......: ";
			cin >> sayfaSayisi;
			cout << endl;
			cout << "\n		*K�TAP EKLEND�*\n " << endl;
			yazmaDosyasi.open("Kitaplar.txt", ios::app);
			yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
				<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
				<< tur << ' ' << sayfaSayisi << endl;
			yazmaDosyasi.close();
		}

		if (secim == 8) {// Kitap silme
			int silindiMI = 1;
			string arananIsbn;
			cout << "   Silinecek kitap i�in ISBN no giriniz: ";
			cin >> arananIsbn;
			okumaDosyasi.open("Kitaplar.txt");
			yazmaDosyasi.open("gecici.txt");
			// kitaplar listesini tarar
			while (okumaDosyasi >> ISBN >> kitapIsmi >> yazarAd >>
				yazarSoyad >> konu >> tur >> sayfaSayisi) {
				// Aranan kitab�n ISBN numaras� e�le�ir ise kitap Kitaplar listesinden silinir
				if (arananIsbn == ISBN) {
					cout << "\n		*K�TAP KAYDI S�L�ND�*\n ";
					silindiMI = 0;
				}
				else {// E�le�meyen kitaplar ge�ici listeye aktar�l�r. E�le�en aktar�lmaz
					yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
						<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
						<< tur << ' ' << sayfaSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("Kitaplar.txt");
			rename("gecici.txt", "Kitaplar.txt");
			//Aranan kitap kayd� yok ise
			if (silindiMI) {
				cout << "\n		*E�LE�ME BULUNAMADI*\n	" << endl;
			}
		}

		if (secim == 9) {// Kitap d�zeltme
			int duzenlendiMi = 1;
			string arananKitap;
			cout << "   \nD�zenlenecek kitap i�in ISBN giriniz: ";
			cin >> arananKitap;
			okumaDosyasi.open("Kitaplar.txt");
			yazmaDosyasi.open("gecici.txt");
			// Okuyucu listesini tarar
			while (okumaDosyasi >> ISBN >> kitapIsmi >> yazarAd 
				>> yazarSoyad >> konu >> tur >> sayfaSayisi) {
				// D�zeltilecek kay�t bulunur
				if (arananKitap == ISBN) { 
					cout << "\n   Kay�tl� Olan Kitap Bilgiler " << endl;
					cout << endl;
					cout << "   ISBN NO............: " << ISBN;
					cout << endl;
					cout << "   K�TAP ADI..........: " << kitapIsmi;
					cout << endl;
					cout << "   YAZAR ADI..........: " << yazarAd;
					cout << endl;
					cout << "   YAZAR SOYAD........: " << yazarSoyad;
					cout << endl;
					cout << "   KONU...............: " << konu;
					cout << endl;
					cout << "   K�TABIN T�R�.......: " << tur;
					cout << endl;
					cout << "   SAYFA SAYISI.......: " << sayfaSayisi;
					cout << endl;
					cout << endl;
					cout << "   \nKitab�n yeni bilgilerini giriniz " << endl;
					cout << endl;
					cout << "   ISBN NO............: " ; cin >> ISBN;
					cout << endl;
					cout << "   K�TAP ADI..........: " ; cin >> kitapIsmi;
					cout << endl;
					cout << "   YAZAR ADI..........: " ; cin >> yazarAd;
					cout << endl;
					cout << "   YAZAR SOYAD........: " ; cin >> yazarSoyad;
					cout << endl;
					cout << "   KONU...............: " ; cin >> konu;
					cout << endl;
					cout << "   K�TABIN T�R�.......: " ; cin >> tur;
					cout << endl;
					cout << "   SAYFA SAYISI.......: " ; cin >> sayfaSayisi;
					cout << endl;
					cout << endl;
					yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
						<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
						<< tur << ' ' << sayfaSayisi << endl;
					// Yeni bilgiler dosyaya yaz�ld� ise dosya yazmaDosya.is_open 1 d�ner
					if (yazmaDosyasi.is_open()) {
						cout << "\n   *K�TAP D�ZENLEND�*\n " << endl;
						duzenlendiMi = 0;
					}
				}
				else {
					yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
						<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
						<< tur << ' ' << sayfaSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("Kitaplar.txt");
			rename("gecici.txt", "Kitaplar.txt");
			// Kay�t yok ise ekrana e�le�me bulunamad� yaz�s�n� d�nd�r�r
			if (duzenlendiMi) {
				cout << "\n		*E�LE�ME BULUNAMADI*\n	" << endl;
			}
		}
		if (secim == 0) {
			break;
		}
		do {// kullan�c� programdan ��kmak itemezse program kapanmaz
			cout << "   \n  Men�ye d�nmek ister misiniz? EVET (e) / HAYIR (h) :  ";
			cin >> devam;
			cout << endl;
		} while (!(devam == 'e' || devam == 'h'));
	}while (devam!='h');

	char cikisSaat[10];
	char cdakika[5];
	int cikisSaatt;
	int cikisdakika;
	do {
		do {// Sistemden ��k�� saati saat:dakika �eklinde girilmeli
			cout << "   Sistemden ��k�� saati:(saat:dakika)..: ";
			cin >> cikisSaat;
		} while (!(cikisSaat[2] == ':' && cikisSaat[5] == '\0'));
		cikisSaatt = atoi(cikisSaat);
		cdakika[0] = cikisSaat[3];
		cdakika[1] = cikisSaat[4];
		cikisdakika = atoi(cdakika);
		if (!(cikisSaatt < 24 && cikisdakika < 60)) {
			cout << "   *HATALI SAAT G�R���* " << endl;
		}
	} while (!(cikisSaatt < 24 && cikisdakika < 60));

	// Giri� ve ��k�� saatleri kaydedilir.
	fstream girisCikisSaatleri;
	girisCikisSaatleri.open("Giris cikis kaydi.txt", ios::out | ios::app);
	girisCikisSaatleri << kullanici;
	girisCikisSaatleri << setw(10) << girisSaatt << ':' << girisdakika;
	girisCikisSaatleri << setw(10) << cikisSaatt << ':' << cikisdakika << endl;
	girisCikisSaatleri.close();

	cout << "   *G�R�� �IKI� KAYDI ALINDI* " << endl;
	cout << "   *�IKI� BA�ARILI* " << endl;

	system("pause");
	return 0;
}