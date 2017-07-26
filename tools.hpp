#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <random>
#include <iostream>
#include <type_traits>
#include <string>

namespace tools {

    // Random Vector Generator for Arithmetic types
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    std::vector<N> rand_set(unsigned int size, N min, N max);

    // Container Printer using std::vector
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    std::ostream& operator<<(std::ostream& os, const std::vector<N>& my_vector);

    // Sorted Array Test
    template <
        typename N = int, typename = std::enable_if_t<std::is_arithmetic<N>::value>
        >
    bool is_sorted(const std::vector<N>& my_vector);

    namespace rdt {
        // Linked List Class
        template <typename N>
        class l_list 
        {
            private:
                int count;
                template<typename N>
                struct l_node
                {
                    N data;
                    l_node* next;
                    l_node* prev;
                    l_node(); // no arg constructor
                    l_node(const l_node& c); // copy constructor
                    l_node(const N& d); // single arg constructor
                    ~l_node(); // destructor
                }
                l_node* head;
                l_node* tail;
            public:
                l_list(); // no argument constructor
                l_list(const l_list& c); // copy constructor
                l_list(const N& item); // single argument constructor
                l_list(const N arr[]); // array constructor
                int size(); // count of elements in the linked list
                bool empty(); // check if empty
                string toString(); // print function
                void insert(const N& item);
                void prepend(const N& item);
                void append(const N& item);
                const N& get(int index);
                const N& front();
                const N& back();
                int find(N item);
                N remove(int index);
                N pop_back();
                N pop_front();
                ~l_list(); // destructor
        }   // Linked List Class

        // Array List Class
        template <typename N>
        class a_list
        {
            private:
                int count;
                int capacity;
                int front;
                int back;
                
            public:
                a_list(); // no arg constructor
                a_list(const N& d); // single arg constructor
                a_list(const N arr[]); // array constructor
                int size(); // count of elements in the array list
                bool empty(); // check if empty
                string toString(); // print function
                void insert(const N& item);
                void prepend(const N& item);
                void append(const N& item);
                const N& get(int index);
                const N& front();
                const N& back();
                int find(N item);
                N remove(int index);
                N pop_back();
                N pop_front();
                ~a_list(); // destructor
        } // end Array List Class
    
    // Binary Tree Class
        template <typename N>
        class bi_tree
        {
            private:
                int count;
                template<typename N>
                struct t_node
                {   
                    N data;
                    t_node* parent;
                    t_node* l_child;
                    t_node* r_child;
                    t_node(); // no arg constructor
                    t_node(const t_node& c); // copy constructor
                    t_node(const N& d); // single arg constructor
                    ~t_node(); // destructor
                }
                t_node* root;
            public:
                bi_tree(); // no arg constructor;
                int getSize(); // returns number of nodes
                bool empty();
                void append(t_node* p,N d); // append to node
                int find(N d); // finds the level of the lowest instance of the data in the tree
                N extract(N d); // extracts and returns the lowest instance of the data
                void swap(t_node a, t_node b); // swap function
        }

    // End Binary Tree Class
    
    // Binary Heap Class
        template <typename N>
        class bi_heap
        {
            private:
                const int size;
                a_list<N> data;
                int count;
            public:
                bi_heap(); // default constructor
                bi_heap(int n); // n element heap constructor
                bi_heap(a_list<N> d); // constructor from array list of data.
                N peek();
                N pop();
                int getParent(int c);
                int getRight(int p);
                int getLeft(int p);
                void push(N d);
                void swap(int a, int b);
                void heapify();
        }
    // End Binary Heap Class

    } // end raw datatypes namespace

    namespace adt {
        // Stack Class
        template <typename N>
        class stack
        {
        } // Stack Class

        // Queue Class
        template <typename N>
        class queue
        {
        } // Queue Class

        // Dequeue Class
        template <typename N>
        class dequeue
        {
        } // Dequeue Class

        // Binary Search Tree
        template <typename N>
        class bin_tree
        {
        } // Binary Search Tree

        // Priority Queue
        template <typename N>
        class p_queue
        {
        } // Priority Queue Class

        // Hash Map
        template <typename N>
        class h_map
        {
        } // Hash Map Class

        // AVL Tree
        template <typename N>
        class avl_tree
        {
        } // AVL Tree Class
    } // end abstract data types namespace

}   // namespace tools
#endif
