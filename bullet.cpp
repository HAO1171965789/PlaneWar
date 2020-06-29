#include "bullet.h"

Bullet::Bullet()
{
    //加载资源
    pixBullet.load(BULLET_PATH);
    //子弹坐标 先随意设一个
    bulletX = GAME_WIDTH*0.5 - pixBullet.width()*0.5;
    bulletY = GAME_HEIGHT;
    //子弹状态
    isFree = true;
    //子弹速度
    bulletSpeed = BULLET_SPEED;
    //子弹边框
    bulletRect.setWidth(pixBullet.width());
    bulletRect.setHeight(pixBullet.height());
    bulletRect.moveTo(bulletX,bulletY);
}

void Bullet::updatePosition()
{
    if (isFree)
    {
        return;
    }
    //子弹向上移动
    bulletY -= bulletSpeed;
    bulletRect.moveTo(bulletX,bulletY);
    if(bulletY <= bulletRect.height())
    {
        isFree = true;
    }
}
