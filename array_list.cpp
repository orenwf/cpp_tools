#include "tools.hpp"

template <typename N>
class a_list
{
    private:
        int count;
        int capacity;
        N* base;
        int offset = 0;
        
    public:
        a_list(); // no arg constructor
        a_list(const N& d); // single arg constructor
        a_list(const N arr[]); // array constructor
        int size(); // count of elements in the array list
        bool empty(); // check if empty
        void print(); // print function
        void insert(const N& item);
        void prepend(const N& item);
        void append(const N& item);
        const N& get(int index);
        const N& front();
        const N& back();
        int find(N item);
        void remove(int index);
        void pop_back();
        ~a_list(); // destructor
}

