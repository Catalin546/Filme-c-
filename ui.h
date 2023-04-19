//
// Created by dusce on 4/3/2023.
//

#ifndef FILME_UI_H
#define FILME_UI_H
#pragma once
#include "filme_service.h"
#include "filme.h"
class UI {
    FilmService& ctr;
    /*
    Citeste datele de la tastatura si adauga Film
    arunca exceptie daca: nu se poate salva, nu e valid
    */
    void filmeDefault();
    void adaugaUI();
    void stergeUI();
    void modificaUI();
    void cautaUI();
    void afiseazaUI();
    void sortareUI();
    void filtrareUI();
    /*
    Tipareste o lista de animale la consola
    */
    void tipareste(const Vector<Film>& pets);
public:
    UI(FilmService& ctr) : ctr{ ctr } {
    }
    //nu permitem copierea obiectelor
    UI(const UI& ot) = delete;

    void start();
};
#endif //FILME_UI_H
