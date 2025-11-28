/*
 * main.c
 * 项目入口
 *
 * 功能：
 * - 加载地图数据
 * - 初始化图结构
 * - 提供简单菜单（后续可扩展）
 */

#include "../include/graph.h"
#include "../include/map.h"
#include "../include/navigation.h"
#include <stdio.h>

int main() {
    Graph g;
    InitGraph(&g);

    // 加载 map_data.txt 数据
    loadMapData(&g, "data/map_data.txt");

    printf("地图数据加载完毕！\n");

    // 后面你会写菜单
    MainMenu(&g);

    return 0;
}

