#ifndef PIZZA_H
#define PIZZA_H

class Pizza
{
private:
    int sabor;
    int borda;
    int tamanho;

public:
    Pizza();
    ~Pizza();
    void constroi_pizza(int sabor, int borda, int tamanho);
    void imprime_pizza();

    void setSabor(int sabor);
    int getSabor();
    void setBorda(int borda);
    int getBorda();
    void setTamanho(int tamanho);
    int getTamanho();
};

#endif // PIZZA_H
