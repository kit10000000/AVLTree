//
//  main.cpp
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <iostream>
#include "tree.h"
#include "tui.h"
#include <unordered_set>


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
        interface.work(tree);

    } else {
        interface.work(tree);
    }
    return 0;
}




