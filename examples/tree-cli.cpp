//
//  main.cpp
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <iostream>
#include "/Users/e.chernikova/kit10000000/workspace/projects/AVLTree/include/tree.h"

void print_menu();
void work();
bool check_repeating(int n, const char * argv_arr[]);
bool check_input(int input);

int main(int argc, const char * argv[]) {
    if (argc > 1) {
        AVLTree::Tree tree;
        std::set<int> nodes;
        std::cout << "Работа с деревом" << std::endl; //инициализация дерева
        for(int i = 1; i < argc; i++)
        {
            nodes.insert(atoi(argv[i]));
        }
        std::for_each(nodes.begin(), nodes.end(), [&tree](int n){tree.insert(n);} );
        
        work();
    } else {
        work();
    }
    return 0;
}

void print_menu() {
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

void work() {
    print_menu();
    int  c = -1;
    while (c!= 8) {
        std::cout << "Выберите одну из операций:" << std::endl;
        std::cin>> c;
        switch (c) {
        case 1:
            std::cout << "1. Вывести дерево на экран" << std::endl;
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

