# [Silver V] Kurjeris - 7244 

[문제 링크](https://www.acmicpc.net/problem/7244) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 3월 29일 18:03:44

### 문제 설명

<p>Bitlandijos maisto pristatymo įmonėje „Unter Valgyt” dirba du kurjeriai. Kurjeriai pradeda darbą tuo pačiu laiku – ryte (Bitlandijos laiku t = 0 minučių). Dienos metu gaunami užsakymai, apie kiekvieną kurių yra žinoma:</p>

<ul>
	<li>Užsakymo gavimo laikas (minutėmis);</li>
	<li>Vertė, kiek kurjeris uždirbs už jo įvykdymą;</li>
	<li>Laikus, kiek užtruktų kiekvienas kurjeris įvykdyti užsakymą (minutėmis). Vieno užsakymo įvykdymo laikai yra skirtingi abiems kurjeriams.</li>
</ul>

<p>Užsakymas yra priskiriamas laisvam kurjeriui (tuo metu nevykdančiam jokio užsakymo), kuris jį įvykdytų greičiausiai. Jei tuo metu abu kurjeriai yra užimti, užsakymas dingsta, nes klientas kreipiasi į kitą įmonę.</p>

<p>Kurjeriai baigia dirbti, kai įvykdo visus per dieną gautus užsakymus.</p>

<p>Suskaičiuokite, kiek kiekvienas kurjeris uždirbs per dieną.</p>

### 입력 

 <p>Pirmoje eilutėje yra pateiktas užsakymų skaičius M. Kitose M eilučių duota užsakymų informacija:</p>

<ul>
	<li>t – užsakymo gavimo laikas minutėmis nuo darbo dienos pradžios. Visų užsakymų laikai yra skirtingi ir pateikti didėjimo tvarka.</li>
	<li>v – užsakymo vertė, kurią kurjeris uždirbs jį įvykdęs.</li>
	<li>z<sub>1</sub>, z<sub>2</sub> – laikai, kurie reiškia, kad i-asis kurjeris įvykdyti šį užsakymą užtruks z<sub>i</sub> minučių. Abu vieno užsakymo laikai yra skirtingi.</li>
</ul>

### 출력 

 <p>Vienoje eilutėje pateikite du skaičius – kiek uždirbs kiekvienas kurjeris tą dieną.</p>

