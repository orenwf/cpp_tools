#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <algorithm>

namespace tools {

template <
    typename V,
    int N_DEGREE, 
    class = typename std::enable_if<std::is_integral<V>::value>::type
    >
class tree
{

private:
    
    node<V,N_DEGREE>* root;
    int count;

public:

    // Tree Constructor
    tree() : count(0) {}

    // Initialize root
    virtual void addRoot(V v)
    {
        if(root == nullptr) {
            root = new node<V,N_DEGREE>(v);
            count++;
        }
        else std::cerr << "Root already exists.\n";
    }

    // Retrieve Root
    virtual const node<V,N_DEGREE>& getRoot() 
    { 
        try { 
            if(root == nullptr) throw node<V,N_DEGREE>::node_error("getRoot()");
            return *root; 
        }
        catch(node<V,N_DEGREE>::node_error& e) {
            std::cerr << "Null node when trying to access: " << e.what() << ".\n";
        }
    }

    //Count & ID Functions
    virtual int getCount() { return count; }
    virtual bool isEmpty() { return getCount() == 0; }
    virtual bool isRoot(const node<V,N_DEGREE>& n) { return n == *root; }
    virtual bool isInternal(const node<V,N_DEGREE>& n) 
        { return n.hasChildren()&&!isRoot(n); }
    virtual bool isLeaf(const node<V,N_DEGREE>& n) { return !(n.isInternal); }
    virtual int height(const node<V,N_DEGREE>& n)
    {
        int max_ht = 0;
        for(auto i : n.getChildren()) 
            max_ht = std::max(max_ht,height(n.getChild(i)));
        return max_ht;
    }
    virtual int height() { return height(getRoot()); }
    virtual int numChildren(const node<V,N_DEGREE>& n) { return n.getChildren(); }

//    virtual std::vector<node<V,N_DEGREE>> path(const node<V,N_DEGREE>& n)
//    {
//    }
    
};

} // namespace tools
#endif
