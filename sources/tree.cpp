//
//  tree.cpp
//  BSTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//


#include "../include/tree.h"

BSTTree::Tree::Tree() {
    this -> root = nullptr;
}

BSTTree::Tree::Tree(std::initializer_list<int> list) {
    for (auto n : list) {
        insert(n);
    }
}
auto BSTTree::Tree::operator=(Tree&& tree) -> Tree& {
    if (this != &tree) {
        this -> root = copy_node(tree.root);
        tree.root = nullptr;
    }
    return *this;
}

BSTTree::Tree::Tree(Tree&& tree) {
    this -> root = copy_node(tree.root);
    tree.root = nullptr;
}

auto BSTTree::Tree::operator=(const Tree& tree)-> Tree& {
    this -> root = copy_node(tree.root);
    return *this;
}
namespace BSTTree {
auto operator<<(std::ostream& stream, const Tree& tree) -> std::ostream& {
    if (tree.root) {
        tree.Tree::save_tree(tree.root, stream);
        std::cout << std::endl;
    } else {
        std::cout <<"Дерево пусто" << std::endl;
    }
    return stream;
}
}  //  namespace BSTTree
BSTTree::Node* BSTTree::Tree::copy_node(BSTTree::Node* old_node) {
    if (old_node != nullptr) {
        BSTTree::Node* node = new BSTTree::Node();
        node -> data = old_node -> data;
        node -> right = copy_node(old_node->right);
        node -> left  = copy_node(old_node->left);
        return node;
    }
    return nullptr;
}


BSTTree::Tree::Tree(const Tree& tree) {
    if (tree.root) {
        this -> root = copy_node(tree.root);
    }
}

BSTTree::Tree::~Tree() {
    this -> root = delete_tree(this->root);
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
        if (key != node ->data) {
            if (key< node ->data)
                node->left = insert(key, node->left);
            else
                node->right = insert(key, node->right);
        } else {
            std::cout <<"Узел уже существует в дереве" << std::endl;
        }
    }
    return node;
}

bool BSTTree::Tree::check_existing(int key) {
    if (this->root == nullptr) {
        std::cout <<"Дерево пусто" << std::endl;
        return false;
    } else {
        if (check_existing(key, this->root)) {
            std::cout <<"Узел найден" << std::endl;
            return true;
        } else {
            std::cout <<"Узел не был найден в дереве" << std::endl;
            return false;
        }
    }
    return false;
}

bool BSTTree::Tree::check_existing(int key, BSTTree::Node *node) {
    bool tmp = false;
    if (node == nullptr) {
        tmp = false;
        return tmp;
    }
    if (node -> data == key)
        tmp = true;
    if (node -> data > key)
        tmp = check_existing(key, node->left);
    if (node->data < key)
        tmp = check_existing(key, node->right);
    return tmp;
}

int BSTTree::Tree:: find_min(BSTTree::Node* node) {
    int tmp_data = -1;
    if (node == nullptr)
        tmp_data = node->data;
    if (node->left == nullptr) {  //  если нет лев листа, то это наименьший
        tmp_data = node -> data;
    } else {
        tmp_data = find_min(node->left);
    }
    return tmp_data;
}

BSTTree::Node*  BSTTree::Tree::delete_node(int key, BSTTree::Node* node) {
    if (node == nullptr) {
        return node;
    }
    if (key > node->data) {
        node->right = delete_node(key, node->right);
    } else if (key < node->data) {
        node->left = delete_node(key, node->left);
    } else if (node->left != nullptr
               && node->right != nullptr) {  //  равный ключ
        node -> data = find_min(node->right);
        node -> right = delete_node(node->data, node->right);
    } else {  // если нет одного из родителей
        BSTTree::Node* tmp_node;
        tmp_node = node;
        if (node -> left != nullptr) {
            node = node -> left;
        } else {
            node = node -> right;
        }
        delete tmp_node;
    }
    return node;
}

void  BSTTree::Tree::delete_node(int key) {
    if (this->root == nullptr) {
        std::cout <<"Дерево пусто" << std::endl;
    } else {
        if (check_existing(key, this->root)) {
            this->root = delete_node(key, this->root);
            std::cout <<"Узел был успешно удален из дерева" << std::endl;
        } else {
            std::cout <<"Узел не был найден в дереве" << std::endl;
        }
    }
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
BSTTree::Node* BSTTree::Tree::delete_tree(BSTTree::Node* node) {
    if (node == nullptr) {
        return nullptr;
    } else {
        node->left = delete_tree(node->left);
        node->right = delete_tree(node->right);
        delete node;
    }
    return nullptr;
}

void BSTTree::Tree::show_nodes(BSTTree::traversal_order order, BSTTree::Node* node) {
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
    if (order == BSTTree::traversal_order::post_order) {
        if (node) {
            show_nodes(order, node ->left);
            show_nodes(order, node ->right);
            std::cout << node->data << " ";
        }
    }
}
std::ostream& BSTTree::Tree::save_tree(const BSTTree::Node* node, std::ostream& file) const {
    if (node) {
        int i = node->data;
        file << i;
        file << " ";
        save_tree(node ->left, file);
        save_tree(node ->right, file);
    }
    return file;
}



