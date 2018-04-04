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
    
enum class traversal_order {pre_order, in_order, post_order};
struct Node {
    int   data;
    // int height;
    Node* left;
    Node* right;
};
class Tree {
 public:
    Tree();
    void insert(int value);
    Node* insert(int key,  BSTTree::Node* node);
    void print_tree(int indent);
    void print_tree(BSTTree::Node* node, int indent);
    void show_nodes(BSTTree::traversal_order order);
    void show_nodes(BSTTree::traversal_order order, BSTTree::Node* node);
    ~Tree();
 private:
    Node* root;
};
}  // namespace BSTTree

#endif  // INCLUDE_TREE_H_
