#define _CRT_SECURE_NO_WARNINGS 

	// 平衡二叉树（判断一个二叉树是否是平衡二叉树）
//// 判断树总高度
//int isBalanced_(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    int size = 1;
//
//    int L = isBalanced_(root->left);
//    int R = isBalanced_(root->right);
//
//    R > L ? (size += R) : (size += L);
//    return size;
//}
//
//// 分别判断节左右节点的高度
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    int L_size = isBalanced_(root->left);
//    int R_size = isBalanced_(root->right);
//
//    if (L_size - R_size > 1 || L_size - R_size < -1)
//        return false;
//
//    return isBalanced(root->left) && isBalanced(root->right);
//}