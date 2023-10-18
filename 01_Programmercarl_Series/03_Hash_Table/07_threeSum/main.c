/*
 * @FilePath     : \Practice_LeetCode_C\01_Programmercarl_Series\03_Hash_Table\07_threeSum\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-08-23 22:54:19
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 20:22:47
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 15. 三数之和：https://leetcode.cn/problems/3sum/
 * https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
 */
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                                                                */
/*                                MACRO FUNCTIONS                                 */
/*                                                                                */
/**********************************************************************************/
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**********************************************************************************/
/**********************************************************************************/
/***                                                                            ***/
/***                               TARGET FUNCTION                              ***/
/***                                                                            ***/
/**********************************************************************************/
/**********************************************************************************/

/* ============================================================================== */
/* ============================================================================== */
/**
 * @description: 比较函数
 * =================================================================================
 * @param {void} *a
 * @param {void} *b
 * @return {*}
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @description: 三数之和
 * =================================================================================
 * @param {int} *nums
 * @param {int} numsSize
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {int} **ans
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    int i, j, k, sum;

    int indexLeft = 0;
    int indexMiddle = 0;
    int indexRight = 0;

    for (indexLeft = 0; indexLeft < numsSize - 2; indexLeft++) {
        if (nums[indexLeft] > 0) {
            return ans;
        }

        if (indexLeft > 0 && nums[indexLeft] == nums[indexLeft - 1]) {
            continue;
        }
        indexMiddle = indexLeft + 1;
        indexRight = numsSize - 1;

        while (indexMiddle < indexRight) {
            sum = nums[indexLeft] + nums[indexMiddle] + nums[indexRight];
            if (sum == 0) {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[indexLeft];
                ans[*returnSize][1] = nums[indexMiddle];
                ans[*returnSize][2] = nums[indexRight];
                *returnSize += 1;
                while (indexMiddle < indexRight && nums[indexMiddle] == nums[++indexMiddle]);
                while (indexMiddle < indexRight && nums[indexRight] == nums[--indexRight]);
            } else if (sum > 0) {
                indexRight--;
            } else {
                indexMiddle++;
            }
        }
    }
    return ans;
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 打印结果
 * =================================================================================
 * @param {int} **result
 * @param {int} returnSize
 * @param {int} *returnColumnSizes
 * @return {*}
 */
void printAns(int **result, int returnSize, int *returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("Ans[%d]: ", i);
        for (int j = 0; j < returnColumnSizes[0]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/**
 * @description: 释放结果空间
 * =================================================================================
 * @param {int} ***result
 * @param {int} *returnSize
 * @param {int} **returnColumnSizes
 * @return {*}
 */
void freeAns(int ***result, int *returnSize, int **returnColumnSizes) {
    for (int i = 0; i < *returnSize; i++) {
        free((*result)[i]);
    }
    free(*result);
    free(*returnColumnSizes);
}

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 验证答案
 * =================================================================================
 * @param {char} testNum    测试编号
 * @param {int} expect      预期
 * @param {int} actual      实际
 * @return {void}
 */
void validateAnswer(char testNum, int expect, int actual) {
    if (expect == actual) {
        printf("✅ Test %c Passed\n", testNum);
    } else {
        printf("❌ Test %c Failed\n", testNum);
    }
}

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

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 2
 * =================================================================================
 * @return {void}
 */
void test_2(void) {
    /* 实际结果 */

    /* 预期结果 */

    /* 比较结果 */

}

/**
 * @description: 测试 3
 * =================================================================================
 * @return {void}
 */
void test_3(void) {
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
int main(int argc, const char *argv[]) {
    int nums[] = {-1, 0, 1, 2, -1, -4};

    int returnSize = 0;
    int *returnColumnSizes;

    int **result = threeSum(nums, ARRAY_SIZE(nums), &returnSize, &returnColumnSizes);
    printAns(result, returnSize, returnColumnSizes);
    freeAns(&result, &returnSize, &returnColumnSizes);
    return 0;
}