<!DOCTYPE html>
<?php include($_SERVER['DOCUMENT_ROOT']."/inc/preparation.inc");
/* footer info contain datas */
$fic_vat = ["hu" => "adószám", "en" => "VAT number"];
$fic_bank = ["hu" => "számlaszám", "en" => "bank account"];
$fic_bank_number = ["hu" => "11742094-26998411", "en" => "HU56 11742094-26998411"];
$doc1 = ["hu" => "Dokumentumok", "en" => "Documents"];
$doc2 = ["hu" => "Átláthatóság", "en" => "Transparency"];
$file_path = "/atlathatosag/";
$file1 = ["hu" => "Adományok", "huFILE" => "AdomanyokFelhasznalasTalpalatnyiVadonAlapitvany1.pdf",
		  "en" => "Donations", "enFILE" => "UseofDonations.pdf"];
$file2 = ["hu" => "Pályázatok", "huFILE" => "NyertesPalyazatokTalpalatnyiVadonAlapitvany1.pdf",
		  "en" => "Grants", "enFILE" => "CurrentGrants.pdf"];
$file3 = ["hu" => "Alapító okirat", "huFILE" => "AlapitoOkirat.pdf",
		  "en" => "Founding document", "enFILE" => "AlapitoOkirat.pdf"];
$file4 = ["hu" => "Adatkezelés", "huFILE" => "adatvedelem.pdf", "en" => "Privacy Policy", "enFILE" => "adatvedelem.pdf"];
//~ $file = ["hu" => "", "huFILE" => "", "en" => "", "enFILE" => ""];
$footer_logo = ["hu" => "/logos/logoVidraZoldBarna4.png", "en" => "/logos/EnglishLogo2.png"];
?>
<html lang="<?php print $_SESSION["visitorLang"]; ?>">
	<head>
		<title><?php print $title[$la]; ?></title>
		<meta name="robots" content="all">
		<meta name="description" content="">
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<?php
			//~ if (strlen($_SERVER['PHP_SELF']) == 10) {
				//~ print "<link rel=\"stylesheet\" type=\"text/css\" href=\"elsooldal.css\">\n";
			//~ }
			//~ else {
				//~ print "<link rel=\"stylesheet\" type=\"text/css\" href=\"../aloldal.css\">\n";
			//~ }
		?>
		<link rel="stylesheet" type="text/css" href="../alap.css">
		<link rel="stylesheet" type="text/css" href="../elsooldal.css">
		<link rel="stylesheet" type="text/css" href="../aloldal.css">

	</head>
	<body>
		<!-- statistic data collecting about screen sizes -->
		<script src="/js/jquery-3.6.0.min.js"></script>
        <script>
            $(document).ready(function () {
                console.log("ready!");
                var sendStat = {
                	lM:  $(window).width() + " x " + $(window).height(),
					kM: window.screen.width + " x " + window.screen.height
                };
				$.ajax({
				    type: 'POST',
				    url: 'stat.php',
				    data: JSON.stringify(sendStat),
				    success: function(response) { console.log(response) },
				    contentType: "application/json",
				    dataType: 'json'
				});
            });
		</script>
		<!-- end script -->
<?php include($ut."/inc/header.inc"); ?>
		<!-- main content -->
		<?php include("mainPage.inc"); ?>
		<!-- end main content -->
		<!-- footer content -->
		<div class="footer" id="footer">
			<img class="footer-logo" src="<?php print $footer_logo[$la];?>" alt="Talpalatnyi Vadon LOGO">
			<div class="footer-info-contain">
				<span class="bg-text"><?php print $alapitvany_nev[$la];?></span>
				<span>info@talpalatnyivadon.hu</span>
				<span>+36 20 235-5488</span>
				<span><? print $fic_vat[$la];?>: 18129748-1-13</span>
				<span><? print $fic_bank[$la].": ".$fic_bank_number[$la];?></span>
			</div>
			<div class="footer-required-content">
				<div class="dropup-menu dokuments">
					<div class="dropup-head"><?php print $doc1[$la]."<br>".$doc2[$la];?></div>
					<div class="dropup-content">
						<a href="<?php print $file_path.$file1[$la."FILE"];?>" target="_blank"><?php print $file1[$la];?></a><br>
						<a href="<?php print $file_path.$file2[$la."FILE"];?>" target="_blank"><?php print $file2[$la];?></a><br>
						<a href="<?php print $file_path.$file3[$la."FILE"];?>" target="_blank"><?php print $file3[$la];?></a><br>
						<a href="<?php print $file_path.$file4[$la."FILE"];?>" target="_blank"><?php print $file4[$la];?></a><br>
					</div>
				</div>
			</div>
			<div class="copirights text-bg bgtext">
					Talpalatnyi Vadon &#169; MINDEN JOG FENNTARTVA | HTML workmanship by csibe525
			</div>
		</div>
		<!-- end footer content -->
	</body>
</html>
