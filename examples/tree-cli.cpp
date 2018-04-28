//  BSTree
//  tree-cli.cpp
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <iostream>
#include "../include/tree.h"
#include "../include/tui.h"
#include <unordered_set>
#include <algorithm>


int main(int argc, const char * argv[]) {
    BSTTree::TUI interface;
    BSTTree::Tree tree;
    if (argc > 1) {
        std:: unordered_set<int> nodes;
        for (int i = 1; i < argc; i++) {
            nodes.insert(atoi(argv[argc-i]));
        }
        std::for_each(nodes.begin(), nodes.end(), [&tree](int n) {
            tree.insert(n);
        });
//        BSTTree::Tree tree1 = BSTTree::Tree(tree);
//        std::cout <<"Проверка работы конструктора копирования" << std::endl;
//        tree1.print_tree(0);
//        std::cout <<"Проверка работы оператора копирования" << std::endl;
//        BSTTree::Tree tree1 = BSTTree::Tree();
//        tree1 = tree;
//        tree1.print_tree(0);
//        std::cout <<"Проверка работы конструктора переноса" << std::endl;
//        BSTTree::Tree tree1 = BSTTree::Tree(std::move(tree));
//        tree1.print_tree(0);
//        std::cout <<"Проверка работы оператора переноса" << std::endl;
//        BSTTree::Tree tree1 = BSTTree::Tree();
//        tree1 = std::move(tree);
        interface.work(tree);

    } else {
        interface.work(tree);
    }
    return 0;
}




