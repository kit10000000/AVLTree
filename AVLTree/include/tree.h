//
//  tree.h
//  AVLTree
//
//  Created by E. Chernikova on 20.03.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#ifndef tree_h
#define tree_h
namespace AVLTree
{
    struct Node {
        int   data;
       // int height;
        Node* left;
        Node* right;
    };
    
    class Tree {
        enum class traversal_order {pre, in, post};
        public:
            Tree();
            //Tree(std::initializer_list<int> list);
            //Tree(const Tree& tree);
           // Tree(Tree&& tree);
            void insert(int value);
            Node* insert(int key, AVLTree::Node* node);
            //bool exists(int value);
            //bool remove(int value);
            //bool save(const std::string& path);
            //bool load(const std::string& path);
            //void print(traversal_order order);
            //auto friend operator<<(std::ostream& stream, const Tree&) -> std::ostream& ;
            //auto operator=(const Tree&) -> Tree&;
            //auto operator=(Tree&&) -> Tree&;
            ~Tree();
        private:
            Node* root;
        };
};

#endif /* tree_h */
