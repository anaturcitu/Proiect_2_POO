#include <iostream>
#include <vector>
using namespace std;

///--------------------clase:--------------------
class film
{
public:
    film(std::string denumire, string gen, string regizor, float rating); ///constructor
    film(const film&); ///constructor
    film(); ///constructor
    ~film(); ///destructor

    friend istream& operator>>(istream&, film&);
    friend ostream& operator<<(ostream&, film&);

    bool operator==(film&);
    friend class film_sf;
    friend class film_actiune;

    virtual void verifica_genul_filmului(film& f);
    static void verifica_rating(film& f);
    virtual void afiseaza_filme(film& f);

private:
    string denumire;
    string gen;
    string regizor;
    float rating;
    vector <film> lista_filme_sf;
    vector <film> lista_filme_actiune;
    vector <string> lista_filme_alt_gen;
};

class film_sf: public film
{
public:
    film_sf(string denumire, string gen, string regizor, float rating);
    film_sf(const film_sf&);
    film_sf();
    ~film_sf();

    void verifica_genul_filmului(film& f);

private:
    string denumire;
    string regizor;
    float rating;
};

class film_actiune: public film
{
public:
    film_actiune(string denumire, string gen, string regizor, float rating);
    film_actiune(const film_actiune&);
    film_actiune();
    ~film_actiune();

    void verifica_genul_filmului(film& f);
private:
    string denumire;
    string regizor;
    float rating;
};

///--------------------constructori:--------------------
film::film(string denumire, string gen, string regizor, float rating) ///constructor class film
{
    this->denumire = denumire;
    this->gen = gen;
    this->regizor = regizor;
    this->rating = rating;
}

film::film(const film& film) ///constructor de copiere class film
{
    denumire = film.denumire;
    gen = film.gen;
    regizor = film.regizor;
    rating = film.rating;
}

film::film(){} ///constructor class film


film_sf::film_sf(string denumire, string gen, string regizor, float rating) : film(denumire, gen, regizor, rating) ///constructor class film_sf
{
    this->denumire = denumire;
    this->regizor = regizor;
    this->rating = rating;
    cout << " A fost apelat constructorul din clasa film_sf.";
}

film_sf::film_sf(const film_sf& film_sf) ///constructor de copiere class film_sf
{
    denumire = film_sf.denumire;
    regizor = film_sf.regizor;
    rating = film_sf.rating;
}

film_sf::film_sf(){}; ///constructor class film_sf


film_actiune::film_actiune(string denumire, string gen, string regizor, float rating) : film(denumire, gen, regizor, rating) ///constructor
{
    this->denumire = denumire;
    this->regizor = regizor;
    this->rating = rating;
    cout << " A fost apelat constructorul din clasa film_actiune.";
}

film_actiune::film_actiune(const film_actiune& film_actiune) ///constructor de copiere class film_actiune
{
    denumire = film_actiune.denumire;
    regizor = film_actiune.regizor;
    rating = film_actiune.rating;
}

film_actiune::film_actiune(){} ///constructor

///--------------------destructori:--------------------
film::~film() {}

film_sf::~film_sf() {}

film_actiune::~film_actiune() {}

///--------------------supraincarcarea operatorilor:--------------------
istream& operator>>(istream& in, film& f) ///supraincarcarea operatorului >>
{
    in>>f.denumire>>f.gen>>f.regizor>>f.rating;
    return in;
}

ostream& operator<<(ostream& out, film& f) ///supraincarcarea operatorului <<
{
    out<<f.denumire<<' '<<f.gen<<' '<<f.regizor<<' '<<f.rating<<"\n";
    return out;
}

bool film::operator==(film& f2) ///supraincarcarea operatorului ==
{
    return (this->denumire == f2.denumire && this->gen == f2.gen && this->regizor == f2.regizor && this->rating == f2.rating);
}

///--------------------functiile din film, film_sf, film_actiune:--------------------
void film::verifica_genul_filmului(film& f) ///functia verifica daca genul filmului este sf sau actiune si pune filmele sf
{                                           ///in vectorul lista_filme_sf si filmele de actiune in lista_filme_actiune
    string x=string(f.denumire);
    try { ///am tratat exceptiile cu try-catch, atunci cand filmele au alt gen sunt adaugate in vectorul lista_filme_alt_gen
        if (f.gen[0] != 'a' && f.gen[0] != 's')
            throw x;
        else {
            if (f.gen[0] == 's')
                lista_filme_sf.push_back(f);
            else if (f.gen[0] == 'a')
                lista_filme_actiune.push_back(f);
        }
    }
    catch (string error) {
        lista_filme_alt_gen.push_back(error);
    }
}

void film_sf::verifica_genul_filmului(film& f)
{
    string x=string(f.denumire);
    try {
        if(f.gen[0] != 'a' && f.gen[0] != 's')
            throw x;
        else if(f.gen[0] == 's')
            lista_filme_sf.push_back(f);
    }
    catch (string error) {
        lista_filme_alt_gen.push_back(error);
    }
}

void film_actiune::verifica_genul_filmului(film& f) {
    string x = string(f.denumire);
    try {
        if (f.gen[0] != 'a' && f.gen[0] != 's')
            throw x;
        else if (f.gen[0] == 'a')
            lista_filme_actiune.push_back(f);
    }
    catch (string error) {
        lista_filme_alt_gen.push_back(error);
    }
}

void film::verifica_rating(film& f) ///verifica daca rating >= 8 si afiseaza daca filmul este apreciat sau nu
{
    if(f.rating >= 8)
        cout<<"Filmul este apreciat.";
    else
        cout<<"Filmul nu este apreciat.";
}

void film::afiseaza_filme(film& f)
{
    if(!lista_filme_sf.empty()) { ///afiseaza filmele sf
        cout << "Filmele sf sunt:\n";
        while (!lista_filme_sf.empty()) {
            cout << lista_filme_sf.back();
            lista_filme_sf.pop_back();
        }
    }
    if(!lista_filme_actiune.empty()) { ///afiseaza filmele de actiune
        cout << "Filmele de actiune sunt:\n";
        while (!lista_filme_actiune.empty()) {
            cout << lista_filme_actiune.back();
            lista_filme_actiune.pop_back();
        }
    }
    if(!lista_filme_alt_gen.empty()) { ///afiseaza filmele care au alt gen
        cout << "Filmele care au alt gen sunt:\n";
        while (!lista_filme_alt_gen.empty()) {
            cout << lista_filme_alt_gen.back()<<"\n";
            lista_filme_alt_gen.pop_back();
        }
    }
}

///---------------Meniu:---------------
static void meniu()
{
    film f1;
    film_sf f2;
    static int optiune;
    cout << "\n\nAlege optiunea:";
    cin >> optiune;
    while(optiune)
    {
        switch(optiune)
        {
            case 1: {
                cout << "Se citeste un film:"; ///citeste un film, pe care mai apoi il verifica daca este un film apreciat sau nu, verificand daca are rating >= 8
                cin >> f1;
                f1.verifica_rating(f1);
                break;
            }
            case 2: { ///daca a fost citit 2, testeaza constructorul din clasa film_sf
                cout << "Testare constructor din clasa film_sf:";
                film_sf f2("Interstellar", "sf", "Cristopher Nolan", 8.6);
                break;
            }

            case 3: { ///daca a fost citit 3, testeaza constructorul din clasa film_actiune
                cout << "Testare constructor din clasa film_actiune:";
                film_actiune("The Avengers", "actiune", "Joe Russo", 8);
                break;
            }

            case 4: { ///incheie programul
                cout << "Incheiere program.";
                return;
            }
        }
        cout<<"\nDoriti alta optiune?\n";
        cin>>optiune;
    }
}

int main() {
    int n, i;
    film f1;
    film f;
    vector<film> lista_filme;
    cin >> n;
    for (i = 0; i < n; i++) {
        film* f2 = new film_sf();
        cin >> *f2;
        lista_filme.push_back(*f2);
        f.verifica_genul_filmului(*f2);
    }

    f.afiseaza_filme(f);
    meniu();
}
