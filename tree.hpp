#ifndef TREE_HPP
#define TREE_HPP
namespace tools {
#include "node.hpp"

template <typename V, int X>
class tree
{
    node<V,X>* root;
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
