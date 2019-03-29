#include "extras.h"

Extras::Extras()
{

}

void Extras :: setBebida(string bebida){
    this->bebida = bebida;
}

void Extras :: setAdicionais(string adicionais){
    this->adicionais = adicionais;
}

void Extras :: criaExtras(string bebida, string adicionais){
    this->bebida = bebida;
    this->adicionais = adicionais;
}

void Extras :: printExtras(){
    cout<<"BEBIDA: "<<this->bebida<<endl<<"EXTRAS: "<<this->adicionais<<endl;
}
