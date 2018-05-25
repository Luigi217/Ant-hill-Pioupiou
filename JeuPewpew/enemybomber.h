#ifndef ENEMYBOMBER_H
#define ENEMYBOMBER_H

#include "include.h"
#include "enemy.h"

class EnemyBomber : public Enemy
{
public:
    EnemyBomber(QPoint *p, QVector<QPoint> *pa);
};

#endif // ENEMYBOMBER_H
