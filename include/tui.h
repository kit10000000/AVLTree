
//  tui.h
//  AVLTree
//
//  Created by E. Chernikova on 27.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "tree.h"

#ifndef INCLUDE_TUI_H_
#define INCLUDE_TUI_H_
namespace  BSTTree {
class TUI {
 public:
    void work(BSTTree::Tree tree);
    void print_menu();
};
}   // namespace BSTTree

#endif  // INCLUDE_TUI_H_
