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

typedef struct {
    int numNodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph *g, int n);
void addEdge(Graph *g, int u, int v, int weight);
void removeEdge(Graph *g, int u, int v);
int dijkstra(Graph *g, int start, int end, int *path);

#endif
