package paket;

public class KontrolEdilebilirDonan─▒m implements IKontrolEdilebilir{
    private IKontrolEdilebilir kontrolEdilebilir;
    public KontrolEdilebilirDonan─▒m(IKontrolEdilebilir kontrolEdilebilir){
        this.kontrolEdilebilir = kontrolEdilebilir;
    }
    @Override
    public void ac() {
        kontrolEdilebilir.ac();
    }

    @Override
    public void kapat() {
        kontrolEdilebilir.kapat();
    }
}
