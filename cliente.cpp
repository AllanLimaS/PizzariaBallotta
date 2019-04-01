#include "cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente()
{
}

int Cliente::getPontuacao()
{
    return pontuacao;
}
void Cliente::setPontuacao(int pontuacao)
{
    this->pontuacao = pontuacao;
}

void Cliente :: constroi_cliente(string name, string endereco, string dataNasc, string cpf, int codigo, int pontuacao){

    this->constroi_pessoa(name,endereco,dataNasc,cpf,codigo);
    this->pontuacao = pontuacao;
}

void Cliente :: imprime_cliente(){
    this->imprime_pessoa();
    cout<< "PONTUCAO: " << this->pontuacao << endl;
}


