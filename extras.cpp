#include "extras.h"
#include <iostream>
using namespace std;

Extras::Extras()
{

}

void Extras :: setBebida(int bebida){
    this->bebida = bebida;
}
int  Extras :: getBebida(){
    return this->bebida;
}

void Extras :: setAdicionais(int adicionais){
    this->adicionais = adicionais;
}
int Extras :: getAdicionais(){
    return this->adicionais;
}

void Extras :: constroi_extras(int bebida, int adicionais){
    this->bebida = bebida;
    this->adicionais = adicionais;
}

void Extras :: imprime_extras(){

    string bebida;
    string adicionais;

    switch(this->bebida){

    case 01:
        bebida = "Skol";
    break;

    case 02:
        bebida = "Coca Cola";
    break;

    case 03:
        bebida = "Cachaca";
    break;

    case 04:
        bebida = "Vodka";
    break;

    case 05:
        bebida = "Suquinho";
    break;

    }

    switch(this->adicionais){
    case 01:
        adicionais = "Cebola";
    break;

    case 02:
        adicionais = "Bacon";
    break;

    case 03:
        adicionais = "Condimentos Extra";
    break;

    case 04:
        adicionais = "Azeitonas";
    break;

    case 05:
        adicionais = "Queijo";
    break;

    }

    cout<<"BEBIDA: "<< bebida <<endl;
    cout<<"ADICIONAIS: "<< adicionais <<endl;
}
