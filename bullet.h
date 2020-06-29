#ifndef BULLET_H
#define BULLET_H

#include "config.h"
#include <QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void updatePosition();
public:
    //子弹资源对象
    QPixmap pixBullet;
    //子弹坐标
    int bulletX;
    int bulletY;
    //子弹移动速度
    int bulletSpeed;
    //子弹是否闲置
    bool isFree;
    //子弹的矩形框（用于碰撞检测）
    QRect bulletRect;

};

#endif // BULLET_H
