#ifndef ANT_H
#define ANT_H

#include "include.h"
class Enemy;

class Ant
{
public:
    Ant();
    ~Ant();
    void move();
    void attack(Enemy *e);
    void setPath(QVector<QPoint> *value);

    QPoint *getPosition() const;
    void setPosition(QPoint *value);
    void setPositionInPath(int value);
    void setHasFood(bool value);
    bool getHasFood() const;

    int getRange() const;
    int getDps() const;

    int getHp() const;
    void setHp(int value);

protected:
    QPoint *position;
    bool hasFood;
    bool isComingBack;
    int positionInPath;

    int dps;
    int hp;
    int speedFactor;
    int range;
    QVector<QPoint> *path;
};

#endif // ANT_H
