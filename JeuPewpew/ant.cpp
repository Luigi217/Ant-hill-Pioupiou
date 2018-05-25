#include "ant.h"
#include "enemy.h"

Ant::Ant()
{
   this->position = new QPoint(BASEX,BASEY);
   this->hasFood = false;
   this->range = FIRERANGE;
   this->positionInPath = 0;
   this->isComingBack = false;
}

Ant::~Ant(){
    delete position;
    delete path;
}

void Ant::move(){
    if(!this->path->isEmpty()){
        if(this->hasFood == false && this->isComingBack == false){
            if(this->positionInPath + speedFactor <= this->path->size()-1){
                this->positionInPath += this->speedFactor;
                this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
            }
            else{
                this->positionInPath = this->path->size()-1;
                this->isComingBack = true;
                this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
            }
        }
        else{
            if(this->positionInPath - speedFactor >= 0){
                this->positionInPath -= this->speedFactor;
                this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
            }
            else{
                this->positionInPath = 0;
                this->isComingBack = false;
                this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
            }
        }
   }
}

void Ant::setPath(QVector<QPoint> *value)
{
    path = value;
}

QPoint *Ant::getPosition() const
{
    return position;
}

void Ant::setPosition(QPoint *value)
{
    position = value;
}

void Ant::setPositionInPath(int value)
{
    positionInPath = value;
}

void Ant::setHasFood(bool value)
{
    hasFood = value;
}

bool Ant::getHasFood() const
{
    return hasFood;
}

int Ant::getRange() const
{
    return range;
}

int Ant::getDps() const
{
    return dps;
}

int Ant::getHp() const
{
    return hp;
}

void Ant::setHp(int value)
{
    hp = value;
}

void Ant::attack(Enemy *e){
    int lifeleaft = e->getHp() - this->dps;
    e->setHp(lifeleaft);
}


