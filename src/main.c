/*
 * main.c
 * 项目入口
 *
 * 功能：
 * - 加载地图数据
 * - 初始化图结构
 * - 提供简单菜单（后续可扩展）
 */

#include <stdio.h>
#include "map.h"
#include "navigation.h"

int main() {
    Graph g;
    loadMapData("data/map_data.txt", &g);

    printf("校园导航系统初始化完成！\n");
    printf("示例：查询 0 到 3 的最短路径（算法未实现）\n");

    findShortestPath(&g, 0, 3);

    return 0;
}
