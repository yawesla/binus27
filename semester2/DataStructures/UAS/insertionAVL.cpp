/* ======================== Inti ======================== */
// 1.Library
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2. Struct
struct Tree{
    int value;
    int height;
    Tree *left, *right;
}*node = NULL;

// 3. Create newNode
Tree *createNewNode (int value){
    Tree *newNode = (Tree*)malloc(sizeof(Tree));

    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode-> right = NULL;

    return newNode;
}





/* ======================== Helper ======================== */
// 1. Height
int height(Tree *node){
    if(!node) return 0;
    return node->height;
}

// 2. get Balance Factor
int getBalance(Tree *node){
    if(!node) return 0;
    return height(node->left) - height(node->right);
}

// 3. Check Max
int max(int a, int b){
    return (a > b) ? a : b;
}

// 4. findMin
Tree *findMin(Tree *node){
    while(node->left !=NULL) return node = node->left;
    return node;
}



/* ======================== Rotation ======================== */
// 1. left Rotate 
Tree *leftRotate(Tree *unbalancedNode){
    Tree *newRoot = unbalancedNode->right;
    Tree *subtree = newRoot->left;

    //Rotasi
    newRoot->left = unbalancedNode;
    unbalancedNode->right =subtree;

    //memperbarui Height
    unbalancedNode-> height = 1 + max(height(unbalancedNode->left),height(unbalancedNode->right));
    newRoot->height = 1 + max(height(newRoot->left),height(newRoot->right));

    return newRoot;
}

// 2. Right Rotation
Tree *rightRotate(Tree *unbalancedNode){
    Tree *newRoot = unbalancedNode->left;
    Tree *subtree = newRoot->right;

    //Rotasi
    newRoot->right = unbalancedNode;
    unbalancedNode->left =subtree;

    //memperbarui Height
    unbalancedNode-> height = 1 + max(height(unbalancedNode->left),height(unbalancedNode->right));
    newRoot->height = 1 + max(height(newRoot->left),height(newRoot->right));

    return newRoot;
}





/* ======================== Function ======================== */
// 1. Insertion
Tree *insert(Tree *node,int value){
    if(!node) return createNewNode(value);

    
    if(value < node->value) {
        node->left = insert(node->left,value);
    } else if(value > node->value){
        node->right = insert(node->right,value);
    } else{
        return node;
    }

    //update Height
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    //Rotation to Unbalanced Case
    //LL (value lebih kecil dari node)
    if(balance > 1 && value < node->left->value){
        return rightRotate(node);
    }

    //RR
    if(balance < -1 && value > node->right->value){
        return leftRotate(node);
    }

    //LR (value lebih besar dari node)
    if(balance > 1 && value > node->left->value){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RL
    if(balance < -1 && value < node->right->value){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 2. Print PreOrder
void printPreorder(Tree *node){
    if(node != NULL){
        printf("%d ",node->value);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

// 3. deletion
Tree *deleteNode(Tree *node, int value){
    if(node == NULL) return node;

    if(value < node->value){
        node->left = deleteNode(node->left, value);
    } else if(value > node->value){
        node->right = deleteNode(node->right,value);
    } else {
        // Node ada 1 atau tanpa anak
        if((node->left) == NULL || (node->right) == NULL){
            Tree *temp = node->left ? node->left : node->right;

            if(temp == NULL){
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            // Node dengan 2 anak, find largest subtree
            Tree *temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right,node->value);
        }
    }

    
    //Height
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    //Rotate
    //LL 
    if(balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }

    //RR
    if(balance < -1 && getBalance(node->right) <= 0){
        return leftRotate(node);
    }

    //LR
    if(balance > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if(balance < -1 && getBalance(node->left) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}





/* ======================== Main ======================== */
int main() {
    Tree *root = NULL;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print preorder traversal of the AVL tree
    printf("Preorder traversal of the constructed AVL tree is \n");
    printPreorder(root);

    root = deleteNode(root,40);
    printf("\nPreorder traversal of the constructed AVL tree is \n");
    printPreorder(root);

    return 0;
}