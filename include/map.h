/*
 * map.h
 * 地图数据加载模块
 *
 * 主要功能：
 * - 读取外部地图文件（map_data.txt）
 * - 解析地点名称、编号、坐标等（如果有）
 * - 构建地图对应的图的数据结构
 */

#ifndef MAP_H
#define MAP_H

#include "graph.h"

void loadMapData(Graph *g, const char *filename);


#endif
