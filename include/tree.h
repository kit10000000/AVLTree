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
#include <fstream>
#include <cstdlib>
#include <initializer_list>


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
    //!
    //!стандартный конструктор
    //!
    Tree();
    //!
    //!конструктор из листа
    //!
    Tree(std::initializer_list<int> list);
    //!
    //!конструктор копирования
    //!
    Tree(const Tree &tree);
    //!
    //!конструктор переноса
    //!
    Tree(Tree&& tree);
    //!
    //!вставка узла в дерево
    //!
    void insert(int value);
    //!
    //!вывод дерева в консоль
    //!
    void print_tree(int indent);
    //!
    //!вывод узлов в нужном порядке
    //!
    void show_nodes(BSTTree::traversal_order order);
    //!
    //!удаление узла
    //!
    void delete_node(int value);
    //!
    //!сохранение дерева(не используется)
    //!
    void save_tree(const Tree& tree, std::ostream &file);
    //!
    //!проверка существования узла
    //!
    bool check_existing(int key);
    //!
    //!проверка дерева на наличие узлов
    //!
    bool is_empty();
    //!
    //!удаление дерева
    //!
    void delete_tree();
    void swap(Tree& one, Tree& two);
    //!
    //!перегразка операторов
    //!
    auto operator=(const Tree& tree)-> Tree&;
    auto operator=(Tree&&) -> Tree&;
    friend auto operator<<(std::ostream& stream, const Tree& tree) -> std::ostream&;
    ~Tree();
 private:
    Node* root;
    Node* insert(int key,  BSTTree::Node* node);
    int find_min(BSTTree::Node* node);
    void print_tree(BSTTree::Node* node, int indent);
    Node* delete_tree(BSTTree::Node* node);
    bool check_existing(int key,  BSTTree::Node* node);
    Node* delete_node(int key,  BSTTree::Node* node);
    void show_nodes(BSTTree::traversal_order order, BSTTree::Node* node);
    std::ostream& save_tree(const BSTTree::Node* node,std::ostream &file) const;
    Node* copy_node(BSTTree::Node* node);

};
    

}  // namespace BSTTree

#endif  // INCLUDE_TREE_H_
