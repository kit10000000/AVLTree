
#include "tree.h"
#include "tui.h"
#include <unordered_set>
#include <algorithm>


int main(int argc, const char * argv[]) {
    BSTTree::TUI interface;
    BSTTree::Tree tree;
    if (argc > 1) {
        std:: unordered_set<int> nodes;
        for (int i = 1; i < argc; i++) {
            nodes.insert(atoi(argv[argc-i]));
        }
        std::for_each(nodes.begin(), nodes.end(), [&tree](int n) {
            tree.insert(n);
        });
        
    } else {
        interface.work(tree);
    }
    return 0;
}




