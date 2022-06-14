using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

/****************************************************************************
**					      SAKARYA ÜNİVERSİTESİ
**			  	BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				     NESNEYE DAYALI PROGRAMLAMA DERSİ
**				   	    2020-2021 BAHAR DÖNEMİ
**	
**				      ÖDEV NUMARASI..........: Proje Ödevi
**				      ÖĞRENCİ ADI............: Yusuf Özaslan
**				      ÖĞRENCİ NUMARASI.......: B201210033
**                    DERSİN ALINDIĞI GRUP...: 1. Öğretim C Grubu
****************************************************************************/

namespace NDP_Proje_Ödevi
{
    class Cilek : KatiMeyve
    {
        public Cilek(double vitA, double vitC, Image image)
        {
            Verim();
            // 100 gr için verilen vitamin değerlerinin (vitA, vitC), hesaplanan ağırlıktaki miktarları hesaplanır.
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitC * Agirlik / 100;
            Resim = image;
        }
    }
    class Armut : KatiMeyve
    {
        public Armut(double vitA, double vitC, Image image)
        {
            Verim();
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitC * Agirlik / 100;
            Resim = image;
        }
    }
    class Elma : KatiMeyve
    {
        public Elma(double vitA, double vitC, Image image)
        {
            Verim();
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitC * Agirlik / 100;
            Resim = image;
        }
    }

    class Mandalina : Narenciye
    {
        public Mandalina(double vitA, double vitC, Image image)
        {
            Verim();
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitC * Agirlik / 100;
            Resim = image;
        }
    }

    class Portakal : Narenciye
    {
        public Portakal(double vitA, double vitc, Image image)
        {
            Verim();
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitc * Agirlik / 100;
            Resim = image;
        }
    }
    class Greyfurt : Narenciye
    {
        public Greyfurt(double vitA, double vitC, Image image)
        {
            Verim();
            VitaminA = vitA * Agirlik / 100;
            VitaminC = vitC * Agirlik / 100;
            Resim = image;
        }
    }
}
