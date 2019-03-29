#ifndef EXTRAS_H
#define EXTRAS_H

#include<iostream>

using namespace std;

class Extras
{
private:
    string bebida;
    string adicionais;

public:
    Extras();
    void constroi_extras(string bebida,string adicionais);
    void imprime_extras();

    void setBebida(string bebida);
    string getBebida();
    void setAdicionais(string adicionais);
    string getAdicionais();

};
#endif // EXTRAS_H
