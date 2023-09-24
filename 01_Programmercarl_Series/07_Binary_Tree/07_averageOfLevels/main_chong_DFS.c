/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\07_averageOfLevels\main_chong_DFS.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-24 09:12:56
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 637. 二叉树的层平均值: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_637-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%B9%B3%E5%9D%87%E5%80%BC
 * 解法参考：https://leetcode.cn/problems/average-of-levels-in-binary-tree/solutions/410522/er-cha-shu-de-ceng-ping-jun-zhi-by-leetcode-soluti/
 *
 * 方法一：深度优先搜索
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * sums:        [1,    5,  22]
 * counts:      [1,    2,   4]
 * averages:    [1,  2.5, 5.5]
 */
#include <stdio.h>
#include <stdlib.h>

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 目标函数 */
/*
    Depth-First-Search (DFS) - 深度优先搜索算法
        使用深度优先搜索计算二叉树的层平均值，需要维护两个数组
        counts: 用于存储二叉树的每一层的节点数
        sums:   用于存储二叉树的每一层的节点值之和
        搜索过程中需要记录当前节点所在层
            如果访问到的节点在第 i 层，
            则将 counts[i] 的值加 1，并将该节点的值加到 sums[i]
*/
/* ==================================================================================================== */
/* ==================================================================================================== */
int countsSize;     /* 记录每层节点数的数组的大小 */
int sumsSize;       /* 记录每层节点值之和的数组的大小 */

/**
 * @description: 深度优先搜索算法
 * =================================================================================
 * @param {TreeNode} *root  二叉树的根节点
 * @param {int} level       当前节点所在的层数
 * @param {int} *counts     记录每层节点数的数组
 * @param {double} *sums    记录每层节点值之和的数组
 * @return {void}
 */
void depthFirstSearch(struct TreeNode *root, int level, int *counts, double *sums) {
    if (root == NULL) {                                         /* 如果当前节点为空，直接返回 */
        return;
    }
    if (level < sumsSize) {                                     /* 如果当前层数小于记录节点值之和的数组的大小 */
        sums[level] += root->val;                                   /* 将当前节点的值加到对应层的节点值之和上 */
        counts[level] += 1;
    } else {
        sums[sumsSize++] = (double)root->val;
        counts[countsSize++] = 1;
    }
    depthFirstSearch(root->left, level + 1, counts, sums);
    depthFirstSearch(root->right, level + 1, counts, sums);
}

/**
 * @description: 二叉树的层平均值
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {double} *averages
 */
double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    countsSize = sumsSize = 0;
    int* counts = malloc(sizeof(int) * 1001);
    double* sums = malloc(sizeof(double) * 1001);
    depthFirstSearch(root, 0, counts, sums);
    double* averages = malloc(sizeof(double) * 1001);
    *returnSize = sumsSize;
    for (int i = 0; i < sumsSize; i++) {
        averages[i] = sums[i] / counts[i];
    }
    return averages;
}
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 创建树节点
 * =================================================================================
 * @param {int} value                   树节点的数值
 * @return {struct TreeNode} *node      新树节点的指针
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));     /* 初始化树节点：为树节点分配空间 */
    node->val = value;                                                              /* 树节点的值为 value */
    node->left = NULL;                                                              /* 树节点的左子节点为 NULL */
    node->right = NULL;                                                             /* 树节点的右子节点为 NULL */
    return node;                                                                    /* 返回树节点 */
}

/**
 * @description: 后续遍历释放树所占用的空间
 * =================================================================================
 * @param {TreeNode} *root
 * @return {void}
 */
void freeTree(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }

    freeTree(root->left);           /* 遍历释放左节点空间 */
    freeTree(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}

/**
 * @description: 打印一维数组
 * =================================================================================
 * @param {double} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(double *array, int size) {
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        printf("%.3f", array[i]);                 /* 打印 array 内的元素 */
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc
 * @param {char} *argv[]
 * @return {*}
 */
int main(int argc, const char *argv[]) {
    /*
     * 创建以下树结构
     *      1
     *     / \
     *    2   3
     *   / \ / \
     *  4  5 6  7
     */
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int returnSize = 0;

    /* 函数调用 */
    double* result = averageOfLevels(root, &returnSize);
    print1DArray(result, returnSize);

    freeTree(root);     /* 释放树所占用的空间 */
    free(result);       /* 释放结果一维数组的内存空间 */
    return 0;
}