/*
 * navigation.c
 * 导航模块实现
 *
 * 主要功能：
 * - 调用图的算法实现最短路径搜索
 * - 打印路径
 */

#include <stdio.h>
#include "navigation.h"

void findShortestPath(Graph *g, int start, int end) {
    int path[MAX_NODES];
    int length = dijkstra(g, start, end, path);

    printf("最短路径：\n");
    displayPath(path, length);
}

void displayPath(int *path, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}
