//
//  tui.h
//  BSTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <limits>
#include "../include/tree.h"

#ifndef INCLUDE_TUI_H_
#define INCLUDE_TUI_H_
namespace  BSTTree {
class TUI {
 public:
    void work(BSTTree::Tree& tree);
    void print_menu();
    void choose_show_order(BSTTree::Tree& tree);
    int approve_choice();
    std::string user_input();
    bool check_file_exist(std::string& path);
    void work_with_file(BSTTree::Tree& tree, int working_mode, bool need_path);
};
}   //  namespace BSTTree

#endif  //  INCLUDE_TUI_H_
