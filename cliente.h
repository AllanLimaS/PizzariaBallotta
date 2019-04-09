#ifndef CLIENTE_H
#define CLIENTE_H
#include "pessoa.h"

class Cliente : public pessoa
{
private:
    int pontuacao;

public:
    Cliente();
    ~Cliente();
    void constroi_cliente(string name, string endereco, string dataNasc, string cpf, int codigo, int pontuacao);
    void imprime_cliente();

    int getPontuacao();
    void setPontuacao(int value);
    void remove_cliente();
};

#endif // CLIENTE_H
