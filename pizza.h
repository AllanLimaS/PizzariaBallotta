#ifndef PIZZA_H
#define PIZZA_H

class Pizza
{
private:

    int sabor,borda,tamanho;




public:
    Pizza();
    void setSabor(int sabor);
    void setBorda(int borda);
    void setTamanho(int tamanho);
    void criaPizza(int sabor, int borda, int tamanho);
    void printPizza();

};

#endif // PIZZA_H
