<?php # kezdőoldal tartalma

function slideMaker() {
	global $la;
	$sliderTexts = [ 1 => ["hu" => "Éltető változatosság", "en" => "Vital diversity"],
					 2 => ["hu" => "Összefüggő élőhelyek", "en" => "A network of habitats"],
					 3 => ["hu" => "Vad tájak", "en" => "Wild landscapes"],
					 4 => ["hu" => "Tudatos közösségek", "en" => "Conscious communities"],
					 5 => ["hu" => "Izgalmas találkozások", "en" => "Gripping encounters"]
					];
	$nyito = rand(1, 5);
	$kimenet = "\t\t\t\t<ul class=\"slider\">\n";
	for ($i=1; $i<6; $i++){
		$jelolo = ($i == $nyito) ? " checked":"";
		$kimenet .= "\t\t\t\t\t<li>\n".
					"\t\t\t\t\t\t<input type=\"radio\" id=\"slide".$i."\" name=\"slide\"".$jelolo.">\n".
					"\t\t\t\t\t\t<label for=\"slide".$i."\"></label>\n".
					"\t\t\t\t\t\t<div>".$sliderTexts[$i][$la]."</div>\n".
					"\t\t\t\t\t\t<img src=\"/bg-pict/kezdolap".$i.".jpg\" alt=\"Panel ".$i."\">\n".
					"\t\t\t\t\t</li>\n";
	}
	$kimenet .= "\t\t\t\t</ul>\n";
	return $kimenet;
}
$vizio = ["hu" => "víziónk",
"en" => "vision"];
$vizio_txt = ["hu" => "Az ember a környezetét a legnagyobb mértékben átalakító faj ezen a bolygón. Mérnökösködésünkkel már számtalan Földlakó társunkat a kihalás szélére sodortuk. Pedig ezen társaink nélkülözhetetlenek az élő rendszerekben, amelyekkel az elmúlt évmilliók során együtt fejlődtek, egymással kölcsönhatásban.
Mi olyan bolygón szeretnénk élni, ahol az emberi közösségeknek tagja és partnere minden földi élőlény, ahol embertársaink a természet változatosságát értéknek és az élet legnagyobb kincsének tekintik.",
"en" => "Humans are transforming the planet to an unprecedented extent. Our engineering threatens innumerable species with extinction. However, all these beings are indispensable within existing ecosystems, in which they have been evolving interdependently for millions of years. We would like to have a world on which human communities welcome as members and partners all other surrounding species, and on which our fellow humans regard biodiversity as the most valuable resource of all."];
$tamogatok = ["hu" => "Támogatók / Partnerek",
			  "en" => "Backing & Partners"];
$focim = ["hu" => "Minden vadon számít", "en" => "Every Wild Place Matters"];
$alcim = ["hu" => "Segíts neki!", "en" => "Let it happen!"];


?>
<div class="nyitooldal">
			<div class="nyitolap">
<?php print slideMaker();?>
				<div><h1 id="firstText"><?php print $focim[$la]; ?></h1></div>
				<div class="downArrow"><a href="#intro" referrerpolicy="origin">&nbsp;D</a></div>
			</div>
			<div id="intro" class="intro">
				<h5 class="bg-text textbg"><?php print $alapitvany_nev[$la];?></h5>
				<div class="mission">
					<h4 class="bg-text textbg"><?php print $vizio[$la];?></h4>
					<p><?php print $vizio_txt[$la];?></p>
				</div>
			</div>
			<div class="sor">
				<div class="nagy bal bg1"><a href="<?php print $t2["link"]?>"><h4><?php print $t2[$la]?></h4></a></div>
				<div class="kicsi">
					<div class="bg2"><a href="<?php print $t1["link"]?>"><h5><?php print $t1[$la]?></h5></a></div>
					<div class="bg3"><a href="<?php print $t8["link"]?>"><h5><?php print $t8[$la]?></h5></a></div>
				</div>
			</div>
			<div class="sor">
				<div class="kicsi dupla">
					<div class="bg5"><a href="<?php print $t5["link"]?>"><h5><?php print $t5[$la]?></h5></a></div>
					<div class="bg4"><a href="<?php print $t4["link"]?>"><h5><?php print $t4[$la]?></h5></a></div>
					<div class="bg7"><a href="<?php print $t7["link"]?>"><h5><?php print $t7[$la]?></h5></a></div>
					<div class="bg6"><a href="<?php print $t6["link"]?>"><h5><?php print $t6[$la]?></h5></a></div>
				</div>
				<div class="nagy jobb bg8"><a href="<?php print $t3["link"]?>"><h4><?php print $t3[$la]?></h4></a></div>
			</div>
			<div class="tamogatok">
				<h4 class="bg-text textbg"><?php print $tamogatok[$la];?></h4>
				<div class="partnerlogok">
					<div class="partner p1">
						<a href="https://www.ckszkpestmegye.com" target="_blank"><img src="/logos/PestKicsi.png" alt="Civil Központ"></a>
						<span class="partnernev">Pest Megyei Civil Közösségi Szolgáltató Központ</span>
					</div>
					<div class="partner p2">
						<a href="https://www.borzsony.org" target="_blank"><img src="/logos/borzsonyalapitvany300ppi.png" alt="Börzsöny Alapítvány"></a>
						<span class="partnernev">Börzsöny Alapítvány</span>
					</div>
					<div class="partner p8">
						<a href="https://www.depo-z.hu" target="_blank"><img class="dz" src="/logos/depoz.png" alt="DEPO-Z Zebegény, kajak, kenu, bicikli"></a>
						<span class="partnernev">DEPO-Z Zebegény</span>
					</div>
					<div class="partner p3">
						<a href="https://www.magosfa.hu" target="_blank"><img src="/logos/magosfa.png" alt="Magosfa Környezeti Nevelési és Ökoturisztikai Alapítvány"></a>
						<span class="partnernev">Magosfa Környezeti Nevelési és Ökoturisztikai Alapítvány</span>
					</div>
					<div class="partner p6"><a href="https://www.vadonleső.hu" target="_blank"><img src="/logos/vadonleso.png" alt="Vadonleső, önkéntesekkel a természetért"></a>
						<span class="partnernev">Vadonleső</span>
					</div>
					<div class="partner p7">
						<a href="https://5f74d38eabf8c.site123.me/" target="_blank"><img src="/logos/tavcsonyomosBordo.png" alt="Vadonlesők közössége természetvédő egyesület"></a>
						<span class="partnernev">Vadonlesők Közössége Természetvédő Egyesület</span>
					</div>
					<div class="partner p4 valaki">
						<span class="partnernev">A Te helyed</span>
					</div>
					<div class="partner p10">
						<a href="https://ipolytolgyes.hu" target="_blank"><img src="/logos/Ipolytolgyes.jpg" alt="Ipolytölgyes Község Önkormányzat"></a>
						<span class="partnernev">Ipolytolgyes Község Önkormányzat</span>
					</div>
					<div class="luft p5"></div>
					<div class="luft p9"></div>
				</div>
				<div class="tamogatok-vidralogo">&nbsp;</div>
			</div>
			<div class="pajazat">
				<div class="tamogatoszoveg bg-text textbg">A honlap fejlesztését támogatta:</div>
				<div class="pajazatlogo"><img src="/logos/NEA_ME_BGA.png" alt="Logocsoport: NEA, Miniszterelnökség, Bethlen Gábor Alapkezelő Zrt" /></div>
			</div>
		</div>
