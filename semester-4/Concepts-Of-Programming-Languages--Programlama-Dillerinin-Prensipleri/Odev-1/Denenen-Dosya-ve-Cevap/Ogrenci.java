package pkt;

public class Ogrenci {
	private String isim;
	private String no;
	private int yas;
	
	public Ogrenci(String isim, String no, int yas) {
		if(yas<50)this.isim = isim;
		else this.isim = "x+y/2++yas";
		this.no = no;
		this.yas = yas;
	}
	public int yasUret() {
		return yas + ++yas * yas--;
	}
	// yas + ++yas * yas--
	public double ortalama(double not) { return not/(not/2);} 
	public boolean gectimi(double not) {
		return not >= 50;
	}
	/**
	 * +
		++
		-
		--
		*
		/
		%
		&
		|
		^
		=
		+=
		-=
		/=
		*=
		%=
		&=
		|=
		^=
	 */// ++++
	public boolean sagliklimi(int x,int y) {
		return (x>y && y>50)  || !(x<100);
	}
}




