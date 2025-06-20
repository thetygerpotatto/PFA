#include "TreeNode.hpp"

template <typename T>
TreeNode<T>::TreeNode(T value) {
    this->value = value;
    this->L = nullptr;
    this->R = nullptr;
    this->P = nullptr;
    this->color = true;
    
}

template <typename T>
T TreeNode<T>::key() {
    return this->value;
}

template <typename T>
TreeNode<T>* TreeNode<T>::right() {
    return this->R;
}

template <typename T>
TreeNode<T>* TreeNode<T>::left() {
    return this->L;
}

template <typename T>
TreeNode<T>* TreeNode<T>::father() {
    return this->P;
}
