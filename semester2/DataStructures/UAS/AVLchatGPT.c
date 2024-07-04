#include <stdio.h>
#include <stdlib.h>

// Struktur Node
typedef struct TreeNode {
    int value;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Fungsi untuk membuat node baru
TreeNode* createNewNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->height = 1; // Node baru awalnya ditambahkan di daun
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk mendapatkan tinggi dari pohon
int getHeight(TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Mendapatkan faktor keseimbangan dari node
int getBalance(TreeNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Fungsi utilitas untuk menemukan nilai maksimum dari dua bilangan bulat
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Fungsi untuk melakukan rotasi kanan pada subtree yang di-root-kan dengan node yang tidak seimbang
TreeNode* rightRotate(TreeNode* unbalancedNode) {
    TreeNode* newRoot = unbalancedNode->left;
    TreeNode* subtree = newRoot->right;

    // Melakukan rotasi
    newRoot->right = unbalancedNode;
    unbalancedNode->left = subtree;

    // Memperbarui tinggi
    unbalancedNode->height = 1 + max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// Fungsi untuk melakukan rotasi kiri pada subtree yang di-root-kan dengan node yang tidak seimbang
TreeNode* leftRotate(TreeNode* unbalancedNode) {
    TreeNode* newRoot = unbalancedNode->right;
    TreeNode* subtree = newRoot->left;

    // Melakukan rotasi
    newRoot->left = unbalancedNode;
    unbalancedNode->right = subtree;

    // Memperbarui tinggi
    unbalancedNode->height = 1 + max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// Fungsi untuk menemukan node dengan nilai terkecil
TreeNode* findMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Fungsi untuk menghapus node dari pohon AVL
TreeNode* deleteNode(TreeNode* root, int value) {
    // 1. Melakukan penghapusan BST biasa
    if (root == NULL)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Node dengan satu atau tanpa anak
        if ((root->left == NULL) || (root->right == NULL)) {
            TreeNode* temp = root->left ? root->left : root->right;

            // Tidak ada anak
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { // Satu anak
                *root = *temp;
            }
            free(temp);
        } else {
            // Node dengan dua anak
            TreeNode* temp = findMinValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    // Jika pohon hanya memiliki satu node, kembalikan node
    if (root == NULL)
        return root;

    // 2. Memperbarui tinggi node nenek moyang ini
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Mendapatkan faktor keseimbangan dari node nenek moyang ini untuk memeriksa apakah node ini menjadi tidak seimbang
    int balance = getBalance(root);

    // Jika node ini menjadi tidak seimbang, maka ada 4 kasus

    // Kasus Kiri-Kiri
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Kasus Kiri-Kanan
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Kasus Kanan-Kanan
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Kasus Kanan-Kiri
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Fungsi untuk menyisipkan node ke dalam pohon AVL
TreeNode* insert(TreeNode* node, int value) {
    if (node == NULL)
        return createNewNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node; // Nilai sudah ada di dalam pohon

    // Memperbarui tinggi dari node ini
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Mendapatkan faktor keseimbangan dari node ini
    int balance = getBalance(node);

    // Jika node ini menjadi tidak seimbang, maka ada 4 kasus

    // Kasus Kiri-Kiri
    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    // Kasus Kanan-Kanan
    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    // Kasus Kiri-Kanan
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Kasus Kanan-Kiri
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Fungsi utilitas untuk melakukan traversal preorder dari pohon
void printPreorder(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

// Fungsi utama untuk mendemonstrasikan penghapusan
int main() {
    TreeNode* root = NULL;

    // Menyisipkan node-node
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Mencetak traversal preorder dari pohon AVL yang dibentuk
    printf("Preorder traversal dari AVL tree yang dibentuk adalah: \n");
    printPreorder(root);
    printf("\n");

    // Menghapus node
    root = deleteNode(root, 40);

    // Mencetak traversal preorder dari pohon AVL setelah penghapusan
    printf("Preorder traversal dari AVL tree setelah penghapusan adalah: \n");
    printPreorder(root);
    printf("\n");

    return 0;
}
