using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

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
    public partial class Form1 : Form
    {
        int time = 60;
        double portakalA;
        double portakalC;
        double MandalinaA;
        double MandalinaC;
        double GreyfurtA;
        double GreyfurtC;
        double CilekA;
        double CilekC;
        double ElmaA;
        double ElmaC;
        double ArmutA;
        double ArmutC;
        double topPure;
        double topSivi;

        List<IMeyve> meyveler = new List<IMeyve>()
        { // Meyve çeşitleri listeye eklenir.
            new Portakal(225, 45, Image.FromFile("portakal.png")),
            new Mandalina(681, 26, Image.FromFile("mandalina.png")),
            new Greyfurt(3, 44, Image.FromFile("greyfurt.png")),
            new Cilek(12, 60, Image.FromFile("cilek.png")),
            new Elma(54, 5, Image.FromFile("elma.png")),
            new Armut(25, 5, Image.FromFile("armut.png"))
        };

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Form yüklendiğinde meyve sıkma makinelerinin resimleri yerlerine eklenir.
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.Image = Image.FromFile("narenciye-sikacagi.png");
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.Image = Image.FromFile("Kati-Meyve-Sikacagi.png");
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;

            buttonNarenciye.Enabled = false;
            buttonKati.Enabled = false;
        }

        private void buttonBasla_Click(object sender, EventArgs e)
        {
            RandomResim();
            // Başla butonuna basılınca makineler kullanıma açılır.
            buttonNarenciye.Enabled = true;
            buttonKati.Enabled = true;
            buttonBasla.Enabled = false;
            // 60 saniye geri sayımı başlar.
            time = 60;
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (time >= 0)
            { // Saniye sıfırdan büyükse geri sayım devam eder.
                timer1.Interval = 1000;
                int sayac = time--;
                labelSure.Text = sayac.ToString();
            }
            else
            { // Süre dolunca makineler kullanıma kapanır ve başla butonu kullanıma açılır.
                buttonBasla.Enabled = true;
                timer1.Stop();
                buttonNarenciye.Enabled = false;
                buttonKati.Enabled = false;
            }
        }

        private void RandomResim()
        { // Rastgele resim belirlenir.
            Random rnd = new Random();
            pictureBox1.Image = meyveler[rnd.Next(6)].Resim;
        }

        double toplamC;
        double toplamA;
        private void buttonNarenciye_Click(object sender, EventArgs e)
        {
            // Suyu sıkılan meyveler için aşağıdaki işlemler yapılır.
            // Rastgele gelen resimlerin hangi meyve oludğu tespit edilir.           
            if (pictureBox1.Image == meyveler[0].Resim)
            { // Meyve kullanıldıktan sonra listedeki aynı meyve çeşidi yerine yeni meyve eklenir.
                // Bu sayede her portaklın kütlesi ve vitamin verimi farklı olur.
                meyveler[0] = new Portakal(225, 45, Image.FromFile("portakal.png"));
                // En son sıkılan meyvenin vitamin miktarları gösterilir.
                labelVitA.Text = meyveler[0].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[0].VitaminC.ToString() + " mg";
                // Her meyveden elde edilen toplam vitamin miktarı kendi değişkeninde tutulur ve ekranda gösterilir.
                portakalA = portakalA + meyveler[0].VitaminA;
                portakalC = portakalC + meyveler[0].VitaminC;
                labelPA.Text = portakalA.ToString() + " mg";
                labelPC.Text = portakalC.ToString() + " mg";
                // Suyu sıkılan ve püre haline getirilen meyvelerin gramajları ayrı ayrı ekranda gösterilir.
                topSivi = topSivi + meyveler[0].Agirlik;
                // Yeni rastgele resim seçilir.
                RandomResim();
            }
            else if (pictureBox1.Image == meyveler[1].Resim)
            {
                meyveler[1] = new Mandalina(681, 26, Image.FromFile("mandalina.png"));
                labelVitA.Text = meyveler[1].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[1].VitaminC.ToString() + " mg";
                MandalinaA = MandalinaA + meyveler[1].VitaminA;
                MandalinaC = MandalinaC + meyveler[1].VitaminC;
                labelMA.Text = MandalinaA.ToString() + " mg";
                labelMC.Text = MandalinaC.ToString() + " mg";
                topSivi = topSivi + meyveler[1].Agirlik;
                RandomResim();
            }
            else if (pictureBox1.Image == meyveler[2].Resim)
            {
                meyveler[2] = new Greyfurt(3, 44, Image.FromFile("greyfurt.png"));
                labelVitA.Text = meyveler[2].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[2].VitaminC.ToString() + " mg";
                GreyfurtA = GreyfurtA + meyveler[2].VitaminA;
                GreyfurtC = GreyfurtC + meyveler[2].VitaminC;
                labelGA.Text = GreyfurtA.ToString() + " mg";
                labelGC.Text = GreyfurtC.ToString() + " mg";
                topSivi = topSivi + meyveler[2].Agirlik;
                RandomResim();
            }
            // En son elde edilen meyve suyundaki toplam vitamin değerleri ekranda gösterilir.
            toplamA = portakalA + MandalinaA + GreyfurtC + CilekA + ElmaA + ArmutA;
            toplamC = portakalC + MandalinaC + GreyfurtC + CilekC + ElmaC + ArmutC;
            labelAtop.Text = toplamA.ToString() + " mg";
            labelCtop.Text = toplamC.ToString() + " mg";
            // Suyu sıkılan ve püre haline getirilen meyvelerin gramajları ayrı ayrı ekranda gösterilir.
            labelSivi.Text = topSivi.ToString() + " gr";
        }

        private void buttonKati_Click(object sender, EventArgs e)
        {
            // buttonNarenciye_Click fonksiyonunda yapılan işlemler katı meyve sıkcağında kullanılan meyveler için yapılır.
            if (pictureBox1.Image == meyveler[3].Resim)
            {
                meyveler[3] = new Cilek(12, 60, Image.FromFile("cilek.png"));
                labelVitA.Text = meyveler[3].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[3].VitaminC.ToString() + " mg";
                CilekA = CilekA + meyveler[3].VitaminA;
                CilekC = CilekC + meyveler[3].VitaminC;
                labelCA.Text = CilekA.ToString() + " mg";
                labelCC.Text = CilekC.ToString() + " mg";
                topPure = topPure + meyveler[3].Agirlik;
                RandomResim();
            }
            else if (pictureBox1.Image == meyveler[4].Resim)
            {
                meyveler[4] = new Elma(54, 5, Image.FromFile("elma.png"));
                labelVitA.Text = meyveler[4].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[4].VitaminC.ToString() + " mg";
                ElmaA = ElmaA + meyveler[4].VitaminA;
                ElmaC = ElmaC + meyveler[4].VitaminC;
                labelEA.Text = ElmaA.ToString() + " mg";
                labelEC.Text = ElmaC.ToString() + " mg";
                topPure = topPure + meyveler[4].Agirlik;
                RandomResim();
            }
            else if (pictureBox1.Image == meyveler[5].Resim)
            {
                meyveler[5] = new Armut(25, 5, Image.FromFile("armut.png"));
                labelVitA.Text = meyveler[5].VitaminA.ToString() + " mg";
                labelVitC.Text = meyveler[5].VitaminC.ToString() + " mg";
                ArmutA = ArmutA + meyveler[5].VitaminA;
                ArmutC = ArmutC + meyveler[5].VitaminC;
                labelAA.Text = ArmutA.ToString() + " mg";
                labelAC.Text = ArmutC.ToString() + " mg";
                topPure = topPure + meyveler[5].Agirlik;
                RandomResim();
            }
            toplamA = CilekA + ElmaA + ArmutA + portakalA + MandalinaA + GreyfurtC;
            toplamC = CilekC + ElmaC + ArmutC + portakalC + MandalinaC + GreyfurtC;
            labelAtop.Text = toplamA.ToString() + " mg";
            labelCtop.Text = toplamC.ToString() + " mg";

            labelPure.Text = topPure.ToString() + " gr";
        }

        private void buttonSifirla_Click(object sender, EventArgs e)
        { // hesaplanan tüm değerler sıfırlanır ve ekrandan kaldırılır.
            portakalA = 0;
            portakalC = 0;
            MandalinaA = 0;
            MandalinaC = 0;
            GreyfurtA = 0;
            GreyfurtC = 0;
            CilekA = 0;
            CilekC = 0;
            ElmaA = 0;
            ElmaC = 0;
            ArmutA = 0;
            ArmutC = 0;
            topPure = 0;
            topSivi = 0;
            toplamC = 0;
            toplamA = 0;

            labelVitA.Text = "";
            labelVitC.Text = "";
            labelPA.Text = "";
            labelPC.Text = "";
            labelMA.Text = "";
            labelMC.Text = "";
            labelGA.Text = "";
            labelGC.Text = "";
            labelCA.Text = "";
            labelCC.Text = "";
            labelEA.Text = "";
            labelEC.Text = "";
            labelAA.Text = "";
            labelAC.Text = "";
            labelSivi.Text = "";
            labelPure.Text = "";
            labelAtop.Text = "";
            labelCtop.Text = "";
        }

        private void buttonCık_Click(object sender, EventArgs e)
        {// Çıkış butonuna basıldığında program kapanır.
            Close();
        }
    }
}
