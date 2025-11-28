/*
 * utils.c
 * 工具函数实现
 */

#include <stdio.h>
#include "../include/utils.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getIntInput(const char *msg) {
    int num;
    printf("%s", msg);
    scanf("%d", &num);
    return num;
}
