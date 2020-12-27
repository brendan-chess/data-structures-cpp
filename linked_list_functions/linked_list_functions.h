/*
 * Author: Brendan Chess
 * Project: Stack and Queue
 * Purpose: Perform operations on doubly linked lists
 * Notes: This is not a doubly linked list class, this is only a set of
 *      functions that operate on doubly linked lists
 */

#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _prev;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = NULL, node<T>* prev = NULL):_item(item), _next(next), _prev(prev){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head){
    head = NULL;
    return head;
}

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head){
    while(head != NULL){
        node<T>* temp = head;
        head = head->_next;
        temp->_prev = NULL;
        temp->_next = NULL;
        delete temp;
    }
}

//true if head is NULL, false otherwise.
template <class T>
bool empty(const node<T>* head){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy){
    init_head(cpy);
    while(head->_next != NULL){
        head = head->_next;
    }
    while(head != NULL){
        insert_head(cpy, head->_item);
        head = head->_prev;
    }
    return cpy;
}

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item){
    node<T>* new_node = new node<T>(item);
    if(head == NULL){
        head = new_node;
    } else {
        new_node->_next = head;
        head->_prev = new_node;
        head = new_node;
    }
    return head;
}

//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item){
    if(empty(head)){
        insert_head(head, item);
        return head;
    } else {
        node<T>* new_node = new node<T>(item);
        new_node->_next = after->_next;
        after->_next = new_node;
        new_node->_prev = after;
        if(new_node->_next != NULL){
            new_node->_next->_prev = new_node;
        }
        return new_node;
    }
}

//delete the node at the head of the list, return the item:
template <class T>
T delete_head(node<T>* &head){
    assert(head != NULL);
    if(head->_next == NULL){
        T item = head->_item;
        head = NULL;
        return item;
    }
    node<T>* temp = head;
    head = head->_next;
    head->_prev = NULL;
    T item = temp->_item;
    delete temp;
    return item;
}

//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout){
    while(head != NULL){
        outs<<"["<<head->_item<<"]->";
        head = head->_next;
    }
    outs<<"|||";
    return outs;
}

template<class T>
node<T>* search_list(node<T>* head, T item, bool &found){
    while(head != NULL){
        if(head->_item == item){
            found = true;
            return head;
        }
        head = head->_next;
    }
    found = false;
    return NULL;
}

template<class T>
bool list_contains(node<T>* head, T item){
    while(head != NULL){
        if(head->_item == item) return true;
        head = head->_next;
    }
    return false;
}

template<class T>
void list_remove(node<T>* &head, T item, bool &success){
    node<T>* temp = head;
    while(temp != NULL){
        if(temp->_item == item){
            success = true;
            if(temp->_prev) temp->_prev->_next = temp->_next;
            if(temp->_next) temp->_next->_prev = temp->_prev;
            temp->_next = NULL;
            temp->_prev = NULL;
            delete temp;
            return;
        }
        temp = temp->_next;
    }
    success = false;
}

#endif //LINKED_LIST_FUNCTIONS_H
