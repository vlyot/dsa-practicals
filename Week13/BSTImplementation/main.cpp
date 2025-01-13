#include "BST.h"

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    

    cout << "Remove 50" << endl;
    bst.remove(50);
    bst.inorder();

    cout << "Remove 20" << endl;
    bst.remove(20);
    bst.inorder();

    return 0;
}
