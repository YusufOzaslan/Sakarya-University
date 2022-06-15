/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#include "Dosya.h"
Dosya new_Dosya()
{
	Dosya this_Dosya;
	this_Dosya = (Dosya)malloc(sizeof(struct DOSYA));
	this_Dosya->Kisi_oku = &Kisi_Oku;
	this_Dosya->Sayi_oku = &Sayi_Oku;
	this_Dosya->Get_kisiSayisi = &Get_KisiSayisi;
	this_Dosya->Get_sayiSayisi = &Get_SayiSayisi;
	this_Dosya->Get_sansliSayilar = &Get_SansliSayilar;
	this_Dosya->Get_kisiler = &Get_Kisiler;
	this_Dosya->delete = &delete_Dosya;

	return this_Dosya;
}

int Get_KisiSayisi(const Dosya this_Dosya)
{
	return this_Dosya->kisiSayisi;
}

int Get_SayiSayisi(const Dosya this_Dosya)
{
	return this_Dosya->sayiSayisi;
}

int *Get_SansliSayilar(const Dosya this_Dosya)
{
	return this_Dosya->sansliSayilar;
}

Kisi *Get_Kisiler(const Dosya this_Dosya)
{
	return this_Dosya->kisiler;
}

void Kisi_Oku(const Dosya this_Dosya)
{
	FILE *filePointer;
	char line[50], isim[20], *charPointer;
	int i, hashCounter, kisiSayac = 0, satirSayisi = 0;
	double sayi;
	filePointer = fopen("Kisiler.txt", "r");
	if (filePointer != NULL)
	{
		while (fgets(line, sizeof(line), filePointer))
		{ // Kisi sayısı bulunur
			satirSayisi++;
		}
		this_Dosya->kisiler = malloc(sizeof(Kisi) * satirSayisi);
		this_Dosya->kisiSayisi = satirSayisi;
	}
	else
	{
		printf("Dosya Yolu Bulunamadi");
	}
	fclose(filePointer);

	filePointer = fopen("Kisiler.txt", "r");
	if (filePointer != NULL)
	{
		while (fgets(line, sizeof(line), filePointer))
		{ // Kisi dosyası okunur
			// Her satır için yeni kişi oluşturulur
			this_Dosya->kisiler[kisiSayac] = new_Kisi();
			i = hashCounter = 0;
			charPointer = line;
			while (*charPointer)
			{
				if (isdigit(*charPointer))
				{
					// sayi bulunur
					sayi = strtod(charPointer, &charPointer); // Sayı okunur
					if (hashCounter == 0)
					{
						this_Dosya->kisiler[kisiSayac]->Set_bakiye(this_Dosya->kisiler[kisiSayac], sayi);
						hashCounter++;
					}
					else if (hashCounter == 1)
					{
						this_Dosya->kisiler[kisiSayac]->Set_paraYatirmaOrani(this_Dosya->kisiler[kisiSayac], sayi);
						hashCounter++;
					}
					else if (hashCounter == 2)
					{
						this_Dosya->kisiler[kisiSayac]->Set_paraYatirdigiSayi(this_Dosya->kisiler[kisiSayac], sayi);
						hashCounter = 0;
					}
				}
				else
				{
					if (line[i] != '#')
					{ // isim okunur
						isim[i] = line[i];
						isim[i + 1] = '\0';
						i++;
					}
					// Bir sonraki karaktere geçilir
					charPointer++;
				}
			}
			// İsim için bellekten yer ayrılır
			char *ad_SoyAd = (char *)malloc(sizeof(char) * ((sizeof(isim) / sizeof(isim[0]) + 1)));
			strcpy(ad_SoyAd, isim);
			this_Dosya->kisiler[kisiSayac]->Set_adSoyAd(this_Dosya->kisiler[kisiSayac], ad_SoyAd);
			kisiSayac++; // Heap'te oluşturulan Kisileri sayar
		}
	}
	else
	{
		printf("Dosya Yolu Bulunamadi");
	}
	fclose(filePointer);
}

void Sayi_Oku(const Dosya this_Dosya)
{
	FILE *filePointer;
	char line[5];
	int okunanSayi, i = 0, satirSayisi = 0;
	filePointer = fopen("Sayilar.txt", "r");
	if (filePointer != NULL)
	{
		while (fgets(line, sizeof(line), filePointer))
		{
			satirSayisi++;
		}
		this_Dosya->sansliSayilar = (int *)malloc(sizeof(int) * satirSayisi);
		this_Dosya->sayiSayisi = satirSayisi;
	}
	else
	{
		printf("Dosya Yolu Bulunamadi");
	}
	fclose(filePointer);

	filePointer = fopen("Sayilar.txt", "r");
	if (filePointer != NULL)
	{ // Sayılar dosyası okunur
		while (fgets(line, sizeof(line), filePointer))
		{
			okunanSayi = atoi(line); // Sayı okunur
			this_Dosya->sansliSayilar[i] = okunanSayi;
			i++;
		}
	}
	else
	{
		printf("Dosya Yolu Bulunamadi");
	}
	fclose(filePointer);
}

void delete_Dosya(const Dosya this_Dosya)
{
	if (this_Dosya == NULL)
		return;
	// kisiler dizisinin elemanları için ayrılan bellek bölgeleri kişi elendikten sonra iade edilir
	free(this_Dosya->kisiler);
	free(this_Dosya->sansliSayilar);
	free(this_Dosya);
}
