using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
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
    public partial class Form1 : Form
    {
        string[,] matris1 = new string[3, 3];
        string[,] matris2 = new string[3, 3];
        string[,] matrisSonucS = new string[3, 3];
        string iz;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] islemler = { "Matris Toplama", "Matris Çarpma", "Matris Tersi Alma", "Matris İzi Bulma", "Matris Transpoze" };
            comboBox1.Items.AddRange(islemler);
            comboBox2.Items.AddRange(islemler);
            comboBox1.Enabled = false;// İlk matris değeri girilmeden işlem seçilemez
            richTextBox1.ReadOnly = true;
            richTextBox1.Text = "\n\n\t\t\t\t\tÖNCE MATRİSLERİ GİRİNİZ";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            comboBox1.Enabled = true;// Matris girilince işlem seçimi açılır.
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Seçilen işleme göre fonksiyonlar çağırılır (comboBoxta işlem seçildiği anda işlemler yapılır).
            if (comboBox1.Text == "Matris Toplama")
            {
                if (textBox1.Text == "" || textBox10.Text == "")
                {
                    MessageBox.Show("Önce 1. ve 2. matris için sayı değerlerini giriniz.\nDaha sonra seçim yapın.");
                }
                groupBox2.Enabled = true;
                textToMatrix();
                label1.Text = "+";
                Matris.matrisCevir(matris1, matris2);
                Matris.matrisToplama();
                textBox28.Text = "";
                label5.Text = "";
            }
            else if (comboBox1.Text == "Matris Çarpma")
            {
                if (textBox1.Text == "" || textBox10.Text == "")
                {
                    MessageBox.Show("Önce 1. ve 2. matris için sayı değerlerini giriniz.\nDaha sonra seçim yapın.");
                }
                groupBox2.Enabled = true;
                textToMatrix();
                label1.Text = "X";
                Matris.matrisCevir(matris1, matris2);
                Matris.matrisCarpma();
                textBox28.Text = "";
                label5.Text = "";
            }

            else if (comboBox1.Text == "Matris Tersi Alma")
            {
                if (textBox1.Text == "")
                {
                    MessageBox.Show("Önce 1. matris için sayı değerlerini giriniz.\nDaha sonra seçim yapın.");
                }
                groupBox2.Enabled = false;
                textToMatrix();
                Matris.matrisCevir(matris1, matris2);
                Matris.matrisTersi();
                textBox28.Text = "";
                label5.Text = "";
            }
            else if (comboBox1.Text == "Matris İzi Bulma")
            {
                if (textBox1.Text == "")
                {
                    MessageBox.Show("Önce 1. matris için sayı değerlerini giriniz.\nDaha sonra seçim yapın.");
                }
                groupBox2.Enabled = false;
                textToMatrix();
                Matris.matrisCevir(matris1, matris2);
                Matris.matrisIzi();
                label5.Text = "Marisin izi = ";
                iz = Convert.ToString(Matris.iz);
            }
            else if (comboBox1.Text == "Matris Transpoze")
            {
                if (textBox1.Text == "")
                {
                    MessageBox.Show("Önce 1. matris için sayı değerlerini giriniz.\nDaha sonra seçim yapın.");
                }
                groupBox2.Enabled = false;
                textToMatrix();
                Matris.matrisCevir(matris1, matris2);
                Matris.matrisTranspoze();
                textBox28.Text = "";
                label5.Text = "";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {// Hesapla butonu çalışır ve fonksiyonlardan gelen değerler textBokxlara aktarılır.
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrisSonucS[i, j] = Convert.ToString(Matris.matrisSonuc[i, j]);
                }
            }
            matrixToText();
            if (comboBox1.Text == "Matris İzi Bulma") { textBox28.Text = iz; }
        }

        private void button3_Click(object sender, EventArgs e)
        {// Kaydet butonu çalışır ve son yapılan işlem, o işleme ait text dosyasına kaydedilir.
            if (comboBox1.Text == "Matris Toplama") { Matris.matrisYazdir("+"); }
            if (comboBox1.Text == "Matris Çarpma") { Matris.matrisYazdir("X"); }
            if (comboBox1.Text == "Matris Tersi Alma") { Matris.matrisYazdir("Matrisin Tersi"); }
            if (comboBox1.Text == "Matris İzi Bulma") { Matris.matrisYazdir("Matrisin İzi"); }
            if (comboBox1.Text == "Matris Transpoze") { Matris.matrisYazdir("Matrisin Transpozu"); }
            MessageBox.Show("İşlemler Kaydedildi");
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {// Kaydedilen işlem richTextBoxta gösterilmek üzere okunur.
            if (comboBox2.Text == "Matris Toplama") { Matris.matrisOkuma("Matris Toplama"); }
            else if (comboBox2.Text == "Matris Çarpma") { Matris.matrisOkuma("Matris Çarpma"); }
            else if (comboBox2.Text == "Matris Tersi Alma") { Matris.matrisOkuma("Matris Tersi Alma"); }
            else if (comboBox2.Text == "Matris İzi Bulma") { Matris.matrisOkuma("Matris İzi Bulma"); }
            else if (comboBox2.Text == "Matris Transpoze") { Matris.matrisOkuma("Matris Transpoze"); }
        }

        private void button4_Click(object sender, EventArgs e)
        {// Seçilen işlemin kaydı silinir.
            if (comboBox2.Text == "Matris Toplama") { Matris.kayitSil("Matris Toplama"); Matris.matrisOkuma("Matris Toplama"); }
            else if (comboBox2.Text == "Matris Çarpma") { Matris.kayitSil("Matris Çarpma"); Matris.matrisOkuma("Matris Çarpma"); }
            else if (comboBox2.Text == "Matris Tersi Alma") { Matris.kayitSil("Matris Tersi Alma"); Matris.matrisOkuma("Matris Tersi Alma"); }
            else if (comboBox2.Text == "Matris İzi Bulma") { Matris.kayitSil("Matris İzi Bulma"); Matris.matrisOkuma("Matris İzi Bulma"); }
            else if (comboBox2.Text == "Matris Transpoze") { Matris.kayitSil("Matris Transpoze"); Matris.matrisOkuma("Matris Transpoze"); }
            richTextBox1.Text = Matris.okunanText;// richtextBox boşaltılır.
            MessageBox.Show("Seçilen işlemin Kayıtları Silindi");
        }

        private void button2_Click(object sender, EventArgs e)
        { // comboBox2 de seçilen (kaydedilen işlemi okuyan comboBox) işlem richtextBoxta gösterilir.
            richTextBox1.Clear();
            richTextBox1.Text = Matris.okunanText;
        }

        private void matrixToText()
        { // Sonuç matrisin değerleri textboxlara aktarılır.
            textBox19.Text = matrisSonucS[0, 0];
            textBox20.Text = matrisSonucS[0, 1];
            textBox21.Text = matrisSonucS[0, 2];
            textBox22.Text = matrisSonucS[1, 0];
            textBox23.Text = matrisSonucS[1, 1];
            textBox24.Text = matrisSonucS[1, 2];
            textBox25.Text = matrisSonucS[2, 0];
            textBox26.Text = matrisSonucS[2, 1];
            textBox27.Text = matrisSonucS[2, 2];
        }

        private void textToMatrix()
        { // textBoxlardan gelen matris değerleri matris hesabı yapan fonksiyonlara gönderilmek üzere iki boyutlu dizilere aktarılır.
            matris1[0, 0] = textBox1.Text;
            matris1[0, 1] = textBox2.Text;
            matris1[0, 2] = textBox3.Text;
            matris1[1, 0] = textBox4.Text;
            matris1[1, 1] = textBox5.Text;
            matris1[1, 2] = textBox6.Text;
            matris1[2, 0] = textBox7.Text;
            matris1[2, 1] = textBox8.Text;
            matris1[2, 2] = textBox9.Text;

            matris2[0, 0] = textBox10.Text;
            matris2[0, 1] = textBox11.Text;
            matris2[0, 2] = textBox12.Text;
            matris2[1, 0] = textBox13.Text;
            matris2[1, 1] = textBox14.Text;
            matris2[1, 2] = textBox15.Text;
            matris2[2, 0] = textBox16.Text;
            matris2[2, 1] = textBox17.Text;
            matris2[2, 2] = textBox18.Text;
        }
    }
}
