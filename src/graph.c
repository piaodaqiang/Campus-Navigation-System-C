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
#include <string.h>
#include "../include/graph.h"


void initGraph(Graph *g, int n) {
    g->numNodes = n;
    g->spotCount = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            g->adjacencyMatrix[i][j] = (i == j ? 0 : INT_MAX);
        }
        // 初始化景点信息
        g->spots[i].id = -1;
        g->spots[i].name[0] = '\0';
        g->spots[i].description[0] = '\0';
    }
}

// 兼容main.c中的InitGraph调用
void InitGraph(Graph *g) {
    initGraph(g, MAX_NODES);
}

// 添加景点信息
void AddScenic(Graph *g, int id, const char *name, const char *desc) {
    if (id >= 0 && id < MAX_NODES) {
        g->spots[id].id = id;
        strncpy(g->spots[id].name, name, MAX_NAME_LENGTH - 1);
        g->spots[id].name[MAX_NAME_LENGTH - 1] = '\0';
        strncpy(g->spots[id].description, desc, MAX_DESC_LENGTH - 1);
        g->spots[id].description[MAX_DESC_LENGTH - 1] = '\0';
        if (id >= g->spotCount) {
            g->spotCount = id + 1;
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
    // 初始化距离数组
    int dist[MAX_NODES];
    // 初始化访问数组
    int visited[MAX_NODES] = {0};
    // 初始化前驱节点数组
    int prev[MAX_NODES] = {-1};
    
    // 初始化距离数组，将所有距离设为无穷大
    for (int i = 0; i < g->numNodes; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    
    // 起点到自身的距离为0
    dist[start] = 0;
    
    // Dijkstra算法主体
    for (int count = 0; count < g->numNodes - 1; count++) {
        // 找到当前距离最小的未访问节点
        int minDist = INT_MAX;
        int minIndex = -1;
        
        for (int i = 0; i < g->numNodes; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        
        // 如果找不到最小距离节点，说明无法到达
        if (minIndex == -1) {
            break;
        }
        
        // 标记当前节点为已访问
        visited[minIndex] = 1;
        
        // 更新相邻节点的距离
        for (int v = 0; v < g->numNodes; v++) {
            // 如果节点v未访问，且存在边minIndex->v，且通过minIndex到达v的距离更小
            if (!visited[v] && g->adjacencyMatrix[minIndex][v] != INT_MAX && 
                dist[minIndex] + g->adjacencyMatrix[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + g->adjacencyMatrix[minIndex][v];
                prev[v] = minIndex;
            }
        }
    }
    
    // 构建路径
    int pathIndex = 0;
    int temp = end;
    
    // 如果无法到达终点，返回-1
    if (dist[end] == INT_MAX) {
        return -1;
    }
    
    // 从终点回溯到起点
    while (temp != -1) {
        path[pathIndex++] = temp;
        temp = prev[temp];
    }
    
    // 反转路径，使其从起点到终点
    for (int i = 0; i < pathIndex / 2; i++) {
        int temp = path[i];
        path[i] = path[pathIndex - 1 - i];
        path[pathIndex - 1 - i] = temp;
    }
    
    // 返回最短路径的距离
    return dist[end];
}




