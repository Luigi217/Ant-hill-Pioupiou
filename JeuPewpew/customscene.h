#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include "include.h"
#include "antfighter.h"
#include "antharvester.h"
#include "anttank.h"
#include "antbase.h"
#include "enemyfighter.h"
#include "enemybomber.h"
#include "enemyspeedster.h"

class CustomScene: public QGraphicsScene,QWidget
{
public:
    CustomScene();
    ~CustomScene();

    // Store the path from a mouseMoveEvent for the ants
    void checkCoordinates(QPoint r,QPoint a);
    void affectPathToAnt(QVector<QPoint> *path);

    // Function WIN / LOOSE
    void loose();
    void win();

    // Initialization of the scene
    void initializePathAndGameStats();
    void addBaseAndGameButtons();
    void initializeAntList();
    void initializeEnemyList(int nbEnemy1, int nbEnemy2, int nbEnemy3);
    QPoint CreationOfPosition();
    QVector<QPoint> InitializeEnemyPath(QPoint *p);
    void initializeAntSprite();
    void initializeEnemySprite();

    // Dynamic display
    void updateFoodText();
    void updateAntSprite();
    void updateEnemySprite();
    void delay();
    void deleteEverything();


    // Movement of ants
    void moveAllAnts();
    void moveAllEnemy();
    void moveAntHarvester(AntHarvester *a);
    void moveAntFighter(AntFighter *f);
    void moveAntTank(AntTank *t);
    void moveEnemy(Enemy *e);


    // States verification
    void checkFoodState();
    Ant* checkForAnt(Enemy *e);
    Enemy* checkForEnemy(Ant *a);
    void checkIfAlive(Enemy *e);
    void checkIfAntAlive(Ant *a);
    void checkIfBaseAlive(AntBase *b);
    bool checkPositionInFood(QPoint *p);
    bool checkReturnOfTheHero(QPoint *p);


    // Boost button of ants
    void addAnt1();
    void addAnt2();
    void addAnt3();


    // Add food on the map
    void addFood();  

    // Creation of waves of ennemies
    void CreateWave(int nbEnemy1, int nbEnemy2, int nbEnemy3);


    bool getStateOfGame() const;
    void setStateOfGame(bool value);

    int getEnemyCountDown() const;
    void setEnemyCountDown(int value);

    bool getGameIsEmpty() const;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:

    // Booleans for MouseMoveEvent
    bool onMove;
    bool isReleased;

    // Boolean to destroy item in scene or not
    bool gameIsEmpty;

    // String of the choice of the button
    QString buttonAntSelected;

    // Enemy count down
    int enemyCountDown;

    // Base
    AntBase *baseData;

    // Help button
    QGraphicsPixmapItem *help;
    QPixmap *helpSprite;
    QGraphicsRectItem *helpButton;
    QRect *rectHelp;


    // Data vectors

    // Paths vectors
    QVector<QPoint> *pathAnt1;
    QVector<QPoint> *pathAnt2;
    QVector<QPoint> *pathAnt3;
    QVector<QPoint> *tempPath;
    // Ants vectors
    QVector<AntHarvester*> *listOfAnt1;
    QVector<AntFighter*> *listOfAnt2;
    QVector<AntTank*> *listOfAnt3;
    // Enemies vectors
    QVector<EnemyFighter*> *listOfEnemy1;
    QVector<EnemySpeedster*> *listOfEnemy2;
    QVector<EnemyBomber*> *listOfEnemy3;
    // GraphicsPixmapItem ants vectors
    QVector<QGraphicsPixmapItem*> *listOfGraphicAnt1;
    QVector<QGraphicsPixmapItem*> *listOfGraphicAnt2;
    QVector<QGraphicsPixmapItem*> *listOfGraphicAnt3;
    // GraphicsPixmapItem enemies vectors
    QVector<QGraphicsPixmapItem*> *listOfGraphicEnemy1;
    QVector<QGraphicsPixmapItem*> *listOfGraphicEnemy2;
    QVector<QGraphicsPixmapItem*> *listOfGraphicEnemy3;

    // Health bar
    QGraphicsPixmapItem *healthBar;
    QPixmap *healthSprite;


    // Aera of interest
    QRect *foodArea;
    QRect *vision;
    QRect *baseArea;
    QRect *EnemyArea;
    QRect *geometry;
    QRect *rectChoice1;
    QRect *rectChoice2;
    QRect *rectChoice3;
    QRect *rectBoost1;
    QRect *rectBoost2;
    QRect *rectBoost3;


    // Counters

    // Number of ants
    int numberOfAnt1;
    int numberOfAnt2;
    int numberOfAnt3;
    // Food needed for boosting
    int foodNeedAnt1;
    int foodNeedAnt2;
    int foodNeedAnt3;
    // Total number of food
    int numberOfFood;
    // Food counter of the food object
    int foodCount;
    // Max Enemy
    const int countMaxEnemy = 50;



    // Sprites

    // Ant sprites
    QPixmap *spriteAnt1;
    QPixmap *spriteAnt2;
    QPixmap *spriteAnt3;
    // Enemies sprites
    QPixmap *spriteEnemy1;
    QPixmap *spriteEnemy2;
    QPixmap *spriteEnemy3;
    // Food sprites
    QPixmap *food;
    // Background sprite
    QPixmap background;
    // UI buttons
    QPixmap *buttonChoiceAnt1Sprite;
    QPixmap *buttonChoiceAnt2Sprite;
    QPixmap *buttonChoiceAnt3Sprite;
    QPixmap *buttonBoostAnt1Sprite;
    QPixmap *buttonBoostAnt2Sprite;
    QPixmap *buttonBoostAnt3Sprite;
    // Ant base sprite
    QPixmap *baseSprite;



    // UI text

    // Black background for text UI
    QGraphicsRectItem *backgroundButtonLeft;
    QGraphicsRectItem *backgroundButtonRight;
    QGraphicsRectItem *infoButtonLeft;
    QGraphicsRectItem *infoButtonRight;
    QGraphicsRectItem *infoFoodBg;
    QGraphicsRectItem *infoButtonFoodNeeded;
    QGraphicsRectItem *infoButtonNumberAnt;
    // Text aera for dynamic information of the game
    QGraphicsTextItem *infoTextLeft;
    QGraphicsTextItem *infoTextRight;
    QGraphicsTextItem *infoFood;
    // Food information as text for ant
    QGraphicsTextItem *infoTextAnt1;
    QGraphicsTextItem *infoTextAnt2;
    QGraphicsTextItem *infoTextAnt3;
    // Number of ant information as text
    QGraphicsTextItem *infoTextNbAnt1;
    QGraphicsTextItem *infoTextNbAnt2;
    QGraphicsTextItem *infoTextNbAnt3;
    // Text for current number of ant
    QGraphicsTextItem *infoTextNumberAnt;
    // Text fort current food needed for boost
    QGraphicsTextItem *infoTextFoodNeeded;

    // GraphicsPixmapItem of UI
    QGraphicsPixmapItem *buttonChoiceAnt1;
    QGraphicsPixmapItem *buttonChoiceAnt2;
    QGraphicsPixmapItem *buttonChoiceAnt3;
    QGraphicsPixmapItem *buttonBoostAnt1;
    QGraphicsPixmapItem *buttonBoostAnt2;
    QGraphicsPixmapItem *buttonBoostAnt3;
    // GraphicsPixmapItem of the food and the ant base in the scene
    QGraphicsPixmapItem *foodGraphics;
    QGraphicsPixmapItem *base;

};




#endif // CUSTOMSCENE_H
