#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    int key;
    struct node *left, *right;
} treeNode;

treeNode *root = NULL;

treeNode *createNode(int value)
{
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));

    newNode->key = value;
    newNode->left = newNode->right = NULL;

    return newNode;
}

treeNode *insertNode(treeNode *curr, int value){
    if(curr = NULL) return createNode(value);
    if(value < curr->key) curr->left = insertNode(curr->left,value);
    else if(value > curr->key) curr->right = insertNode(curr->right,value);

    return curr;
}

treeNode *printInfix(treeNode *node){
    if(node == NULL) return;

    printInfix(node->left);
    printd("%d ",node->key);
    printInfix(node->right);
}


treeNode *printPrefix(treeNode *node){
    if(node == NULL) return;

    printd("%d ",node->key);
    printPrefix(node->left);
    printPrefix(node->right);
}

treeNode *printPostfix(treeNode *node){
    if(node == NULL) return;

    printPostfix(node->left);
    printPostfix(node->right);
    printd("%d ",node->key);
}

int count(treeNode *node){
    if(node == NULL) return NULL;

    return (1 + count(node->left) + count(node->right));
}

int height (treeNode *node){
    if(node == NULL) return NULL;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;

    return (1 + maxHeight);
}

int findMin (treeNode *node){
    if (node == NULL) return 0;

    if(node->left == NULL) return node->key;

    return findMin(node->left);
}

int findMax (treeNode *node){
    if (node == NULL) return 0;

    if(node->right == NULL) return node->key;

    return findMax(node->right);
}

treeNode *search(treeNode *curr, int find){
    if (curr == NULL) {
        printf("%d is not found\n", find);
        return;
    }

    if(find == curr->key){
        printf("%d is found\n", find);
        return;
    }

    if(find < curr->key) return search(curr->left,find);
    else if(find > curr->key) return search(curr->right,find);

    return curr;
}

treeNode *findPredecessor (treeNode *node){
    if (node == NULL) return NULL;

    if(node->right == NULL) return NULL;

    return findPredecessor(node->right);
}

treeNode *delete(treeNode *curr, int del){
    if( curr == NULL) return NULL;

    else if(del < curr->key) curr->left = delete(curr->left, del);
    else if(del > curr->key) curr->right = delete(curr->right, del);
    else{
        if(!curr->left && !curr->right){
            free(curr);
            return NULL;
        }
        else if (curr->left == NULL || curr->right == NULL)
		{
			treeNode *temp = (curr->left) ? curr->left : curr->right;
			free(curr);
			return temp;
		}
        else if(curr->left && curr->right){
            treeNode *temp = findPredecessor(curr->left);
			curr->key = temp->key;
			curr->left = delete (curr->left, temp->key);
        }
    }

    return curr;
}

int main()
{

    return 0;
}