#ifndef D_NODE_H
#define D_NODE_H

#include <stddef.h>

/** A doubly-linked list node */
template<class T>
struct D_Node {
    // Data fields
    T data;  // Stores some data in the node.
    D_Node<T>* next;  // Stores a reference to the next node in the list.
    D_Node<T>* prev;  // Stores a reference to the previous node in the list.

    // Constructor
    D_Node(const T& data) : data(data), next(NULL), prev(NULL) {}
};

#endif