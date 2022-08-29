#ifndef MY_LIST_NODE
#define MY_LIST_NODE
#define NULL 0

template <class ElemType>
class ListNode {
    public:
        ElemType element;
        ListNode *next;

        ListNode();
        ListNode(ElemType data, ListNode *pnode = NULL);
};

template <class ElemType>
ListNode<ElemType>::ListNode(){
    next = NULL;
}

template <class ElemType>
ListNode<ElemType>::ListNode(ElemType data, ListNode *pnode){
    element = data;
    next = pnode;
}
#endif
