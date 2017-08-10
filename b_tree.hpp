#ifndef B_TREE_HPP 
#define B_TREE_HPP
namespace tools {

// Binary Tree Class
template <typename N>
class b_tree
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
 
} // namespace tools
#endif
