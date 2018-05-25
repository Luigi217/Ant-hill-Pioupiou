#include "enemyspeedster.h"

EnemySpeedster::EnemySpeedster(QPoint *p, QVector<QPoint> *pa)
{
    this->dps = 10;
    this->damageToBase = 5;
    this->hp = 5;
    this->setPosition(p);
    this->speedFactor = 4;
    this->setPath(pa);
}
