//
// Created by AILEE on 2023/2/2.
//

#ifndef DATASTRUCTURECPP_BINARYTREE_H
#define DATASTRUCTURECPP_BINARYTREE_H


namespace ailee {
    /**
     * @brief define binary tree node data struct.
     */
    typedef struct BinaryTreeNodeType {
        int m_nValue;
        BinaryTreeNodeType* m_pLeft;
        BinaryTreeNodeType* m_pRight;
    } BinaryTreeNode;

    /**
     * @brief define binary tree class.
     */
    class BinaryTree {
    public:
        /**
         * @brief create binary tree node.
         * @param value the value of this node.
         * @return binary tree node.
         */
        static BinaryTreeNode *CreateBinaryTreeNode(int value);

        /**
         * @brief connect binary node to children node.
         * @param pParent the pointer of parent node.
         * @param pLeft the pointer of left children node.
         * @param pRight the pointer of right children node.
         */
        static void ConnectBinaryNodes(BinaryTreeNode* pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);

        /**
         * @brief print binary tree node.
         * @param pNode the pointer of node that wanted to print.
         */
        static void PrintBinaryTreeNode(const BinaryTreeNode *pNode);

        /**
         * @brief print binary tree
         * @param pRoot the pointer of binary tree root node.
         */
        static void PrintBinaryTree(const BinaryTreeNode *pRoot);

        /**
         * @brief destroy binary tree.
         * @param pRoot the pointer of binary tree root node.
         */
        static void DestroyBinaryTree(BinaryTreeNode *pRoot);
    };
}


#endif //DATASTRUCTURECPP_BINARYTREE_H
