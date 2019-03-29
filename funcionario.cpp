#include "funcionario.h"
#include<iostream>
using namespace std;

Funcionario::Funcionario()
{

}

void Funcionario :: setSalario(float salario){
    this->salario = salario;
}

void Funcionario :: setFuncao(string funcao){
    this->funcao = funcao;
}




void Funcionario::constroi_funcionario(string nome, string endereco,string dataNasc,int cpf,int codigo,float salario,string funcao){
    this->constroi_pessoa(nome,endereco,dataNasc,cpf,codigo);
    this->setSalario(salario);
    this->setFuncao(funcao);
}

void Funcionario :: print_funcionario(){
    this->print_pessoa();
    cout<<"SALARIO: " << this->salario<<endl<<"FUNCAO: "<< this->funcao;

}
