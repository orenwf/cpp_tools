#ifndef TREE_HPP
#define TREE_HPP
namespace tools {
#include "entry_node.hpp"

template <typename K, typename V, int X>
class tree
{
    typedef entry_node<K,V,X> node;
    node* root;
    int count;

public:

    tree() {}

    const node& root() { return *root; }
    bool isRoot(const node& n) { return n == *root; }
    bool isInternal(const node& n) { return !isLeaf(n); }
    bool isLeaf(const node& n) { return !(n.hasChildren); }


}

} // namespace tools
#endif
