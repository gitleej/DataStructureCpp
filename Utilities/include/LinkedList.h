//
// Created by AILEE on 2023/1/29.
//

#ifndef DATASTRUCTURECPP_LINKEDLIST_H
#define DATASTRUCTURECPP_LINKEDLIST_H


namespace ailee {
    /**
     * @brief   define list node data struct
     */
    typedef struct ListNodeType {
        int             m_nValue;
        ListNodeType*   m_pNext;
    } ListNode;

    /**
     * @brief   define complex list node data struct.
     */
    typedef struct ComplexListNodeType {
        int                     m_nValue;
        ComplexListNodeType     *m_pNext;
        ComplexListNodeType     *m_pSibling;
    } ComplexListNode;

    /**
     * @brief   define linked list class
     */
    class LinkedList {
    public:
        /**
         * @brief   create a list node.
         * @param value the node value.
         * @return  ListNode pointer.
         */
        static ListNode* CreateListNode(int value);

        /**
         * @brief   connect two list node.
         * @param pCurrent the current list node.
         * @param pNext the next list node.
         */
        static void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);

        /**
         * @brief   print the value of input list node.
         * @param pNode the list node that want to print the value.
         */
        static void PrintListNode(ListNode* pNode);

        /**
         * @brief   print the values of list
         * @param pHead the head pointer of linked list.
         */
        static void PrintList(ListNode* pHead);

        /**
         * @brief   destroy linked list.
         * @param pHead the head pointer of linked list.
         */
        static void DestroyList(ListNode* pHead);

        /**
         * @brief   Add the node to the end of the linked list.
         * @param pHead the head pointer of linked list.
         * @param value the value of the node that wanted to add to the end of the linked list.
         */
        static void Add2Tail(ListNode** pHead, int value);

        /**
         * @brief   remove target node from linked list.
         * @param pHead the head pointer of linked list.
         * @param value the value of the node that wanted to remove from the end of the linked list.
         */
        static void RemoveNode(ListNode** pHead, int value);
    };

    /**
     * @brief   define complex list class.
     */
    class ComplexList {
    public:
        /**
         * @brief   create complex list node.
         * @param value the value of node.
         * @return the complex list node.
         */
        static ComplexListNode *CreateComplexListNode(int value);

        /**
         * @brief   connect complex list node.
         * @param pNode the current complex list node pointer.
         * @param pNext the next complex list node pointer.
         * @param pSibling the sibling complex list node pointer.
         */
        static void ConnectComplexListNode(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling);

        /**
         * @brief   print complex list.
         * @param pHead the head pointer of complex list.
         */
        static void PrintComplexList(ComplexListNode *pHead);
    };
}


#endif //DATASTRUCTURECPP_LINKEDLIST_H
