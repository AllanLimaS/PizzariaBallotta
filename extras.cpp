#include "extras.h"

Extras::Extras()
{

}

void Extras :: setBebida(string bebida){
    this->bebida = bebida;
}
string Extras :: getBebida(){
    return this->bebida;
}

void Extras :: setAdicionais(string adicionais){
    this->adicionais = adicionais;
}
string Extras :: getAdicionais(){
    return this->adicionais;
}

void Extras :: constroi_extras(string bebida, string adicionais){
    this->bebida = bebida;
    this->adicionais = adicionais;
}

void Extras :: imprime_extras(){
    cout<<"BEBIDA: "<<this->getBebida()<<endl;
    cout<<"EXTRAS: "<<this->getAdicionais()<<endl;
}
