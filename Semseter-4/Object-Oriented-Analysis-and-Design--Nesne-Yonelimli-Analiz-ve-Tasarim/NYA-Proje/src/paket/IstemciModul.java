package paket;

public class IstemciModul {
    IArayuzFactory arayuzFactory;

    public IstemciModul(IArayuzFactory arayuzFactory) {
        this.arayuzFactory = arayuzFactory;
    }

    public IArayuz basla(){
        return arayuzFactory.factoryMethod();
    }
}
