<?php
/*
 * a fájlban tárolt tartalom feldolgozása, a tartalom előkészítése.
 * a fájl kötött formátumú:
 * alcim: szöveg			-> ez egy alcím az oldalra
 * content: több sor szöveg -> az elem után a sorban nem lehet szöveg,
 * 							   új sorban kezdődhet a tartalmi rész
 * 							   lehet az oldal tartalma, vagy a csempék
 * 							   tartama is, tartalmazhat lista elemeket
 * 							   feldolgozáskor sortörés kerül a sor végére
 * 							   lezáró eleme a '!q:'
 * !q:						-> lezárja a többsoros 'content' elemet
 * fs:						-> felsorolás kezdete, csak 'content' elemben
 * 							   fordulhat elő!
 * !fq:						-> felsorolás lezárása
 * tiles:					-> jelzi, hogy csempe tartalom következik
 * 							   ami az oldaon formázva jelenik meg,
 * 							   tartozik hozzá egy kép, egy cím
 * 							   és egy leírás is
 * pict:					-> a csempe képe, a kép az adott mappában
 * 							   van tárolva, így csak egy filenév
 * title: szöveg			-> a csempe címe
 *
 * a szövegfájl tartalmazhat 'alcim' és 'content' elemeket az elején,
 * a 'content' elemen belül 'fs' felsorolás elemet
 * a 'tiels' kulcs után kötött sorrenben 'pict' - 'title' - 'content'
 * elemekből álló hármasokat
 * */

function ao_make_engin($file) {
	$content = file($file);
	$ao_content = $tiles_content = $kimenet = $text_content = NULL;
	$content_prosessing = $tiles_processing = $lista_processing = FALSE;
	foreach ($content as $line){
		$line = trim($line);
		if ($content_prosessing){ #tartalmi rész feldolgozása
			if ($line == "!q:"){  #tartaolm-vége, adatok lezárása, formázása, kiírása
				$text_content = substr_replace($text_content, "", -6, -1);
				$kimenet .= ($tiles_processing) ? "\t\t\t\t\t<p>".$text_content."</p>":$text_content;
				$kimenet .= "\n";
				$text_content = NULL;
				$content_prosessing = FALSE;
				if ($tiles_processing) {
					$tiles_content .= "\t\t\t\t<div class=\"tiles-bar\">\n".$kimenet."\t\t\t\t</div>\n";
					$kimenet = NULL;
				}
			}
			elseif ($line == "!fq:") { #lista feldolgozás vége, lista véglegesítés
		 		$text_content .= "\t\t\t\t<ul>\n".$kimenet."\t\t\t\t</ul>\n";
		 		$lista_processing = FALSE;
				$kimenet = NULL;
			}
			elseif ($lista_processing) $kimenet .= "\t\t\t\t\t<li>".$line."</li>\n";
		 	elseif (is_int(stripos($line, "fs:"))) $lista_processing = TRUE; #listafeldolgozás következik a tartalomban
			else{
				$text_content .= ($tiles_processing) ?  "" : "\t\t\t\t";
				$text_content .= $line."<br>\n ";
			}
		}
		elseif (is_int(stripos($line, "alcim:"))){
			$tomb = explode(":",$line);
			$kimenet .= "\t\t\t\t<h2 class=\"alcim bg-text textbg\">".($tomb[1])."</h2>\n";
		}
		elseif (is_int(stripos($line, "title:"))){
			$tomb = explode(":",$line);
			$kimenet .= "\t\t\t\t\t<span class=\"bg-text textbg\">".$tomb[1]."</span>\n";
		}
		elseif (is_int(stripos($line, "pict:"))){
			$tomb = explode(":",$line);
			$kimenet .= "\t\t\t\t\t<img src=\"".$tomb[1]."\">\n";
		}
		elseif (is_int(stripos($line, "tiles:"))){
			$ao_content = $kimenet;
			$kimenet = NULL;
			$tiles_processing = TRUE;
		}
		elseif (is_int(stripos($line, "content:"))){
			$content_prosessing = TRUE;
		}
		else {
			$kimenet .= $line;
		}
	}
	$ao_content = (empty($ao_content)) ? "\t\t\t<div class=\"tartalom\">\n".$kimenet."\t\t\t</div>\n" : "\t\t\t<div class=\"tartalom\">\n".$ao_content."\t\t\t</div>\n";
	$tiles_content = (empty($tiles_content)) ? "" : "\t\t\t<div class=\"tiles\">\n".$tiles_content."\t\t\t</div>\n";
	return 	$ao_content.$tiles_content;
}
?>
<!-- ao engin loaded -->
