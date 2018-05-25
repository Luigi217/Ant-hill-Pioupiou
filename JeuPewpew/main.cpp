#include <QApplication>

#include "view.h"
#include "model.h"
#include "control.h"
#include "customscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;

    w.show();

    return a.exec();
}
