#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP
namespace tools {

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

} // namespace tools
#endif
