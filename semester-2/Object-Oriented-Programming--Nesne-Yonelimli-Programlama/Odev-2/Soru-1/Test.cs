using System;
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
    class Test
    {
        BenimString benimString = new BenimString();
        string ikinciDizi;
        string aranan;
        int parameter;
        int parameter1;
        string ayrac;

        public Test()
        {   // Kaynak nesne girilir.
            Console.WriteLine("Üzerinde işlem yapmak istediğiniz diziyi girin");
            benimString.Dizi = Console.ReadLine();

            // Eleman sayısı hesaplanır.
            Console.WriteLine("\n" + benimString.ElemanSayisi() + "\n");

            // İki dizi birleştirilir.
            Console.WriteLine("Birleştir fonksiyonu için ikinci diziyi girin.");
            ikinciDizi = Console.ReadLine();
            benimString.Birlestir(ikinciDizi);

            do
            { // ArayaGir fonksiyonuna gönderilecek parametrelerin doğru yazılması için gerekli kontroller yapılır.
                Console.Write("ArayaGir fonksiyonu için parametre girin: ");
                if (!(int.TryParse(Console.ReadLine(), out parameter)))
                {
                    parameter = 1; // parametre dönüştürülemezse 1 alınır
                }
                if (parameter < 0 || parameter > benimString.Dizi.Length)
                { Console.WriteLine("Parametre sıfırdan küçük veya dizi uzunluğundan büyük olamaz."); }
            } while (parameter < 0 || parameter > benimString.Dizi.Length);
            Console.WriteLine("ArayaGir fonksiyonu için kaynak nesnenin arasına girecek ikinci diziyi girin.");
            ikinciDizi = Console.ReadLine();
            benimString.ArayaGir(parameter, ikinciDizi);

            do
            {// DeğerAl fonksiyonuna gönderilecek parametrelerin doğru yazılması için gerekli kontroller yapılır.
                Console.WriteLine("\nDeğerAl fonksiyonunda kullanılacak ilk indisi girin.");
                if (!(int.TryParse(Console.ReadLine(), out parameter)))
                {
                    parameter = 1; // parametre dönüştürülemezse 1 alınır
                }
                if (parameter < 0 || parameter > benimString.Dizi.Length)
                { Console.WriteLine("Parametre sıfırdan küçük veya dizi uzunluğundan büyük olamaz."); }
            } while (parameter < 0 || parameter > benimString.Dizi.Length);
            do
            {
                Console.WriteLine("DeğerAl fonksiyonunda kullanılacak son indisi girin.");
                if (!(int.TryParse(Console.ReadLine(), out parameter1)))
                {
                    parameter1 = 1; // parametre dönüştürülemezse 1 alınır
                }
                if (parameter1 < 0 || parameter1 > benimString.Dizi.Length || parameter > parameter1)
                { Console.WriteLine("Parametre sıfırdan küçük veya dizi uzunluğundan büyük ve ilk parametreden küçük olamaz."); }
            } while (parameter1 < 0 || parameter1 > benimString.Dizi.Length || parameter > parameter1);
            benimString.DegerAl(parameter, parameter1);

            // DiziyeAyır fonksiyonuna gönderilecek parametrelerin doğru yazılması için gerekli kontroller yapılır.
            Console.WriteLine("\n\nDiziyeAyır fonksiyonu için dizide bulunan bir tane karakter girin");
            do
            {
                ayrac = Console.ReadLine();
                if (ayrac.Length != 1) { Console.WriteLine("Ayırma işlemi tek karaktere göre yapılmaktadır"); }
            } while (ayrac.Length != 1);
            benimString.DiziyeAyir(ayrac);
            Console.ReadKey();

            // Kaynak string nesnesi char diziye çevrilir.
            benimString.CharDiziyeDonustur();

            // Aranan değer girilir ve kaynak nesnede indis değeri bulunmak üzere parametre olarak gönderilir.
            Console.WriteLine("\nDegerINdis fonksiyonu için aranan nesneyi girin");
            aranan = Console.ReadLine();
            Console.WriteLine(benimString.DegerIndis(aranan));
            Console.ReadKey();

            // Kaynak nesnenin değerlerinin A'dan Z'ye sıralanması için SiralaAZ fonksiyonu çağrılır.
            benimString.SiralaAZ(); Console.ReadKey();

            // Kaynak nesnenin değerlerinin Z'dan A'ye sıralanması için SiralaZA fonksiyonu çağrılır.
            benimString.SiralaZA(); Console.ReadKey();

            //  Kaynak nesnenin değerlerinin ters çevrilmesi için TersCevir fonksiyonu çağrılır.
            benimString.TersCevir(); Console.ReadKey();
        }
    }
}
