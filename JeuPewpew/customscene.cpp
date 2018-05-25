#include "customscene.h"

CustomScene::CustomScene() : QGraphicsScene(){
    // Initialization of seed
    srand(time(NULL));

    // Initialization of memory for listEnemy
    listOfEnemy1 = new QVector<EnemyFighter*>;
    listOfEnemy2 = new QVector<EnemySpeedster*>;
    listOfEnemy3 = new QVector<EnemyBomber*>;

    // Initialization of the different aeras
    geometry = new QRect(0,0,WIDTHBOARD,HEIGHTBOARD);
    baseArea = new QRect(BASEX,BASEY,WIDTHBASE,HEIGHTBASE);
    rectChoice1 = new QRect(0,HEIGHTBOARD-HEIGHTBGBUTTONLEFT,WIDTHBUTTON+5,HEIGHTBGBUTTONLEFT);
    rectChoice2 = new QRect(WIDTHBUTTON+5,HEIGHTBOARD-HEIGHTBGBUTTONLEFT,WIDTHBUTTON+5,HEIGHTBGBUTTONLEFT);
    rectChoice3 = new QRect(15+WIDTHBUTTON*2,HEIGHTBOARD-HEIGHTBGBUTTONLEFT,WIDTHBUTTON+5,HEIGHTBGBUTTONLEFT);
    rectBoost1 = new QRect(WIDTHBOARD-(WIDTHBUTTON*3)-20,HEIGHTBOARD-HEIGHTBUTTON,WIDTHBUTTON+5,HEIGHTBUTTON);
    rectBoost2 = new QRect(WIDTHBOARD-(WIDTHBUTTON*2)-15,HEIGHTBOARD-HEIGHTBUTTON,WIDTHBUTTON+5,HEIGHTBUTTON);
    rectBoost3 = new QRect(WIDTHBOARD-WIDTHBUTTON-5,HEIGHTBOARD-HEIGHTBUTTON,WIDTHBUTTON+5,HEIGHTBUTTON);
    rectHelp = new QRect(WIDTHBOARD/2 - 32, HEIGHTBOARD-64-5, 64, 64);

    // Initialization of attributes
    this->initializePathAndGameStats();

    // Add UI
    this->addBaseAndGameButtons();

    // Initialization of units
    this->initializeAntList();

    // Add sprites on the scene
    this->initializeAntSprite();

    // Add food at the beginning
    this->addFood();
}

CustomScene::~CustomScene(){
    delete baseData;

    pathAnt1->clear();
    delete pathAnt1;
    pathAnt2->clear();
    delete pathAnt2;
    pathAnt3->clear();
    delete pathAnt3;

    for(int p = 0; p < listOfAnt1->size(); p++){
        delete listOfAnt1->at(p);
    }
    for(int p = 0; p < listOfAnt2->size(); p++){
        delete listOfAnt2->at(p);
    }
    for(int p = 0; p < listOfAnt3->size(); p++){
        delete listOfAnt3->at(p);
    }
    listOfAnt1->clear();
    delete listOfAnt1;
    listOfAnt2->clear();
    delete listOfAnt2;
    listOfAnt3->clear();
    delete listOfAnt3;

    for(int p = 0; p < listOfEnemy1->size(); p++){
        delete listOfEnemy1->at(p);
    }
    for(int p = 0; p < listOfEnemy2->size(); p++){
        delete listOfEnemy2->at(p);
    }
    for(int p = 0; p < listOfEnemy3->size(); p++){
        delete listOfEnemy3->at(p);
    }
    listOfEnemy1->clear();
    delete listOfEnemy1;
    listOfEnemy2->clear();
    delete listOfEnemy2;
    listOfEnemy3->clear();
    delete listOfEnemy3;

    for(int p = 0; p < listOfGraphicAnt1->size(); p++){
        delete listOfGraphicAnt1->at(p);
    }
    for(int p = 0; p < listOfGraphicAnt2->size(); p++){
        delete listOfGraphicAnt2->at(p);
    }
    for(int p = 0; p < listOfGraphicAnt3->size(); p++){
        delete listOfGraphicAnt3->at(p);
    }
    listOfGraphicAnt1->clear();
    delete listOfGraphicAnt1;
    listOfGraphicAnt2->clear();
    delete listOfGraphicAnt2;
    listOfGraphicAnt3->clear();
    delete listOfGraphicAnt3;

    for(int p = 0; p < listOfGraphicEnemy1->size(); p++){
        delete listOfGraphicEnemy1->at(p);
    }
    for(int p = 0; p < listOfGraphicEnemy2->size(); p++){
        delete listOfGraphicEnemy2->at(p);
    }
    for(int p = 0; p < listOfGraphicEnemy3->size(); p++){
        delete listOfGraphicEnemy3->at(p);
    }
    listOfGraphicEnemy1->clear();
    delete listOfGraphicEnemy1;
    listOfGraphicEnemy2->clear();
    delete listOfGraphicEnemy2;
    listOfGraphicEnemy3->clear();
    delete listOfGraphicEnemy3;

    delete healthBar;
    delete healthSprite;

    delete foodArea;
    delete vision;
    delete baseArea;
    delete EnemyArea;
    delete geometry;
    delete rectChoice1;
    delete rectChoice2;
    delete rectChoice3;
    delete rectBoost1;
    delete rectBoost2;
    delete rectBoost3;

    delete spriteAnt1;
    delete spriteAnt2;
    delete spriteAnt3;
    delete spriteEnemy1;
    delete spriteEnemy2;
    delete spriteEnemy3;
    delete food;
    delete buttonChoiceAnt1Sprite;
    delete buttonChoiceAnt2Sprite;
    delete buttonChoiceAnt3Sprite;
    delete buttonBoostAnt1Sprite;
    delete buttonBoostAnt2Sprite;
    delete buttonBoostAnt3Sprite;
    delete baseSprite;

    delete backgroundButtonLeft;
    delete backgroundButtonRight;
    delete infoButtonLeft;
    delete infoButtonRight;
    delete infoFoodBg;
    delete infoButtonFoodNeeded;
    delete infoButtonNumberAnt;
    delete infoTextLeft;
    delete infoTextRight;
    delete infoFood;
    delete infoTextAnt1;
    delete infoTextAnt2;
    delete infoTextAnt3;
    delete infoTextNbAnt1;
    delete infoTextNbAnt2;
    delete infoTextNbAnt3;
    delete infoTextNumberAnt;
    delete infoTextFoodNeeded;
    delete buttonChoiceAnt1;
    delete buttonChoiceAnt2;
    delete buttonChoiceAnt3;
    delete buttonBoostAnt1;
    delete buttonBoostAnt2;
    delete buttonBoostAnt3;
    delete foodGraphics;
    delete base;
}

// Store the path of a mouseMoveEvent for the ants

// Store the path during a mouseMoveEvent
void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    QPoint posAbsolute(event->screenPos());
    QPoint posRelativ(event->scenePos().toPoint());

    // Check if we are on the board
    if(geometry->contains(posRelativ)){
        // Check if the left click on the base is on the rect of the base
        if (baseArea->contains(event->buttonDownScenePos(Qt::LeftButton).toPoint())){
                if(!(this->isReleased)){
                    this->tempPath->append(posRelativ);
                    this->onMove = true;
                }
            }
        else{
            this->onMove = false;
        }
    }
    else{
        this->checkCoordinates(posRelativ,posAbsolute);
    }


    QGraphicsScene::mouseMoveEvent(event);
}
// Check if the cursor stay in the scene during MouseMoveEvent
void CustomScene::checkCoordinates(QPoint r,QPoint a){
    QCursor curs = QCursor();

    if (r.x()<0){
        QPoint Limite(a.x() - (r.x() + 0),a.y());
        curs.setPos(Limite);
        this->setCursor(curs);
    }
    else if (r.x()>WIDTHBOARD){
        QPoint Limite(a.x() - (r.x() - WIDTHBOARD),a.y());
        curs.setPos(Limite);
        this->setCursor(curs);
    }

    if (r.y()<0){
        QPoint Limite(a.x(),a.y() - (r.y() + 0));
        curs.setPos(Limite);
        this->setCursor(curs);

    }
    else if (r.y()>HEIGHTBOARD){
        QPoint Limite(a.x(),a.y() - (r.y() - HEIGHTBOARD));
        curs.setPos(Limite);
        this->setCursor(curs);
    }

}
// Call the affectPathToAnt when left click is released
void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

        if(event->button() == Qt::LeftButton){
            if(this->onMove){
                this->isReleased = true;
                this->affectPathToAnt(tempPath);
                this->tempPath = new QVector<QPoint>;
                this->onMove = false;
            }
        }
        QGraphicsScene::mouseReleaseEvent(event);
}

bool CustomScene::getGameIsEmpty() const
{
    return gameIsEmpty;
}

int CustomScene::getEnemyCountDown() const
{
    return enemyCountDown;
}

void CustomScene::setEnemyCountDown(int value)
{
    enemyCountDown = value;
}

// Temporary path of the selected ants
void CustomScene::affectPathToAnt(QVector<QPoint> *path){
    if(this->buttonAntSelected == "harvest"){
        this->pathAnt1=path;
        for (int z = 0; z < listOfAnt1->size(); z++){
            listOfAnt1->at(z)->setPositionInPath(0);
            listOfAnt1->at(z)->setPath(this->pathAnt1);
            listOfAnt1->at(z)->setPosition(new QPoint(BASEX,BASEY));
            delay();
        }
    }
    else if(this->buttonAntSelected == "fighters"){
        this->pathAnt2=path;
        for (int z = 0; z < listOfAnt2->size(); z++){
            listOfAnt2->at(z)->setPath(this->pathAnt2);
            listOfAnt2->at(z)->setPosition(new QPoint(BASEX,BASEY));
            listOfAnt2->at(z)->setPositionInPath(0);
            delay();
    }
}
    else if(this->buttonAntSelected == "tank"){
        this->pathAnt3=path;
        for (int z = 0; z < listOfAnt3->size(); z++){
            listOfAnt3->at(z)->setPath(this->pathAnt3);
            listOfAnt3->at(z)->setPosition(new QPoint(BASEX,BASEY));
            listOfAnt3->at(z)->setPositionInPath(0);
            delay();
        }
    }
}

// Function WIN / LOOSE
void CustomScene::loose(){
    if(!gameIsEmpty){
        this->deleteEverything();

        QPixmap *looseBg = new QPixmap("../JeuPewpew/Images/loose.png");
        QGraphicsPixmapItem *looseImage = new QGraphicsPixmapItem();
        looseImage->setPixmap(*looseBg);
        this->addItem(looseImage);
        looseImage->setPos(0,0);
    }
}

void CustomScene::win(){
    if(!gameIsEmpty){
        this->deleteEverything();

        QPixmap *winBg = new QPixmap("../JeuPewpew/Images/win.png");
        QGraphicsPixmapItem *winImage = new QGraphicsPixmapItem();
        winImage->setPixmap(*winBg);
        this->addItem(winImage);
        winImage->setPos(0,0);
    }
}



// initialization of the scene

// Initialization of game attributes
void CustomScene::initializePathAndGameStats(){
    buttonAntSelected = "harvest";
    numberOfFood = 5;
    numberOfAnt1 = 2;
    numberOfAnt2 = 0;
    numberOfAnt3 = 0;

    gameIsEmpty = false;
    enemyCountDown = 0;

    foodNeedAnt1 = 1;
    foodNeedAnt2 = 2;
    foodNeedAnt3 = 5;
    this->baseData = new AntBase();
    this->tempPath = new QVector<QPoint> ;
    this->pathAnt1 = new QVector<QPoint> ;
    this->pathAnt2 = new QVector<QPoint> ;
    this->pathAnt3 = new QVector<QPoint> ;
}

// Initialisazation of Ui
void CustomScene::addBaseAndGameButtons(){

    background.load("../JeuPewPew/Images/bg.png");
    this->addPixmap(background);
    this->setSceneRect(0,0, WIDTHBOARD, HEIGHTBOARD);

    // Help button
    help = new QGraphicsPixmapItem();
    helpSprite = new QPixmap("../JeuPewpew/Images/help.png");
    help->setPixmap(*helpSprite);
    this->addItem(help);
    help->setPos(WIDTHBOARD/2 - 32, HEIGHTBOARD-64-5);

    base = new QGraphicsPixmapItem();
    baseSprite = new QPixmap("../JeuPewpew/Images/base.png");
    base->setPixmap(*baseSprite);
    this->addItem(base);
    base->setPos(BASEX,BASEY);

    backgroundButtonLeft = new QGraphicsRectItem(0,HEIGHTBOARD-HEIGHTBGBUTTONLEFT,WIDTHBGBUTTONLEFT,HEIGHTBGBUTTONLEFT);
    backgroundButtonLeft->setBrush(Qt::black);
    this->addItem(backgroundButtonLeft);

    backgroundButtonRight = new QGraphicsRectItem(WIDTHBOARD-WIDTHBGBUTTONRIGHT,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT,WIDTHBGBUTTONRIGHT,HEIGHTBGBUTTONRIGHT);
    backgroundButtonRight->setBrush(Qt::black);
    this->addItem(backgroundButtonRight);

    infoButtonLeft = new QGraphicsRectItem(0,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON,WIDTHINFOBUTTON+60,HEIGHTINFOBUTTON);
    infoButtonLeft->setBrush(Qt::black);
    this->addItem(infoButtonLeft);
    infoTextLeft = new QGraphicsTextItem();
    infoTextLeft->setPos(QPoint(0,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON));
    infoTextLeft->setPlainText("AntPath : "+ buttonAntSelected);
    infoTextLeft->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextLeft);

    infoFoodBg = new QGraphicsRectItem((WIDTHBOARD/2)-WIDTHINFOBUTTON/2,0,WIDTHINFOBUTTON+20,HEIGHTINFOBUTTON);
    infoFoodBg->setBrush(Qt::black);
    this->addItem(infoFoodBg);
    infoFood = new QGraphicsTextItem();
    infoFood->setPos(QPoint((WIDTHBOARD/2)+10-WIDTHINFOBUTTON/2,8));
    infoFood->setPlainText("Food   : " + QString::number(numberOfFood));
    infoFood->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoFood);

    infoButtonRight = new QGraphicsRectItem(WIDTHBOARD-WIDTHINFOBUTTON,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON,WIDTHINFOBUTTON,HEIGHTINFOBUTTON);
    infoButtonRight->setBrush(Qt::black);
    this->addItem(infoButtonRight);
    infoTextRight = new QGraphicsTextItem();
    infoTextRight->setPos(QPoint(WIDTHBOARD-WIDTHINFOBUTTON+5,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON));
    infoTextRight->setPlainText("AntBoost");
    infoTextRight->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextRight);

    // Added number of ant information text
    infoButtonNumberAnt = new QGraphicsRectItem(WIDTHBOARD-WIDTHINFOBUTTON-250,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON+30,WIDTHINFOBUTTON+100,HEIGHTINFOBUTTON+100);
    infoButtonNumberAnt->setBrush(Qt::black);
    this->addItem(infoButtonNumberAnt);
    infoTextNumberAnt = new QGraphicsTextItem();
    infoTextNumberAnt->setPos(QPoint(WIDTHBOARD-WIDTHINFOBUTTON+5-250,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON+30));
    infoTextNumberAnt->setPlainText("Number of ant :");
    infoTextNumberAnt->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextNumberAnt);
    infoTextFoodNeeded = new QGraphicsTextItem();
    infoTextFoodNeeded->setPos(QPoint(WIDTHBOARD-WIDTHINFOBUTTON+5-250,HEIGHTBOARD-HEIGHTBGBUTTONRIGHT-HEIGHTINFOBUTTON+80));
    infoTextFoodNeeded->setPlainText("Food needed :");
    infoTextFoodNeeded->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextFoodNeeded);

    buttonChoiceAnt1 = new QGraphicsPixmapItem();
    buttonChoiceAnt1Sprite = new QPixmap("../JeuPewPew/Images/unicornChoice.png");
    buttonChoiceAnt1->setPixmap(*buttonChoiceAnt1Sprite);
    this->addItem(buttonChoiceAnt1);
    buttonChoiceAnt1->setPos(0,HEIGHTBOARD-HEIGHTBUTTON);

    buttonChoiceAnt2 = new QGraphicsPixmapItem();
    buttonChoiceAnt2Sprite = new QPixmap("../JeuPewPew/Images/pokeChoice.png");
    buttonChoiceAnt2->setPixmap(*buttonChoiceAnt2Sprite);
    this->addItem(buttonChoiceAnt2);
    buttonChoiceAnt2->setPos(WIDTHBUTTON+10,HEIGHTBOARD-HEIGHTBUTTON);

    buttonChoiceAnt3 = new QGraphicsPixmapItem();
    buttonChoiceAnt3Sprite = new QPixmap("../JeuPewPew/Images/steamChoice.png");
    buttonChoiceAnt3->setPixmap(*buttonChoiceAnt3Sprite);
    this->addItem(buttonChoiceAnt3);
    buttonChoiceAnt3->setPos((WIDTHBUTTON+10)*2,HEIGHTBOARD-HEIGHTBUTTON);

    buttonBoostAnt1 = new QGraphicsPixmapItem();
    buttonBoostAnt1Sprite = new QPixmap("../JeuPewPew/Images/unicornBoost.png");
    buttonBoostAnt1->setPixmap(*buttonBoostAnt1Sprite);
    this->addItem(buttonBoostAnt1);
    buttonBoostAnt1->setPos(WIDTHBOARD-(WIDTHBUTTON*3)-20,HEIGHTBOARD-HEIGHTBUTTON);
    // Add food needed as text on the bottom right of the button
    infoTextAnt1 = new QGraphicsTextItem();
    infoTextAnt1->setPos(WIDTHBOARD-(WIDTHBUTTON*3)-20+50,HEIGHTBOARD-HEIGHTBUTTON+40);
    infoTextAnt1->setPlainText(QString::number(foodNeedAnt1));
    infoTextAnt1->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextAnt1);
    // Add current number of ant as text on top right
    infoTextNbAnt1 = new QGraphicsTextItem();
    infoTextNbAnt1->setPos(WIDTHBOARD-(WIDTHBUTTON*3)-20+50,HEIGHTBOARD-HEIGHTBUTTON-10);
    infoTextNbAnt1->setPlainText(QString::number(numberOfAnt1));
    infoTextNbAnt1->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextNbAnt1);

    buttonBoostAnt2 = new QGraphicsPixmapItem();
    buttonBoostAnt2Sprite = new QPixmap("../JeuPewPew/Images/pokeBoost.png");
    buttonBoostAnt2->setPixmap(*buttonBoostAnt2Sprite);
    this->addItem(buttonBoostAnt2);
    buttonBoostAnt2->setPos(WIDTHBOARD-(WIDTHBUTTON*2)-10,HEIGHTBOARD-HEIGHTBUTTON);
    // Add food needed as text on the button
    infoTextAnt2 = new QGraphicsTextItem();
    infoTextAnt2->setPos(WIDTHBOARD-(WIDTHBUTTON*2)-10+50,HEIGHTBOARD-HEIGHTBUTTON+40);
    infoTextAnt2->setPlainText(QString::number(foodNeedAnt2));
    infoTextAnt2->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextAnt2);
    // Add current number of ant as text on top right
    infoTextNbAnt2 = new QGraphicsTextItem();
    infoTextNbAnt2->setPos(WIDTHBOARD-(WIDTHBUTTON*2)-10+50,HEIGHTBOARD-HEIGHTBUTTON-10);
    infoTextNbAnt2->setPlainText(QString::number(numberOfAnt2));
    infoTextNbAnt2->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextNbAnt2);

    buttonBoostAnt3 = new QGraphicsPixmapItem();
    buttonBoostAnt3Sprite = new QPixmap("../JeuPewPew/Images/steamBoost.png");
    buttonBoostAnt3->setPixmap(*buttonBoostAnt3Sprite);
    this->addItem(buttonBoostAnt3);
    buttonBoostAnt3->setPos(WIDTHBOARD-WIDTHBUTTON,HEIGHTBOARD-HEIGHTBUTTON);
    // Add food needed as text on the button
    infoTextAnt3 = new QGraphicsTextItem();
    infoTextAnt3->setPos(WIDTHBOARD-WIDTHBUTTON+50,HEIGHTBOARD-HEIGHTBUTTON+40);
    infoTextAnt3->setPlainText(QString::number(foodNeedAnt3));
    infoTextAnt3->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextAnt3);
    // Add current number of ant as text on top right
    infoTextNbAnt3 = new QGraphicsTextItem();
    infoTextNbAnt3->setPos(WIDTHBOARD-WIDTHBUTTON+50,HEIGHTBOARD-HEIGHTBUTTON-10);
    infoTextNbAnt3->setPlainText(QString::number(numberOfAnt3));
    infoTextNbAnt3->setDefaultTextColor(QColor(Qt::green));
    this->addItem(infoTextNbAnt3);

    // Add Health Bar
    healthSprite = new QPixmap("../JeuPewpew/Images/fullHealth.png");

    healthBar = new QGraphicsPixmapItem();
    healthBar->setPixmap(*healthSprite);
    this->addItem(healthBar);
    healthBar->setPos(0,0);
}
// Initialisation of units vectors
void CustomScene::initializeAntList(){
    listOfAnt1 = new QVector<AntHarvester*>;
    listOfAnt2 = new QVector<AntFighter*>;
    listOfAnt3 = new QVector<AntTank*>;

    AntHarvester *harve;
    for(int i = 0; i < numberOfAnt1; i++){
        harve = new AntHarvester(this->pathAnt1);
        this->listOfAnt1->append(harve);
    }
}

void CustomScene::initializeEnemyList(int nbEnemy1, int nbEnemy2, int nbEnemy3){
    QPoint *p;
    QVector<QPoint> *pa;
    QVector<QPoint> temp;

    EnemyFighter* herv;
    for(int i = 0; i < nbEnemy1; i++){
        p = new QPoint(CreationOfPosition());
        temp = InitializeEnemyPath(p);
        pa = new QVector<QPoint>(temp);
        herv = new EnemyFighter(p,pa);
        this->listOfEnemy1->append(herv);
    }

    EnemySpeedster* hype;
    for(int i = 0; i < nbEnemy2; i++){
        p = new QPoint(CreationOfPosition());
        temp = InitializeEnemyPath(p);
        pa = new QVector<QPoint>(temp);
        hype = new EnemySpeedster(p,pa);
        this->listOfEnemy2->append(hype);
    }

    EnemyBomber* hvo;
    for(int i = 0; i < nbEnemy3; i++){
        p = new QPoint(CreationOfPosition());
        temp = InitializeEnemyPath(p);
        pa = new QVector<QPoint>(temp);
        hvo = new EnemyBomber(p,pa);
        this->listOfEnemy3->append(hvo);
    }
}

// Function to create a random position for an enemy
QPoint CustomScene::CreationOfPosition(){
    int choice = rand() % 2; // random entre 0 et 1
    int IfXorY = rand() % 2; // random to choose if X or Y is random
    int X,Y;

    if(IfXorY == 0){
        // X = edge , Y = random in range
        if (choice == 0){
            X = 0;
        }else {
            X = WIDTHBOARD - WIDTHSOLDIER;
        }

        Y = (rand() % (HEIGHTBOARD - HEIGHTBGBUTTONLEFT - HEIGHTINFOBUTTON - HEIGHTSOLDIER + 1));
    }
    else{
        // X random
        if (choice == 0){
            Y = 0;
        }else{
            Y = HEIGHTBOARD - HEIGHTSOLDIER - HEIGHTINFOBUTTON - HEIGHTBGBUTTONLEFT;
        }

        X = (rand() % (WIDTHBOARD - WIDTHSOLDIER +1));
    }

    return QPoint(X,Y);
}

// Function to create a path based on a random position
QVector<QPoint> CustomScene::InitializeEnemyPath(QPoint *p){
    QPoint test(p->x(),p->y());
    QVector<QPoint> temp;

    while(!baseArea->contains(test)){

        // If the position is on the left of the base
        if(test.x() < BASEX){

            // If the position is on the left top of the base
            if(test.y() < BASEY){
                test.setX(test.x()+1);
                test.setY(test.y()+1);
                temp.append(test);
            }
            // If the position is on the left bottom of the base
            else if (test.y() > BASEY){
                test.setX(test.x()+1);
                test.setY(test.y()-1);
                temp.append(test);
            }
            // If the position is on left of the base
            else if (test.y() == BASEY){
                test.setX(test.x()+1);
                test.setY(test.y());
                temp.append(test);
            }

        }
        // If the position is on the right of the base
        else if(test.x() > BASEX){

            // If the position is on the right top of the base
            if(test.y() < BASEY){
                test.setX(test.x()-1);
                test.setY(test.y()+1);
                temp.append(test);
            }
            // If the position is on the right bottom of the base
            else if (test.y() > BASEY){
                test.setX(test.x()-1);
                test.setY(test.y()-1);
                temp.append(test);
            }
            // If the position is on right of the base
            else if (test.y() == BASEY){
                test.setX(test.x()-1);
                test.setY(test.y());
                temp.append(test);
            }

        }

        // If the position is on the same X as base
        else if(test.x() == BASEX){

            // If the position is on top of the base
            if(test.y() < BASEY){
                test.setX(test.x());
                test.setY(test.y()+1);
                temp.append(test);
            }
            // If the position is on bottom of the base
            else if (test.y() > BASEY){
                test.setX(test.x());
                test.setY(test.y()-1);
                temp.append(test);
            }

        }
    }
    // Return the new Path
    return temp;
}

// Initialization of units (sprites)
void CustomScene::initializeAntSprite(){

    listOfGraphicAnt1 = new QVector<QGraphicsPixmapItem*>;
    listOfGraphicAnt2 = new QVector<QGraphicsPixmapItem*>;
    listOfGraphicAnt3 = new QVector<QGraphicsPixmapItem*>;

    spriteAnt1 = new QPixmap("../JeuPewpew/Images/unicornSprite.png");
    spriteAnt2 = new QPixmap("../JeuPewpew/Images/pikachuSprite.png");
    spriteAnt3 = new QPixmap("../JeuPewpew/Images/blackPantherSprite.png");
    QGraphicsPixmapItem *tempPixMap;


    for(int t = 0; t < listOfAnt1->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteAnt1);
    this->addItem(tempPixMap);
    tempPixMap->setPos(BASEX,BASEY);
    listOfGraphicAnt1->append(tempPixMap);
    }

    for(int t = 0; t < listOfAnt2->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteAnt2);
    this->addItem(tempPixMap);
    tempPixMap->setPos(BASEX,BASEY);
    listOfGraphicAnt2->append(tempPixMap);
    }

    for(int t = 0; t < listOfAnt3->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteAnt3);
    this->addItem(tempPixMap);
    tempPixMap->setPos(BASEX,BASEY);
    listOfGraphicAnt3->append(tempPixMap);
    }
}
void CustomScene::initializeEnemySprite(){
    listOfGraphicEnemy1 = new QVector<QGraphicsPixmapItem*>;
    listOfGraphicEnemy2 = new QVector<QGraphicsPixmapItem*>;
    listOfGraphicEnemy3 = new QVector<QGraphicsPixmapItem*>;
    spriteEnemy1 = new QPixmap("../JeuPewpew/Images/cuteLittleGirl.png");
    spriteEnemy2 = new QPixmap("../JeuPewpew/Images/reverse_flash.png");
    spriteEnemy3 = new QPixmap("../JeuPewpew/Images/bomber.png");
    QGraphicsPixmapItem *tempPixMap;

    for(int t = 0; t < listOfEnemy1->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteEnemy1);
    this->addItem(tempPixMap);
    tempPixMap->setPos(*(this->listOfEnemy1->at(t)->getPosition()));
    listOfGraphicEnemy1->append(tempPixMap);
    }

    for(int t = 0; t < listOfEnemy2->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteEnemy2);
    this->addItem(tempPixMap);
    tempPixMap->setPos(*(this->listOfEnemy2->at(t)->getPosition()));
    listOfGraphicEnemy2->append(tempPixMap);
    }

    for(int t = 0; t < listOfEnemy3->size(); t++){
    tempPixMap = new QGraphicsPixmapItem();
    tempPixMap->setPixmap(*spriteEnemy3);
    this->addItem(tempPixMap);
    tempPixMap->setPos(*(this->listOfEnemy3->at(t)->getPosition()));
    listOfGraphicEnemy3->append(tempPixMap);
    }
}


// Dynamic display

// Update the ants sprites, triggered by the signal emitted by the QThread
void CustomScene::updateAntSprite(){

    for(int x = 0; x < this->listOfAnt1->size(); x++){
        this->listOfGraphicAnt1->at(x)->setPos(*(this->listOfAnt1->at(x)->getPosition()));
    }
    for(int x = 0; x < this->listOfAnt2->size(); x++){
        this->listOfGraphicAnt2->at(x)->setPos(*(this->listOfAnt2->at(x)->getPosition()));
    }
    for(int x = 0; x < this->listOfAnt3->size(); x++){
        this->listOfGraphicAnt3->at(x)->setPos(*(this->listOfAnt3->at(x)->getPosition()));
    }
}

// Update the enemy sprites, triggered by the signal emitted by the QThread
void CustomScene::updateEnemySprite(){
    for(int l = 0; l < this->listOfEnemy1->size(); l++){
        this->listOfGraphicEnemy1->at(l)->setPos(*(this->listOfEnemy1->at(l)->getPosition()));
    }

    for(int l = 0; l < this->listOfEnemy2->size(); l++){
        this->listOfGraphicEnemy2->at(l)->setPos(*(this->listOfEnemy2->at(l)->getPosition()));
    }

    for(int l = 0; l < this->listOfEnemy3->size(); l++){
        this->listOfGraphicEnemy3->at(l)->setPos(*(this->listOfEnemy3->at(l)->getPosition()));
    }
}

// Update food text on the top of the UI
void CustomScene::updateFoodText(){
    this->infoFood->setPlainText("Food   : " + QString::number(this->numberOfFood));
}
// Add a delay between each ant
void CustomScene::delay()
{
    //addSecs(s) add a delay of s seconds
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// Function that clear the scene from all existing sprite
void CustomScene::deleteEverything(){
    this->removeItem(foodGraphics);
    this->removeItem(base);

    for(int x = 0; x < listOfGraphicAnt1->size(); x++){
        this->removeItem(listOfGraphicAnt1->at(x));
    }

    for(int x = 0; x < listOfGraphicAnt2->size(); x++){
        this->removeItem(listOfGraphicAnt2->at(x));
    }

    for(int x = 0; x < listOfGraphicAnt3->size(); x++){
        this->removeItem(listOfGraphicAnt3->at(x));
    }

    for(int x = 0; x < listOfGraphicEnemy1->size(); x++){
        this->removeItem(listOfGraphicEnemy1->at(x));
    }

    for(int x = 0; x < listOfGraphicEnemy2->size(); x++){
        this->removeItem(listOfGraphicEnemy2->at(x));
    }

    for(int x = 0; x < listOfGraphicEnemy3->size(); x++){
        this->removeItem(listOfGraphicEnemy3->at(x));
    }

    this->removeItem(buttonChoiceAnt1);
    this->removeItem(buttonChoiceAnt2);
    this->removeItem(buttonChoiceAnt3);
    this->removeItem(buttonBoostAnt1);
    this->removeItem(buttonBoostAnt2);
    this->removeItem(buttonBoostAnt3);

    this->removeItem(backgroundButtonLeft);
    this->removeItem(backgroundButtonRight);
    this->removeItem(infoButtonLeft);
    this->removeItem(infoButtonRight);
    this->removeItem(infoFood);
    this->removeItem(infoFoodBg);
    this->removeItem(infoButtonNumberAnt);
    this->removeItem(infoTextLeft);
    this->removeItem(infoTextRight);
    this->removeItem(infoTextAnt1);
    this->removeItem(infoTextAnt2);
    this->removeItem(infoTextAnt3);
    this->removeItem(infoTextNbAnt1);
    this->removeItem(infoTextNbAnt2);
    this->removeItem(infoTextNbAnt3);
    this->removeItem(infoTextNumberAnt);
    this->removeItem(infoTextFoodNeeded);

    this->gameIsEmpty = true;
    this->numberOfFood = 0;
}


// Movement of the ants

// Movement of all ants
void CustomScene::moveAllAnts(){

    for(int j = 0; j < this->listOfAnt1->size(); j++){
        this->moveAntHarvester(this->listOfAnt1->at(j));
    }

    for(int l = 0; l < this->listOfAnt2->size(); l++){

       this->moveAntFighter(listOfAnt2->at(l));
    }

    for(int m = 0; m < this->listOfAnt3->size(); m++){
        this->moveAntTank(listOfAnt3->at(m));
    }
}

// Movement of all Enemy
void CustomScene::moveAllEnemy(){
    for(int j = 0; j < this->listOfEnemy1->size(); j++){
        this->moveEnemy(this->listOfEnemy1->at(j));
    }

    for(int j = 0; j < this->listOfEnemy2->size(); j++){
        this->moveEnemy(this->listOfEnemy2->at(j));
    }

    for(int j = 0; j < this->listOfEnemy3->size(); j++){
        this->moveEnemy(this->listOfEnemy3->at(j));
    }
}



// Move for the harvest ant
void CustomScene::moveAntHarvester(AntHarvester *a){
    a->move();
    if(a->getHasFood() == true)
    {
        // if the ant already has food
        if(checkReturnOfTheHero(a->getPosition())){
            // if the ant has food and is on the base
            a->setHasFood(false);
            this->numberOfFood++;
            this->updateFoodText();
        }
    }else{
        // if the ant has no food
        if(checkPositionInFood(a->getPosition())){
           // if the ant is on the food
           a->setHasFood(true);
           this->foodCount--;
           this->checkFoodState();
         }else{
           a->setHasFood(false);
         }
    }
}

// Move for fighter ant
void CustomScene::moveAntFighter(AntFighter *f){
    Enemy *e = checkForEnemy(f);
    if(e == NULL){
        // No enemies around
        f->move();
    }else{
        f->attack(e);
        this->checkIfAlive(e);
    }
}
// Move for tank ant
void CustomScene::moveAntTank(AntTank *t){
    Enemy *e = checkForEnemy(t);
    if(checkForEnemy(t) == NULL){
        // No enemies around
        t->move();
    }else{
        t->attack(e);
        this->checkIfAlive(e);
    }
}

// Move one enemy
void CustomScene::moveEnemy(Enemy *e){
    Ant *a = checkForAnt(e);
    if(baseArea->contains(*(e->getPosition()))){
        e->attack(baseData);
        this->checkIfBaseAlive(baseData);
    }else{
        if(a == NULL){
            // No enemies around
            e->move();
        }else{
            e->attack(a);
            this->checkIfAntAlive(a);
        }
    }
}



// Check the states of items on the map

// Add food if the counter of food added before is zero
void CustomScene::checkFoodState(){
    if(foodCount <= 0){
        this->removeItem(foodGraphics);
        this->addFood();
    }else if(0 < foodCount && foodCount < 5){
        food = new QPixmap("../JeuPewpew/Images/halfFood.png");
        foodGraphics->setPixmap(*food);
    }
}

// Check if the base is alive, if not then the game is lost
void CustomScene::checkIfBaseAlive(AntBase *b){
    if(b->getHp() <= 0){
        // Loose
        this->loose();
    }else if(b->getHp() < 750 && b->getHp() > 500){
        healthSprite = new QPixmap("../JeuPewpew/Images/75Health.png");
        healthBar->setPixmap(*healthSprite);
    }else if(b->getHp() < 500 && b->getHp() > 250){
        healthSprite = new QPixmap("../JeuPewpew/Images/50Health.png");
        healthBar->setPixmap(*healthSprite);
    }else if(b->getHp() < 250 && b->getHp() > 0){
        healthSprite = new QPixmap("../JeuPewpew/Images/25Health.png");
        healthBar->setPixmap(*healthSprite);
    }
}

// Check if there is an Enemy next to the ant
Enemy* CustomScene::checkForEnemy(Ant *a){
    int x = (a->getPosition()->x()) - (a->getRange());
    int y = (a->getPosition()->y()) - (a->getRange());
    int width = (a->getRange()*2) + WIDTHSOLDIER;
    int height = (a->getRange()*2) + HEIGHTSOLDIER;

    vision = new QRect(x,y,width,height);

    for(int j = 0; j < this->listOfEnemy1->size(); j++){
        int xe = this->listOfEnemy1->at(j)->getPosition()->x();
        int ye = this->listOfEnemy1->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfEnemy1->at(j);
         }
    }

    for(int j = 0; j < this->listOfEnemy2->size(); j++){
        int xe = this->listOfEnemy2->at(j)->getPosition()->x();
        int ye = this->listOfEnemy2->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfEnemy2->at(j);
         }
    }

    for(int j = 0; j < this->listOfEnemy3->size(); j++){
        int xe = this->listOfEnemy3->at(j)->getPosition()->x();
        int ye = this->listOfEnemy3->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfEnemy3->at(j);
         }
    }
        return NULL;
}

// Check if there is an Ant next to the enemy
Ant* CustomScene::checkForAnt(Enemy *e){
    int x = (e->getPosition()->x()) - (e->getRange());
    int y = (e->getPosition()->y()) - (e->getRange());
    int width = (e->getRange()*2) + WIDTHSOLDIER;
    int height = (e->getRange()*2) + HEIGHTSOLDIER;

    vision = new QRect(x,y,width,height);

    for(int j = 0; j < this->listOfAnt1->size(); j++){
        int xe = this->listOfAnt1->at(j)->getPosition()->x();
        int ye = this->listOfAnt1->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfAnt1->at(j);
         }
    }

    for(int j = 0; j < this->listOfAnt2->size(); j++){
        int xe = this->listOfAnt2->at(j)->getPosition()->x();
        int ye = this->listOfAnt2->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfAnt2->at(j);
         }
    }

    for(int j = 0; j < this->listOfAnt3->size(); j++){
        int xe = this->listOfAnt3->at(j)->getPosition()->x();
        int ye = this->listOfAnt3->at(j)->getPosition()->y();
        EnemyArea = new QRect(xe,ye,WIDTHSOLDIER,HEIGHTSOLDIER);
        if(vision->intersects(*(this->EnemyArea))){
            return this->listOfAnt3->at(j);
         }
    }
        return NULL;
}

// Check if the Enemy is alive, else the Enemy is removed
void CustomScene::checkIfAlive(Enemy *e){
    if(e->getHp() <= 0){
        for(int p = 0; p < listOfEnemy1->size(); p++){
            if(this->listOfEnemy1->at(p) == e){
                this->listOfEnemy1->remove(p);
                this->removeItem(this->listOfGraphicEnemy1->at(p));
                this->listOfGraphicEnemy1->remove(p);
                this->enemyCountDown++;
                if(this->enemyCountDown >= NUMBEROFENEMY){
                    this->win();
                }
            }
        }

        for(int p = 0; p < listOfEnemy2->size(); p++){
            if(this->listOfEnemy2->at(p) == e){
                this->listOfEnemy2->remove(p);
                this->removeItem(this->listOfGraphicEnemy2->at(p));
                this->listOfGraphicEnemy2->remove(p);
                this->enemyCountDown++;
                if(this->enemyCountDown >= NUMBEROFENEMY){
                    this->win();
                }
            }
        }

        for(int p = 0; p < listOfEnemy3->size(); p++){
            if(this->listOfEnemy3->at(p) == e){
                this->listOfEnemy3->remove(p);
                this->removeItem(this->listOfGraphicEnemy3->at(p));
                this->listOfGraphicEnemy3->remove(p);
                this->enemyCountDown++;
                if(this->enemyCountDown >= NUMBEROFENEMY){
                    this->win();
                }

            }
        }
    }
}

// Check if the ant that was attack is alive or not
void CustomScene::checkIfAntAlive(Ant *a){
    if(a->getHp() <= 0){
        for(int p = 0; p < listOfAnt1->size(); p++){
            if(this->listOfAnt1->at(p) == a){
                this->listOfAnt1->remove(p);
                this->removeItem(this->listOfGraphicAnt1->at(p));
                this->listOfGraphicAnt1->remove(p);
                if(foodNeedAnt1 > 1){
                    this->foodNeedAnt1 /= 2;
                }
                infoTextAnt1->setPlainText(QString::number(foodNeedAnt1));
                this->numberOfAnt1--;
                infoTextNbAnt1->setPlainText(QString::number(numberOfAnt1));
            }
        }

        for(int p = 0; p < listOfAnt2->size(); p++){
            if(this->listOfAnt2->at(p) == a){
                this->listOfAnt2->remove(p);
                this->removeItem(this->listOfGraphicAnt2->at(p));
                this->listOfGraphicAnt2->remove(p);
                if(foodNeedAnt2 > 2){
                    this->foodNeedAnt2 /= 2;
                }
                infoTextAnt2->setPlainText(QString::number(foodNeedAnt2));
                this->numberOfAnt2--;
                infoTextNbAnt2->setPlainText(QString::number(numberOfAnt2));
            }
        }

        for(int p = 0; p < listOfAnt3->size(); p++){
            if(this->listOfAnt3->at(p) == a){
                this->listOfAnt3->remove(p);
                this->removeItem(this->listOfGraphicAnt3->at(p));
                this->listOfGraphicAnt3->remove(p);
                if(foodNeedAnt3 > 5){
                    this->foodNeedAnt3 /= 2;
                }
                infoTextAnt3->setPlainText(QString::number(foodNeedAnt3));
                this->numberOfAnt3--;
                infoTextNbAnt3->setPlainText(QString::number(numberOfAnt3));
            }
        }
    }
}

// Check if the coordinates are on the food
bool CustomScene::checkPositionInFood(QPoint *p){
    if(foodArea->contains(*p)){
        return true;
    }
    else{
        return false;
    }
}
// Check if the ant that has food in the base
bool CustomScene::checkReturnOfTheHero(QPoint *p){
    // Check if the ant with food is in the base
    if(baseArea->contains(*p)){
        return true;
    }
    else{
        return false;
    }
}


// Functions related to Boost buttons of ants

// Trigger boost buttons functions
void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    this->isReleased = false;

    if(rectChoice1->contains(event->scenePos().toPoint())){
        buttonAntSelected = "harvest";
        infoTextLeft->setHtml("AntPath : "+ buttonAntSelected);
    }
    else if(rectChoice2->contains(event->scenePos().toPoint())){
        buttonAntSelected = "fighters";
        infoTextLeft->setHtml("AntPath : "+ buttonAntSelected);
    }
    else if(rectChoice3->contains(event->scenePos().toPoint())){
        buttonAntSelected = "tank";
        infoTextLeft->setHtml("AntPath : "+ buttonAntSelected);
    }
    else if(rectBoost1->contains(event->scenePos().toPoint())){
        this->addAnt1();
    }
    else if(rectBoost2->contains(event->scenePos().toPoint())){
        this->addAnt2();
    }
    else if(rectBoost3->contains(event->scenePos().toPoint())){
        this->addAnt3();
    }//bouton d'aide
    else if(rectHelp->contains(event->scenePos().toPoint())){
        //message box
        qDebug() << "Help asked";
        QMessageBox::information(this, "Send help", "Defend your colony against vile ennemies!\n"
                                                    "Send harvesters collect food to your base.\n"
                                                    "They are defenseless, defend them with fighters or tanks.\n"
                                                    "Fighters will do good amounts of damage but lack survivability,\n"
                                                    "meanwhile Tanks are well protected but have limited damage.\n\n"
                                                    "How to play:\n"
                                                    "Use one of the bottom left button to select one type of unit:\n"
                                                    "Harvesters, Fighters or Tanks\n"
                                                    "Place your mouse cursor on top of your base, left click, draw a path, then release the cursor.\n"
                                                    "The units will start flowing the path if there are some available.\n\n"
                                                    "If you have enough food, you can recruit more units with food boosts!\n"
                                                    "Boosts are located on the bottom right corner\n"
                                                    "You can recuit one unit of one type per boost used.\n"
                                                    "But be careful.\n"
                                                    "The more units of one type you have, the more expensive they will be.\n"
                                                    "Harvesters will cost the less and Tanks the most\n"
                                                    "\n\t\tGood luck!");
        //ou alors on ouvre un txt, plain text ou page html avec l'aide
    }

    QGraphicsScene::mousePressEvent(event);
}
// Boost buttons functions
void CustomScene::addAnt1(){
    if(numberOfFood >= foodNeedAnt1){
        numberOfFood -= foodNeedAnt1;
        foodNeedAnt1 += foodNeedAnt1;
        numberOfAnt1++;
        infoFood->setPlainText("Food   : " + QString::number(numberOfFood));
        // Add food needed as text on the button (refresh)
        infoTextAnt1->setPlainText(QString::number(foodNeedAnt1));
        // Add number of ant as text on the button (refresh)
        infoTextNbAnt1->setPlainText(QString::number(numberOfAnt1));


        AntHarvester *harve = new AntHarvester(this->pathAnt1);
        listOfAnt1->append(harve);

        QGraphicsPixmapItem *tempPixMap = new QGraphicsPixmapItem();
        tempPixMap->setPixmap(*spriteAnt1);
        this->addItem(tempPixMap);
        tempPixMap->setPos(BASEX,BASEY);
        listOfGraphicAnt1->append(tempPixMap);
    }
}
void CustomScene::addAnt2(){
    if(numberOfFood >= foodNeedAnt2){
        numberOfFood -= foodNeedAnt2;
        foodNeedAnt2 += foodNeedAnt2;
        numberOfAnt2++;
        infoFood->setPlainText("Food   : " + QString::number(numberOfFood));
        // Add food needed as text on the button (refresh)
        infoTextAnt2->setPlainText(QString::number(foodNeedAnt2));
        // Add number of ant as text on the button (refresh)
        infoTextNbAnt2->setPlainText(QString::number(numberOfAnt2));

        AntFighter *fight = new AntFighter(pathAnt2);
        listOfAnt2->append(fight);

        QGraphicsPixmapItem *tempPixMap = new QGraphicsPixmapItem();
        tempPixMap->setPixmap(*spriteAnt2);
        this->addItem(tempPixMap);
        tempPixMap->setPos(BASEX,BASEY);
        listOfGraphicAnt2->append(tempPixMap);
    }
}
void CustomScene::addAnt3(){
    if(numberOfFood >= foodNeedAnt3){
        numberOfFood -= foodNeedAnt3;
        foodNeedAnt3 += foodNeedAnt3;
        numberOfAnt3++;
        infoFood->setPlainText("Food   : " + QString::number(numberOfFood));
        // Add food needed as text on the button (refresh)
        infoTextAnt3->setPlainText(QString::number(foodNeedAnt3));
        // Add number of ant as text on the button (refresh)
        infoTextNbAnt3->setPlainText(QString::number(numberOfAnt3));

        AntTank *tank = new AntTank(pathAnt3);
        listOfAnt3->append(tank);

        QGraphicsPixmapItem *tempPixMap = new QGraphicsPixmapItem();
        tempPixMap->setPixmap(*spriteAnt3);
        this->addItem(tempPixMap);
        tempPixMap->setPos(BASEX,BASEY);
        listOfGraphicAnt3->append(tempPixMap);
    }
}


// Randomly add food on the board within an aera around the base
void CustomScene::addFood(){

    foodCount = FOODCOUNT;
    food = new QPixmap("../JeuPewpew/Images/food.png");

    foodGraphics = new QGraphicsPixmapItem();
    foodGraphics->setPixmap(*food);
    this->addItem(foodGraphics);

    int X = (rand() % (BASEX - 1 + 1));
    int Y = (rand() % (HEIGHTBOARD - HEIGHTBGBUTTONLEFT - HEIGHTINFOBUTTON - HEIGHTFOOD + 1));
    foodArea = new QRect(X,Y,WIDTHFOOD,HEIGHTFOOD);
    foodGraphics->setPos(X,Y);
}

// Creation of waves of ennemies
void CustomScene::CreateWave(int nbEnemy1, int nbEnemy2, int nbEnemy3){

    this->initializeEnemyList(nbEnemy1,nbEnemy2,nbEnemy3);
    this->initializeEnemySprite();

}
