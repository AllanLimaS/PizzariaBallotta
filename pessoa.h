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
    string cpf;
    int codigo;

public:
    void constroi_pessoa(string name, string endereco, string dataNasc, string cpf, int codigo);
    void imprime_pessoa();

    void setName(string name);
    string getName();

    void setEndereco(string endereco);
    string getEndereco();

    void setDataNasc(string dataNasc);
    string getDataNasc();

    void setCpf(string cpf);
    string getCpf();

    void setCodigo(int codigo);
    int getCodigo();
};

#endif // PESSOA_H
