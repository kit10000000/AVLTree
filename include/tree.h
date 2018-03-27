//
//  tree.h
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <stdio.h>
#include <iostream>

namespace  BSTTree {
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
    void insert(int value);
    Node* insert(int key,  BSTTree::Node* node);
    void print_tree(int indent);
    void print_tree(BSTTree::Node* node, int indent);
    ~Tree();
 private:
    Node* root;
};
}  // namespace BSTTree

#endif  // INCLUDE_TREE_H_
