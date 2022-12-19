<?php
session_start();
$ut = $_SERVER['DOCUMENT_ROOT'];			#root basedir to include
$bh = "http://www.talpalatnyivadon.hu/"; #basehome linkekhez
/*
 * nyelvválasztás:
 * 1. nyelv váltásának kérését figyelni
 * 2. egyéb váltás (valamelyik menü, hone link, ...) esetén a
 * 		váltás előtti nyelvet megtartani
 * 3. első megjelenéskor a böngésző nyelvét figyelni
 * 		ha nem HU, akkor EN-re állítani
 * */

function langSet ($newLang, $aktAction) {
	if ($aktAction == "change") {
		$_SESSION["visitorLang"] = $newLang;
	}
	if ($aktAction == "set") {
		$_SESSION["visitorLang"] = ($newLang == "hu") ? "hu" : "en";
	}
	$_SESSION["optionalLang"] = ($_SESSION["visitorLang"] == "hu") ? "en" : "hu";
}

if (!isset($_SESSION['openBgNumber'])) {$_SESSION['openBgNumber'] = 0;}

if (isset($_POST["menuButtonLang"])) {
	langSet($_POST["menuButtonLang"], "change");
}
else {
	$browserLang = (substr($_SERVER["HTTP_ACCEPT_LANGUAGE"], 0, 2));
	isset($_SESSION["visitorLang"]) ?  : langSet($browserLang, "set");
}

include ($ut.'/inc/langtexts.inc');
$la = $_SESSION["visitorLang"];
$alapitvany_nev = ["hu" => "Talpalatnyi Vadon Természetmegőrzési Alapítvány",
				   "en" => "Traces of Wilderness Foundation for Nature Conservation"];

/* az aloldal szöveges tartlom fájl nevének előállítása
 * minden aloldal mappában van két (hu, en) tartalom-fájl
 * ezt dolgozza fel az ao_make_engin fv, ebből állítja
 * elő a tartamat */
$ao_lang_content_file = $la."_content.txt";
?>
