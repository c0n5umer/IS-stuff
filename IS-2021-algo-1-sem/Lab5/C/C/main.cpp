#include <iostream>

struct tree {
    int value;
    tree* left;
    tree* right;
};

tree* insert(tree* root, int key) {
    if (root == NULL) {
        root = new tree;
        root->value = key;
        root->left = root->right = NULL;
    }
    else if (root->value > key) 
        root->left = insert(root->left, key);
    else if (root->value < key) 
        root->right = insert(root->right, key);
    return root;
}

tree* to_min(tree* root) {
    if (root->left == NULL) return root;
    return to_min(root->left);
}


tree *delete_element(tree *root, int key) {
    if (root == NULL) return root;

    if (key < root->value) //в левом поддереве
        root->left = delete_element(root->left, key);
    else if (key > root->value) //в правом поддереве
        root->right = delete_element(root->right, key);
    else if (root->left != NULL && root->right != NULL) { //в корне и есть два ребенка
        root->value = to_min(root->right)->value;
        root->right = delete_element(root->right, root->value);
    } else { //один ребенок
        if (root->left != NULL)
            root = root->left;
        else if (root->right != NULL)
            root = root->right;
        else
            root = NULL;
    }
    return root;
}

bool exist(tree* root, int key) {
    if (root == NULL) 
        return false;
    if (root->value == key) 
        return true;
    if (key < root->value) 
        return exist(root->left, key);
    else 
        return exist(root->right, key);
}

tree* next(tree* root, int key) {
    tree* current = root;
    tree* successor = NULL;

    while (current != NULL) {
        if (current->value > key) {
            successor = current;
            current = current->left;
        }
        else 
            current = current->right;
    }
    return successor;
}

tree* prev(tree* root, int key) {
    tree* current = root;
    tree* successor = NULL;

    while (current != NULL) {
        if (current->value < key) {
            successor = current;
            current = current->right;
        }
        else current = current->left;
    }
    return successor;
}

int main(void) {
    tree* root = NULL;
    int x;
    std::string s;

    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    while (std::cin >> s) {
        std::cin >> x;

        if (s == "insert") 
            if (root == NULL)
                root = insert(root, x);
            else
                insert(root, x);
        else if (s == "delete")
            root = delete_element(root, x);
        else if (s == "exists")
            if (exist(root, x))
                std::cout << "true\n";
            else
                std::cout << "false\n";
        else if (s == "next") {
            tree* res = next(root, x);
            
            if (res == NULL)
                std::cout << "none\n";
            else
                std::cout << res->value << "\n";
        }
        else if (s == "prev") {
            tree* res = prev(root, x);

            if (res == NULL)
                std::cout << "none\n";
            else
                std::cout << res->value << "\n";
        }
    }
    return 0;
}