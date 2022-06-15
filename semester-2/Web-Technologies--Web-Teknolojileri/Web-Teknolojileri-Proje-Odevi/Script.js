function ValidateForm() {
    const button = document.getElementById("git");
    if (ValidateIsim()) {
        if (ValidatePosta()) {
            if (ValidateSehir()) {
                if (ValidateHobi()) {
                    if (ValidateCinsiyet()) {
                        button.disabled = false;
                    }
                }
            }
        }
    } else {
        button.disabled = true;
    }
}

function ValidateIsim() {
    var isim = document.forms["myForm"]["ad_soyad"].value;
    if (isim == null || isim == "") {
        alert("Lütfen İsminizi Girin!");
        return false;
    } else {
        return true;
    }
}

function ValidatePosta() {
    var p = document.forms["myForm"]["E_Posta"].value;
    var str1 = document.getElementById("Email").value;
    var et = str1.indexOf("@");
    if (p == "" || et == -1) {
        if (et == -1) {
            alert("Lütfen E-Posta Adresine '@' ekleyin!");
        }
        return false;
    } else {
        return true;
    }
}

function ValidateSehir() {
    var sehir = document.getElementById("sehir");
    if (sehir.selectedIndex == 0) {
        alert("Lütfen Şehir Seçiniz!");
        return false;
    } else {
        return true;
    }
}

function ValidateHobi() {

    var hobi = document.getElementsByClassName("chbx");
    if (hobi[0].checked) {
        return true;
    } else if (hobi[1].checked) {
        return true;
    } else if (hobi[2].checked) {
        return true;
    } else {
        alert("Lütfen Hobi Seçiniz!");
        return false;
    }
}

function ValidateCinsiyet() {
    var ERKEK = document.getElementById("ERKEK");
    var KADIN = document.getElementById("KADIN");
    if (ERKEK.checked) {
        return true;
    } else if (KADIN.checked) {
        return true;
    } else {
        alert("Lütfen Cinsiyet Seçiniz!");
        return false;
    }

}