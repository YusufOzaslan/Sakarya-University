package paket;

public class Kullanici1 implements IObserver {

    public Kullanici1(){

    }
    @Override
    public void update(String mesaj) {
        System.out.println("Kullanici 1' e gelen mesaj->" + mesaj);
    }
}