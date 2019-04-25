#ifndef LOJA_H
#define LOJA_H
#include "objeto.h"
#include <QGraphicsRectItem>

class Loja :public QGraphicsRectItem, public Objeto
{
public:
    Loja();
};

#endif // LOJA_H
