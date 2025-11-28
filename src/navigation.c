/*
 * navigation.c
 * 导航模块实现
 *
 * 主要功能：
 * - 调用图的算法实现最短路径搜索
 * - 打印路径
 */

#include "../include/navigation.h"
#include "../include/graph.h"
#include <stdio.h>

// 打印所有景点
void printAllScenic(Graph *g) {
    printf("\n====== 所有景点 ======\n");
    for (int i = 0; i < g->spotCount; i++) {
        if (g->spots[i].id != -1) {
            printf("%d. %s\n", g->spots[i].id, g->spots[i].name);
        }
    }
    printf("========================\n");
}

// 查询景点信息
void queryScenic(Graph *g) {
    int id;
    printf("请输入景点编号：");
    scanf("%d", &id);
    
    if (id >= 0 && id < g->spotCount && g->spots[id].id != -1) {
        printf("\n====== 景点信息 ======\n");
        printf("编号：%d\n", g->spots[id].id);
        printf("名称：%s\n", g->spots[id].name);
        printf("简介：%s\n", g->spots[id].description);
        printf("========================\n");
    } else {
        printf("无效的景点编号！\n");
    }
}

// 查询两个景点的最短路径
void shortestPath(Graph *g) {
    int start, end;
    int path[MAX_NODES];
    
    printf("请输入起点编号：");
    scanf("%d", &start);
    printf("请输入终点编号：");
    scanf("%d", &end);
    
    if (start < 0 || start >= g->spotCount || end < 0 || end >= g->spotCount || 
        g->spots[start].id == -1 || g->spots[end].id == -1) {
        printf("无效的景点编号！\n");
        return;
    }
    
    int distance = dijkstra(g, start, end, path);
    
    if (distance == -1) {
        printf("从 %s 到 %s 没有可达路径！\n", g->spots[start].name, g->spots[end].name);
    } else {
        printf("\n====== 最短路径 ======\n");
        printf("起点：%s\n", g->spots[start].name);
        printf("终点：%s\n", g->spots[end].name);
        printf("最短距离：%d 单位\n", distance);
        printf("路径：");
        
        int i = 0;
        while (path[i] != -1 && i < MAX_NODES) {
            if (i > 0) {
                printf(" -> ");
            }
            printf("%s", g->spots[path[i]].name);
            // 当遇到终点时停止
            if (path[i] == end) {
                break;
            }
            i++;
        }
        printf("\n========================\n");
    }
}

// 主菜单
void MainMenu(Graph *g) {
    int choice;

    while (1) {
        printf("\n====== 校园导航系统 ======\n");
        printf("1. 查看所有景点\n");
        printf("2. 查询景点信息\n");
        printf("3. 查询两个景点的最短路径\n");
        printf("4. 退出\n");
        printf("请输入选项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAllScenic(g);
                break;
            case 2:
                queryScenic(g);
                break;
            case 3:
                shortestPath(g);
                break;
            case 4:
                return;
            default:
                printf("无效输入，请重试。\n");
        }
    }
}
