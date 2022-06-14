<!doctype html>
<html lang="en">

<head>
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=KoHo&display=swap" rel="stylesheet">
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="main.css">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-+0n0xVW2eSR5OomGNYDnhzAbDsOXxcvSN1TPprVMTNDbiYZCxYbOOl7+AMvyTG2x" crossorigin="anonymous">

    <title>GİRİŞ!</title>
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
        <h1 style="text-align: center; padding: 1rem;">HOŞGELDİNİZ!</h1>
        <div style="font-size: large; padding: 1rem;">
            <label> <b>E-Mail :</b>  </label>
            <label><?php
                    if (isset($_POST["email"]) && $_POST["email"] == "yusuf.ozaslan@ogr.sakarya.edu.tr")
                        echo $_POST["email"];
                    else
                        header("location: 7Login.html ")
                    ?>
            </label>
        </div>
        <div style="font-size: large; padding: 1rem;">
            <label><b>Parola : </b> </label>
            <label><?php
                    if (isset($_POST["parola"]) && $_POST["parola"] == "b201210033")
                        echo $_POST["parola"];
                    else header("location: 7Login.html ")
                    ?>
            </label>
        </div>
    </div>



</html>