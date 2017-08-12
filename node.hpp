// HEADER GUARD
#ifndef NODE_HPP
#define NODE_HPP

#include <array>
#include <exception>
#include <iostream>

namespace tools {

template <typename V, int N_DEGREE>
class node
{
    V value;
    node<V,N_DEGREE>* parent;
    std::array<node<V,N_DEGREE>*,N_DEGREE> children;

public:
    node(V v) : value(v) {} // key constructor
    node(V v, node<V,N_DEGREE>& p) : value(v), parent(p) {} // 2 arg ctor

    V getValue() { return value; }
    node<V,N_DEGREE>& getParent() 
    {   
        try { 
            if(parent==nullptr) throw "This node has no parent.\n";
            return *parent; 
        }
        catch(const char* exception) {
            std::cerr << exception;
        }
    }

    auto getChildren() { return children; }

    auto& getChild(int i) 
    { 
        try {
            if(children[i]==nullptr) throw "This child does not exist.\n";
            return children[i]; 
        }
        catch(const char* exception) {
            std::cerr << exception;
        }
    }

    int numChildren()
    {
        int c = 0;
        auto i = std::begin(getChildren());
        auto end_i = std::end(getChildren());
        while(i++ != end_i)
            if(i!=nullptr) ++c;
        return c;
    }

    bool hasChildren() { return numChildren()!=0; }

    void setValue(V v) { value = v; }
    auto replaceValue(V d)
    {
        auto current = getValue();
        setValue(d);
        return current;
    }
    void setParent(node<V,N_DEGREE>& p) { parent = p; }
    void setChild(int i, node<V,N_DEGREE>& c) { children[i] = c; }
    
    ~node();

};

} // namespace tools
#endif
