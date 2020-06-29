#include "map.h"
#include "config.h"

Map::Map()
{
    //初始化加载地图对象
    pixMap1.load(MAP_PATH);
    pixMap2.load(MAP_PATH);

    //设置坐标
    map1_posY = -GAME_HEIGHT;
    map2_posY = 0;

    //设置滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}
void Map::mapPosition(){

    //处理第一张图片滚动
    map1_posY += m_scroll_speed;
    if(map1_posY >= 0)
    {
        map1_posY = -GAME_HEIGHT;
    }
    //处理第二张图片滚动
    map2_posY += m_scroll_speed;
    if(map2_posY >= GAME_HEIGHT)
    {
        map2_posY = 0;
    }

}
