package paket;

public class AgArayuzuFactory implements IArayuzFactory{

    public  AgArayuzuFactory(){}
    @Override
    public AgArayuzu factoryMethod() {
        return new AgArayuzu();
    }
}
