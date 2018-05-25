#include "control.h"
#include "model.h"
#include "view.h"


Control::Control(Model *model, View &view) :
    view(view)
{
    this->model = model;
    view.setControl(this);
}
