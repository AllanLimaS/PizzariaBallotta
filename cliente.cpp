#include "cliente.h"
#include <iostream>
using namespace std;


Cliente::Cliente()
{

}


void Cliente :: constroi_cliente(string name, string endereco, string dataNasc, int cpf, int codigo, int pontuacao){

    this->constroi_pessoa(name,endereco,dataNasc,cpf,codigo);
    this->pontuacao = pontuacao;
}

void Cliente :: amostra_cliente(){
    this->print_pessoa();
    cout<< "PONTUCAO: " << this->pontuacao << endl;
}


