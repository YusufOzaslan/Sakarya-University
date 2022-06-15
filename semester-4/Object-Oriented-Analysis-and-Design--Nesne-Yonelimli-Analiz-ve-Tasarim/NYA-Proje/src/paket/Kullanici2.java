package paket;

public class Kullanici2 implements IObserver {

    public Kullanici2(){

    }
    @Override
    public void update(String mesaj) {
        System.out.println("Kullanıcı 2'ye gelen mesaj->" + mesaj);
    }
}