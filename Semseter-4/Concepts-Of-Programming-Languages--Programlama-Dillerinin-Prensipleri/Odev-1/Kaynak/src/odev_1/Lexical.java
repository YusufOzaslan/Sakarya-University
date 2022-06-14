package odev_1;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
* 	 @author		Yusuf Ozaslan
* 	 @class			1. ogretim A grubu 
*	 @No			B201210033
* 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
*	 @since			17/03/2022
*	 @assignment	1. Odev
**/

public class Lexical {

	private String file;
	private int tekliOperatorSayisi = 0;
	private int ikiliOperatorSayisi = 0;
	private int sayisalOperatorSayisi = 0;
	private int iliskiselOperatorSayisi = 0;
	private int mantiksalOperatorSayisi = 0;
	private int operandSayisi = 0;

	public Lexical(String file) {
		this.file = file;
		// üzerinde işlem yapılmayacak ifadeler stringten çıkarılır
		commentControl();
		//System.out.println(this.file);
		findOperators(this.file);
	}

	private void findOperators(String file) {
		// istenilen operatörler regex ile tespit edilir ve sayıları sınıfın değişkenlerine atanır.
		this.sayisalOperatorSayisi = calculateMatches("((?<=(\\ |\\w|\\n|\\t|\\r|\\+|\\-|\\/|\\*|\\%|\\&|\\||\\^))\\=(?!\\=))|(\\+\\+)|"
				+ "((?<!(\\+))\\+(?!(\\+|\\=)))|(\\-\\-)|((?<!(\\-))\\-(?!(\\-|\\=|\\>)))|(\\*(?!(\\=)))|(\\/(?!(\\=)))|(\\%(?!(\\=)))|"
				+ "((?<!(\\&))\\&(?!(\\=|\\&)))|((?<!(\\|))\\|(?!(\\=|\\|)))|(\\^(?!(\\=)))",this.file ,Pattern.MULTILINE);
		this.iliskiselOperatorSayisi = calculateMatches("((?<=(\\=|\\<|\\>|\\!))\\=)|((?<!\\<)\\<(?!(\\=|\\<)))|"
				+ "((?<!(\\>|\\-))\\>(?!(\\=|\\>)))",this.file ,Pattern.MULTILINE);
		this.mantiksalOperatorSayisi = calculateMatches("([\\&]\\&)|([\\|]\\|)|(\\!(?!(\\=)))",this.file ,Pattern.MULTILINE);
		int toplamOperator = sayisalOperatorSayisi + iliskiselOperatorSayisi + mantiksalOperatorSayisi;
		// tekli operatörler (!, ++, --, -, +)// (55) - (--5) ve -(--5) için \\)?
		this.tekliOperatorSayisi = calculateMatches("([\\+]\\+)|([\\-]\\-)|(\\!(?!(\\=))|(?<!(\\w\\)?))((?<!(\\s))\\s*\\-(?=(\\d|\\()|\\w))"
				+ "|(?<!(\\w\\)?))((?<!(\\s))\\s*\\+(?=(\\d|\\w))))",this.file ,Pattern.MULTILINE);
		this.ikiliOperatorSayisi = toplamOperator - tekliOperatorSayisi;
		// hatalı java kodlarında - operatoründe hatalı sayma önlenir
		this.ikiliOperatorSayisi = this.ikiliOperatorSayisi < 0 ? 0 : this.ikiliOperatorSayisi;
		this.operandSayisi = ikiliOperatorSayisi*2 + tekliOperatorSayisi;
	}

	private void commentControl() {
		// Çok satırlı yorumlar kaldırılır
		String noComment1 = this.file.replaceAll("/\\*(?:.|[\\n\\r])*?\\*/"," ");
		// Tek satırlı yorumlar kaldırılır
		String noComment2 = noComment1.replaceAll("(\\/\\/)([^\\n\\r]+)|(\\/\\/)"," ");
		// Tırnak işaretleri arasındaki string ifadeleri kaldırır ("String operator")
		String noString = noComment2.replaceAll("\"(?:.|[\n\r])*?\""," ");
		//  <> ifadesi ve arasındaki ifadeler kaldırılır 
		String noType = noString.replaceAll("\\<(?:.|[\r])*?\\>"," ");
		this.file = noType;
	}

	private int calculateMatches(String regex, String inputFile, int flag)
	{
		// regex ifade pattern nesnesine verilir
		Pattern pattern = Pattern.compile(regex, flag);
		Matcher matcher = pattern.matcher(inputFile);
		int matches = 0;
		/*	Java'da global flag olmadığı için eşleşen ifadeler döngü ile bulunur.
		 *  Find yöntemi, giriş metni boyunca ilerlemeye devam eder ve her eşleşme için true döndürür, 
		 *  böylece eşleşme sayısını bulmak için de kullanabiliriz
		 */
		while (matcher.find())
		{
			++matches;
		}
		return matches;
	}

	public void Print() {
		// Değerler ekrana yazdırılır
		System.out.println("Operator Bilgisi:");
		System.out.println("\tTekli Operator Sayisi: " + tekliOperatorSayisi);
		System.out.println("\tIkili Operator Sayisi: " + ikiliOperatorSayisi);
		System.out.println("\tSayisal Operator Sayisi: " + sayisalOperatorSayisi);
		System.out.println("\tIliskisel Operator Sayisi: " + iliskiselOperatorSayisi);
		System.out.println("\tMantiksal Operator Sayisi: " + mantiksalOperatorSayisi);
		System.out.println("Operand Bilgisi:");
		System.out.println("\tToplam Operand Sayisi: " + operandSayisi);
	}
}
