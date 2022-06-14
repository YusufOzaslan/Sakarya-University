<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="main.css">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=KoHo&display=swap" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-+0n0xVW2eSR5OomGNYDnhzAbDsOXxcvSN1TPprVMTNDbiYZCxYbOOl7+AMvyTG2x" crossorigin="anonymous">
    <title>Hakkında</title>
</head>

<body>
    <header>
        <div>
            <div> <img src="dortayakliminare.jpg" alt=""></div>
            <div><img src="halk.jpg" alt=""></div>
            <div> <img src="han.jpg" alt=""></div>
            <div> <img src="karpuz.jpg" alt=""></div>
            <div><img src="ongozlu.jpg" alt=""></div>
            <div><img src="kilise.jpg" alt=""></div>
            <div> <img src="sl.jpg" alt=""></div>
            <div><img src="sur.jpg" alt=""></div>
        </div>
        <div class="clear"></div>
        <div style="padding: 1rem;">
            <a class="baslik" href="index.html">HAKKIMDA</a>
            <a class="baslik" href="2Sehrim.html">ŞEHRİM</a>
            <a class="baslik" href="3Ozgecmis.html">ÖZGEÇMİŞİM</a>
            <a class="baslik" href="4Mirasimis.html">MİRASIMIZ</a>
            <a class="baslik" href="5IlgiAlanlarim.html">İLGİ ALANLARIM</a>
            <a class="baslik" href="6iletisim.html">İLETİŞİM</a>
            <a class="baslik" href="7Login.html">GİRİŞ</a>
        </div>
    </header>

    <br><br><br><br><br><br>

    <div class="login">
        <h1 style="text-align: center; padding: 1rem;">VERİLER ALINDI!</h1>
        <div style="font-size: large; padding: 1rem;">
            <label><b>Ad Soyad :</b>  </label>
            <label><?php
                    if (isset($_POST["ad_soyad"]))
                        echo $_POST["ad_soyad"];
                    ?>
            </label>
        </div>
        <div style="font-size: large; padding: 1rem;">
            <label><b>E-Posta Adresi :</b>  </label>
            <label><?php
                    if (isset($_POST["E_Posta"]))
                        echo $_POST["E_Posta"];
                    ?>
            </label>
        </div>
        <div style="font-size: large; padding: 1rem;">
            <label><b>Şehir :</b>  </label>
            <label><?php
                    if (isset($_POST["sehir"]))
                        echo $_POST["sehir"];
                    ?>

            </label>
        </div>
        <div style="font-size: large; padding: 1rem;">
            <label><b>Hobiler :</b>  </label>
            <label>
                <?php
                if (isset($_POST["hobi1"])) echo " Bilgisayar Oyunları, ";
                if (isset($_POST["hobi2"])) echo "Enstrüman Çalmak, ";
                if (isset($_POST["hobi3"])) echo  "Spor Yapmak";
                ?>
            </label>
        </div>
        <div style="font-size: large; padding: 1rem;">
            <label><b> Cinsiyet :</b> </label>
            <label>
                <?php
                if (isset($_POST["cinsiyet"]))
                    echo $_POST["cinsiyet"]; ?>
            </label>
        </div>
    </div>
    <script src="Script.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-gtEjrD/SeCtmISkJkNUaaKMoLD0//ElJ19smozuHV6z3Iehds+3Ulb9Bn9Plx0x4" crossorigin="anonymous"></script>
</body>

</html>