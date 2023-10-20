/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\04_twoSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-10 23:39:22
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-20 21:11:07
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 1. 两数之和：https://leetcode.cn/problems/two-sum/
 * https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))          /* 获取数组长度 */

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
/**
 * @description: 两数之和
 * =================================================================================
 * @param {int} *nums           输入数组
 * @param {int} numsSize        输入数组长度
 * @param {int} target          目标值
 * @param {int} *returnSize     返回数组长度
 * @return {int} *result        返回数组
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {                            /* 慢指针遍历数组 */
        for (int j = i + 1; j < numsSize; j++) {                        /* 快指针遍历数组，快指针恒大于慢指针 */
            if (nums[i] + nums[j] == target) {                              /* 如果快指针和慢指针所指的值和为target*/
                int *result = (int *)malloc(2 * sizeof(int));                   /* 为结果数组分配空间 */
                result[0] = i;                                                      /* 结果数组的第 0 位为慢指针 */
                result[1] = j;                                                      /* 结果数组的第 1 位为快指针 */
                *returnSize = 2;                                                    /* 将返回数组大小修改为2 */
                return result;                                                      /* 返回结果数组 */
            }
        }
    }
    *returnSize = 0;                                                /* 如果快慢指针所指的和没有等于target的情况，将返回数组大小修改为0 */
    return NULL;                                                    /* 返回 NULL*/
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印结果
 * =================================================================================
 * @param {int} *indices
 * @return {void}
 */
void printIndices(int *indices) {
    if (indices) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }
}

/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum        测试编号
 * @param {int} *expectNums     预期结果
 * @param {int} expectLen       预期结果长度
 * @param {int} *actualNums     实际结果
 * @param {int} actualLen       实际结果长度
 * @return {void}
 */
void validateAnswerArray(char testNum, int *expectNums, int expectLen, int *actualNums, int actualLen) {
    if (expectLen != actualLen) {
        printf("❌ Test %c Failed\n", testNum);
    } else {
        for (int i = 0; i < expectLen; i++) {
            if (expectNums[i] != actualNums[i]) {
                printf("❌ Test %c Failed\n", testNum);
            }
        }
        printf("✅ Test %c Passed\n", testNum);
    }
}

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 测试 1
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void test_1(void) {
    /* 实际结果 */
    int nums[] = {2, 7, 11, 15};
    int numsSize = ARR_SIZE(nums);
    int target = 9;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int expect[] = {0, 1};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateAnswerArray('1', expect, expectSize, actual, actualSize);

    /* 释放内存 */
    free(actual);
}

/**
 * @description: 测试 2
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */
    int nums[] = {3, 2, 4};
    int numsSize = ARR_SIZE(nums);
    int target = 6;
    int actualSize = 0;
    int *actual = twoSum(nums, numsSize, target, &actualSize);

    /* 预期结果 */
    int expect[] = {1, 2};
    int expectSize = ARR_SIZE(expect);

    /* 比较结果 */
    validateAnswerArray('2', expect, expectSize, actual, actualSize);

    /* 释放内存 */
    free(actual);
}

/**
 * @description: 测试 3
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 4
 * 输入：nums = [3,3], target = 7
 * 输出：NULL
 * =================================================================================
 * @return {void}
 */
void test_4(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

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
int main(int argc, char const *argv[]) {
    test_1();
    test_2();

    return 0;
}