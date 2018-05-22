#include "catch.hpp"
#include "../include/tree.h"
#include "../include/tui.h"
#include <initializer_list>
TEST_CASE("Test tree", "[tree]"){
    BSTTree::Tree tree1 = BSTTree::Tree();
    tree1.insert(6);
    
    std::cout <<"Проверка работы конструктора копирования" << std::endl;
    BSTTree::Tree tree2 = BSTTree::Tree(tree1);
    tree2.print_tree(0);
    
    std::cout <<"Проверка работы оператора копирования" << std::endl;
    BSTTree::Tree tree3 = BSTTree::Tree();
    tree3 = tree1;
    tree3.print_tree(0);
    
    std::cout <<"Проверка работы конструктора переноса" << std::endl;
    BSTTree::Tree tree4 = BSTTree::Tree(std::move(tree1));
    tree4.print_tree(0);
    
    std::cout <<"Проверка работы оператора переноса" << std::endl;
    BSTTree::Tree tree5 = BSTTree::Tree();
    tree5 = std::move(tree1);
    
    std::cout <<"Конструктор с листом" << std::endl;
    std::initializer_list <int> nodes1 = {6,8,7,9,4,1};
    BSTTree::Tree tree =  BSTTree::Tree(nodes1);
    tree.print_tree(0);
    
    std::cout <<"Добавление существующего узла" << std::endl;
    tree.insert(6);
    tree.print_tree(0);
    REQUIRE(tree.check_existing(6)==true);
    
    std::cout <<"Добавление несуществующего узла" << std::endl;
    tree.insert(30);
    tree.print_tree(0);
    
    std::cout <<"Прямой обход" << std::endl;
    tree.show_nodes(BSTTree::traversal_order:: pre_order);
    
    std::cout <<"Поперечный обход" << std::endl;
    tree.show_nodes(BSTTree::traversal_order:: in_order);
    
    std::cout <<"Обратный обход" << std::endl;
    tree.show_nodes(BSTTree::traversal_order:: post_order);
    
    std::cout <<"Удаление узла из дерева" << std::endl;
    tree.delete_node(6);
    tree.print_tree(0);
    REQUIRE(tree.check_existing(6)==false);
    
    std::cout <<"Проверка существования файла" << std::endl;
    BSTTree::TUI interface = BSTTree::TUI();
    std::string path1 = "1.txt";
    std::string path2 = "2.txt";
    REQUIRE(interface.check_file_exist(path2)==false);
    
    std::cout <<"Запись в файл" << std::endl;
    interface.work_with_file(tree, 1, false);
    REQUIRE(interface.check_file_exist(path1)==true);
    
    std::cout <<"Загрузка из файла" << std::endl;
    BSTTree::Tree tree7;
    tree7.print_tree(0);
    interface.work_with_file(tree7, 2, false);
    tree7.print_tree(0);
}

