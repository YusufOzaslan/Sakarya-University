package paket;

public class AkilliCihaz {
    private IVeritabaniRepository veriTabani;
    private IArayuzFactory arayuzFactory;
    private IstemciModul istemciModul;
    private IArayuz agArayuzu;
    private int secim;

    public AkilliCihaz(){
        veriTabani = new PostgreSQLSurucu();
        arayuzFactory = new AgArayuzuFactory();
        istemciModul = new IstemciModul(arayuzFactory);
        // nesne, istemci modül içerisinde Factory method ile oluşturuldu
        agArayuzu = istemciModul.basla();
       // agArayuzu = new AgArayuzu();
    }

    public void basla(){
        String sifre;
        String kullaniciAdi;
        System.out.println("Kullanici Bilgileri");
        System.out.print("Kullanici Adi:");
        kullaniciAdi=agArayuzu.kullaniciVeriGirisi();
        System.out.print("Sifre:");
        sifre=agArayuzu.kullaniciVeriGirisi();
        if(veriTabani.kullaniciDogrula(kullaniciAdi,sifre)){
            this.islemSecimi();
        }
        else{
            Araclar.bekle(200);
            System.out.println("Kullanici Eslesmedi");
        }
    }

    private void islemSecimi(){

        do{
            secim = anaMenuyuGoster();
            switch (secim) {
                case 1:
                    agArayuzu.sicaklikGonder();
                    Araclar.bekle(1000);
                    break;
                case 2:
                    agArayuzu.sogutucuAc();
                    Araclar.bekle(1000);
                    break;

                case 3:
                    agArayuzu.sogutucuKapat();
                    Araclar.bekle(1000);
                    break;

                case 4:
                    System.out.println("Çıkılıyor!");
                    Araclar.bekle(1200);
                    break;
                default:
                    agArayuzu.ekranaYaz("1-4 arasında bir sayı girmelisiniz");
                    break;
            }
        }while(secim!=4);
    }

    private int anaMenuyuGoster()
    {
        agArayuzu.ekranaYaz("**********************************************");
        agArayuzu.ekranaYaz("Ana Menu");
        agArayuzu.ekranaYaz("1-Sıcaklik Goruntule");
        agArayuzu.ekranaYaz("2-Sogutucu Ac");
        agArayuzu.ekranaYaz("3-Sogutucu Kapat");
        agArayuzu.ekranaYaz("4-Cikis");
        agArayuzu.ekranaYaz("Seciminiz:");
        agArayuzu.ekranaYaz("**********************************************");
        return  agArayuzu.kullaniciSecimi();
    }

}
