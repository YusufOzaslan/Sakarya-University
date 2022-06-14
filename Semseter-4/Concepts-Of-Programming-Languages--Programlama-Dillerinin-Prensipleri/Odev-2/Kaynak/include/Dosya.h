/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#include "Kisi.h"
#include "windows.h"

struct DOSYA
{
	Kisi *kisiler; // pointer dizisi
	int *sansliSayilar;
	int kisiSayisi;
	int sayiSayisi;
	void (*Kisi_oku)(struct DOSYA *);
	void (*Sayi_oku)(struct DOSYA *);
	int (*Get_kisiSayisi)(struct DOSYA *);
	int (*Get_sayiSayisi)(struct DOSYA *);
	int *(*Get_sansliSayilar)(struct DOSYA *);
	Kisi *(*Get_kisiler)(struct DOSYA *);
	void (*delete)(struct DOSYA *);
};
typedef struct DOSYA *Dosya;

Dosya new_Dosya();
void Kisi_Oku(const Dosya);
void Sayi_Oku(const Dosya);
int Get_KisiSayisi(const Dosya);
int Get_SayiSayisi(const Dosya);
int *Get_SansliSayilar(const Dosya);
Kisi *Get_Kisiler(const Dosya);
void delete_Dosya(const Dosya);
#endif