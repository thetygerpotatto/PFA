#include "BinaryTree.hpp"
#include <iostream>

template <typename T>
BinaryTree<T>::BinaryTree() {
    this->trunk = nullptr;
}


template <typename T>
void BinaryTree<T>::Insert(T user) {
    std::cout << "Insert";
}

template <typename T>
void BinaryTree<T>::Search(unsigned long user) {
    std::cout << "Search";
}
