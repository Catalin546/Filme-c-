//
// Created by dusce on 4/3/2023.
//

#include "filme_service.h"
#include "filme_repo.h"
#include "validare.h"
#include <cassert>

Vector<Film> FilmService::generalSort(bool(*maiMicF)(const Film &, const Film &)) {
    Vector<Film> v{rep.getAll()};//fac o copie
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (!maiMicF(v[i], v[j])) {
                //interschimbam
                Film aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;}

Vector<Film> FilmService::sortDupaAn() {
    return generalSort(cmpAn);
}

Vector<Film> FilmService::sortDupaTitlu() {
    return generalSort(cmpTitlu);
}

Vector<Film> FilmService::sortDupaAnSiTitlu() {
    return generalSort([](const Film &f1, const Film &f2) {
        if (f1.getAn() == f2.getAn()) {
            return f1.getTitlu() < f2.getTitlu();
        }
        return f1.getAn() < f2.getAn();
    });
}

void FilmService::adaugaFilmService(int id, string titlu, string gen, int an, string actor_principal) {
    Film f{id, titlu, gen, an, actor_principal};
    val.validare(f);
    rep.addFilm(f);
}

void FilmService::stergeFilmService(Film &f) {
    rep.deleteFilm(f.getId());
}

void FilmService::updateFilmService(int id, string titlu, string gen, int an, string actor_principal) {
    Film f{id, titlu, gen, an, actor_principal};
    val.validare(f);
    rep.updateFilm(id, titlu, gen, an, actor_principal);
}
Vector<Film> FilmService::filtreaza(function<bool(const Film &)> fct) {
    Vector<Film> rez;
//    for (const auto &film: rep.getAll()) {
//        if (fct(film)) {
//            rez.push_back(film);
//        }
//    }
    for(int i=0;i<rep.getSize();i++){
        if(fct(rep.getAll()[i])){
            rez.push_back(rep.getAll()[i]);
        }
    }

    return rez;}

Vector<Film> FilmService::filtrareDupaGen(string gen) {
    return filtreaza([gen](const Film &f) { return f.getGen() == gen; });
}

Vector<Film> FilmService::filtrareDupaAn(int anMin, int anMax) {
    return filtreaza([=](const Film& f) {
        return f.getAn() >= anMin && f.getAn() <= anMax;
    });
}

