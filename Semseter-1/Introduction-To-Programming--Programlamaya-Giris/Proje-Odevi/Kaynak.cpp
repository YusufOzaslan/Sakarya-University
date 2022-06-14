#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h>
#include <iomanip>
using namespace std;

/**********************************************************************
**                      SAKARYA ÜNÝVERSÝTESÝ
**              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                    PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                  ÖDEV NUMARASI....: Proje Ödevi
**                  ÖÐRENCÝ ADI......: Yusuf Özaslan
**                  ÖÐRENCÝ NUMARASI.: b201210033
**                  DERS GRUBU.......: 1. Öðretim B grubu
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
	yazmaDosyasi << "sakarya ";//kullanýcý adý 1
	yazmaDosyasi << "universitesi\n";//parola 1
	yazmaDosyasi << "bilgisayar	";//kullanýcý adý 2
	yazmaDosyasi << "muhendisligi\n";//parola 2
	yazmaDosyasi << "yusuf	";//kullanýcý adý 3
	yazmaDosyasi << "ozaslan\n";//parola 3
	yazmaDosyasi.close();
	int deger = 1;
	// Sisteme giriþ yapabilmesi için kullanýcýdan bilgi istenir.
	do {
		cout << "   Kullanýcý adý.....................: ";
		cin >> kullanici;
		cout << endl;
		cout << "   Kullanýcý þifre ..................: ";
		cin >> sifre;
		cout << endl;
		okumaDosyasi.open("Kullanicilar.txt");
		// Þifre ve kullanýcý adý kontrol edilir.
		while (!okumaDosyasi.eof())
		{
			okumaDosyasi >> sifreKontrol >> idKontrol;
			if (kullanici == sifreKontrol && sifre == idKontrol) {
				deger = 0;
			}
		}
		okumaDosyasi.close();

		if (deger != 0) {// Þifre kontrolü
			cout << " Kullanýcý adý veya þifre hatalý\n " << endl;
		}if (!deger) {
			do {
				do {// Sisteme giriþ saati saat:dakika þeklinde girilmeli
					cout << "   Sisteme giriþ saati(saat:dakika)..: ";
					cin >> girisSaat;
				} while (!(girisSaat[2] == ':' && girisSaat[5] == '\0'));
				girisSaatt = atoi(girisSaat);
				dakika[0] = girisSaat[3];
				dakika[1] = girisSaat[4];
				girisdakika = atoi(dakika);
				if (!(girisSaatt < 24 && girisdakika < 60)) {
					cout << "   *HATALI SAAT GÝRÝÞÝ* " << endl;
				}
			} while (!(girisSaatt < 24 && girisdakika < 60));
			cout << endl;
		}
	} while (deger);// Þifre ve kullanýcý adý doðru girildiyse döngüden çýkar

	cout << endl;

	char devam = 'e';
	do {// Ýþlem bittikten sonra kullanýcýya tekrar menüye gidip gitmeyeceði sorulur.
		int secim;
		// Yapýlmak istenen iþlem seçilir.
		do
		{
			cout << "   -----------MENÜ-----------\n " << endl;
			cout << "   1) Okuyucu kaydý " << endl;
			cout << "   2) Okuyucu kaydý güncelleme  " << endl;
			cout << "   3) Okuyucu silme " << endl;
			cout << "   4) Okuyucu üzerindeki kitaplar listesi " << endl;
			cout << "   5) Okuyucu kitap ödünç alma  " << endl;
			cout << "   6) Okuyucu kitap geri döndürme " << endl;
			cout << "   7) Kitap ekleme " << endl;
			cout << "   8) Kitap silme " << endl;
			cout << "   9) Kitap düzeltme " << endl;
			cout << "   0) programdan çýkýþ " << endl;
			cin >> secim;
			// yukarýda verilenlerden farklý bir seçenek seçilmesine izin verilmez.
			if (secim != 1
				&& secim != 2 && secim != 3
				&& secim != 4 && secim != 5
				&& secim != 6 && secim != 7
				&& secim != 8 && secim != 9
				&& secim != 0) {
				cout << " \n\n		GEÇERLÝ SEÇENEKLERDEN BÝRÝNÝ SEÇÝNÝZ\n " << endl;
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


		if (secim == 1) {// Okuyucu kaydý
			cout << endl;
			do {
				cout << "   TC NO...................: ";
				cin >> TC;
				if (TC.length() != 11)
					cout << "\n	*GÝRÝLEN TC NO HATALI* \n " << endl;
			} while (TC.length() != 11);
			cout << endl;
			cout << "   ADI.....................: ";
			cin >> isim;
			cout << endl;
			cout << "   SOYADI..................: ";
			cin >> soyIsim;
			cout << endl;
			cout << "   ÜYE NO..................: ";
			cin >> uyeNo;
			cout << endl;
			cout << "   TELEFON.................: ";
			cin >> telefon;
			cout << endl;
			cout << "   DOÐUM TARÝHÝ............: ";
			cin >> dTarih;
			cout << endl;
			cout << "   GÖREVÝ..................: ";
			cin >> gorev;
			cout << endl;
			cout << "   ALABÝLECEÐÝ KÝTAP SAYISI.: ";
			cin >> kSayisi;
			cout << endl;
			cout << "\n		*KAYIT YAPILDI*\n " << endl;

			yazmaDosyasi.open("Okuyucular.txt", ios::app);
			yazmaDosyasi << TC << ' ' << isim << ' '
				<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
				<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
			yazmaDosyasi.close();
		}

		if (secim == 2) {// Okuyucu kaydý güncelleme.
			int guncellendiMi = 1;
			string arananString;
			cout << "   Kaydý güncellenecek kiþinin TC no: ";
			cin >> arananString;
			okumaDosyasi.open("Okuyucular.txt");
			yazmaDosyasi.open("gecici.txt");
			// Okuyucu listesini tarar.
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {

				if (arananString == TC) { // Düzeltilecek kayýt aranan string ise
					cout << "\n   Kayýtlý Olan Bilgiler " << endl;
					cout << endl;
					cout << "   TC NO...................: " << TC;
					cout << endl;
					cout << "   ADI.....................: " << isim;
					cout << endl;
					cout << "   SOYADI..................: " << soyIsim;
					cout << endl;
					cout << "   ÜYE NO..................: " << uyeNo;
					cout << endl;
					cout << "   TELEFON.................: " << telefon;
					cout << endl;
					cout << "   DOÐUM TARÝHÝ............: " << dTarih;
					cout << endl;
					cout << "   GÖREVÝ..................: " << gorev;
					cout << endl;
					cout << "   ALABÝLECEÐÝ KÝTA SAYISI.: " << kSayisi;
					cout << endl;
					cout << "   \nGüncelleme için yeni bilgileri giriniz " << endl;
					cout << endl;
					do {
						cout << "   TC NO...................: ";
						cin >> TC;
						if (TC.length() != 11)// TC numarasýnýn 11 haneden farklý girilmesini engeller
							cout << "\n	*GÝRÝLEN TC NO HATALI* \n " << endl;
					} while (TC.length() != 11);
					cout << endl;
					cout << "   ADI.....................: "; cin >> isim;					
					cout << endl;
					cout << "   SOYADI..................: "; cin >> soyIsim;				
					cout << endl;
					cout << "   ÜYE NO..................: "; cin >> uyeNo;					
					cout << endl;
					cout << "   TELEFON.................: "; cin >> telefon;					
					cout << endl;
					cout << "   DOÐUM TARÝHÝ............: "; cin >> dTarih;					
					cout << endl;
					cout << "   GÖREVÝ..................: "; cin >> gorev;					
					cout << endl;
					cout << "   ALABÝLECEÐÝ KÝTA SAYISI.: "; cin >> kSayisi;					
					cout << endl;
					// Güncellenen bilgi geçici dosyaya yazýlýr
					yazmaDosyasi << TC << ' ' << isim << ' '
						<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
						<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
					// Güncelleme baþarýlý olursa ekrana yazdýrýr
					if (yazmaDosyasi.is_open()) {
						cout << "\n		*GÜNCELLEME BAÞARIYLA TAMAMLANDI*\n " << endl;
						guncellendiMi = 0;
					}
				}
				else {// Güncelleme yapýlmayan okuyucu kayýtlarý geçici listeye aktarýlýr
					yazmaDosyasi << TC << ' ' << isim << ' '
						<< soyIsim << ' ' << uyeNo << ' ' << telefon << ' '
						<< dTarih << ' ' << gorev << ' ' << kSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("Okuyucular.txt");
			rename("gecici.txt", "Okuyucular.txt");
			// Güncelleme yapýlacak kiþinin kaydý kontrol edilir
			if (guncellendiMi) {
				cout << "\n		*EÞLEÞME BULUNAMADI*\n	" << endl;
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

		if (secim == 3) {// Okuyucu silme. Eðer ödünç alýnan kitaplar varsa ekrana yazdýrýr ve ödünç listesinden silinir
			int silindiMi = 1;
			string aranan;
			string Tc;
			cout << "   Silinecek kiþinin TC no: ";
			cin >> aranan;
			okumaDosyasi.open("Okuyucular.txt");
			okumaDosyasi2.open("Odunc.txt");
			yazmaDosyasi.open("geciciOkuyucu.txt");
			yazmaDosyasi2.open("geciciOdunc.txt");
			// Okuyucu listesini tarar
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {

				if (aranan == TC) {// Aranan kiþinin TC numarasý okuyucu listesinden biriyle eþleþir ise...
					cout << "\n   Okuyucuya kayýtlý kitaplarýn ISBN numaralarý " << endl;
					int sayac = 1;
					// Ödünç listesini tarar
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
				// Aranan kiþinin TC si eþleþir ise okuyucu, Okuyucu listesinden silinir
				if (aranan == TC) {
					cout << "\n		*OKUYUCU SÝLÝNDÝ*\n ";
					silindiMi = 0;
				}
				// Eþleþmesi bulunmayan okuyucular geçici dosyaya yazýlýr
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
			//Aranan okuyucu kaydý yok ise
			if (silindiMi) {
				cout << "\n		*EÞLEÞME BULUNAMADI*\n	" << endl;
			}
		}		

		if (secim == 4) {// Okuyucu üzerindeki kitap listesini gösterir.
			int kntrl = 1;
			string aarananTC;
			cout << "\n   Okuyucu TC no: "; cin >> aarananTC;
			okumaDosyasi.open("Odunc.txt");
			// Ödünç verilen kitaplar listesi taranýr ve kayýtlýysa bilgilerini ekrana çýkarýr
			while (okumaDosyasi >> TC >> ISBN >> onducTarih >> donusTarih) {
				if (aarananTC == TC) {
					kntrl = 0;
					cout << endl;
					cout << "   Okuyucunun TC no..............: " << TC;
					cout << endl;
					cout << "   Okuyucudaki kitabýn ISBN NO...: " << ISBN;
					cout << endl;
					cout << "   Ödünç Tarihi..................: " << onducTarih;
					cout << endl;
					cout << "   Dönüþ Tarihi..................: " << donusTarih;
					cout << endl;
				}
			}
			okumaDosyasi.close();
			// Kayýt bulunamazsa ekran çýktýsý döndürür
			if (kntrl) {
				cout << "\n		*KAYIT BULUNAMADI*\n	" << endl;
			}
		}

		if (secim == 5) {// Kitap ödünç verme.
			string araniyorTc;
			string araniyorIsbn;
			int dogrulamaTc = 1;
			int dogrulamaIsbn = 1;
			cout << "\n   Kitabý alacak olan üyenini TC no: "; cin >> araniyorTc;
			cout << "\n   Alýnacak kitabýn ISBN: "; cin >> araniyorIsbn;
			okumaDosyasi.open("Okuyucular.txt");
			okumaDosyasi2.open("Kitaplar.txt");
			yazmaDosyasi.open("Odunc.txt",ios::app);
			// Okuyucular listesi taranýr eðer okuyucu listede kayýtlý ise ISBN numarasýný girilir
			while (okumaDosyasi >> TC >> isim >> soyIsim >>
				uyeNo >> telefon >> dTarih >> gorev >> kSayisi) {
				if (araniyorTc == TC) {
					dogrulamaTc = 0;
					// Kitaplar listesi taranýr girilen ISBN numarasý kayýtlý ise ödünç listesine eklenir
					while (okumaDosyasi2 >> ISBN >> kitapIsmi >> yazarAd >>
						yazarSoyad >> konu >> tur >> sayfaSayisi) {
						if (araniyorIsbn == ISBN) {
							dogrulamaIsbn = 0;
							cout << "\n   Kitabýn veriliþ tarihi giriniz: "; cin >> onducTarih;
							cout << "\n   Kitabýn dönüþ tarihini giriniz: "; cin >> donusTarih;
							// Kiþi bilgisi kitap bilgisi, ödünç ve iade tarihleri kayýt edilir.
							yazmaDosyasi << TC << ' ' << ISBN << ' ' << onducTarih << ' ' << donusTarih << endl;
							cout << "\n\n		*KAYIT ALINDI*\n	" << endl;
						}
					}					
				}
			}
			// TC kayýtlý deðil ise eþleþme bulunamadý yazýsýný döndürür
			if (dogrulamaTc) {
				dogrulamaIsbn = 0;
				cout << "\n		*TC NO EÞLEÞMESÝ BULUNAMADI*\n	" << endl;
			}
			// TC kayýtlý fakat ISBN numarasý kayýtlý kitap yoksa sadece kitabýn bulunamadýðý yazýsýný döndürür
			if (dogrulamaIsbn) {
				cout << "\n		*BU KÝTAP KÜTÜPHANEDE BULUNMAMAKTADIR*\n	" << endl;
			}
			okumaDosyasi.close();
			okumaDosyasi2.close();
			yazmaDosyasi.close();
		}

		if (secim == 6) {//Kitap geri döndürme
			int kontrol = 1;
			string araniyorTc2;
			string araniyorIsbn2;
			int dogrulamaTc2 = 1;
			int dogrulamaIsbn2 = 1;
			cout << "\n   Kitap alan üyenini TC no: "; cin >> araniyorTc2;
			cout << "\n   Getirilen kitabýn ISBN: "; cin >> araniyorIsbn2;
			okumaDosyasi.open("Odunc.txt");
			yazmaDosyasi.open("geciciOdunc.txt");
			// Ödünç listesi taranýr, okuyucunun TC numarasý ve ödünç alýnan ISBN numarasý ile kayýtlý olan kitap varsa ödünç listesinden silinir
			while (okumaDosyasi >> TC >> ISBN >> onducTarih >> donusTarih) {
				if (araniyorTc2 == TC && araniyorIsbn2 == ISBN) {
					cout << "\n		*KÝTAP ÝADESÝ ALINDI*\n	" << endl;
					kontrol = 0;
				}
				else {
					yazmaDosyasi << TC << ' ' << ISBN << ' ' << onducTarih << ' ' << donusTarih << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			// Kayýt bulunamazsa
			if (kontrol) {
				cout << "\n		*KAYIT BULUNAMADI*\n	" << endl;
			}
			remove("Odunc.txt");
			rename("geciciOdunc.txt", "Odunc.txt");
		}

		if (secim == 7) {// Kitap kaydý
			cout << endl;
			cout << "   ISBN NO............: ";
			cin >> ISBN;
			cout << endl;
			cout << "   KÝTAP ADI..........: ";
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
			cout << "   KÝTABIN TÜRÜ.......: ";
			cin >> tur;
			cout << endl;
			cout << "   SAYFA SAYISI.......: ";
			cin >> sayfaSayisi;
			cout << endl;
			cout << "\n		*KÝTAP EKLENDÝ*\n " << endl;
			yazmaDosyasi.open("Kitaplar.txt", ios::app);
			yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
				<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
				<< tur << ' ' << sayfaSayisi << endl;
			yazmaDosyasi.close();
		}

		if (secim == 8) {// Kitap silme
			int silindiMI = 1;
			string arananIsbn;
			cout << "   Silinecek kitap için ISBN no giriniz: ";
			cin >> arananIsbn;
			okumaDosyasi.open("Kitaplar.txt");
			yazmaDosyasi.open("gecici.txt");
			// kitaplar listesini tarar
			while (okumaDosyasi >> ISBN >> kitapIsmi >> yazarAd >>
				yazarSoyad >> konu >> tur >> sayfaSayisi) {
				// Aranan kitabýn ISBN numarasý eþleþir ise kitap Kitaplar listesinden silinir
				if (arananIsbn == ISBN) {
					cout << "\n		*KÝTAP KAYDI SÝLÝNDÝ*\n ";
					silindiMI = 0;
				}
				else {// Eþleþmeyen kitaplar geçici listeye aktarýlýr. Eþleþen aktarýlmaz
					yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
						<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
						<< tur << ' ' << sayfaSayisi << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("Kitaplar.txt");
			rename("gecici.txt", "Kitaplar.txt");
			//Aranan kitap kaydý yok ise
			if (silindiMI) {
				cout << "\n		*EÞLEÞME BULUNAMADI*\n	" << endl;
			}
		}

		if (secim == 9) {// Kitap düzeltme
			int duzenlendiMi = 1;
			string arananKitap;
			cout << "   \nDüzenlenecek kitap için ISBN giriniz: ";
			cin >> arananKitap;
			okumaDosyasi.open("Kitaplar.txt");
			yazmaDosyasi.open("gecici.txt");
			// Okuyucu listesini tarar
			while (okumaDosyasi >> ISBN >> kitapIsmi >> yazarAd 
				>> yazarSoyad >> konu >> tur >> sayfaSayisi) {
				// Düzeltilecek kayýt bulunur
				if (arananKitap == ISBN) { 
					cout << "\n   Kayýtlý Olan Kitap Bilgiler " << endl;
					cout << endl;
					cout << "   ISBN NO............: " << ISBN;
					cout << endl;
					cout << "   KÝTAP ADI..........: " << kitapIsmi;
					cout << endl;
					cout << "   YAZAR ADI..........: " << yazarAd;
					cout << endl;
					cout << "   YAZAR SOYAD........: " << yazarSoyad;
					cout << endl;
					cout << "   KONU...............: " << konu;
					cout << endl;
					cout << "   KÝTABIN TÜRÜ.......: " << tur;
					cout << endl;
					cout << "   SAYFA SAYISI.......: " << sayfaSayisi;
					cout << endl;
					cout << endl;
					cout << "   \nKitabýn yeni bilgilerini giriniz " << endl;
					cout << endl;
					cout << "   ISBN NO............: " ; cin >> ISBN;
					cout << endl;
					cout << "   KÝTAP ADI..........: " ; cin >> kitapIsmi;
					cout << endl;
					cout << "   YAZAR ADI..........: " ; cin >> yazarAd;
					cout << endl;
					cout << "   YAZAR SOYAD........: " ; cin >> yazarSoyad;
					cout << endl;
					cout << "   KONU...............: " ; cin >> konu;
					cout << endl;
					cout << "   KÝTABIN TÜRÜ.......: " ; cin >> tur;
					cout << endl;
					cout << "   SAYFA SAYISI.......: " ; cin >> sayfaSayisi;
					cout << endl;
					cout << endl;
					yazmaDosyasi << ISBN << ' ' << kitapIsmi << ' '
						<< yazarAd << ' ' << yazarSoyad << ' ' << konu << ' '
						<< tur << ' ' << sayfaSayisi << endl;
					// Yeni bilgiler dosyaya yazýldý ise dosya yazmaDosya.is_open 1 döner
					if (yazmaDosyasi.is_open()) {
						cout << "\n   *KÝTAP DÜZENLENDÝ*\n " << endl;
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
			// Kayýt yok ise ekrana eþleþme bulunamadý yazýsýný döndürür
			if (duzenlendiMi) {
				cout << "\n		*EÞLEÞME BULUNAMADI*\n	" << endl;
			}
		}
		if (secim == 0) {
			break;
		}
		do {// kullanýcý programdan çýkmak itemezse program kapanmaz
			cout << "   \n  Menüye dönmek ister misiniz? EVET (e) / HAYIR (h) :  ";
			cin >> devam;
			cout << endl;
		} while (!(devam == 'e' || devam == 'h'));
	}while (devam!='h');

	char cikisSaat[10];
	char cdakika[5];
	int cikisSaatt;
	int cikisdakika;
	do {
		do {// Sistemden çýkýþ saati saat:dakika þeklinde girilmeli
			cout << "   Sistemden çýkýþ saati:(saat:dakika)..: ";
			cin >> cikisSaat;
		} while (!(cikisSaat[2] == ':' && cikisSaat[5] == '\0'));
		cikisSaatt = atoi(cikisSaat);
		cdakika[0] = cikisSaat[3];
		cdakika[1] = cikisSaat[4];
		cikisdakika = atoi(cdakika);
		if (!(cikisSaatt < 24 && cikisdakika < 60)) {
			cout << "   *HATALI SAAT GÝRÝÞÝ* " << endl;
		}
	} while (!(cikisSaatt < 24 && cikisdakika < 60));

	// Giriþ ve çýkýþ saatleri kaydedilir.
	fstream girisCikisSaatleri;
	girisCikisSaatleri.open("Giris cikis kaydi.txt", ios::out | ios::app);
	girisCikisSaatleri << kullanici;
	girisCikisSaatleri << setw(10) << girisSaatt << ':' << girisdakika;
	girisCikisSaatleri << setw(10) << cikisSaatt << ':' << cikisdakika << endl;
	girisCikisSaatleri.close();

	cout << "   *GÝRÝÞ ÇIKIÞ KAYDI ALINDI* " << endl;
	cout << "   *ÇIKIÞ BAÞARILI* " << endl;

	system("pause");
	return 0;
}