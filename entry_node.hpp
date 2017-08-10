// HEADER GUARD
#ifndef ENTRY_NODE_HPP
#define ENTRY_NODE_HPP
#include <array>
namespace tools {

template <typename K, typename V, int X>
class entry_node
{
    K key;
    V value;
    entry_node<K,V,X>* parent;
    std::array<entry_node<K,V,X>*,X> children;

public:
    entry_node(K k) : key(k) {} // key constructor
    entry_node(K k, V v) : key(k), value(v) {} // key+value ctor
    entry_node(K k, entry_node& p) : key(k), parent(p) {} // key + parent ctor
    entry_node(K k, V v, entry_node& p) : key(k), value(v), parent(p) {} // 3 arg ctor

    const K& getKey() { return key; }
    const V& getValue() { return value; }
    const entry_node<K,V,X>& getParent() { return *parent; }
    const auto getChildren() { return children.begin(); }
    const auto& getChild(int i) { return children[x]; }
    bool hasChildren()
    {
        for(auto i : children) if(i!=nullptr) return true;
        return false;
    }
    void setKey(K k) { key = k; }
    void setValue(V v) { value = v; }
    void setParent(entry_node<K,V,X>& p) { parent = p; }
    void setChild(int i, entry_node<K,V,X>& c) { children[i] = c; }

    virtual ~entry_node();
}

} // namespace tools
#endif
