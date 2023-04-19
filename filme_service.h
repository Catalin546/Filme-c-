//
// Created by dusce on 4/3/2023.
//

#ifndef FILME_FILME_SERVICE_H
#define FILME_FILME_SERVICE_H
#include <string>
//#include <Vector>
#include "vector.h"
#include <functional>
#include "validare.h"
#include "filme_repo.h"

//using std::Vector;
using namespace std;

class FilmService {
    FilmValidator& val;

    /*
     Functie de sortare generala
     maiMareF - functie care compara 2 Film, verifica daca are loc relatia mai mare
              - poate fi orice functe (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Film)
              - poate fi functie lambda (care nu capteaza nimic in capture list)
     returneaza o lista sortata dupa criteriu dat ca paramatru
    */
    Vector<Film> generalSort(bool (*maiMicF)(const Film&, const Film&));
    /*
    Functie generala de filtrare
    fct - poate fi o functie
    fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
    returneaza doar animalele care trec de filtru (fct(pet)==true)
    */
    Vector<Film> filtreaza(function<bool(const Film&)> fct);
public:
    FilmService(FilmRepo& rep, FilmValidator& val) : rep{rep }, val{val } {
    }
    //nu permitem copierea de obiecte FilmService
    FilmService(const FilmService& ot) = delete;
    /*
    Adauga un nou pet
    arunca exceptie daca: nu se poate salva, nu este valid
    */
    void adaugaFilmService(int id, string titlu, string gen, int an, string actor_principal);
    void stergeFilmService(Film& f);
    void updateFilmService(int id, string titlu, string gen, int an, string actor_principal);


    Vector<Film> sortDupaTitlu();

    Vector<Film> sortDupaAn();

    Vector<Film> sortDupaAnSiTitlu();

    Vector<Film> filtrareDupaGen(string gen);

    Vector<Film> filtrareDupaAn(int anMin, int anMax);

    FilmRepo& rep;
};
void testService();

#endif //FILME_FILME_SERVICE_H
