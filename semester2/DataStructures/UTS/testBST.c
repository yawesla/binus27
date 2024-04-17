#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
} treeNode;

treeNode *root = NULL;

treeNode *createNode(int value){
    treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));

    //masukin detail newNode ke value
    newNode->key = value;
    newNode->left = newNode-> right = NULL;

    return newNode;
}

treeNode *insertNode(treeNode *curr, int value){
    if(curr == NULL) return createNode(value);
    if(value < curr->left) curr->left = insertNode(curr->left, value);
    if(value > curr->right) curr->right = insertNode(curr->right, value);

    return curr;
}

printInfix(treeNode *curr){
    if(curr == NULL) return;

    printInfix(curr->left);
    printf("%d ",curr->key);
    printInfix(curr->right);
}

printPrefix(treeNode *curr){
    if(curr == NULL) return;

    printf("%d ",curr->key);
    printPrefix(curr->left);
    printPrefix(curr->right);
}

printPostfix(treeNode *curr){
    if(curr == NULL) return;

    printPostfix(curr->left);
    printPostfix(curr->right);
    printf("%d ",curr->key);
}

treeNode *search(treeNode *curr, int find){
    if(!curr) {
        printf("%d is not found",find);
        return;
    }

    if(find == curr->key){
        printf("%d is found",find);
        return;
    }

    //mencari ke kiri
    if(find<curr->key){
        return search(curr->left,find);
    }

    //mencari ke kanan
    else if( find > curr->key){
        return search(curr->right,find);
    }
    
    return curr;
}



int main(){

    return 0;
}
