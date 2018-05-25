#include "enemyfighter.h"

EnemyFighter::EnemyFighter(QPoint *p, QVector<QPoint> *pa)
{
    this->dps = 10;
    this->damageToBase = 10;
    this->hp = 25;
    this->setPosition(p);
    this->speedFactor = 2;
    this->setPath(pa);
}
