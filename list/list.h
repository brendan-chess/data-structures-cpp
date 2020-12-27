/*
 * Author: Brendan Chess
 * Project: Hash Tables
 * Purpose: Implement an open hash table class and a chained hash table class
 *      along with demo functions
 * Notes: Interactive demo works best with table size of 17, and random demo
 *      works best with table size of 811
 */
#ifndef LIST_H
#define LIST_H

template <typename T>
struct node {
    T _item;
    node<T>* _next;

    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

template <class T>
node<T>* init_head(node<T>* &head){
    head = NULL;
    return head;
}

template <class T>
node<T>* insert_head(node<T>* &head, T item){
    node<T>* new_node = new node<T>(item);
    if(head == NULL){
        head = new_node;
    } else {
        new_node->_next = head;
        head = new_node;
    }
    return head;
}

template <class T>
node<T>* find_node(node<T>* head, T item, bool &found){
    while(head){
        if(head->_item == item){
            found = true;
            return head;
        }
        head = head->_next;
    }
    found = false;
    return NULL;
}

template <class T>
void list_remove(node<T>* &head, T item, bool &success){
    //assert(head);
    find_node(head, item, success);
    if(!success) return;
    node<T>* temp = head;
    if(!head->_next){
        success = true;
        delete temp;
        temp = NULL;
    } else {
        if(head->_item == item) {
            success = true;
            head = head->_next;
            delete temp;
            return;
        } else {
            while(head->_next){
                if(head->_next->_item == item){
                    success = true;
                    node<T>* remove = head->_next;
                    head->_next = remove->_next;
                    delete remove;
                    break;
                }
                head = head->_next;
            }
        }
    }
    head = temp;
}

template<class T>
void delete_list(node<T>* &head){
    while(head != NULL){
        node<T>* temp = head;
        head = head->_next;
        delete temp;
    }
}

template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout){
    while(head != NULL){
        outs<<"["<<head->_item<<"]->";
        head = head->_next;
    }
    outs<<"|||";
    return outs;
}

#endif //LIST_H
