#ifndef ENEMYFIGHTER_H
#define ENEMYFIGHTER_H

#include "include.h"
#include "enemy.h"

class EnemyFighter : public Enemy
{
public:
    EnemyFighter(QPoint *p, QVector<QPoint> *pa);
};

#endif // ENEMYFIGHTER_H
