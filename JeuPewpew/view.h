#ifndef VIEW_H
#define VIEW_H

#include "include.h"
#include "customscene.h"
#include "timerupdateview.h"

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

    void keyPressEvent(QKeyEvent *event);
    void setBoard();


public slots:
    void updateView();
    void moveAnts();
    void moveEnemy();
    void waves();

private:
    Ui::View *ui;
    QGraphicsScene *scene;
    CustomScene *cust;
    timerUpdateView *timerForView;
    timerUpdateView *timerForAnts;
    timerUpdateView *timerForEnemy;

    timerUpdateView *timerForWaves;
    int countForWaves;
};

#endif // VIEW_H
