/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\08_Backtracking\01_combine\main_uncut.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-28 09:44:35
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-17 23:34:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 77. 组合: https://leetcode.cn/problems/combinations/
 * https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 * 解法参考：https://leetcode.cn/problems/combinations/solutions/857507/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
 */
 /* 标准头文件 */
#include <stdio.h>
#include <stdlib.h>
/* 通用头文件 */
#include "commonArray.h"
/* 解题方法配置文件 */
#include "methodCfg.h"
/* 本文件头文件 */
#include "combine.h"

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int n = 4;
    int k = 2;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);

    /* 预期结果 */

    /* 比较结果 */
    print2DArray(result, returnSize, returnColumnSizes);

    /* 释放内存 */
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int n = 1;
    int k = 1;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);

    /* 预期结果 */

    /* 比较结果 */
    print2DArray(result, returnSize, returnColumnSizes);

    /* 释放内存 */
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */
    int n = 5;
    int k = 3;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);

    /* 预期结果 */

    /* 比较结果 */
    print2DArray(result, returnSize, returnColumnSizes);

    /* 释放内存 */
    for (int i = 0; i < returnSize; ++i) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
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
#if BASELINE_METHOD_EN
    printf("BASELINE_METHOD_EN\n");
#elif CUT_BRANCH_METHOD_EN
    printf("CUT_BRANCH_METHOD_EN\n");
#elif CUT_BRANCH_GPT4_METHOD_EN
    printf("CUT_BRANCH_GPT4_METHOD_EN\n");
#endif
    test_1();
    test_2();
    test_3();
    return 0;
}
