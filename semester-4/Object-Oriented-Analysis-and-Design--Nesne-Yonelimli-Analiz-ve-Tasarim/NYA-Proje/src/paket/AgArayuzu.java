package paket;

import java.util.Scanner;

public class AgArayuzu implements IArayuz {
    private Scanner scan=new Scanner(System.in);
    private IAnaIslemPlatformu anaIslemPlatformu;
    public AgArayuzu(){
        anaIslemPlatformu = new AnaIslemPlatformu();
    }
    @Override
    public String kullaniciVeriGirisi() {
        return scan.next();
    }

    @Override
    public int kullaniciSecimi() {
        return scan.nextInt();
    }

    @Override
    public void ekranaYaz(String ekran){
        System.out.println(ekran);
    }

    @Override
    public void sicaklikGonder() {
        anaIslemPlatformu.sicaklikAlgilayiciyaGonder();
    }

    @Override
    public void sogutucuAc() {
        anaIslemPlatformu.eyleyiciAcmaKomutu();
    }

    @Override
    public void sogutucuKapat() {
        anaIslemPlatformu.eyleyiciKapatmaKomutu();
    }
}
