#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"


class HeroPlane
{
public:
    HeroPlane();

    //发射子弹
    void shot();
    //设置飞机位置
    void setPosition(int x, int y);
public:
    //飞机资源 对象
    QPixmap pixPlane;
    //飞机坐标
    int plane_x;
    int plane_y;
    //飞机的矩形边框
    QRect planeRect;

    //弹夹
    Bullet bullets[BULLET_NUM];

    //发射间隔记录
    int shotRecorder;

};

#endif // HEROPLANE_H
