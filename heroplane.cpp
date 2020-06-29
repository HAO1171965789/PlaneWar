#include "heroplane.h"
#include "config.h"
HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    pixPlane.load(HERO_PATH);
    //初始化飞机坐标
    plane_x = (GAME_WIDTH-pixPlane.width())*0.5;
    plane_y = GAME_HEIGHT - pixPlane.height();
    //初始化矩形边框
    planeRect.setWidth(pixPlane.width());
    planeRect.setHeight(pixPlane.height());
    planeRect.moveTo(plane_x,plane_y);
}

void HeroPlane::shot()
{
    //累加时间间隔记录变量
    shotRecorder++;
    if(shotRecorder < BULLET_INTERVAL)
    {
        return;
    }
    //达到发射间隔
    shotRecorder = 0;
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果是空闲的 进行发射
        if(bullets[i].isFree)
        {
            bullets[i].isFree = false;

            bullets[i].bulletX = plane_x+planeRect.width()*0.5-10;
            bullets[i].bulletY = plane_y-planeRect.height()*0.5;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    plane_x = x;
    plane_y = y;
    planeRect.moveTo(plane_x,plane_y);
}
