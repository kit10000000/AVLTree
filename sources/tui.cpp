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
bool BSTTree::TUI::check_file_exist(std::string &path){
    std::ifstream f(path);
    return f.good();
};

std::string BSTTree::TUI::user_input(){
        std::string in;
        while (!(std::cin >> in)) {
            std::cout << "Неправильный ввод";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return in;
}

void BSTTree::TUI::work_with_file(BSTTree::Tree &tree , int working_mode, bool need_path){
    std::string path = "";
    if (need_path){
        std::cout << "Введите путь к файлу" << std::endl;
        std::string path = user_input();
    } else{
        path= "1.txt";
    }
    bool check = check_file_exist(path);
    std::string str;
    if (working_mode == 1){
        if(check){
            std::cout << "Файл уже существует, перезаписать? (Да|Нет):" << std::endl;
            str = "";
            while(str != "Нет" && str != "Да"){
                str = user_input();
            }
            if (str == "Да"){
                std::ofstream f;
                f.open(path, std::ios::trunc);
                f << tree;
                f.close();
                std::cout << "Файл был перезаписан" << std::endl;
            }
        } else {
            std::ofstream f;
            f.open(path);
            f << tree;
            f.close();
            std::cout << "Дерево было успешно сохранено" << std::endl;
        }
    }
    if (working_mode == 2){
        if(check){
            tree.delete_tree();
            std::string line;
            std::ifstream f;
            f.open(path, std::ios::out);
            if (f.is_open())
            {
                while ( getline (f,line) )
                {
                    std::istringstream iss(line);
                    int node;
                    while(iss>>node){
                        tree.insert(node);
                    }
                }
                f.close();
                std::cout << "Дерево было успешно загружено" << std::endl;
            }
            
        } else {
            std::cerr << "Файла с заданным путем не существует" << std::endl;
        }
    }
}
int BSTTree::TUI::input_digit() {

    int in;
    while (!(std::cin >> in))
    {
        std::cout << "Неправильный ввод. Введите цифру."<< std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return in;
}
void BSTTree::TUI::work(BSTTree::Tree &tree) {
    print_menu();
    int  c = -1;
    int value = 0;
    while (c!= 0) {
        std::cout << "Выберите одну из операций:" << std::endl;
        c = input_digit();
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
            std::cout << "Введите ключ" << std::endl;
            if(std::cin>> value){
                  tree.insert(value);
            } else{
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 4:
            std::cout << "4. Удалить узел из дерева" << std::endl;
            std::cout << "Введите ключ " << std::endl;
                if(std::cin>> value){
                tree.delete_node(value);
            } else {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 5:
            std::cout << "5. Сохранить дерево в файл" << std::endl;
            work_with_file(tree,1, true);
            break;
        case 6:
            std::cout << "6. Загрузить дерево из файла" << std::endl;
                if(!tree.is_empty()){
                    std::cout << "Дерево непустое. Перезаписать?";
                    if( user_input() == "Нет" ) {
                        break;
                    }
                }
                work_with_file(tree, 2,true);
            break;
        case 7:
            std::cout << "7. Проверить наличие узла" << std::endl;
            std::cout << "Введите ключ для поиска" << std::endl;
            if(std::cin>> value){
                tree.check_existing(value);
            } else {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 8:
            std::cout << "8. Завершить работу программы" << std::endl;
            c = approve_choice();
            break;
        default:
            std::cout << "Не является пунктом меню" << std::endl;
        }
    }
}
void BSTTree::TUI::choose_show_order(BSTTree::Tree &tree){
    int c  = -1;
    while (c!= 0) {
        std::cout << "Выберите вариант обхода:" << std::endl;
        std::cout << "1. Прямой обход" << std::endl;
        std::cout << "2. Поперечный обход" << std::endl;
        std::cout << "3. Обратный обход " << std::endl;
        std::cout << "4. Выход в главное меню " << std::endl;
        c = input_digit();
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
                case 4:
                    return;
                default:
                    std::cerr << "Не является пунктом меню" << std::endl;
        }
    }
}

int BSTTree::TUI::approve_choice(){
    int choice = 0;
    std::string str = "";
    std::cout << "Вы уверены, что хотите выйти из программы ?" << std::endl;
    while(str != "Нет" && str != "Да"){
        str = user_input();
    }
    if (str == "Нет"){
        choice =  8;
    }
    if (str == "Да"){
        choice = 0;
    }
    return choice;
}

