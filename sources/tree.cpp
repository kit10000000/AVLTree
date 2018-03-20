//
//  tree.cpp
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <stdio.h>
#include "/Users/e.chernikova/kit10000000/workspace/projects/AVLTree/AVLTree/include/tree.h"

AVLTree::Tree::Tree() {
    this -> root = nullptr;
}
AVLTree::Tree::~Tree() {
}
void AVLTree::Tree::insert(int key) {
    this->root = insert(key, this->root);
}
AVLTree::Node* AVLTree::Tree::insert(int key, AVLTree::Node* node) {
    if (node == nullptr) {
        Node* node = new Node();
        node -> data = key;
        node -> right = nullptr;
        node -> left  = nullptr;
        return node;
    } else {
        if (key< node ->data) {
            node->left = insert(key, node->left);
        } else {
            node->right = insert(key, node->right);
        }
    }
    return node;
}
