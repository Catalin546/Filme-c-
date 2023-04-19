#include <iostream>
#include "filme.h"
#include "filme_repo.h"
#include "validare.h"
#include "ui.h"
#include "filme_service.h"
#include "teste.h"
using namespace std;
void runTests(){
    testeRepo();
    cout << "Repo tests passed!" << endl;
    testValidator();
    cout << "Validator tests passed!" << endl;
    testService();
    cout << "Service tests passed!" << endl;
}

int main() {
    runTests();
    FilmRepo rep;
    FilmValidator val;
    FilmService srv{rep,val} ;
    UI ui{srv};
    ui.start();
    return 0;
}
