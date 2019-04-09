#include "pessoa.h"
#include<iostream>

using namespace std;

void pessoa::setName(string name){
    this->name = name;
}
string pessoa::getName(){
    return this->name;
}

void pessoa::setEndereco(string endereco){
    this->endereco = endereco;
}
string pessoa::getEndereco(){
    return this->endereco;
}

void pessoa::setDataNasc(string dataNasc){
    this->dataNasc = dataNasc;
}
string pessoa::getDataNasc(){
    return this->dataNasc;
}

void pessoa::setCpf(string cpf){
    this->cpf = cpf;
}
string pessoa::getCpf(){
    return this->cpf;
}

void pessoa::setCodigo(int codigo){
    this->codigo = codigo;
}
int pessoa::getCodigo(){
    return this->codigo;
}

void pessoa :: constroi_pessoa(string name, string endereco, string dataNasc, string cpf, int codigo){
    this->setName(name);
    this->setEndereco(endereco);
    this->setDataNasc(dataNasc);
    this->setCpf(cpf);
    this->setCodigo(codigo);
    this->ativo = true;
}

void pessoa :: imprime_pessoa(){
    if(this->ativo == true){
        cout<<"CPF: " << this->getCpf() <<endl;
        cout<<"NOME: " << this->getName() <<endl;
        cout<<"CODIGO: " << this->getCodigo() <<endl;
        cout<<"NASC: " << this->getDataNasc() <<endl;
        cout<<"ENDERECO: " << this->getEndereco() <<endl;
    }
}

bool pessoa :: get_ativo(){
    return this->ativo;
}

bool pessoa :: set_ativo(bool cond){
    this->ativo = cond;
}

