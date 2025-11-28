/*
 * navigation.h
 * 导航逻辑模块
 *
 * 主要功能：
 * - 基于图结构进行路径查询
 * - 提供路径打印、距离显示等功能
 */

#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "graph.h"

void findShortestPath(Graph *g, int start, int end);
void displayPath(int *path, int length);

#endif
