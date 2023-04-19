//
// Created by dusce on 4/3/2023.
//
#include "filme.h"
#include "filme_repo.h"
#include "validare.h"
#include "ui.h"
#include "filme_service.h"

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void UI::tipareste(const Vector<Film>& filme) {
    cout << "Filme:\n";
//    for (const auto& film : filme) {
//        cout<< film.getTitlu() << " " << film.getGen() << " " << film.getAn() << " " << film.getActor_principal() << '\n';
//    }
    for(int i=0; i<filme.size(); i++)
        cout<< filme[i].getTitlu() << " " << filme[i].getGen() << " " << filme[i].getAn() << " " << filme[i].getActor_principal() << '\n';
    cout << "Sfarsit lista filme\n";
}

void UI::adaugaUI() {
    cout<< "Dati Id:";
    int id;
    cin >> id;
    cout << "Dati titlul:";
    string titlu;
    cin >> titlu;
    cout << "Dati genul:";
    string gen;
    cin >> gen;
    cout << "Dati anul:";
    int an;
    cin >> an;
    cout << "Dati actorul principal:";
    string actor_principal;
    cin >> actor_principal;
    Film f{id, titlu, gen, an, actor_principal };
    ctr.adaugaFilmService(id , titlu, gen, an, actor_principal);
    cout<< "Filmul a fost adaugat cu succes!\n";
}

void UI::stergeUI() {
    cout << "Dati Id:";
    int id;
    cin >> id;
    ctr.stergeFilmService(const_cast<Film &>(ctr.rep.getFilm(id)));
    cout<< "Filmul a fost sters cu succes!\n";
}

void UI::modificaUI() {
    cout << "Dati Id:";
    int id;
    cin >> id;
    cout << "Dati titlul nou:";
    string titlu;
    cin >> titlu;
    cout << "Dati genul nou:";
    string gen;
    cin >> gen;
    cout << "Dati anul nou:";
    int an;
    cin >> an;
    cout << "Dati actorul principal nou:";
    string actor_principal;
    cin >> actor_principal;
    Film f{id, titlu, gen, an, actor_principal };
    ctr.updateFilmService(id , titlu, gen, an, actor_principal);
    cout<< "Filmul a fost modificat cu succes!\n";
}

void UI::filmeDefault() {
    ctr.adaugaFilmService(1, "Star Wars", "Sci-Fi", 1977, "Mark Hamill");
    ctr.adaugaFilmService(2, "Titanic", "Drama", 1997, "Leonardo DiCaprio");
    ctr.adaugaFilmService(3, "The Godfather", "Drama", 1972, "Marlon Brando");
    ctr.adaugaFilmService(4, "The Shawshank Redemption", "Drama", 1994, "Tim Robbins");
    ctr.adaugaFilmService(5, "The Dark Knight", "Action", 2008, "Christian Bale");
    ctr.adaugaFilmService(6, "The Lord of the Rings: The Return of the King", "Fantasy", 2003, "Elijah Wood");
    ctr.adaugaFilmService(7, "The Good, the Bad and the Ugly", "Western", 1966, "Clint Eastwood");
    ctr.adaugaFilmService(8, "The Lord of the Rings: The Fellowship of the Ring", "Fantasy", 2001, "Elijah Wood");
    ctr.adaugaFilmService(9, "Inception", "Sci-Fi", 2010, "Leonardo DiCaprio");
    ctr.adaugaFilmService(10, "Fight Club", "Drama", 1999, "Brad Pitt");
    ctr.adaugaFilmService(11, "Unstoppable", "Action", 2010, "Denzel Washington");
}

void UI::start() {
    string gen;
    filmeDefault();
    while (true) {
        cout << "Meniu:\n";
        cout << "1 adauga film\n2 tipareste\n3 sort dupa titlu\n4 sort dupa an\n5 sort dupa an+titlu\n6 filtrare dupa gen\n7 filtrare dupa an min max\n8 sterge film\n9 modifica film\n0 iesire\nDati comanda:";
        int cmd;
        cin >> cmd;
        try {
            switch (cmd) {
                case 1:
                    adaugaUI();
                    break;
                case 2:
                    tipareste(ctr.rep.getAll());
                    break;
                case 3:
                    tipareste(ctr.sortDupaTitlu());
                    break;
                case 4:
                    tipareste(ctr.sortDupaAn());
                    break;
                case 5:
                    tipareste(ctr.sortDupaAnSiTitlu());
                    break;
                case 6:
                    cout << "Dati un gen:";
                    cin >> gen;
                    tipareste(ctr.filtrareDupaGen(gen));
                    break;
                case 7:
                    cout << "Dati an minim:";
                    int anMin;
                    cin >> anMin;
                    cout << "Dati an maxim:";
                    int anMax;
                    cin >> anMax;
                    tipareste(ctr.filtrareDupaAn(anMin,anMax));
                    break;
                case 8:
                    stergeUI();
                    break;
                case 9:
                    modificaUI();
                    break;
                case 0:
                    return;
                default:
                    cout << "Comanda invalida\n";
            }
        }
        catch (const FilmRepoException& ex) {
            cout << ex <<'\n';
        }
        catch (const ValidationException& ex) {
            cout << ex << '\n';
        }
    }
}