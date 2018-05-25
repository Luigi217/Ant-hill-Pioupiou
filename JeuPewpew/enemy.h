#ifndef ENEMY_H
#define ENEMY_H

#include "include.h"
class Ant;
class AntBase;

class Enemy
{
public:
    Enemy();
    ~Enemy();
    void move();
    void attack(Ant *a);
    void attack(AntBase *b);

    QPoint *getPosition() const;
    void setPosition(QPoint *value);
    int getPositionInPath() const;
    void setPositionInPath(int value);
    QVector<QPoint> *getPath() const;
    void setPath(QVector<QPoint> *value);
    void setHp(int value);
    int getHp() const;

    int getRange() const;

protected:
    QPoint *position;
    int positionInPath;

    int dps;
    int damageToBase;
    int hp;
    int range;
    int speedFactor;
    QVector<QPoint> *path;
};

#endif // ENEMY_H
