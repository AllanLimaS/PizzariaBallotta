#include "pizza.h"
#include <iostream>
using namespace std;


Pizza::Pizza()
{

}

void Pizza :: setBorda(int borda){
    this->borda = borda;
}

void Pizza :: setSabor(int sabor){
    this->sabor = sabor;
}

void Pizza :: setTamanho(int tamanho){
    this->tamanho = tamanho;
}

void Pizza :: criaPizza(int sabor, int borda, int tamanho){
    this->borda = borda;
    this->sabor = sabor;
    this->tamanho = tamanho;
}

void Pizza :: printPizza(){
    string sabor;
    string tamanho;
    string borda;

    switch (this->sabor) {
    case 1:
        sabor = "calabresa";
        break;
    case 2:
        sabor = "peito de piru";
        break;
    case 3:
        sabor= "frango e catupiry";
        break;
    case 4:
        sabor= "frango com batata doce";
        break;
    case 5:
        sabor= "4 queijos";
        break;
    case 6:
        sabor= "coracao";
        break;
    case 7:
        sabor= "abacaxi";
        break;
    case 8:
        sabor= "Portuguesa";
        break;
    case 9:
        sabor= "Bacon";
        break;
    case 10:
        sabor= "strogonof";
        break;
    }

    switch (this->tamanho) {
    case 1:
        tamanho = "pequena";
        break;
    case 2:
        tamanho = "media";
        break;
    case 3:
        tamanho = "grande";
        break;
    }

    switch(this->borda){
    case 1:
        borda = "catupiry";
        break;
    case 2:
        borda = "normal";
        break;
    }

    cout<<"TAMANHO: "<< tamanho <<endl<<"SABOR: "<<sabor<< endl<<"BORDA: " << borda << endl;
}
