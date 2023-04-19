//
// Created by dusce on 4/3/2023.
//

#ifndef FILME_VALIDARE_H
#define FILME_VALIDARE_H
#pragma once
#include <string>
#include "filme.h"
//#include <Vector>
#include "vector.h"


//using std::Vector;
using std::string;
using std::ostream;

class ValidationException {
    Vector<string> msgs;
public:
    ValidationException(const Vector<string>& errors) :msgs{ errors } {}
    //functie friend (vreau sa folosesc membru privat msg)
    friend ostream& operator<<(ostream& out, const ValidationException& ex);
};

ostream& operator<<(ostream& out, const ValidationException& ex);

class FilmValidator {
public:
    void validare(const Film& f);
};

void testValidator();
#endif //FILME_VALIDARE_H
