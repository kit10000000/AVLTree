//
//  tree.cpp
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include "tree.h"

BSTTree::Tree::Tree() {
    this -> root = nullptr;
}
BSTTree::Tree::~Tree() {
}
void  BSTTree::Tree::insert(int key) {
    this->root = insert(key, this->root);
}
BSTTree::Node*  BSTTree::Tree::insert(int key, BSTTree::Node* node) {
    if (node == nullptr) {
        Node* node = new Node();
        node -> data = key;
        node -> right = nullptr;
        node -> left  = nullptr;
        return node;
    } else {
        if (key< node ->data)
            node->left = insert(key, node->left);
        else
            node->right = insert(key, node->right);
    }
    return node;
}
void  BSTTree::Tree::print_tree(int indent) {
    if (this->root) {
        print_tree(this->root, indent + 1);
    } else {
        std::cout <<"Дерево пусто" << std::endl;
    }
}
void BSTTree::Tree::print_tree(BSTTree::Node *node, int indent) {
    if (node) {
        print_tree(node -> right, indent + 1);
        for (int i = 0; i< indent; i++) std::cout <<"  ";
        std::cout << "--" << node->data << std::endl;
        print_tree(node -> left, indent + 1);
    }
}
