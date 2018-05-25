#include "enemy.h"
#include "ant.h"
#include "antbase.h"

Enemy::Enemy()
{
    this->positionInPath = 0;
    this->range = FIRERANGE;
}

Enemy::~Enemy(){
    delete position;
    delete path;
}

void Enemy::move(){
    if(!this->path->isEmpty()){
       if(*(this->getPosition()) != this->path->at(this->path->size()-1)){
          if(this->positionInPath + this->speedFactor <= this->path->size()-1){
              this->positionInPath += this->speedFactor;
              this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
          }
          else{
              this->positionInPath = this->path->size()-1;
              this->position = new QPoint(this->path->at(positionInPath).x(),this->path->at(positionInPath).y());
          }
       }
    }
}

void Enemy::attack(Ant *a){
    int lifeleft = a->getHp() - this->dps;
    a->setHp(lifeleft);
}

void Enemy::attack(AntBase *b){
    int lifeleft = b->getHp() - this->damageToBase;
    b->setHp(lifeleft);
}

QPoint *Enemy::getPosition() const
{
    return position;
}

void Enemy::setPosition(QPoint *value)
{
    position = value;
}

int Enemy::getPositionInPath() const
{
    return positionInPath;
}

QVector<QPoint> *Enemy::getPath() const
{
    return path;
}

void Enemy::setPath(QVector<QPoint> *value)
{
    path = value;
}

void Enemy::setHp(int value)
{
    hp = value;
}

int Enemy::getHp() const
{
    return hp;
}

int Enemy::getRange() const
{
    return range;
}

void Enemy::setPositionInPath(int value)
{
    positionInPath = value;
}
