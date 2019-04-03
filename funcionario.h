
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "pessoa.h"
#include <iostream>

using namespace std;

class Funcionario:public pessoa
{
private:

    float salario;
    int funcao;

public:

    Funcionario();
    void constroi_funcionario(string nome, string endereco,string dataNasc,string cpf,int codigo,float salario,int funcao);
    void imprime_funcionario();

    void setSalario(float salario);
    float getSalario();
    void setFuncao(int funcao);
    int getFuncao();
};

#endif // FUNCIONARIO_H
