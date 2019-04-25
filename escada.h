#ifndef ESCADA_H
#define ESCADA_H
#include "objeto.h"
#include <QGraphicsRectItem>

class Escada : public QGraphicsRectItem, public Objeto
{
public:
    Escada();
};

#endif // ESCADA_H
