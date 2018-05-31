//
//  tui.h
//  AVLTree
//
//  Created by E. Chernikova on 27.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <string>
#include <sstream>
#include <limits>
#include "tree.h"



#ifndef INCLUDE_TUI_H_
#define INCLUDE_TUI_H_
namespace  BSTTree {
class TUI {
public:
    //!
    //!работа с деревом
    //!
    void work(BSTTree::Tree &tree);
    //!
    //!вывод меню
    //!
    void print_menu();
    //!
    //!выбора варианта обхода узлов для вывода
    //!
    void choose_show_order(BSTTree::Tree &tree);
    //!
    //!подтверждение выхода из программы
    //!
    bool approve_choice();
    //!
    //!обработка пользовательского ввода (строка)
    //!
    std::string user_input();
    //!
    //!обработка пользовательского ввода (число)
    //!
    int input_digit();
    //!
    //!проверка на существование файла
    //!
    bool check_file_exist(std::string &path);
    //!
    //!создание и считывание из файла (need_path -- для тестов)
    //!
    void work_with_file(BSTTree::Tree &tree, int working_mode, bool need_path);

};
}   // namespace BSTTree

#endif // INCLUDE_TUI_H_
