//
// Created by dusce on 4/3/2023.
//

#include "validare.h"
#include <cassert>
 using namespace std;

void FilmValidator::validare(const Film& f) {
    Vector<string> errors;
    if (f.getTitlu().size() <= 1)
        errors.push_back("Titlul nu poate fi vid");
    if (f.getGen().size() <= 1)
        errors.push_back("Genul nu poate fi vid");
    if (f.getAn() < 0)
        errors.push_back("Anul nu poate fi negativ");
    if (f.getActor_principal().size() <= 1)
        errors.push_back("Actorul nu poate fi vid");
    if (errors.size() > 0)
        throw ValidationException(errors);
}

ostream& operator<<(ostream& out, const ValidationException& ex) {
//    for (const auto& msg : ex.msgs) {
//        out << msg<<" ";
//    }
    for (int i = 0; i < ex.msgs.size(); i++)
        out << ex.msgs[i] << " ";
    return out;
}
