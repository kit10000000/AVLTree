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
    int value = 0;
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
            choose_show_order(tree);
            break;
        case 3:
            std::cout << "3. Добавить узел в дерево" << std::endl;
            std::cout << " Введите ключ" << std::endl;
            std::cin>> value;
            tree.insert(value);
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
                approve_choice();
            break;
        default:
            std::cout << "Не является пунктом меню" << std::endl;
        }
    }
}
void BSTTree::TUI::choose_show_order(BSTTree::Tree tree){
    int c  = -1;
    std::cout << "Выберите вариант обхода:" << std::endl;
    std::cout << "1. Прямой обход" << std::endl;
    std::cout << "2. Поперечный обход" << std::endl;
    std::cout << "3. Обратный обход " << std::endl;
    std::cin>> c;
    switch (c) {
        case 1:
            tree.show_nodes(BSTTree::traversal_order:: pre_order);
            break;
        case 2:
            tree.show_nodes(BSTTree::traversal_order:: in_order);
            break;
        case 3:
            tree.show_nodes(BSTTree::traversal_order:: post_order);
            break;
        default:
            std::cout << "Не является пунктом меню" << std::endl;
    }
}

void BSTTree::TUI::approve_choice(){

}

