# Proiect_2_POO
Clase:
Am folosit 3 clase:
	- class film (clasa de baza)
	- class film_sf (clasa derivata)
	- class film_actiune (clasa derivata)
- Clasa film contine constructor de initializare, parametrizat si de copiere, destructor, variabile si 3 functii (2 virtuale si una de tip static).
- Clasa film_sf contine constructor de initializare, parametrizat (prin care se evidentiaza transmiterea parametrilor catre constructorul din clasa de baza) si de copiere, destructor, variabile si o functie.
- Clasa film_actiune contine constructor de initializare, parametrizat (prin care se evidentiaza transmiterea parametrilor catre constructorul din clasa de baza) si de copiere, destructor, variabile si o functie.

Constructori si destructori:
Cele 3 clase au constructori de initializare, parametrizati, de copiere si destructori.

Supraincarcarea operatorilor:
Am supraincarcat operatorul de citire >>, de afisare << si operatorul ==.

Functii:
- Functia verifica_genul_filmului (a clasei film) verifica daca genul filmului este sf sau actiune si pune filmele sf in vectorul lista_filme_sf si filmele de actiune in lista_filme_actiune. De asemenea, am facut aceasta functie si pentru clasele film_sf si film_actiune.
- Functia verifica_rating (a clasei film) verifica daca rating >= 8 si afiseaza daca filmul este apreciat sau nu.
- Functia afiseaza_filme (a clasei film) verifica daca rating >= 8 si afiseaza daca filmul este apreciat sau nu.

Meniu:
- Daca citeste 1: citeste un film, pe care mai apoi il verifica daca este un film apreciat sau nu, verificand daca are rating >= 8.
- Daca citeste 2: testeaza constructorul din clasa film_sf.
- Daca citeste 3: testeaza constructorul din clasa film_actiuhne.
- Daca citeste 4: incheie programul.

main:
Citesc n filme, le bag intr-un vector, verific pt fiecare ce gen sunt cu ajutorul functiei verifica_genul_functiei, apoi afisez vectorii care contin filmele si apelez functia meniu.
