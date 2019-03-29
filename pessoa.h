#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

using namespace std;

class pessoa
{

private:
    string name;
    string endereco;
    string dataNasc;
    int cpf;
    int codigo;

public:
    void constroi_pessoa(string name, string endereco, string dataNasc, int cpf, int codigo);
    void setName(string name);
    void print_pessoa();
    string getName();
    void setEndereco(string endereco);
    string getEndereco();
    void setDataNasc(string dataNasc);
    string getDataNasc();
    void setCpf(int cpf);
    int getCpf();
    void setCodigo(int codigo);
    int getCodigo();
};

#endif // PESSOA_H
