package paket;

public class EyleyiciModul implements IKontrolEdilebilir{

    public EyleyiciModul(){}
    @Override
    public void ac() {
        System.out.println("Cihaz Aciliyor...");
        Araclar.bekle(1000);
        System.out.println("Cihaz Durumu: ACIK");
    }

    @Override
    public void kapat() {
        System.out.println("Cihaz Kapatiliyor...");
        Araclar.bekle(1000);
        System.out.println("Cihaz Durumu: KAPALI");
    }
}
