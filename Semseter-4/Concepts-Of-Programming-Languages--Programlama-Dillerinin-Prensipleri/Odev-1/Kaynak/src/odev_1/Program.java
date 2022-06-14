package odev_1;

import java.nio.file.Files;
import java.nio.file.Paths;

/**
* 	 @author		Yusuf Ozaslan
* 	 @class			1. ogretim A grubu 
*	 @No			B201210033
* 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
*	 @since			17/03/2022
*	 @assignment	1. Odev
**/

public class Program {
	
	public static String Read_File_As_String(String javaFile) throws Exception {
		// Dosya string olarak okunur ve dataOfJavaFile değişkenine atanır.
		String dataOfJavaFile  = new String(Files.readAllBytes(Paths.get(javaFile)));
		return dataOfJavaFile;
	}

	public static void main(String[] args) {
		try {// Lexical nesnesi oluşturulur ve fonksiyondan gelen string veri kurucu fonksiyona gönderilir.
			String dataOfJavaFile = Read_File_As_String(args[0]);
			Lexical lex = new Lexical(dataOfJavaFile);
			lex.Print();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		System.out.println("\nNOT: ikili ve tekli operatorler hesaplanirken sadece sayisallar degil, mantiksal ve iliskisel operatorler de dikkate alinmistir.\n");
	}
}
