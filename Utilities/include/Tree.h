//
// Created by AILEE on 2023/2/1.
//

#ifndef DATASTRUCTURECPP_BINARYTREE_H
#define DATASTRUCTURECPP_BINARYTREE_H


#include <vector>

namespace ailee {
    /**
     * @brief define tree node data struct.
     */
    typedef struct TreeNodeType {
        int                             m_nValue;
        std::vector<TreeNodeType *>     m_vChildren;
    } TreeNode;

    /**
     * @brief define binary tree class.
     */
    class Tree {
    public:
        /**
         * @brief 创建树节点
         * @param value 树节点值
         * @return 树节点
         */
        static TreeNode *CreateTreeNode(int value);

        /**
         * @brief 连接父子节点
         * @param pParent 父节点指针
         * @param pChildren 子节点指针
         */
        static void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChildren);

        /**
         * @brief 打印树节点
         * @param pNode 待打印节点指针
         */
        static void PrintTreeNode(const TreeNode *pNode);

        /**
         * @brief 打印树
         * @param pRoot 树的根节点指针
         */
        static void PrintTree(const TreeNode *pRoot);

        /**
         * @brief 销毁树
         * @param pRoot 树的根节点指针
         */
        static void DestroyTree(TreeNode *pRoot);
    };
}


#endif //DATASTRUCTURECPP_BINARYTREE_H
