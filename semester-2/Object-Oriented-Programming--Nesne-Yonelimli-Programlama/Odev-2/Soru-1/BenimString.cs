using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

/****************************************************************************
**					      SAKARYA ÜNİVERSİTESİ
**			  	BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				     NESNEYE DAYALI PROGRAMLAMA DERSİ
**				   	    2020-2021 BAHAR DÖNEMİ
**	
**				      ÖDEV NUMARASI..........: 2. Ödev 1. Soru
**				      ÖĞRENCİ ADI............: Yusuf Özaslan
**				      ÖĞRENCİ NUMARASI.......: B201210033
**                    DERSİN ALINDIĞI GRUP...: 1. Öğretim C Grubu
****************************************************************************/

namespace _2020_2021_Bahar_Dönemi_2._Ödev_1._Soru
{
    class BenimString
    {
        string dizi;
        string geciciString = "";
        string sıralananString;
        ArrayList ayriDizi = new ArrayList();
        char[] alfabeAZ = "ABCÇDEFGĞHIİJKLMNOÖPQRSŞTUÜVWXYZ".ToCharArray();
        char[] alfabeZA = "ZYXWVÜUTŞSRQPÖONMLKJİIHĞGFEDÇCBA".ToCharArray();
        char[] charDizi;
        char gecici;
        int uzunluk;
        bool eslesme;

        public string Dizi
        {
            get { return dizi; }
            set { dizi = value; }
        }
        public int ElemanSayisi()
        { // Dizinin eleman sayısı bulunur.
            uzunluk = 0;
            foreach (char item in dizi)
            {
                uzunluk++;
            }
            Console.Write("Dizinin elemean sayısı: ");
            return uzunluk;
        }

        public void Birlestir(string ikinciDizi)
        { // Gönderilen ikinci sayı ilk diziyle birleştirilerek ekrana yazılır.
            Console.WriteLine("İki dizinin birleştirilmiş hali");
            Console.WriteLine(dizi + ikinciDizi + "\n");
        }

        public void ArayaGir(int parameter, string ikinciDizi)
        { // Parametre olarak alınan indisten sonra gönderilen ikinci string eklenir.
            for (int i = 0; i < parameter; i++)
            {
                Console.Write(dizi[i]);
            }
            Console.Write(ikinciDizi);
            for (int i = parameter; i < dizi.Length; i++)
            {
                Console.Write(dizi[i]);
            }
            Console.WriteLine();
        }

        public void DegerAl(int parameter, int parameter1)
        { // Parametre olarak alınan indisler arasında bulunan dizi ekrana yazılır.
            Console.WriteLine("Dizinin girilen indisler arasındaki bölümü");
            for (int i = parameter; i < parameter1; i++)
            {
                Console.Write(dizi[i]);
            }
        }

        public void DiziyeAyir(string ch)
        { // parametre olarak alınan karaktere göre kaynak nesne ayrılarak ekrana yazılır.
            Console.WriteLine("Dizi girilen karaktere göre ayrıldı");
            for (int i = 0; i < uzunluk; i++)
            {
                if (dizi[i] != ch[0])
                {
                    geciciString = geciciString + dizi[i];
                    if (i + 1 == uzunluk) { ayriDizi.Add(geciciString); }
                    continue;
                }
                ayriDizi.Add(geciciString);
                geciciString = "";
            }

            foreach (string item in ayriDizi)
            {
                Console.WriteLine(item);
            }
        }

        public void CharDiziyeDonustur()
        { // Kaynak nesne string'ten karakter dizisine dnüştürülür ve ekrana yazılır.
            Console.WriteLine("\nString dizi char diziye dönüştürüldü");
            charDizi = new char[uzunluk];
            for (int i = 0; i < uzunluk; i++)
            {
                charDizi[i] = dizi[i];
            }
            foreach (char item in charDizi)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        public int DegerIndis(string aranan)
        { // Parametre olarak alınan aranan nesnenin kaynak nesnedeki indisi bulunur.
            for (int i = 0; i < uzunluk - aranan.Length + 1; i++)
            {
                eslesme = true;
                for (int j = 0; j < aranan.Length; j++)
                {
                    if (dizi[i + j] != aranan[j])
                    { // aranan karakterler dizide yoksa -1 döndürülür.
                        eslesme = false;
                        break;
                    }
                }
                if (eslesme) { Console.Write("Aranan indis: "); return i; }
            }
            Console.Write("Aranan indis: ");
            return -1;
        }

        public void SiralaAZ()
        { // Kaynak nesnenin değerleri A'dan Z'ye sıralanır ve ekrana yazılır.
            sıralananString = dizi.ToUpper();
            Console.WriteLine("\n\nDizinin karakterlerinin A'dan Z'ye sıralanmış hali");
            foreach (var harf in alfabeAZ)
            {
                for (int i = 0; i < uzunluk; i++)
                {
                    if (harf == sıralananString[i])
                    {
                        Console.Write(sıralananString[i]);
                    }
                }
            }
        }

        public void SiralaZA()
        {// Kaynak nesnenin karakterleri Z'dan A'ye sıralanır ve ekrana yazılır.
            Console.WriteLine("\n\nDizinin karakterlerinin Z'dan A'ye sıralanmış hali");
            foreach (var harf in alfabeZA)
            {
                for (int i = 0; i < uzunluk; i++)
                {
                    if (harf == sıralananString[i])
                    {
                        Console.Write(sıralananString[i]);
                    }
                }
            }
        }

        public void TersCevir()
        { // Kaynak nesnenin değerleri ters çevirilir.
            Console.WriteLine("\n\nDizinin Ters çevrilmiş hali");
            for (int i = 0; i < uzunluk / 2; i++)
            {
                gecici = charDizi[uzunluk - 1 - i];
                charDizi[uzunluk - 1 - i] = dizi[i];
                charDizi[i] = gecici;
            }
            for (int i = 0; i < uzunluk; i++)
            {
                Console.Write(charDizi[i]);
            }
            Console.WriteLine();
        }
    }
}
