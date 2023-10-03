/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\07_Binary_Tree\12_maxDepth\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-03 09:53:29
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 104. 二叉树的最大深度: https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 * 解法参考: https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/349250/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
 */
#include <stdio.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
/* 方法使能宏，注意一次只能使能一个方法，否则会出现函数重定义告警 */
#define DFS_METHOD_EN 1     /* 深度优先搜索方法使能 */
#define BFS_METHOD_EN 1     /* 广度优先搜索方法使能 */

/**********************************************************************************/
/*                                                                                */
/*                                 GLOBAL VARIABLES                               */
/*                                                                                */
/**********************************************************************************/
/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/*
    方法一：深度优先搜索
        如果我们知道了左子树和右子树的最大深度 l 和 r，那么该二叉树的最大深度即为 max(l,r) + 1
        而左子树和右子树的最大深度又可以以同样的方式进行计算
        因此我们可以用「深度优先搜索」的方法来计算二叉树的最大深度
        具体而言，在计算当前二叉树的最大深度时，可以先递归计算出其左子树和右子树的最大深度
        然后在 O(1) 时间内计算出当前二叉树的最大深度。递归在访问到空节点时退出
*/
/* ============================================================================== */
/* ============================================================================== */
#if DFS_METHOD_EN
/**
 * @description: 二叉树的最大深度 - 深度优先搜索
 * =================================================================================
 * @param {struct TreeNode*} root   根节点
 * @return {int} depth              最大深度
 */
int maxDepth(struct TreeNode* root) {
    /* TODO */
    return 0;
}
#endif /* DFS_METHOD_EN */

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/
/* TODO */
/* ============================================================================== */
/* ============================================================================== */

int maxDepth(struct TreeNode* root){
    /* TODO */
    return 0;
}


/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description:
 * =================================================================================
 * @return {*}
 */
void test_1(void) {
    /* 预期结果 */

    /* 构建二叉树 */

    /* 实际结果 */

    /* 比较结果 */

    /* 释放内存空间 */

}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @param {int} argc        程序入参个数
 * @param {char} *argv[]    程序入参字符串数组
 * @return {int}            程序运行状态
 */
int main(int argc, const char *argv[]) {

    return 0;
}