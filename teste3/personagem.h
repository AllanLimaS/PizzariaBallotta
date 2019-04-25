#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <QGraphicsRectItem>

class Personagem: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PERSONAGEM_H
