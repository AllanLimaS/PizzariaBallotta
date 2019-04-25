#ifndef INIMIGO_H
#define INIMIGO_H
#include "entidade.h"
#include <QGraphicsRectItem>

class Inimigo :public QGraphicsRectItem, public Entidade
{
private:

    //algum atributo especial para os inimigos

public:
    Inimigo();
};

#endif // INIMIGO_H
