/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"

struct KISI
{
	char *adSoyAd;
	double bakiye;
	double paraYatirmaOrani;
	int paraYatirdigiSayi;

	char *(*Get_adSoyAd)(struct KISI *);
	double (*Get_bakiye)(struct KISI *);
	double (*Get_paraYatirmaOrani)(struct KISI *);
	int (*Get_paraYatirdigiSayi)(struct KISI *);
	void (*Set_adSoyAd)(struct KISI *, char *);
	void (*Set_bakiye)(struct KISI *, double);
	void (*Set_paraYatirmaOrani)(struct KISI *, double);
	void (*Set_paraYatirdigiSayi)(struct KISI *, int);
	void (*delete)(struct KISI *);
};
typedef struct KISI *Kisi;

Kisi new_Kisi();

char *Get_AdSoyAd(const Kisi);
double Get_Bakiye(const Kisi);
double Get_ParaYatirmaOrani(const Kisi);
int Get_ParaYatirdigiSayi(const Kisi);
void Set_AdSoyAd(const Kisi, char *);
void Set_Bakiye(const Kisi, double);
void Set_ParaYatirmaOrani(const Kisi, double);
void Set_ParaYatirdigiSayi(const Kisi, int);
void delete_Kisi(const Kisi);
#endif