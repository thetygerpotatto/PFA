#pragma once

template <typename T>
class TreeNode {
    public:
    T value;
    TreeNode* L;
    TreeNode* R;
    TreeNode* P;
    bool color;

    TreeNode(T value);
    T key();
    TreeNode* left();
    TreeNode* right();
    TreeNode* father();
};
