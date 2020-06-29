#include "mainscene.h"
#include <QIcon>
#include <QMouseEvent>
#include <QSound>


MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    playGame();
    plane = new HeroPlane;

}

MainScene::~MainScene()
{

}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    //敌机出厂时间初始化
    enemyRecorder = 0;
    //随机数种子
    srand((unsigned int)time(NULL));  //头文件  #include <ctime>

}

void MainScene::playGame()
{
    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);
    //定时器设置
    this->m_Timer.setInterval(GAME_RATE);
    this->m_Timer.start();
    //监听定时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        //更新坐标
        updatePosition();
        //敌机出厂
        enemyToScene();
        //画到屏幕中
        update();
        //配置检测
        collisionDetection();
    });
}

void MainScene::updatePosition()
{
    m_map.mapPosition();

    //测试子弹
    //temp.isFree = false;
    //temp.updatePosition();

    plane->shot();
    for(int i =0;i<BULLET_NUM;i++)
    {
        if(plane->bullets[i].isFree == false )
        {
            plane->bullets[i].updatePosition();
        }
    }

    //敌机出厂
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机 更新坐标
        if(enemys[i].isFree == false)
        {
            enemys[i].updatePosition();
        }
    }

    //计算爆炸
    for(int i = 0; i< BOMB_NUM; i++)
    {
        //非空闲敌机 更新坐标
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();
        }
    }

}
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.map1_posY,m_map.pixMap1);
    painter.drawPixmap(0,m_map.map2_posY,m_map.pixMap2);

    //绘制英雄飞机
    painter.drawPixmap(plane->plane_x,plane->plane_y,plane->pixPlane);

    //绘制子弹

    for(int i =0;i<BULLET_NUM;i++)
    {
        if(plane->bullets[i].isFree == false )
        {
            painter.drawPixmap(plane->bullets[i].bulletX,plane->bullets[i].bulletY,plane->bullets->pixBullet);
        }
    }
    //测试子弹
    //painter.drawPixmap(temp.bulletX,temp.bulletY,temp.pixBullet);
    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(enemys[i].isFree == false)
        {
            painter.drawPixmap(enemys[i].enemyX,enemys[i].enemyY,enemys[i].pixEnemy);
        }
    }

    //绘制爆炸
    for(int i = 0; i < BOMB_NUM; i++)
    {
        if(enemys[i].isFree == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - plane->planeRect.width()*0.5;
    int y = event->y() - plane->planeRect.height()*0.5;

    //边界检测
    if(x<=0)
    {
        x = 0;
    }
    if(x>= GAME_WIDTH - plane->planeRect.width())
    {
        x = GAME_WIDTH - plane->planeRect.width();
    }
    if(y<=0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - plane->planeRect.height())
    {
        y = GAME_HEIGHT - plane->planeRect.height();
    }

    plane->setPosition(x,y);
}

void MainScene::enemyToScene()
{
    enemyRecorder++;
    if(enemyRecorder < ENEMY_INTERVAL)
    {
        return;
    }

    enemyRecorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(enemys[i].isFree)
        {
            //敌机空闲状态改为false
            enemys[i].isFree = false;
            //设置坐标
            enemys[i].enemyX = rand() % (GAME_WIDTH - enemys[i].enemyRect.width());
            enemys[i].enemyY = -enemys[i].enemyRect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有敌机
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(enemys[i].isFree)
        {
            continue;
        }
        //遍历子弹
        for(int j = 0;j < BULLET_NUM; j++)
        {
            if(plane->bullets[j].isFree)
            {
                continue;
            }

            //如果子弹和飞机相交 发生碰撞
            if(enemys[i].enemyRect.intersects(plane->bullets[j].bulletRect))
            {
                enemys[i].isFree = true;
                plane->bullets[i].isFree = true;
                //播放爆炸效果
                for(int k = 0; k < BOMB_NUM; k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //播放爆炸音效
                        QSound::play(SOUND_BOMB);
                        m_bombs[k].m_Free = false;
                        //更新爆炸坐标
                        m_bombs[k].m_X = enemys[i].enemyX;
                        m_bombs[k].m_Y = enemys[i].enemyY;
                        break;

                    }
                }
            }
        }
    }
}



