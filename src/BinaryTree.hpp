#pragma once

#include <iostream>
#include "TreeNode.hpp"

template <typename T>
class BinaryTree {
    private:
    TreeNode<T>* trunk;
    public:

    BinaryTree();
    void Insert(T user);
    void Search(unsigned long id);
};
