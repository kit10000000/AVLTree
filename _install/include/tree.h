//
//  tree.h
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
namespace AVLTree {
struct Node {
    int   data;
    // int height;
    Node* left;
    Node* right;
};
class Tree {
    enum class traversal_order {pre, in, post};
 public:
    Tree();
    // Tree(std::initializer_list<int> list);
    // Tree(const Tree& tree);
    // Tree(Tree&& tree);
    void insert(int value);
    Node* insert(int key, AVLTree::Node* node);
    // bool exists(int value);
    // bool remove(int value);
    // bool save(const std::string& path);
    // bool load(const std::string& path);
    // void print(traversal_order order);
    ~Tree();
 private:
    Node* root;
};
}  // namespace AVLTree

#endif  // INCLUDE_TREE_H_
