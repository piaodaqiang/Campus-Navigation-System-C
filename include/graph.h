/*
 * graph.h
 * 图结构头文件
 *
 * 主要功能：
 * - 定义图的数据结构（邻接矩阵或邻接表）
 * - 节点结构体、边结构体
 * - 图的初始化、插入节点、插入边、删除边
 * - 最短路径算法接口（Dijkstra / Floyd）
 */

#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 100
#define MAX_NAME_LENGTH 100
#define MAX_DESC_LENGTH 200

// 景点信息结构体
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
} ScenicSpot;

// 图结构体
typedef struct {
    int numNodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    ScenicSpot spots[MAX_NODES];
    int spotCount;
} Graph;

// 函数声明
void initGraph(Graph *g, int n);
void InitGraph(Graph *g); // 兼容main.c中的调用
void addEdge(Graph *g, int u, int v, int weight);
void removeEdge(Graph *g, int u, int v);
int dijkstra(Graph *g, int start, int end, int *path);
void AddScenic(Graph *g, int id, const char *name, const char *desc);

#endif
