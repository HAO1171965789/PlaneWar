#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>

class EnemyPlane
{
public:
    EnemyPlane();
    //更新坐标
    void updatePosition();
public:
    //敌机资源对象
    QPixmap pixEnemy;

    //位置
    int enemyX;
    int enemyY;

    //敌机的矩形边框（碰撞检测）
    QRect enemyRect;

    //状态
    bool isFree;

    //速度
    int enemySpeed;
};

#endif // ENEMYPLANE_H
