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
    delete this;
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
        if (key != node ->data){
            if(key< node ->data)
                node->left = insert(key, node->left);
            else
                node->right = insert(key, node->right);
        } else {
            std::cout <<"Узел уже существует в дереве" << std::endl;
        }
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
void  BSTTree::Tree::show_nodes(BSTTree::traversal_order order) {
    if (this->root) {
        show_nodes(order, this->root);
        std::cout << std::endl;
    } else {
        std::cout <<"Дерево пусто" << std::endl;
    }
}
void BSTTree::Tree::show_nodes(BSTTree::traversal_order order, BSTTree::Node* node){
    if (order == BSTTree::traversal_order::pre_order) {
        if (node) {
            std::cout << node->data << " ";
            show_nodes(order, node ->left);
            show_nodes(order, node ->right);
        }
    }
    if (order == BSTTree::traversal_order:: in_order) {
        if (node) {
            show_nodes(order, node ->left);
            std::cout << node->data << " ";
            show_nodes(order, node ->right);
        }
    }
    if (order == BSTTree::traversal_order::post_order ) {
        if (node) {
            show_nodes(order, node ->left);
            show_nodes(order, node ->right);
            std::cout << node->data << " ";
        }
    }
}


