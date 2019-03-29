#ifndef CLIENTE_H
#define CLIENTE_H
#include "pessoa.h"

class Cliente : public pessoa
{
private:
    int pontuacao;

public:
    Cliente();
    void constroi_cliente(string name, string endereco, string dataNasc, int cpf, int codigo, int pontuacao);
    void amostra_cliente();
};

#endif // CLIENTE_H
