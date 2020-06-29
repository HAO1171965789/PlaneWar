#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "config.h"
#include <QTimer>
#include "map.h"
#include <QPainter>
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include <ctime>
#include <bomb.h>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane * plane;

    //敌机出场
    void enemyToScene();

    //敌机数组
    EnemyPlane enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int enemyRecorder;

    //定时器
    QTimer m_Timer;

    //碰撞检测
    void collisionDetection();

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //测试子弹对象
    //Bullet temp;
};
#endif // MAINSCENE_H
