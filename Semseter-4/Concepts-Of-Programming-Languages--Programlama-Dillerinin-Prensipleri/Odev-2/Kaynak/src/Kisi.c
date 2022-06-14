/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#include "Kisi.h"
#include "Oyun.h"
Kisi new_Kisi()
{
	Kisi this_Kisi;
	this_Kisi = (Kisi)malloc(sizeof(struct KISI));

	this_Kisi->Get_adSoyAd = &Get_AdSoyAd;
	this_Kisi->Get_bakiye = &Get_Bakiye;
	this_Kisi->Get_paraYatirmaOrani = &Get_ParaYatirmaOrani;
	this_Kisi->Get_paraYatirdigiSayi = &Get_ParaYatirdigiSayi;
	this_Kisi->Set_adSoyAd = &Set_AdSoyAd;
	this_Kisi->Set_bakiye = &Set_Bakiye;
	this_Kisi->Set_paraYatirmaOrani = &Set_ParaYatirmaOrani;
	this_Kisi->Set_paraYatirdigiSayi = &Set_ParaYatirdigiSayi;
	this_Kisi->delete = &delete_Kisi;
	return this_Kisi;
}

char *Get_AdSoyAd(const Kisi this_Kisi)
{
	return this_Kisi->adSoyAd;
}

double Get_Bakiye(const Kisi this_Kisi)
{
	return this_Kisi->bakiye;
}

double Get_ParaYatirmaOrani(const Kisi this_Kisi)
{
	return this_Kisi->paraYatirmaOrani;
}

int Get_ParaYatirdigiSayi(const Kisi this_Kisi)
{
	return this_Kisi->paraYatirdigiSayi;
}

void Set_AdSoyAd(const Kisi this_Kisi, char *isim)
{
	this_Kisi->adSoyAd = isim;
}

void Set_Bakiye(const Kisi this_Kisi, double bakiye)
{
	this_Kisi->bakiye = bakiye;
}

void Set_ParaYatirmaOrani(const Kisi this_Kisi, double pyo)
{
	this_Kisi->paraYatirmaOrani = pyo;
}

void Set_ParaYatirdigiSayi(const Kisi this_Kisi, int pys)
{
	this_Kisi->paraYatirdigiSayi = pys;
}
void delete_Kisi(const Kisi this_Kisi)
{
	if (this_Kisi == NULL)
		return;
	free(this_Kisi->adSoyAd);
	free(this_Kisi);
}