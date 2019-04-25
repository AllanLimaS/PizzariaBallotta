#ifndef PIROK_H
#define PIROK_H

#include <QGraphicsRectItem>

class pirok: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PIROK_H
