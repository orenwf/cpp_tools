// HEADER GUARD
#ifndef NODE_HPP
#define NODE_HPP
#include <array>
namespace tools {

template <typename V, int X>
class node
{
    int key;
    V value;
    node<V,X>* parent;
    std::array<node<V,X>*,X> children;

public:
    node(int k) : key(k) {} // key constructor
    node(int k, V v) : key(k), value(v) {} // key+value ctor
    node(int k, node<V,X>& p) : key(k), parent(p) {} // key + parent ctor
    node(int k, V v, node<V,X>& p) : key(k), value(v), parent(p) {} // 3 arg ctor

    const int getKey() { return key; }
    const V& getValue() { return value; }
    const node<V,X>& getParent() { return *parent; }
    const auto getChildren() { return children.begin(); }
    const auto& getChild(int i) { return children[x]; }
    bool hasChildren()
    {
        for(auto i : children) if(i!=nullptr) return true;
        return false;
    }
    void setKey(int k) { key = k; }
    void setValue(V v) { value = v; }
    void setParent(node<K,V,X>& p) { parent = p; }
    void setChild(int i, node<K,V,X>& c) { children[i] = c; }

    virtual ~node();
}

} // namespace tools
#endif
