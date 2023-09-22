/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\06_rightSideView\main_chong_iteration.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-22 22:09:25
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 199. 二叉树的右视图: https://leetcode.cn/problems/binary-tree-right-side-view/
 * https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_199-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%8F%B3%E8%A7%86%E5%9B%BE
 * 解法参考：https://leetcode.cn/problems/binary-tree-right-side-view/solutions/1453989/by-goodgoodday-2kho/
 *
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * 二叉树的右视图：
 * [1, 3, 7]
 *
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
/*
    BFS 层序遍历法 - 只记录每层的最后一个元素
*/
/* ==================================================================================================== */
/* ==================================================================================================== */
#define MAX_SIZE 2000           /* 初始化大小 */

/**
 * @description: 二叉树的右视图
 * =================================================================================
 * @param {TreeNode} *root          二叉树的根节点
 * @param {int} *returnSize         返回数组大小
 * @return {int} *resultArray       结果一维数组（返回数组）
 */
int *rightSideView(struct TreeNode *root, int *returnSize){
    int *resultArray = (int *)calloc(MAX_SIZE, sizeof(int));            /* 为返回结果数组分配空间，并初始化为 0 */
    *returnSize = 0;                                                    /* 初始化返回数组大小为 0 */
    struct TreeNode *treeNodeQueue[MAX_SIZE];                           /* 创建队列存储树节点 */
    int queueFront = 0;                                                 /* 队列头指针初始化为 0 */
    int queueRear = 0;                                                  /* 队列尾指针初始化为 0 */

    if (root == NULL) {                                                 /* 如果根节点为空,直接返回 */
        return resultArray;
    }
    treeNodeQueue[queueRear++] = root;                                  /* 将根节点入队 */

    while (queueFront < queueRear) {                                    /* 当队列非空时循环 */
        int layerLastIndex = queueRear;                                     /* 记录当前层的最后一个元素的索引 */
        int value = 0;                                                      /* 当前层的最后一个元素的值初始化为 0 */
        while (queueFront < layerLastIndex) {                               /* 遍历当前层的元素 */
            struct TreeNode *curNode = treeNodeQueue[queueFront];               /* 获取当前遍历到的节点 */
            value = curNode->val;                                               /* 更新 value 为当前节点的值 */
            if (curNode->left != NULL) {                                        /* 如果左子节点非空,则入队 */
                treeNodeQueue[queueRear++] = curNode->left;
            }
            if (curNode->right != NULL) {                                       /* 如果右子节点非空,则入队 */
                treeNodeQueue[queueRear++] = curNode->right;
            }
            queueFront++;                                                       /* 队列头指针后移 */
        }
        resultArray[(*returnSize)++] = value;                               /* 将当前层的最后一个元素的值放入结果数组 */
    }

    return resultArray;                                                 /* 返回数组 */
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
 * @param {int} *array      一维数组
 * @param {int} size        一维数组的大小
 * @return {void}
 */
void print1DArray(int *array, int size) {
    printf("[");                        /* 打印行边框 [ */
    for (int i = 0; i < size; ++i) {        /* 遍历 array 内的元素 */
        printf("%d", array[i]);                 /* 打印 array 内的元素 */
        if (i < size - 1) {                     /* 打印分隔符：, */
            printf(", ");
        }
    }
    printf("]\n");                      /* 打印行边框 ] */
}

/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
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
    int* result = rightSideView(root, &returnSize);
    print1DArray(result, returnSize);

    freeTree(root);     /* 释放树所占用的空间 */
    free(result);       /* 释放结果一维数组的内存空间 */
    return 0;
}