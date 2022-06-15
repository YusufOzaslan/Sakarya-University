package paket;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class PostgreSQLSurucu implements IVeritabaniRepository{

    private Connection baglan(){

        Connection conn=null;

        try {
            conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/AkilliCihaz",
                    "postgres", "ysusf0033");

            System.out.println("Veritabanına bağlandı!");

        } catch (Exception e) {
            System.out.println("Bağlantı girişimi başarısız!");
            e.printStackTrace();
        }
        return conn;
    }

    @Override
    public boolean kullaniciDogrula(String ad, String sifre) {
        Connection conn=this.baglan();
        String ifade= "SELECT \"kullaniciAdi\",\"sifre\" FROM \"KullaniciHesabi\" WHERE \"kullaniciAdi\"="+"'"+ad+"'"+"AND \"sifre\"="+"'"+sifre+"'";
        try {
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(ifade);
            conn.close();
            if(!rs.next()){
                return false;
            }
            else{
                Araclar.bekle(1000);
                System.out.println("Kullanıcı doğrulandı!");
                return true;
            }
        }
        catch (Exception e){
            e.printStackTrace();
            return false;
        }
    }
}
