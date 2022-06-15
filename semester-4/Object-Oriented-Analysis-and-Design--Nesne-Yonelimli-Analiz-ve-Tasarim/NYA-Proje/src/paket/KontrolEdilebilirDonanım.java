package paket;

public class KontrolEdilebilirDonanım implements IKontrolEdilebilir{
    private IKontrolEdilebilir kontrolEdilebilir;
    public KontrolEdilebilirDonanım(IKontrolEdilebilir kontrolEdilebilir){
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
