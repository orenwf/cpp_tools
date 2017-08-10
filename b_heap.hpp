#ifndef B_HEAP_HPP
#define B_HEAP_HPP
namespace tools {

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


}
#endif
