package paket;


import java.util.Random;

public class SicaklikAlgilayiciModul implements ISicaklikAlgilayici{

    private Random rand=new Random();
    private ISubject publisher;
    private static SicaklikAlgilayiciModul instance;

    public SicaklikAlgilayiciModul(ISubject publisher){
        this.publisher = publisher;
    }

    public static SicaklikAlgilayiciModul getInstance(ISubject publisher){
        if(instance == null){
            instance = new SicaklikAlgilayiciModul(publisher);
        }
        return instance;
    }

    @Override
    public void sicakilkOku() {
        int celsius = rand.nextInt(100);
        System.out.println("Sicaklik Olculuyor");
        Araclar.bekle(500);

        System.out.print("Sicaklik: ");
        System.out.println(celsius);

        if(celsius >= 50){
            Araclar.bekle(1000);
            publisher.notify("Sicaklik 50 derecenin uzerinde, sogutucuyu acin");
        }
        else if(celsius >= 20 && celsius<50){
            Araclar.bekle(1000);
            publisher.notify("Uygun sicaklik araligi");
        }
        else if(celsius < 20){
            Araclar.bekle(1000);
            publisher.notify("Sicaklik 20 derecenin altınada, sogutucuyu kapatin.");
        }
    }

    @Override
    public void aboneEkle(IObserver subscriber) {
        publisher.attach(subscriber);
    }
}
