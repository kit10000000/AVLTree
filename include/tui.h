//
//  tui.h
//  AVLTree
//
//  Created by E. Chernikova on 27.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "tree.h"
#include <limits>


#ifndef INCLUDE_TUI_H_
#define INCLUDE_TUI_H_
namespace  BSTTree {
class TUI {
public:
    void work(BSTTree::Tree &tree);
    void print_menu();
    void choose_show_order(BSTTree::Tree &tree);
    int approve_choice();
    std::string user_input();
    bool check_file_exist(std::string &path);
    void work_with_file(BSTTree::Tree &tree, int working_mode);
};
}   // namespace BSTTree

#endif // INCLUDE_TUI_H_
