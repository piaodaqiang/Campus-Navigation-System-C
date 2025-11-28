/*
 * map.c
 * 地图数据加载模块实现
 *
 * 数据格式示例（map_data.txt）：
 *   节点数量
 *   u v weight
 *   u v weight
 *
 * 例如：
 *   5
 *   0 1 10
 *   1 2 5
 *   ...
 */

#include <stdio.h>
#include "map.h"

void loadMapData(const char *filename, Graph *g) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("无法打开地图文件：%s\n", filename);
        return;
    }

    int n;
    fscanf(fp, "%d", &n);
    initGraph(g, n);

    int u, v, w;
    while (fscanf(fp, "%d %d %d", &u, &v, &w) == 3) {
        addEdge(g, u, v, w);
    }

    fclose(fp);
}
