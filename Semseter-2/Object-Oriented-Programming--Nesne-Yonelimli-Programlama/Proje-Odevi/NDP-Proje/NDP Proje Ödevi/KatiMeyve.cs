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
    class KatiMeyve : IMeyve
    {
        public double VitaminA { get; set; }
        public double VitaminC { get; set; }
        public double Agirlik { get; set; }
        public Image Resim { get; set; }

        public void Verim()
        { // Her yeni meyve için rastgele ağırlık ve rastgele yüzdelik oran ile bu ağırlıktan elde edilen püre hesaplanır.
            Random rnd = new Random();
            Agirlik = rnd.Next(70, 120) * rnd.Next(80, 95) / 100;
        }
    }
}
