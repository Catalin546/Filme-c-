//
// Created by dusce on 4/3/2023.
//

#ifndef FILME_FILME_H
#define FILME_FILME_H
#include <string>
#include <iostream>
using namespace std;

class Film {
private:
    int id;
    string titlu;
    string gen;
    int an;
    string actor_principal;
public:
    Film(int id, const string titlu, const string gen, int an, const string actor_principal): id{id}, titlu{titlu}, gen{gen}, an{an}, actor_principal{actor_principal}{cout<<"film creat\n";}; //constructor
    Film():
        id{0},
        titlu{""},
        gen{""},
        an { 0 },
        actor_principal { "" }
    {}
    //getters
    int getId() const{
        return id;
    }
    string getTitlu() const{
        return titlu;
    }
    string getGen() const{
        return gen;
    }
    int getAn() const{
        return an;
    }
    string getActor_principal() const{
        return actor_principal;
    }
    //setters
    void setId(int id){
        this->id = id;
    }
    void setTitlu(string titlu){
        this->titlu = titlu;
    }
    void setGen(string gen){
        this->gen = gen;
    }
    void setAn(int an){
        this->an = an;
    }
    void setActor_principal(string actor_principal){
        this->actor_principal = actor_principal;
    }
    const bool operator==(const Film& f) const{
        return this->id == f.id;
    }
};

bool cmpAn(const Film& f1, const Film& f2) ;

bool cmpTitlu(const Film& f1, const Film& f2) ;


#endif //FILME_FILME_H
