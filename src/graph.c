/*
 * graph.c
 * 图结构实现文件
 *
 * 主要功能实现：
 * - 图初始化：创建空图
 * - 增加边 / 删除边
 * - Dijkstra 最短路径算法（接口留空，后续由开发者补充）
 */

#include <stdio.h>
#include <limits.h>
#include "graph.h"

void initGraph(Graph *g, int n) {
    g->numNodes = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adjacencyMatrix[i][j] = (i == j ? 0 : INT_MAX);
        }
    }
}

void addEdge(Graph *g, int u, int v, int weight) {
    g->adjacencyMatrix[u][v] = weight;
    g->adjacencyMatrix[v][u] = weight;
}

void removeEdge(Graph *g, int u, int v) {
    g->adjacencyMatrix[u][v] = INT_MAX;
    g->adjacencyMatrix[v][u] = INT_MAX;
}

int dijkstra(Graph *g, int start, int end, int *path) {
    // TODO: 完成 Dijkstra 最短路径算法
    return 0;
}
