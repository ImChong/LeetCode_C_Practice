/*
 * @FilePath     : \Practice_LeetCode_C\00_Basics\01_Common_Func\inc\commonLinkedListDummy.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-21 10:33:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-22 09:55:45
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 链表公共函数 - 使用虚拟头节点
 */
#ifndef __DUMMY_LINKED_LIST_COMMON_H
#define __DUMMY_LINKED_LIST_COMMON_H

/**********************************************************************************/
/*                                                                                */
/*                               STRUCT DEFINITION                                */
/*                                                                                */
/**********************************************************************************/
struct ListNode {
    int val;                    /* 节点数值 */
    struct ListNode *next;      /* 下一节点地址 */
};

typedef struct {
    struct ListNode *head;      /* 链表虚拟头节点 */
    int size;                   /* 链表长度 */
} MyLinkedList;

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
MyLinkedList *myLinkedListCreate(void);
int myLinkedListGet(MyLinkedList *dummyHead, int index);
void myLinkedListAddAtHead(MyLinkedList *dummyHead, int val);
void myLinkedListAddAtTail(MyLinkedList *dummyHead, int val);
void myLinkedListAddAtIndex(MyLinkedList *dummyHead, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList *dummyHead, int index);
void myLinkedListFree(MyLinkedList *dummyHead);

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
void arrayToMyLinkedList(MyLinkedList *dummyHead, int *nums, int numsSize);
void printLinkedList(MyLinkedList *dummyHead);

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
void validateAnswerMyLinkedList(char testNum, MyLinkedList *expect, MyLinkedList *actual);


#endif  /* __DUMMY_LINKED_LIST_COMMON_H */
