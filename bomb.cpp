#include "bomb.h"

Bomb::Bomb()
{
    //将所有爆炸pixmap放入到准备的数组中
    for(int i = 1; i <= BOMB_MAX; i++)
    {
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    //坐标
    m_X = 0;
    m_Y = 0;

    //初始化空闲状态
    m_Free = true;

    //当前播放图片下标
    m_index = 0;

    //爆炸间隔记录
    m_Recoder = 0;
}

void Bomb::updateInfo()//（播放图片下标、播放间隔）
{
    if(m_Free)
    {
        return;
    }

    m_Recoder++;

    //如果记录爆炸的实际未达到爆炸间隔，不需要切图，直接return
    if(m_Recoder < BOMB_INTERVAL)
    {
        return;
    }
    //重置记录
    m_Recoder = 0;
    //切换爆炸图片的下标
    m_index++;
    if(m_index > BOMB_MAX - 1)
    {
        m_index = 0;
        m_Free = true;
    }

}
