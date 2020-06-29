#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    pixEnemy.load(ENEMY_PATH);

    //敌机位置
    enemyX = 0;
    enemyY = 0;

    //敌机状态
    isFree = true;

    //敌机速度
    enemySpeed = ENEMY_SPEED;

    //敌机矩形
    enemyRect.setWidth(pixEnemy.width());
    enemyRect.setHeight(pixEnemy.height());
    enemyRect.moveTo(enemyX,enemyY);
}

void EnemyPlane::updatePosition()
{
    if(isFree)
    {
        return;
    }
    enemyY += enemySpeed;
    enemyRect.moveTo(enemyX,enemyY);

    //如果超出屏幕 重置空闲状态
    if(enemyY >= GAME_HEIGHT)
    {
        isFree = true;
    }
}
