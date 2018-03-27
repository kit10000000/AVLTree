//
//  tui.cpp
//  AVLTree
//
//  Created by E. Chernikova on 27.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include "tui.h"
#include "tree.h"
void  BSTTree::TUI::print_menu() {
    std::cout << "Выберите одну из операций:" << std::endl;
    std::cout << "1. Вывести дерево на экран" << std::endl;
    std::cout << "2. Вывести список узлов дерева" << std::endl;
    std::cout << "3. Добавить узел в дерево" << std::endl;
    std::cout << "4. Удалить узел из дерева" << std::endl;
    std::cout << "5. Сохранить дерево в файл" << std::endl;
    std::cout << "6. Загрузить дерево из файла" << std::endl;
    std::cout << "7. Проверить наличие узла" << std::endl;
    std::cout << "8. Завершить работу программы" << std::endl;
}
void  BSTTree::TUI::work(BSTTree::Tree tree) {
    print_menu();
    int  c = -1;
    while (c!= 8) {
        std::cout << "Выберите одну из операций:" << std::endl;
        std::cin>> c;
        switch (c) {
        case 1:
            std::cout << "1. Вывести дерево на экран" << std::endl;
            tree.print_tree(0);
            break;
        case 2:
            std::cout << "2. Вывести список узлов дерева" << std::endl;
            break;
        case 3:
            std::cout << "3. Добавить узел в дерево" << std::endl;
            break;
        case 4:
            std::cout << "4. Удалить узел из дерева" << std::endl;
            break;
        case 5:
            std::cout << "5. Сохранить дерево в файл" << std::endl;
            break;
        case 6:
            std::cout << "6. Загрузить дерево из файла" << std::endl;
            break;
        case 7:
            std::cout << "7. Проверить наличие узла" << std::endl;
            break;
        case 8:
            std::cout << "8. Завершить работу программы" << std::endl;
            break;
        default:
            std::cout << "Не является пунктом меню" << std::endl;
        }
    }
}
