
#include "funcionario.h"
#include<iostream>

using namespace std;

Funcionario::Funcionario()
{

}

void Funcionario :: setSalario(float salario){
    this->salario = salario;
}
float Funcionario :: getSalario(){
    return this->salario;
}

void Funcionario :: setFuncao(int funcao){
    this->funcao = funcao;
}
int Funcionario :: getFuncao(){
    return this->funcao;
}

void Funcionario::constroi_funcionario(string nome, string endereco,string dataNasc,string cpf,int codigo,float salario,int funcao){
    this->constroi_pessoa(nome,endereco,dataNasc,cpf,codigo);
    this->setSalario(salario);
    this->setFuncao(funcao);
}

void Funcionario :: imprime_funcionario(){
    string funcao;
    if(this->get_ativo() == true){
        this->imprime_pessoa();
        cout<<"SALARIO: " << this->salario<<endl;
        switch(this->funcao){
            case 00:
                funcao = "Atendente";
            break;
            case 01:
                funcao = "Pizzaiolo";
            break;
            case 02:
                funcao = "Motoboi";
            break;
            case 03:
                funcao = "Gerente";
            break;
        }

        cout<<"FUNCAO: "<< funcao<<endl;
    }
}
