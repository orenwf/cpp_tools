#ifndef B_TREE_HPP 
#define B_TREE_HPP
// Binary Tree Class
#include <algorithm>
#include "node.hpp"

namespace tools {

// Binary Tree Class
template 
<   
    typename V, 
    class = typename std::enable_if<std::is_integral<V>::value>::type
>
class b_tree 
{
private:
    int count;
    node<V,2>* root = nullptr;

public:
    // Constructor
    b_tree() : count(0) {} // no arg constructor;
    
    // Initialize root
    virtual void addRoot(V v)
    {
        if(!root) {
            root = new node<V,2>(v);
            count++;
        }
        else std::cerr << "Root already exists.\n";
    }

    // Retrieve Root
    virtual node<V,2>& getRoot() 
    { 
        try { 
            if(!root) throw "This tree has no root.\n";
            return *root; 
        }
        catch(const char* exception) {
            std::cerr << exception;
        }
    }

    //Count & ID Functions
    virtual int getCount() { return count; }
    virtual bool isEmpty() { return getCount() == 0; }
    virtual bool isRoot(node<V,2>& n) { return &n == root; }
    virtual bool isInternal(node<V,2>& n) 
        { return n.hasChildren()&&!isRoot(n); }
    virtual bool isLeaf(node<V,2>& n) { return !isInternal(n); }
    virtual int height(node<V,2>& n)
    {
        int max_ht = 0;
        auto i = std::begin(n.getChildren());
        auto end_i = std::end(n.getChildren());
        while(i++ != end_i)
            max_ht = std::max(max_ht,height(**i));
        return max_ht;
    }
    virtual int height() { return height(getRoot()); }
    virtual int numChildren(node<V,2>& n) { return n.numChildren(); }

//    node<V,2>& find(V d) //finds highest instance of the data in the tree
//    {
//    }

//    virtual std::vector<node<V,2>> path(const node<V,2>& n)
//    {
//    }
 
//    V& extract(node<V,2>& n)
//    {
//    }

//    void swap(node<V,2> a, node<V,2> b) // swap function
//    {
//    }

//    void merge(node<V,2>& n, b_tree<V>& t1, b_tree<V>& t2)
//    {
//    }

// Additional Binary Tree adapter member functions for node<V,2>

    auto getLeft(node<V,2>& n) { return n.getChild(0); }
    auto getRight(node<V,2>& n) { return n.getChild(1); }
    auto sibling(node<V,2>& n) 
    { 
        node<V,2>& p = n.getParent();
        if(n == p.getLeft())
            return p.getRight();
        else return p.getLeft();
    }

    void setLeft(node<V,2>& n, node<V,2>& d)
    {
        n.setChild(0,d);
    }

    void setRight(node<V,2>& n, node<V,2>& d)
    {
        n.setChild(1,d);
    }

    void addLeft(node<V,2>& n, V d)
    {
        if(getLeft(n)==nullptr) setLeft(n, new node<V,2>(d,n));
        else std::cerr << "Already has left child.\n";
        ++count;
    }

    void addRight(node<V,2>& n, V d)
    {
        if(getRight(n)==nullptr) setRight(n, new node<V,2>(d,n));
        else std::cerr << "Already has right child.\n";
        ++count;
    }

};
// End Binary Tree Class


 
} // namespace tools
#endif
