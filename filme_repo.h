//
// Created by dusce on 4/3/2023.
//

#ifndef FILME_FILME_REPO_H
#define FILME_FILME_REPO_H
//#include <Vector>
#include "vector.h"
#include <string>
#include <iostream>
#include "filme.h"

using namespace std;

class FilmRepo {
public:
    FilmRepo() = default;
    FilmRepo(const FilmRepo& ot) = delete;
    void addFilm(Film& f);
    void deleteFilm(int id);
    void updateFilm(int id, string titlu, string gen, int an, string actor_principal);
    const Vector<Film> getAll() const noexcept; //nu arunca exceptii
    int getSize();
    const Film& getFilm(int id) const;
    int findFilm(int id) const;
    bool exista(int id) const;

    Vector<Film> filme;
};

class FilmRepoException {
    string msg;
public:
    FilmRepoException(string m) :msg{ m } {}
    //functie friend (vreau sa folosesc membru privat msg)
    friend ostream& operator<<(ostream& out, const FilmRepoException& ex);
};

ostream& operator<<(ostream& out, const FilmRepoException& ex);

void testeRepo();

#endif //FILME_FILME_REPO_H
