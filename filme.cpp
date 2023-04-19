//
// Created by dusce on 4/3/2023.
//
#include "filme.h"

bool cmpAn(const Film& f1, const Film& f2) {
    return f1.getAn() < f2.getAn();
}

bool cmpTitlu(const Film& f1, const Film& f2) {
    return f1.getTitlu() < f2.getTitlu();
}

