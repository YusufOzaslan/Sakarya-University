/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#include "Oyun.h"
Oyun new_Oyun()
{
	Oyun this_Oyun;
	this_Oyun = (Oyun)malloc(sizeof(struct OYUN));
	this_Oyun->masaBakiye = 0;
	this_Oyun->turSayisi = 0;
	this_Oyun->Basla = &Oyun_Baslat;
	this_Oyun->Set_kisiler = &Set_Kisiler;
	this_Oyun->Set_sansliSayilar = &Set_SansliSayilar;
	this_Oyun->yazdir = &Ekrana_Yaz;
	this_Oyun->delete = &delete_Oyun;

	return this_Oyun;
}

void Set_Kisiler(const Oyun this_Oyun, Kisi *kisiler)
{
	this_Oyun->kisiler = kisiler;
}

void Set_SansliSayilar(const Oyun this_Oyun, int *sayilar)
{
	this_Oyun->sansliSayilar = sayilar;
}

void Oyun_Baslat(const Oyun this_Oyun)
{
	Dosya dosya = new_Dosya();
	dosya->Kisi_oku(dosya);
	dosya->Sayi_oku(dosya);
	this_Oyun->Set_kisiler(this_Oyun, dosya->Get_kisiler(dosya));
	this_Oyun->Set_sansliSayilar(this_Oyun, dosya->Get_sansliSayilar(dosya));
	int kisiSayisi = dosya->Get_kisiSayisi(dosya);
	int sayiSayisi = dosya->Get_sayiSayisi(dosya);
	double araSayi = 0;
	// ilk olarak ilk okunan kişi en zengin olarak seçilir
	this_Oyun->enZenginKisi = this_Oyun->kisiler[0];
	int k = 0, i = 0;

	while (this_Oyun->kisiler[i] != NULL && i < kisiSayisi)
	{ // Parası olan varsa oyun devam eder
		if (this_Oyun->kisiler[i] != NULL)
		{
			for (int j = 0; j < kisiSayisi; j++)
			{ // oyuncular üzerinde gezilir
				if (this_Oyun->kisiler[j] != NULL)
				{ // parası olan oyuncular oyuna devam eder
					if (this_Oyun->kisiler[j]->paraYatirdigiSayi == this_Oyun->sansliSayilar[k])
					{ // Şanslı olan oyuncular para kazanır. Kasa para kaybeder
						this_Oyun->masaBakiye -= this_Oyun->kisiler[j]->Get_paraYatirmaOrani(this_Oyun->kisiler[j]) * this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]) * 9;
						araSayi = (this_Oyun->kisiler[j]->Get_paraYatirmaOrani(this_Oyun->kisiler[j]) * this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]) * 10) +
								  ((1 - this_Oyun->kisiler[j]->Get_paraYatirmaOrani(this_Oyun->kisiler[j])) * this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]));
						this_Oyun->kisiler[j]->Set_bakiye(this_Oyun->kisiler[j], araSayi);
					}
					else
					{ // Şanslı olmayan oyuncular para kaybeder. Kasa para kazanır
						this_Oyun->masaBakiye += this_Oyun->kisiler[j]->Get_paraYatirmaOrani(this_Oyun->kisiler[j]) * this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]);
						this_Oyun->kisiler[j]->bakiye -= this_Oyun->kisiler[j]->Get_paraYatirmaOrani(this_Oyun->kisiler[j]) * this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]);
					}
					if (this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]) > this_Oyun->enZenginKisi->Get_bakiye(this_Oyun->enZenginKisi))
					{
						this_Oyun->enZenginKisi = this_Oyun->kisiler[j];
					}
					if (this_Oyun->kisiler[j]->Get_bakiye(this_Oyun->kisiler[j]) < 1000)
					{ // Elenen kişilerin adresleri iade edilir.
						this_Oyun->kisiler[j]->delete (this_Oyun->kisiler[j]);
						this_Oyun->kisiler[j] = NULL;
					}
				}
			}
			this_Oyun->turSayisi++;
			this_Oyun->yazdir(this_Oyun, this_Oyun->sansliSayilar[k]);
			k = (k + 1) % (sayiSayisi);
		}
		if (this_Oyun->kisiler[i] == NULL)
		{ // Hiçbir oyuncuda para kalmayana kadar oyun devam eder
			i++;
			for (int m = i; m < kisiSayisi; m++)
			{ // Dizideki Null değerler için döngü yapılmaz. Index NULL değerler kadar atlatılır
				if (this_Oyun->kisiler[m] != NULL)
				{
					i = m;
					break;
				}
			}
		}
	}
	dosya->delete (dosya);
	free(dosya);
}

void Ekrana_Yaz(const Oyun this_Oyun, int sansliSayi)
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t###################################################\n\t\t\t\t\t###\t\tSANSLI SAYI:%d\t\t\t###", sansliSayi);
	printf("\n\t\t\t\t\t###################################################\n\t\t\t\t\t###################################################");
	printf("\n\t\t\t\t\t###\t\tTur:%d\t\t\t\t###", this_Oyun->turSayisi);
	printf("\n\t\t\t\t\t###\tMasa Bakiye:%.lf\t\t\t###\n\t\t\t\t\t###---------------------------------------------###", this_Oyun->masaBakiye);
	printf("\n\t\t\t\t\t###\t\tEN ZENGIN KISI\t\t\t###");
	printf("\n\t\t\t\t\t###\t\t%s\t\t\t###", this_Oyun->enZenginKisi->Get_adSoyAd(this_Oyun->enZenginKisi));
	printf("\n\t\t\t\t\t###\tBAKIYESI:%.lf\t\t\t\t###", this_Oyun->enZenginKisi->bakiye);
	printf("\n\t\t\t\t\t###\t\t\t\t\t\t###");
	printf("\n\t\t\t\t\t###################################################");
}

void delete_Oyun(const Oyun this_Oyun)
{
	if (this_Oyun == NULL)
		return;
	free(this_Oyun);
}
