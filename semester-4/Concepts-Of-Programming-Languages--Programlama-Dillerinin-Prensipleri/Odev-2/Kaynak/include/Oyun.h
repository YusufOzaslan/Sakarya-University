/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#ifndef OYUN_H
#define OYUN_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Dosya.h"
#include "Kisi.h"

struct OYUN
{
	int turSayisi;
	double masaBakiye;
	Kisi enZenginKisi;
	Kisi *kisiler; // pointer dizisi
	int *sansliSayilar;
	int kisiSayisi;
	int sayiSayisi;

	void (*Basla)(struct OYUN *);
	void (*Set_kisiler)(struct OYUN *, Kisi *);
	void (*Set_sansliSayilar)(struct OYUN *, int *);
	void (*Set_kisiSayisi)(struct OYUN *, int);
	void (*Set_sayiSayisi)(struct OYUN *, int);
	void (*yazdir)(struct OYUN *, int);
	void (*delete)(struct OYUN *);
};
typedef struct OYUN *Oyun;

Oyun new_Oyun();
void Oyun_Baslat(const Oyun);
void Ekrana_Yaz(const Oyun, int);
void Set_Kisiler(const Oyun, Kisi *);
void Set_SansliSayilar(const Oyun, int *);
void Set_KisiSayisi(const Oyun, int);
void Set_SayiSayisi(const Oyun, int);
void delete_Oyun(const Oyun);
#endif