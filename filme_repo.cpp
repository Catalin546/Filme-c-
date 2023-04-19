//
// Created by dusce on 4/3/2023.
//
#include <cassert>
#include <iostream>
#include <sstream>
#include "filme_repo.h"


using namespace std;

void FilmRepo::addFilm(Film &f) {
    if (exista(f.getId()))
        //cout<< "Filmul exista deja!\n";
        throw FilmRepoException("Filmul exista deja!\n");
    filme.push_back(f);
}

void FilmRepo::deleteFilm(int id) {
    if (!exista(id))
        throw FilmRepoException("Filmul nu exista!\n");
    int poz = findFilm(id);
    filme.erase(filme.begin() + poz);
//    erase_if(filme, [id](const Film& f) {return f.getId() == id; }
}

void FilmRepo::updateFilm(int id, string titlu, string gen, int an, string actor_principal) {
    if (!exista(id))
        throw FilmRepoException("Filmul nu exista!\n");
    int poz = findFilm(id);
    filme[poz].setTitlu(titlu);
    filme[poz].setGen(gen);
    filme[poz].setAn(an);
    filme[poz].setActor_principal(actor_principal);
}

const Vector<Film> FilmRepo::getAll() const noexcept {
    return filme;
}

bool FilmRepo::exista(int id) const {
    for (int i = 0; i < filme.size(); i++)
        if (filme[i].getId() == id)
            return true;
    return false;
}
int FilmRepo::getSize() {
    return filme.size();
}

const Film& FilmRepo::getFilm(int id) const {
    if (!exista(id))
        //cout<< "Filmul nu exista!\n";
        throw FilmRepoException("Filmul nu exista!\n");
    int poz = findFilm(id);
    //cout<< "Filmul cautat este: " << filme[poz].getTitlu() << endl;
    return filme[poz];
}

int FilmRepo::findFilm(int id) const {
    for (int i = 0; i < filme.size(); i++)
        if (filme[i].getId() == id)
            return i;
    return -1;
}

ostream& operator<<(ostream& out, const FilmRepoException& ex) {
    out << ex.msg;
    return out;
}
