#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "pessoa.h"
#include <iostream>

using namespace std;

class Funcionario:public pessoa
{
private:
    float salario;
    string funcao;
public:
    Funcionario();
    void constroi_funcionario(string nome, string endereco,string dataNasc,int cpf,int codigo,float salario,string funcao);
    void setSalario(float salario);
    float getSalario();
    void setFuncao(string funcao);
    string getFuncao();
    void print_funcionario();
};

#endif // FUNCIONARIO_H
