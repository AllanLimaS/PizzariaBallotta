#ifndef EXTRAS_H
#define EXTRAS_H

class Extras
{
private:

    int bebida;
    int adicionais;

public:

    Extras();
    void constroi_extras(int bebida, int adicionais);
    void imprime_extras();

    void setBebida(int bebida);
    int getBebida();
    void setAdicionais(int adicionais);
    int getAdicionais();

};
#endif // EXTRAS_H
