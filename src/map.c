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
#include <stdlib.h>
#include <string.h>
#include "../include/map.h"

void loadMapData(Graph *g, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("无法打开地图数据文件：%s\n", filename);
        return;
    }

    int id;
    char name[100];
    char desc[200];

    while (fscanf(fp, "%d \"%[^\"]\" \"%[^\"]\"\n", &id, name, desc) == 3) {
        AddScenic(g, id, name, desc);
    }

    fclose(fp);
}

