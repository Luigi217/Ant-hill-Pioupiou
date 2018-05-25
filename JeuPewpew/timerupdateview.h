#ifndef TIMERUPDATEVIEW_H
#define TIMERUPDATEVIEW_H

#include "include.h"

class timerUpdateView : public QThread
{
    Q_OBJECT
public:
    timerUpdateView(QObject *parent, int x);
    void run();
    void exec();

    void setRunning(bool value);

signals:
    void signalUpdate();

private:
    int fps;
    bool running;
};

#endif // TIMERUPDATEVIEW_H
