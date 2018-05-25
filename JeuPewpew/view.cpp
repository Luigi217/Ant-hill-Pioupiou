#include "view.h"
#include "ui_view.h"

#include "control.h"
#include "customscene.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    this->setFixedSize(WIDTHWINDOW,HEIGHTWINDOW);
    ui->setupUi(this);
    this->setBoard();


    timerForView = new timerUpdateView(this,50);
    connect(timerForView, SIGNAL(signalUpdate()),this,SLOT(updateView()));
    timerForView->start();

    timerForAnts = new timerUpdateView(this,10);
    connect(timerForAnts, SIGNAL(signalUpdate()),this,SLOT(moveAnts()));
    timerForAnts->start();

    timerForEnemy = new timerUpdateView(this,6);
    connect(timerForEnemy, SIGNAL(signalUpdate()),this,SLOT(moveEnemy()));
    timerForEnemy->start();

    countForWaves = 0;
    timerForWaves = new timerUpdateView(this,1);
    connect(timerForWaves, SIGNAL(signalUpdate()),this,SLOT(waves()));
    timerForWaves->start();

}

View::~View()
{
    timerForView->setRunning(false);
    timerForAnts->setRunning(false);
    timerForWaves->setRunning(false);
    timerForEnemy->setRunning(false);

    timerForView->wait();
    timerForAnts->wait();
    timerForWaves->wait();
    timerForEnemy->wait();

    delete timerForView;
    delete timerForAnts;
    delete timerForEnemy;
    delete timerForWaves;

    delete scene;
    delete cust;
    delete ui;
}

void View::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F11){
        if(!this->isFullScreen()){
            this->showFullScreen();
        } else {
            this->showNormal();
        }
    }
    else if(event->key() == Qt::Key_Escape){
        this->close();
    }
}

void View::setBoard(){

    cust= new CustomScene();
    scene = cust;

    ui->graphicsView->setScene(scene);

    ui->graphicsView->resize(WIDTHBOARD, HEIGHTBOARD);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);
    setCentralWidget(ui->graphicsView);
    ui->statusbar->hide();
}

void View::updateView(){
    if(!cust->getGameIsEmpty()){
        cust->updateAntSprite();
        cust->updateEnemySprite();
    }
}

void View::moveAnts(){
    if(!cust->getGameIsEmpty()){
        cust->moveAllAnts();
    }
}

void View::moveEnemy(){
    if(!cust->getGameIsEmpty()){
        cust->moveAllEnemy();
    }
}

void View::waves(){
    if(!cust->getGameIsEmpty()){
        countForWaves++;

        if(countForWaves == 40){
            cust->CreateWave(3,0,0);
        }
        if(countForWaves == 80){
            cust->CreateWave(3,2,0);
        }
        if(countForWaves == 120){
            cust->CreateWave(3,2,1);
        }
        if(countForWaves == 160){
            cust->CreateWave(3,2,2);
        }
        if(countForWaves == 200){
            cust->CreateWave(4,3,2);
        }
    }
}


