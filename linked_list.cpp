#include "tools.hpp"

template <typename N>
class l_list 
{
    private:
        struct l_node<N>
        {
            N data;
            l_node* next;
            l_node* prev;

            l_node(); // no arg constructor
            
            l_node(const N& d) // single arg constructor
            {
                data = d;
            }   // single arg constructor
            
            l_node(const l_node& c) // copy constructor
            {
                data = c.data;
                next = c.next;
                prev = c.prev;
            }   // copy constructor

            ~l_node(); // destructor
        }
        l_node* head;
        l_node* tail;
        int count;

    public:
        l_list()    // no argument constructor
        {
            l_node dummy = new l_node();
            head = &dummy;
            tail = &dummy;
            count = 0;
        }           // no argument constructor

        l_list(const l_list& c) // copy constructor
        {
            l_list copy = new l_list();
        }
        l_list(const N arr[]); // array constructor

        int size() { return count; } // count of elements in the linked list
        
        bool empty() { return count==0; } // check if empty
        
        string toString(); // print function

        void insert(const l_node& node, const N& item)
        {
            l_node ln = new l_node(item);
            // check if we are at the first node or last node
            // insert
            count++;
        }

        void prepend(const N& item)
        {   
            l_node ln = new l_node(item);
            ln.next = head->next;
            ln.prev = head;
            head->next->prev = &ln;
            count++;
        }

        void append(const N& item)
        {
            l_node ln = new l_node(item);
            tail.prev = &ln;
            ln.next = tail;
            tail = &ln;
            count++;
        }

        const N& get(int index);
        const N& front();
        const N& back();
        int find(N item);
        void remove(int index);
        void pop_back();
        void pop_front();
        ~l_list() { delete ll; } // destructor

}   // Linked List Class
