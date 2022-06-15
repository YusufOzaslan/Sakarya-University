using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

/****************************************************************************
**					      SAKARYA ÜNİVERSİTESİ
**			  	BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				     NESNEYE DAYALI PROGRAMLAMA DERSİ
**				   	    2020-2021 BAHAR DÖNEMİ
**	
**				      ÖDEV NUMARASI..........: 2. Ödev 2. Soru
**				      ÖĞRENCİ ADI............: Yusuf Özaslan
**				      ÖĞRENCİ NUMARASI.......: B201210033
**                    DERSİN ALINDIĞI GRUP...: 1. Öğretim C Grubu
****************************************************************************/

namespace _2020_2021_Bahar_Dönemi_2.Ödev_2.Soru
{
    static class Matris
    {
        static double[,] matris1 = new double[3, 3];
        static double[,] matris2 = new double[3, 3];
        static public double[,] matrisSonuc = new double[3, 3];// Fonksiyonlarda yapılan işlemler bu matrise aktarılır.
        static double[,] araMatris = new double[3, 3];
        static double toplam;
        static public double iz;
        static public string okunanText;

        public static void matrisToplama()
        { // Matris toplama işlemi yapılır.
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrisSonuc[i, j] = matris1[i, j] + matris2[i, j];
                }
            }
        }

        public static void matrisCarpma()
        { // Matris çarpma işlemi yapılr.
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    toplam = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        toplam += matris1[i, k] * matris2[k, j];
                    }
                    matrisSonuc[i, j] = toplam;
                }
            }
        }

        public static void matrisTersi()
        { // Matrisin tersi alınır.
            double det = determinant(matris1);
            araMatris = kofaktor(matris1);
            for (int i = 0; i < 3; i++)
            {// Fonksiyonlarla bulunan ek matris determinant ile çarpılır
                for (int j = 0; j < 3; j++)
                {
                    matrisSonuc[i, j] = (1 / det) * araMatris[i, j];
                }
            }
        }

        public static void matrisIzi()
        { // Matrisin izi alınır.
            iz = 0;
            for (int i = 0; i < 3; i++)
            {
                iz += matris1[i, i];
            }
        }

        public static void matrisTranspoze()
        { // Matisin transpozu alınır.
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrisSonuc[j, i] = matris1[i, j];
                }
            }
        }

        public static void matrisYazdir(string islem)
        {// Bu fonksiyon yardımıyla kaydedilmek istenen matris işlemleri matris şeklinde kendi text dosyasına kaydedilir.
            using (StreamWriter topla = new StreamWriter("Matris Toplama.txt", true))
            using (StreamWriter carp = new StreamWriter("Matris Carpma.txt", true))
            using (StreamWriter ters = new StreamWriter("Matris Tersi.txt", true))
            using (StreamWriter Iz = new StreamWriter("Matris İzi.txt", true))
            using (StreamWriter transpoze = new StreamWriter("Matris Transpoze.txt", true))
                if (islem == "+")
                {// Toplam işlemi için dosya kaydı yapılır.
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            topla.Write("  " + matris1[i, j].ToString("0.##"));
                        }
                        if (i == 1) { topla.Write("  " + islem + "  "); }
                        else { topla.Write("      "); }
                        for (int j = 0; j < 3; j++)
                        {
                            topla.Write("  " + matris2[i, j].ToString("0.##"));
                        }
                        if (i == 1) { topla.Write("   = "); }
                        else { topla.Write("      "); }
                        for (int j = 0; j < 3; j++)
                        {
                            topla.Write("  " + matrisSonuc[i, j].ToString("0.##"));
                        }
                        topla.WriteLine();
                    }
                    topla.WriteLine();
                }
                else if (islem == "X")
                {// Çarpma işlemi için dosya kaydı yapılır.
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            carp.Write("  " + matris1[i, j].ToString("0.##"));
                        }
                        if (i == 1) { carp.Write("  " + islem + "  "); }
                        else { carp.Write("      "); }
                        for (int j = 0; j < 3; j++)
                        {
                            carp.Write("  " + matris2[i, j].ToString("0.##"));
                        }
                        if (i == 1) { carp.Write("   = "); }
                        else { carp.Write("      "); }
                        for (int j = 0; j < 3; j++)
                        {
                            carp.Write("  " + matrisSonuc[i, j].ToString("0.##"));
                        }
                        carp.WriteLine();
                    }
                    carp.WriteLine();
                }
                else if (islem == "Matrisin Tersi")
                {// Matris tersi işlemi için dosya kaydı yapılır.
                    ters.WriteLine("\n\t" + islem + "\n");
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            ters.Write("  " + matris1[i, j].ToString("0.##"));
                        }
                        ters.Write("\t");
                        if (islem != "Matrisin İzi")
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                ters.Write("  " + matrisSonuc[i, j].ToString("0.##"));
                            }
                        }
                        if (islem == "Matrisin İzi" && i == 1)
                        {
                            ters.Write(" " + islem + iz);
                        }
                        ters.WriteLine();
                    }
                }
                else if (islem == "Matrisin İzi")
                {// Matris izi işlemi için dosya kaydı yapılır.
                    Iz.WriteLine("\n");
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            Iz.Write("  " + matris1[i, j].ToString("0.##"));
                        }
                        Iz.Write("\t");
                        if (i == 1)
                        {
                            Iz.Write(islem + " = " + iz);
                        }
                        Iz.WriteLine();
                    }
                }
                else if (islem == "Matrisin Transpozu")
                {// Matris transpozu işlemi için dosya kaydı yapılır.
                    transpoze.WriteLine("\n\t" + islem + "\n");
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            transpoze.Write("  " + matris1[i, j].ToString("0.##"));
                        }
                        transpoze.Write("\t");
                        for (int j = 0; j < 3; j++)
                        {
                            transpoze.Write("  " + matrisSonuc[i, j].ToString("0.##"));
                        }
                        transpoze.WriteLine();
                    }
                }
        }

        public static void matrisOkuma(string islem)
        { // Bu fonksiyon çağrıldığında istenilen text dosyaındaki veriler okunur ve okunanText string değişkenine aktarılır.
            if (islem == "Matris Toplama") { okunanText = File.ReadAllText("Matris Toplama.txt"); }
            else if (islem == "Matris Çarpma") { okunanText = File.ReadAllText("Matris Carpma.txt"); }
            else if (islem == "Matris Tersi Alma") { okunanText = File.ReadAllText("Matris Tersi.txt"); }
            else if (islem == "Matris İzi Bulma") { okunanText = File.ReadAllText("Matris İzi.txt"); }
            else if (islem == "Matris Transpoze") { okunanText = File.ReadAllText("Matris Transpoze.txt"); }
        }

        public static void matrisCevir(string[,] textBox1, string[,] textBox2)
        { // Form'dan gönderilen iki boyutlu string diziler yukarıdaki işlemlerde kullanılmak için double tipinde iki boyutlu dizilere dönüştürülür.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (!double.TryParse(textBox1[i, j], out matris1[i, j]))
                        { // string double'a dönüştürülemezse "0" atanır.
                            matris1[i, j] = 0;
                        }
                    }
                }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (!double.TryParse(textBox2[i, j], out matris2[i, j]))
                    {
                        matris2[i, j] = 0;
                    }
                }
            }
        }

        public static void kayitSil(string islem)
        { // Seçilen işlemin kaydı silinir.
            if (islem == "Matris Toplama") { using (StreamWriter topla = new StreamWriter("Matris Toplama.txt")) topla.Write(""); }
            else if (islem == "Matris Çarpma") { using (StreamWriter carp = new StreamWriter("Matris Carpma.txt")) carp.Write(""); }
            else if (islem == "Matris Tersi Alma") { using (StreamWriter ters = new StreamWriter("Matris Tersi.txt")) ters.Write(""); }
            else if (islem == "Matris İzi Bulma") { using (StreamWriter Iz = new StreamWriter("Matris İzi.txt")) Iz.Write(""); }
            else if (islem == "Matris Transpoze") { using (StreamWriter transpoze = new StreamWriter("Matris Transpoze.txt")) transpoze.Write(""); }
        }

        static double[,] kofaktor(double[,] matris)
        { // Gönderilen matrisin kofaktörleri oluşturulup altmatrisin elemanlarına aktarılır.
            // Daha sonra altmatrisin transpozu alınarak gönderilen matrisin ek matrisi bulunur.
            double[,] ekMatris = new double[3, 3];
            double[,] altMatris = new double[2, 2];
            for (int i = 0; i < 3; i++)
            {// 9 tane 2x2 matris oluşturulur ve her birinin determinantı alınarak ekMatrise yerleştirilir.
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        for (int t = 0; t < 2; t++)
                        {
                            {
                                altMatris[k, t] = matris[(i + k + 1) % 3, (j + t + 1) % 3];
                            }
                        }
                    }
                    if ((i + j) % 2 == 0)
                    {
                        ekMatris[i, j] = Math.Pow(-1, i + j) * determinant(altMatris);
                    }
                    else
                    {// (i+j)'nin tek sayı olduğu altmatrislerde determinantın mutlak değeri değimese de işaret değişimi olur.
                        ekMatris[i, j] = -Math.Pow(-1, i + j) * determinant(altMatris);
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {// transpoze alınır.
                for (int j = 0; j < i + 1; j++)
                {
                    double g = ekMatris[j, i];
                    ekMatris[j, i] = ekMatris[i, j];
                    ekMatris[i, j] = g;
                }
            }
            return ekMatris;
        }

        static double determinant(double[,] matris)
        {// Gönderilen matrisin birinci satırına göre Laplace açılımıyla determinant hesaplanır.
            int boyut = Convert.ToInt32(Math.Sqrt(matris.Length));
            double isaret = 1;
            double toplam = 0;
            if (boyut == 1)
            {
                return matris[0, 0];
            }
            for (int i = 0; i < boyut; i++)
            {
                double[,] altmatris = new double[boyut - 1, boyut - 1];
                for (int satir = 1; satir < boyut; satir++)
                {
                    for (int sutun = 0; sutun < boyut; sutun++)
                    {
                        if (sutun < i)
                        {
                            altmatris[satir - 1, sutun] = matris[satir, sutun];
                        }
                        else if (sutun > i)
                        {
                            altmatris[satir - 1, sutun - 1] = matris[satir, sutun];
                        }
                    }
                }
                if (i % 2 == 0)
                {
                    isaret = 1;
                }
                else
                {
                    isaret = -1;
                }
                toplam += isaret * matris[0, i] * (determinant(altmatris));
            }
            return toplam;
        }
    }
}
