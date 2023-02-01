//
// Created by AILEE on 2023/2/1.
//

#include "Tree.h"

#include <iostream>

ailee::TreeNode *ailee::Tree::CreateTreeNode(int value) {
    TreeNode *pNode = new TreeNode();
    pNode->m_nValue = value;

    return pNode;
}

void ailee::Tree::ConnectTreeNodes(ailee::TreeNode *pParent, ailee::TreeNode *pChildren) {
    pParent->m_vChildren.push_back(pChildren);
}

void ailee::Tree::PrintTreeNode(const ailee::TreeNode *pNode) {
    if (pNode == nullptr) {
        std::cout << "this node is nullptr." << std::endl;
    } else {
        std::cout << "the value of this node is: " << pNode->m_nValue << std::endl;
        std::cout << "the children values of this node is: ";
        for (auto &it : pNode->m_vChildren) {
            std::cout << it->m_nValue << "\t";
        }
    }
}

void ailee::Tree::PrintTree(const ailee::TreeNode *pRoot) {
    PrintTreeNode(pRoot);

    if (pRoot != nullptr) {
        for (auto &it : pRoot->m_vChildren) {
            PrintTree(it);
        }
    }
}

void ailee::Tree::DestroyTree(ailee::TreeNode *pRoot) {
    if (pRoot != nullptr) {
        for (auto &it : pRoot->m_vChildren) {
            DestroyTree(it);
            delete it;
        }

        delete pRoot;
    }
}
