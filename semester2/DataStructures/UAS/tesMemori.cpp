// A. Inti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
    int value;
    int height;
    Tree *left,*right;
} *node = NULL;

Tree *createNewNode(int value){
    Tree *newNode = (Tree*)malloc(sizeof(Tree));

    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;

    return newNode;
}

//B. helper
int height (Tree *node){
    if(!node) return 0;
    return node->height;
}

int getBalance(Tree *node){
    if(!node) return 0;
    return height(node->left) - height(node->right);
}

int max (int a,int b){
    return (a>b) ? a: b;
}

Tree *findMin(Tree *node){
    while(node != NULL) return node = node->left;
    return node;
}

// C. rotate
Tree *leftRotate(Tree *unbalancedNode){
    Tree *newRoot = unbalancedNode->right;
    Tree *subtree = newRoot->left;

    newRoot->left = unbalancedNode;
    unbalancedNode->right = subtree;

    //height
    unbalancedNode->height = 1+ max(height(unbalancedNode->left),height(unbalancedNode->right));
    newRoot->height =  1+ max(height(newRoot->left),height(newRoot->right));

    return newRoot;
}

Tree *rightRotate(Tree *unbalancedNode){
    Tree *newRoot = unbalancedNode->left;
    Tree *subtree = newRoot->right;

    newRoot->right = unbalancedNode;
    unbalancedNode->left = subtree;

    //height
    unbalancedNode->height = 1+ max(height(unbalancedNode->left),height(unbalancedNode->right));
    newRoot->height =  1+ max(height(newRoot->left),height(newRoot->right));

    return newRoot;
}

//D. Fucntion
Tree *insert(Tree *node,int value){
    if(!node) return createNewNode(value);

    if(value < node->value){
        node->left = insert(node->left,value);
    } else if(value > node->value){
        node->right = insert(node->right, value);
    } else {
        return node;
    }

    //height
    node->height = 1+ max(height(node->left),height(node->right));
    int balance = getBalance(node);

    //rotate
    //ll
    if(balance > 1 && value < node->left->value){
        return rightRotate(node);
    }

    //rr
    if(balance < -1 && value > node->right->value){
        return leftRotate(node);
    }

    //lr
    if(balance > 1 && value > node->left->value){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //rl
    if(balance < -1 && value < node->right->value){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

void printPreorder(Tree *node){
    if(node != NULL){
        printf("%d ",node->value);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

Tree *deleteNode(Tree *node,int value){
    if(node == NULL) return node;

    if(value < node->value){
        node->left = deleteNode(node->left,value);
    } else if(value > node->value){
        node->right = deleteNode(node->right, value);
    } else {
        if((node->left == NULL) || (node->right == NULL)){
            Tree *temp = node->left ? node->left : node->right;

            if(temp == NULL){
                temp = node;
                node = NULL;
            } else{
                *node = *temp;
            }
            free(temp);
        }
        else {
            Tree *temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right,node->value);
        }
    }
    
    //height
    node->height = 1+ max(height(node->left),height(node->right));
    int balance = getBalance(node);

    //rotate
    //ll
    if(balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }

    //rr
    if(balance < -1 && getBalance(node->right) <= 0){
        return leftRotate(node);
    }

    //lr
    if(balance > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //rl
    if(balance < -1 && getBalance(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main(){

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