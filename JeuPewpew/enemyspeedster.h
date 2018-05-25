#ifndef ENEMYSPEEDSTER_H
#define ENEMYSPEEDSTER_H

#include "include.h"
#include "enemy.h"

class EnemySpeedster : public Enemy
{
public:
    EnemySpeedster(QPoint *p, QVector<QPoint> *pa);
};

#endif // ENEMYSPEEDSTER_H
