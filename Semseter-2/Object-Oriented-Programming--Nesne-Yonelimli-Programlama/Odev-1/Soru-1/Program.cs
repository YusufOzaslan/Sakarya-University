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
**				      ÖDEV NUMARASI..........: 1. Ödev 1. Soru
**				      ÖĞRENCİ ADI............: Yusuf Özaslan
**				      ÖĞRENCİ NUMARASI.......: B201210033
**                    DERSİN ALINDIĞI GRUP...: 1. Öğretim C Grubu
****************************************************************************/


namespace _2020_2021_Bahar_Dönem_Ödevi_1.Soru
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] tahtaCiz = new int[8, 8];
            Random rnd = new Random();
            int sayac = 0;
            int sayac2 = 0;
            Boolean birKereWhile = true;
            int[] kordinatlarX = new int[8];
            int[] kordinatlarY = new int[8];
            int asamaSayisi = 0;
            int x;
            int y;
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine();
            Console.WriteLine("\tBAŞLANGIÇ");

            while (sayac < 8)
            {

                x = rnd.Next(8);
                y = rnd.Next(8);
                tahtaCiz[x, y] = 75; // x: satır sırası, y: sütün sırası.
                kordinatlarX[sayac] = x;
                kordinatlarY[sayac] = y;
                yazdir(tahtaCiz);
                asamaSayisi++;// Toplam aşama sayısı her ekran çıktısında değişebilir.
                Console.ForegroundColor = ConsoleColor.DarkCyan;
                Console.WriteLine("\t" + asamaSayisi + ". AŞAMA");
                sayac2 = sayac;

                for (int i = 0; i < sayac2; i++)
                {// Son yerleştirilen kalenin konumu öncekilerle karşılaltırılır. 
                    if (kordinatlarX[sayac2] == kordinatlarX[i] || kordinatlarY[sayac2] == kordinatlarY[i])
                    {
                        if (kordinatlarX[sayac2] == kordinatlarX[i] && kordinatlarY[sayac2] == kordinatlarY[i])
                        {// Eğer kaleler üst üste yerleştiyse döngüden çıkılır ve farklı rastegele bir konuma yerleştirilir.
                            sayac--;// Yeni konumun aynı kordinatlarX ve kordinatlarY indislerine kaydedilmesini sağlar.
                            break;
                        }
                        else
                        {
                            while (true)// Doğru rastgele değerler gelene kadar döngü devam eder.
                            {

                                if (birKereWhile)
                                {// Yanlış yerleşen konumu sfırlarken yeni verilen rastgele kordinatların sıfırlanmasını engeller.
                                    tahtaCiz[x, y] = 0;
                                    birKereWhile = false;
                                }

                                if (kordinatlarX[sayac2] == kordinatlarX[i])
                                {// Hatalı kordinat X ise sadece X'in konumunu rastgele belirler.
                                    x = rnd.Next(8);
                                    if (Array.IndexOf(kordinatlarX, x) == -1)// Mevcut kordinatların dışında rastgele bir kordinat belirlenir.
                                    {// Yeni X kordinatı kordinatlarX dizisine kaydedilir ve kale yeni konuma yerleştirilir.
                                        kordinatlarX[sayac] = x;
                                        tahtaCiz[x, y] = 75;
                                        birKereWhile = true;
                                        break;
                                    }
                                }
                                if (kordinatlarY[sayac2] == kordinatlarY[i])
                                {// Hatalı kordinat Y ise sadece Y'nin konumunu rastgele belirler.
                                    y = rnd.Next(8);
                                    if (Array.IndexOf(kordinatlarY, y) == -1)
                                    {
                                        kordinatlarY[sayac] = y;
                                        tahtaCiz[x, y] = 75;
                                        birKereWhile = true;
                                        break;
                                    }
                                }
                            }

                        }
                    }
                }
                sayac++;
            }
            yazdir(tahtaCiz);

            Console.ReadKey();
        }


        private static void yazdir(int[,] tahtaCiz)
        {// Tahtayı ekrana yazdırır.
            Console.WriteLine();
            for (int i = 0; i < 8; i++)
            {
                Console.Write("     ");
                for (int j = 0; j < 8; j++)
                {
                    if (tahtaCiz[i, j] == 75)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write(Convert.ToChar(tahtaCiz[i, j]));
                        Console.Write(" ");
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Write(tahtaCiz[i, j]);
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
