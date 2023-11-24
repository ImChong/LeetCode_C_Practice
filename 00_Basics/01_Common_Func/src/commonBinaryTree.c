/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\src\commonBinaryTree.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-22 09:30:32
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-11-24 20:12:19
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 通用二叉树源文件
 */
/* 编译配置文件 */
#include "compileCfg.h"
#if COMMON_BINARY_TREE_EN         /* 在每一道题 cfg 文件夹下的 compileCfg.h 开启编译宏定义 */
/* 标准头文件 */
#include <stdio.h>
/* 常用头文件 */
#include "commonBinaryTree.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define MAX_SIZE 100                /* 数组和栈的大小 */

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 前序遍历
 * =================================================================================
 * @param {TreeNode} *node      当前节点指针
 * @param {int} *ret            用于储存遍历答案的数组
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {void}
 */
void preOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    ret[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    preOrder(node->left, ret, returnSize);              /* 前序遍历左节点 */
    preOrder(node->right, ret, returnSize);             /* 前序遍历右节点 */
}

/**
 * @description: 前序遍历 - 递归方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ret           用于储存遍历答案的数组
 */
int *preorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    preOrder(root, ret, returnSize);                    /* 前序遍历根节点 */
    return ret;                                         /* 返回结果 ret 数组 */
}

/**
 * @description: 前序遍历 - 迭代方法
 * =================================================================================
 * @param {TreeNode} *root      根节点指针
 * @param {int} *returnSize     用于储存遍历答案的数组的大小
 * @return {int} *ret           用于储存遍历答案的数组
 */
int *preorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return res;
    }

    struct TreeNode *stk[MAX_SIZE];                     /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (stk_top > 0 || node != NULL) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            res[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return res;                                         /* 返回结果数组 */
}

/* ============================================================================== */
/* ============================================================================== */

/**
 * @description: 中序遍历
 * =================================================================================
 * @param {TreeNode} *node
 * @param {int} *ret
 * @param {int} *returnSize
 * @return {*}
 */
void inOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    inOrder(node->left, ret, returnSize);               /* 中序遍历左节点 */
    ret[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
    inOrder(node->right, ret, returnSize);              /* 中序遍历右节点 */
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {*}
 */
int *inorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个100长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    inOrder(root, ret, returnSize);                     /* 中序遍历根节点 */
    return ret;                                         /* 返回结果 ret 数组 */
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {*}
 */
int *inorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);   /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案 */
    *returnSize = 0;                                    /* 初始化数组的大小为 0 */
    if (root == NULL) {                                 /* 如果当前节点为 NULL，直接返回 */
        return res;
    }

    struct TreeNode **stk = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE);   /* 分配一个MAX_SIZE容量的树节点栈空间（后期需要free） */
    int stk_top = 0;                                    /* 栈顶索引为 0 */
    struct TreeNode *node = root;                       /* 获取根节点的指针 */
    while (node != NULL || stk_top > 0) {               /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                              /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                              /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                  /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                              /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        res[(*returnSize)++] = node->val;                   /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
        node = node->right;                                 /* 节点指针向右移动 */
    }
    return res;                                         /* 返回结果数组 */
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *node
 * @param {int} *ret
 * @param {int} *returnSize
 * @return {*}
 */
void postOrder(struct TreeNode *node, int *ret, int *returnSize) {
    if (node == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return;
    }
    postOrder(node->left, ret, returnSize);                 /* 后序遍历左节点 */
    postOrder(node->right, ret, returnSize);                /* 后序遍历右节点 */
    ret[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {*}
 */
int *postorderTraversal_recursion(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个 MAX_SIZE 长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    postOrder(root, ret, returnSize);                       /* 后序遍历根节点 */
    return ret;                                             /* 返回结果 ret 数组 */
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @param {int} *returnSize
 * @return {*}
 */
int *postorderTraversal_iteration(struct TreeNode *root, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_SIZE);       /* 初始化一个MAX_SIZE长度的 ret 数组，用于储存遍历答案（后期需要free） */
    *returnSize = 0;                                        /* 初始化数组的大小为 0 */
    if (root == NULL) {                                     /* 如果当前节点为 NULL，直接返回 */
        return res;
    }

    struct TreeNode *stk[MAX_SIZE];                         /* 用数组实现初始化一个MAX_SIZE容量的树节点栈 */
    int stk_top = 0;                                        /* 栈顶索引为 0 */
    struct TreeNode *node = root;                           /* 获取根节点的指针 */
    struct TreeNode *prev = NULL;                           /* 设置前节点的指针为 NULL */
    while (node != NULL || stk_top > 0) {                   /* 当栈顶索引大于0 或者 节点指针不指向NULL */
        while (node != NULL) {                                  /* 当结点指针不指向NULL */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->left;                                      /* 节点指针向左移动 */
        }
        node = stk[--stk_top];                                  /* 出栈：当节点指针指向NULL - 左节点指针已经到头：获取栈顶节点指针，并将栈顶索引 - 1 */
        if (node->right == NULL || node->right == prev) {       /* 如果右节点为NULL 或者 右节点为前节点 */
            res[(*returnSize)++] = node->val;                       /* 把当前节点的值放入ret数组的 *returnSize 索引，并将 *returnSize 索引值 + 1 */
            prev = node;                                            /* 给前节点指针赋值为当前节点 */
            node = NULL;                                            /* 把当前节点指针赋值为 NULL*/
        } else {                                                /* 否则 */
            stk[stk_top++] = node;                                  /* 入栈：将当前节点指针放入栈顶，并将栈顶索引 + 1 */
            node = node->right;                                     /* 节点指针向右移动 */
        }
    }
    return res;                                             /* 返回结果数组 */
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description:
 * =================================================================================
 * @param {int} value
 * @return {*}
 */
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @description:
 * =================================================================================
 * @param {int} *arr
 * @param {int} arrSize
 * @param {int} index
 * @param {TreeNode} *
 * @return {*}
 */
void arrayToTree(int *arr, int arrSize, int index, struct TreeNode **root) {
    if (index < arrSize) {
        *root = newNode(*(arr + index));
        arrayToTree(arr, arrSize, 2 * index + 1, &((*root)->left));
        arrayToTree(arr, arrSize, 2 * index + 2, &((*root)->right));
    }
}

/**
 * @description:
 * =================================================================================
 * @param {TreeNode} *root
 * @return {*}
 */
void freeTree(struct TreeNode *root) {
    if (root == NULL) {             /* 如果传入节点为 NULL 则返回 */
        return;
    }
    freeTree(root->left);           /* 遍历释放左节点空间 */
    freeTree(root->right);          /* 遍历释放右节点空间 */
    free(root);                     /* 释放当前节点空间 */
}



#endif      /* COMMON_BINARY_TREE_EN */