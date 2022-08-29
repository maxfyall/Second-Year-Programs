#ifndef LINKLIST
#define LINKLIST

#include "ListNode.h"
#include <iostream>
using namespace std;

template <class ElemType>
class Linklist{
    private:
        ListNode<ElemType> *head;

    public:
        Linklist();
        ~Linklist();
        bool empty();
        bool ins(const ElemType& new_element);
        bool del(const ElemType& del_element);
        friend ostream& operator<<(ostream& output, const Linklist &outlist){
            ListNode<ElemType> *temp;
            temp = outlist.head;
            while(temp != NULL){
                output << temp->element << " ";
                temp = temp->next;
            }
            return output;
        }
};

template <class ElemType>
Linklist<ElemType>::Linklist(){
    head = NULL;
}

template <class ElemType>
Linklist<ElemType>::~Linklist(){
    ListNode<ElemType> *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class ElemType>
bool Linklist<ElemType>::empty(){
    return (head == NULL) ? true : false;
}

template <class ElemType>
bool Linklist<ElemType>::ins(const ElemType& new_element){
    ListNode<ElemType> *newnode;
    newnode = new ListNode<ElemType>;
    newnode->element = new_element;
    newnode->next = head;
    head = newnode;
    return true;
}

template <class ElemType>
bool Linklist<ElemType>::del(const ElemType& del_element){
    ListNode<ElemType> *temp;
    ListNode<ElemType> *previous;

    if(empty()){
        return false;
    }else if(head->element == del_element){
        temp = head;
        head = head->next;
        delete temp;
        return true;
    }else if(head->next == NULL){
        return false;
    }else{
        previous = head;
        temp = head->next;
        while((temp->element != del_element) && (temp->next != NULL)){
            previous = temp;
            temp = temp->next;
        }
        if(temp->element == del_element){
            previous->next = temp->next;
            delete temp;
            return true;
        }else{  // list exhausted
            return false;
        }
    }
}
#endif
