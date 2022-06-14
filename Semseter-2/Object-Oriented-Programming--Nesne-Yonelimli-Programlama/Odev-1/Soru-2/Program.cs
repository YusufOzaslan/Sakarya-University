using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/****************************************************************************
**					      SAKARYA ÜNİVERSİTESİ
**			  	BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				     NESNEYE DAYALI PROGRAMLAMA DERSİ
**				   	    2020-2021 BAHAR DÖNEMİ
**	
**				      ÖDEV NUMARASI..........: 1. Ödev 2. Soru
**				      ÖĞRENCİ ADI............: Yusuf Özaslan
**				      ÖĞRENCİ NUMARASI.......: B201210033
**                    DERSİN ALINDIĞI GRUP...: 1. Öğretim C Grubu
****************************************************************************/


namespace _2020_2021_Bahar_Dönem_Ödevi_2.Soru
{
    class Program
    {
        static void Main(string[] args)
        {
            int secim;
            string girilenDizin = "";
            string aranan = "";
            char menuGec;
            do// Menüyü tekrar açar.
            {
                do
                {
                    Console.WriteLine("\t\tMENÜ");
                    Console.WriteLine("1- String bir değişkende, string değeri substring kullanmadan ara.");
                    Console.WriteLine("2- String bir değişkende, string değeri substring kullanarak ara.");
                    Console.WriteLine("3- Alfabenin karakterlerini bir string'de ara kaç adet geçiyor bul ve çiz.");
                    Console.Write("Seçiminiz:");
                    secim = Convert.ToInt32(Console.ReadLine());

                    if (secim == 1 || secim == 2 || secim == 3)
                    {
                        Console.Write("Karakter Dizini Giriniz: ");
                        girilenDizin = Console.ReadLine();
                    }
                    if (secim == 1 || secim == 2)
                    {
                        Console.Write("Aranılacak kelime: ");
                        aranan = Console.ReadLine();
                    }

                } while (secim != 1 && secim != 2 && secim != 3);

                if (secim == 1)
                {
                    int sonKonum = 0;
                    int arananMiktar = 0;
                    int indis = 0;
                    while (true)
                    {
                        arananMiktar = girilenDizin.Length - sonKonum;
                        indis = girilenDizin.IndexOf(aranan, sonKonum, arananMiktar);
                        // "aranan" kelimesini "sonKonum"dan başlayarak "arananMiktar" kadar arar.
                        if (indis == -1) break;// Aranan kelime yoksa döngüden çıkar.
                        Console.WriteLine("kelime " + aranan + " indis " + indis);
                        sonKonum = indis + 1;
                        // sonKonum değeri bir arttırılarak döngü içinde indisin tekrar aynı değeri alması önlenir.
                    }
                }

                if (secim == 2)
                {
                    int boyut = girilenDizin.Length;
                    int indis33 = 0;
                    int indis3 = 0;
                    while (true)
                    { // Her döngüde aranan kelimenin bulunduğu indisten sonraki karakterler Substring ile girilenDizine aktarılır.
                        indis3 = girilenDizin.IndexOf(aranan);
                        girilenDizin = girilenDizin.Substring(indis3 + 1);
                        if (indis3 == -1) break;
                        indis33 = boyut - girilenDizin.Length - 1;
                        Console.WriteLine("kelime " + aranan + " indis " + indis33);
                    }
                }

                if (secim == 3)
                {
                    Console.WriteLine("\nKarakter sayısı grafik gösterimi");
                    Console.WriteLine("---------------------------------");
                    string buyukDizin = girilenDizin.ToUpper();// girilenDizindeki tüm harfler büyük harfe dönüştürülür.
                    List<char> alfabe = "ABCÇDEFGĞHIİJKLMNOÖPQRSŞTUÜVWXYZ".ToCharArray().ToList();
                    foreach (var harf in alfabe)
                    // alfabe listesindeki elemanları tek tek seçer.
                    {
                        int indis2 = buyukDizin.IndexOf(harf);
                        int sonKonum2 = 0;
                        int arananMiktar2 = 0;
                        int sayac = 0;// Harf sayısını sayar.
                        while (true)
                        {
                            // Girilen metinde, alfabe listesinden seçilen harfin kaç tane olduğu bulunnur.
                            arananMiktar2 = buyukDizin.Length - sonKonum2;
                            indis2 = buyukDizin.IndexOf(harf, sonKonum2, arananMiktar2);
                            if (indis2 == -1) break;
                            sonKonum2 = indis2 + 1;
                            sayac++;
                        }
                        Console.Write(harf + ",  sayısı:  " + sayac);
                        for (int i = 0; i < sayac; i++)
                        // harf sayıları bulunduktan sonra harf sayısı kadar yıldız çizilir.
                        {
                            Console.Write("  *");
                        }
                        Console.WriteLine();
                    }
                }
                do// işlem bittikten sonra kullanıcıya menüye dönüp dönmeyeceği sorulur.
                {
                    Console.WriteLine();
                    Console.WriteLine(" Menüye dönmek ister misiniz? (e/h) ");
                    menuGec = Convert.ToChar(Console.ReadLine());
                } while (!(menuGec == 'e' || menuGec == 'h'));
            } while (menuGec != 'h');
        }
    }
}
