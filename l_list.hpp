// HEADER GUARD 
#ifndef L_LIST_HPP
#define L_LIST_HPP
// HEADER GUARD
namespace tools {

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

} // namespace tools
//HEADER GUARD
#endif
// HEADER GUARD
