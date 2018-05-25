#ifndef CONTROL_H
#define CONTROL_H

#include "include.h"

class Model;
class View;

class Control
{
private:
    Model *model;
    View &view;   //  BOTH attribute types are valid, heterogenity is for *pedagogical* reason
public:
    Control(Model *model, View &view);

};

#endif // CONTROL_H

