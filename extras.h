#ifndef EXTRAS_H
#define EXTRAS_H

#include<iostream>
using namespace std;

class Extras
{
private:
    string bebida,adicionais;

public:
    Extras();
    void setBebida(string bebida);
    void setAdicionais(string adicionais);
    void criaExtras(string bebida,string adicionais);
    void printExtras();
};
#endif // EXTRAS_H
