<?php
function menumaker(){
	global $la, $bh, $nav_list;
	$kimenet = "\t\t\t\t<details>
					<summary>
						<img class=\"menu-icon\" src=\"/icons/MENUicon.png\" alt=\"Menu\" >
						<a href=".$bh."><img class=\"menu-icon home-icon\" src=\"/icons/homeicon.png\" alt=\"Menu\" ></a>
					</summary>
					<nav class=\"menu-content2\">\n";
	foreach($nav_list as $sor) {
		$kimenet.="\t\t\t\t\t\t<a href=\"".$bh.$sor['link']."\">".$sor[$la]."</a>\n";
	}
	$kimenet.="\t\t\t\t\t</nav>
				</details>\n";
	return $kimenet;
}
/* A feldolgozó kerete:
 * lista -> ez lesz elrejtve
 * a home osztály alatt...
 * */
$header_logo = ["hu" => "/logos/logoVidraBarna.png", "en" => "/logos/EnglishLogo1.png"];
?>
		<!-- top menubar -->
		<div class="header">
			<form method="POST" id="menuBar"></form>
			<div class="menu-dropdown2">
<?php print menumaker();?>
			</div>
			<div><a href="<?php print $bh;?>"><img src="<?php print $header_logo[$la];?>" alt="Talpalatnyi Vadon logo" class="logomeret"></a></div>
			<div id="fb_link"><a href="https://www.facebook.com/TalpalatnyiVadon" target="_blank"><img src="/icons/fbicon.png" class="fbicon"></a></div>
			<button type="submit" form="menuBar" value="<?php print $_SESSION["optionalLang"]; ?>" name="menuButtonLang"><?php print $_SESSION["optionalLang"]; ?></button>
			<div class="menu_bar_link"><a href="#footer"><?php print $kapcsolat[$la];?></a></div>
			<div class="menu_bar_link"><a href="<?php print $bh.$t1['link'];?>"><?php print $t1[$la]; ?></a></div>
			<div class="menu_bar_link"><a href="<?php print $bh.$tamogatas['link'];?>"><?php print $tamogatas[$la]; ?></a></div>
			<div class="menu_bar_link"><a href="<?php print $bh.$terepi['link'];?>"><?php print $terepi[$la]; ?></a></div>
		</div>
		<!-- end top menubar -->
