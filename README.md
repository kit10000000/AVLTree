# BSTTree
[![Build Status](https://travis-ci.org/kit10000000/BSTTree.svg?branch=develop)](https://travis-ci.org/kit10000000/BSTTree)
[![Build status](https://ci.appveyor.com/api/projects/status/sw6yldb4u6fggkf5?svg=true)](https://ci.appveyor.com/project/kit10000000/bsttree)

Целью данного проекта является разработка программы для работы с двоичным деревом поиска (далее будем называть просто деревом) со следующим TUI:

Выберите одну из операций:
1. Вывести дерево на экран
2. Вывести список узлов дерева 
   a. Прямой обход
   b. Поперечный обход
   c. Обратный обход
3. Добавить узел в дерево
4. Удалить узел из дерева
5. Сохранить дерево в файл
6. Загрузить дерево из файла
7. Проверить наличие узла
8. Завершить работу программы

Этапы:
1. :deciduous_tree:
2. :deciduous_tree:
3. :deciduous_tree:
4. :deciduous_tree:
5. :deciduous_tree:
6. :deciduous_tree:
7. :deciduous_tree:
8. :deciduous_tree:

Требования:
1. :white_check_mark: Все функции по работе с деревом должны находиться в
пространстве имен ${Type}Tree.
2. :white_check_mark: Структура узла должна иметь определённый прототип.
3. :white_check_mark: Класс дерева должна иметь определённый прототип.
4. :white_check_mark: Файлы исходного кода должны располагаться на сервисе GitHub
в открытом репозитории с названием ${Type}Tree.
5. :white_check_mark: Репозиторий ${Type}Tree должен иметь определённую структуру
6. :white_check_mark: Код должен быть читабельным и оформлен в едином стиле.
astyle
7. :white_check_mark: Файлы исходного кода должны пройти проверку утилитой
cpplint.
8. :white_check_mark: Оформить README.md файл, содержащий описание проекта.
9. :white_check_mark: Оформить .gitignore файл, создать отдельную ветку develop,
каждый этап помечать соответствующим тэгом.
10. :white_check_mark: Создать CMakeLists.txt для автоматизации сборки проекта.
11. :white_check_mark: Добавить в CMakeLists.txt автоматизацию процесса сборки
примеров.
12. :white_check_mark: Обеспечить 100% покрытие кода с использованием фреймворка
Catch.
13. :white_check_mark: Обеспечить непрерывный процесс сборки проекта с
использованием сервиса Travis CI .
14. :white_check_mark: Обеспечить непрерывный процесс сборки и тестирование проекта
с использованием сервисов Travis CI и AppVeyor.
15. :white_check_mark: Написать документацию к проекту с использованием инструмента
doxygen и разместить ее на сервисе GitHub Page.
16. :white_check_mark: Добавить в CMakeLists.txt автоматизацию процесса
пакетирования.
17. :x: Обеспечить размещение пакета проекта на сервисе GitHub
Release при успешном слиянии ветки develop и master.

```ShellSession
$ git clone https://github.com/kit10000000/BSTTree.git BSTTree
$ cd BSTTree
$ git checkout develop
$ cmake -H. -B_builds
$ cmake --build _builds
```
