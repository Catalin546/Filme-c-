//
// Created by dusce on 4/3/2023.
//

#include "teste.h"
#include "filme_repo.h"
#include "filme_service.h"
#include "validare.h"
#include <cassert>


void testService(){
    //test adauga
    FilmRepo rep;
    FilmValidator val;
    FilmService srv{rep, val};
    srv.adaugaFilmService(1, "Titanic", "Drama", 1997, "Leonardo DiCaprio");
    try{
        srv.adaugaFilmService(1, "Titanic", "Drama", 1997, "Leonardo DiCaprio");
        assert(false);
    }
    catch (FilmRepoException&){
        assert(true);
    }
    assert(rep.getAll().size() == 1);
    assert(rep.getAll()[0].getTitlu() == "Titanic");
    //test sterge
    Film f{1, "Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    srv.stergeFilmService(f);
    assert(rep.getAll().size() == 0);
    //test update
    srv.adaugaFilmService(1, "Titanic", "Drama", 1997, "Leonardo DiCaprio");
    srv.updateFilmService( 1, "Star Wars", "Sci-Fi", 1977, "Mark Hamill");
    assert(rep.getAll().size() == 1);
    assert(rep.getAll()[0].getTitlu() == "Star Wars");
    //test sortare
    srv.adaugaFilmService(2, "Titanic", "Drama", 1997, "Leonardo DiCaprio");
    srv.adaugaFilmService(3, "The Godfather", "Drama", 1972, "Marlon Brando");
    srv.adaugaFilmService(4, "The Shawshank Redemption", "Drama", 1994, "Tim Robbins");
    srv.adaugaFilmService(5, "The Dark Knight", "Action", 2008, "Christian Bale");
    srv.adaugaFilmService(6, "The Lord of the Rings: The Return of the King", "Fantasy", 2003, "Elijah Wood");
    srv.adaugaFilmService(7, "The Good, the Bad and the Ugly", "Western", 1966, "Clint Eastwood");
    srv.adaugaFilmService(8, "The Lord of the Rings: The Fellowship of the Ring", "Fantasy", 2001, "Elijah Wood");
    srv.adaugaFilmService(9, "Inception", "Sci-Fi", 2010, "Leonardo DiCaprio");
    srv.adaugaFilmService(10, "Fight Club", "Drama", 1999, "Brad Pitt");
    srv.adaugaFilmService(11, "Unstoppable", "Action", 2010, "Denzel Washington");

    Vector<Film> v = srv.sortDupaAn();
    assert(v[0].getTitlu() == "The Good, the Bad and the Ugly");
    assert(v[1].getTitlu() == "The Godfather");
    assert(v[2].getTitlu() == "Star Wars");


    v = srv.sortDupaTitlu();
    assert(v[0].getTitlu() == "Fight Club");
    assert(v[1].getTitlu() == "Inception");
    assert(v[2].getTitlu() == "Star Wars");

    v = srv.sortDupaAnSiTitlu();
    assert(v[0].getTitlu() == "The Good, the Bad and the Ugly");
    assert(v[1].getTitlu() == "The Godfather");
    assert(v[2].getTitlu() == "Star Wars");
    assert(v[3].getTitlu() == "The Shawshank Redemption");
    assert(v[4].getTitlu() == "Titanic");

    //test filtrare
    v = srv.filtrareDupaGen("Drama");
    assert(v.size() == 4);

    v = srv.filtrareDupaAn(2000, 2010);
    assert(v.size() == 5);
}

void testValidator(){
    FilmValidator v;
    Film f1{ 1, "Titanic", "Drama", 1997, "Leonardo DiCaprio" };
    Film f2{ 2, "", "Drama", 1997, "Leonardo DiCaprio" };
    Film f3{ 3, "Titanic", "", 1997, "Leonardo DiCaprio" };
    Film f4{ 4, "Titanic", "Drama", -1997, "Leonardo DiCaprio" };
    Film f5{ 5, "Titanic", "Drama", 1997, "" };
    try {
        v.validare(f1);
        assert(true);
    }
    catch (ValidationException& ex) {
        assert(false);
    }
    try {
        v.validare(f2);
        assert(false);
    }
    catch (ValidationException& ex) {
        assert(true);
    }
    try {
        v.validare(f3);
        assert(false);
    }
    catch (ValidationException& ex) {
        assert(true);
    }
    try {
        v.validare(f4);
        assert(false);
    }
    catch (ValidationException& ex) {
        assert(true);
    }
    try {
        v.validare(f5);
        assert(false);
    }
    catch (ValidationException& ex) {
        assert(true);
    }
}

void testeRepo(){
    //teste constructor
    FilmRepo repo;
    assert(repo.getSize() == 0);
    //teste addFilm
    Film f1{1, "Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    Film f2{2, "The Godfather", "Drama", 1972, "Marlon Brando"};
    Film f3{3, "Star Wars: Episode V - The Empire Strikes Back", "Action", 1980, "Mark Hamill"};
    assert(repo.getSize() == 0);
    repo.addFilm(f1);
    assert(repo.getSize() == 1);
    repo.addFilm(f2);
    assert(repo.getSize() == 2);
    repo.addFilm(f3);
    assert(repo.getSize() == 3);
    //teste deleteFilm
    repo.deleteFilm(1);
    assert(repo.getSize() == 2);
    repo.deleteFilm(2);
    assert(repo.getSize() == 1);
    //teste updateFilm
    Film f4{3, "Star Wars: Episode V - The Empire Strikes Back", "Action", 1980, "Mark Hamill"};
    repo.updateFilm(3, "Star Wars: Episode V - The Empire Strikes Back", "Action", 1980, "Mark Hamill");
    assert(repo.getFilm(3).getTitlu() == f4.getTitlu());
    assert(repo.getFilm(3).getGen() == f4.getGen());
    //teste getAll
    Vector<Film> filme = repo.getAll();
    assert(filme.size() == 1);
//    assert(filme[0].getTitlu() == f4.getTitlu());
//    assert(filme[0].getGen() == f4.getGen());
    //teste exista
    assert(repo.exista(3) == true);
    assert(repo.exista(1) == false);
    //teste findFilm
    assert(repo.findFilm(3) == 0);
    assert(repo.findFilm(1) == -1);
    //teste getFilm
    Film f5{3, "Star Wars: Episode V - The Empire Strikes Back", "Action", 1980, "Mark Hamill"};
    cout << "ok1" << endl;
    assert(repo.getFilm(3).getTitlu() == f5.getTitlu());
    cout << "ok2" << endl;
    assert(repo.getFilm(3).getGen() == f5.getGen());
    try {
        cout << "ok3" << endl;
        repo.getFilm(1);
        assert(false);
    }
    catch (FilmRepoException&) {
        cout << "ok4" << endl;
        assert(true);
    }
    cout<<"ok5"<<endl;
    //teste exceptii
    try {
        repo.addFilm(f3);
        assert(false);
    }
    catch (FilmRepoException&) {
        cout << "ok6" << endl;
        assert(true);
    }
    try {
        repo.deleteFilm(1);
        assert(false);
    }
    catch (FilmRepoException&) {
        cout << "ok7" << endl;
        assert(true);
    }
    try {
        repo.updateFilm(1, "Star Wars: Episode V - The Empire Strikes Back", "Action", 1980, "Mark Hamill");
        assert(false);
    }
    catch (FilmRepoException&) {
        cout << "ok8" << endl;
        assert(true);
    }
    cout<<repo.getFilm(3).getTitlu()<<endl;
    cout<< "ok9" << endl;
}
