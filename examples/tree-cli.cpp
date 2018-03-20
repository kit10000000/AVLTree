//
//  main.cpp
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include <iostream>
#include "./include/tree.h"

void print_menu();
void work();
bool check_repeating(int n, const char * argv_arr[]);
bool check_input(int input);

int main(int argc, const char * argv[]) {
    if (argc >= 1) {
        AVLTree::Tree tree;
        // проверка на уникальность ключей
        bool check = check_repeating(argc, argv);
        if (check) {
            std::cout << "Элементы повторяются" << std::endl;
            return 0;
        } else {
            // инициализация дерева
            std::cout << "Работа с деревом" << std::endl;
            for (int i = 1; i < argc; i++) {
                tree.insert(atoi(argv[i]));
            }
            work();
        }
    } else {
        work();
    }
    return 0;
}

bool check_repeating(int n, const char * argv_arr[]) {
    bool contain_repeating = false;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
            } else {
                if (atoi(argv_arr[i]) == atoi(argv_arr[j])) {
                    contain_repeating = true;
                    return contain_repeating;
                }
            }
        }
    }
    return contain_repeating;
}
bool check_input(int input) {
    bool is_correct = true;
    is_correct =  input > 8 || input < 1 ? 0 : 1;
    return is_correct;
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

