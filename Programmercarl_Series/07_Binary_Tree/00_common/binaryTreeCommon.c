/* 用数组来存储二叉树: 如果父节点的数组下标是 i，那么它的左孩子就是 i * 2 + 1，右孩子就是 i * 2 + 2。*/
/* 
 * 二叉树主要有两种遍历方式：
 *      深度优先遍历：先往深走，遇到叶子节点再往回走。
 *          前序遍历（递归法，迭代法）
 *          中序遍历（递归法，迭代法）
 *          后序遍历（递归法，迭代法）
 *      广度优先遍历：一层一层的去遍历。
 *          层次遍历（迭代法）
 */


#include <stdio.h>

/* NOTE: 树节点 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* NOTE: 前序遍历 */
void preOrder(struct TreeNode *root, int *ret, int *returnSize) {
    if (root == NULL) {
        return;
    }
    ret[(*returnSize)++] = root->val;
    preOrder(root->left, ret, returnSize);
    preOrder(root->right, ret, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}

/* NOTE: 主函数 */
int main(int argc, const char* argv[]) {

    return 0;
}