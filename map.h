#ifndef MAP_H
#define MAP_H
#include <QPixmap>


class Map
{
public:
    Map();
    //地图滚动坐标计算
    void mapPosition();
public:

    //地图图片对象
    QPixmap pixMap1;
    QPixmap pixMap2;

    //地图Y轴坐标
    int map1_posY;
    int map2_posY;

    //地图滚动幅度
    int m_scroll_speed;
};

#endif // MAP_H
