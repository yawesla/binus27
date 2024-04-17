#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node* left;
	struct node* right;
}*root = NULL,*temp;

void inputnode(struct node* newnode,struct node* root){
	if(newnode->num > root->num){
		if(root->right == NULL) root->right = newnode;
		else inputnode(newnode,root->right);
	}else if(newnode->num < root->num){
		if(root->left == NULL) root->left = newnode;
		else inputnode(newnode,root->left);
	}
}

void scandata(){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	scanf("%d",&newnode->num);
	newnode->left = newnode->right = NULL;
    
	if(root == NULL) root = newnode;
	inputnode(newnode,root);
}

void printdatainfix(struct node* root){
	if(root == NULL) return;
	printdatainfix(root->left);
	printf("%d ",root->num);
	printdatainfix(root->right);
}

void printdataprefix(struct node* root){
	if(root == NULL) return;
	printf("%d ",root->num);
	printdataprefix(root->left);
	printdataprefix(root->right);
}

void printdatapostfix(struct node* root){
	if(root == NULL) return;
	printdatapostfix(root->left);
	printdatapostfix(root->right);
	printf("%d ",root->num);
}

struct node* rightmost(struct node* root){
	while(root->right != NULL) root = root->right;
	return root;
}

struct node* deletenode(int target,struct node* root){
	if(root == NULL) return NULL;
	if(root->num < target) root->right = deletenode(target,root->right);
	else if(root->num > target) root->left = deletenode(target,root->left);
	else{
		if(root->left == NULL){
			temp = root->right;
			free(root);
			return temp;
		} else if(root->right == NULL){
			temp = root->left;
			free(root);
			return temp;
		}
		temp = rightmost(root->left);
		root->num = temp->num;
		root->left = deletenode(temp->num,root->left);
	}
	return root;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int i = 0;i < tc;i++){
		scandata();
	}
	printf("Prefix : ");
	printdataprefix(root);
	printf("\nInfix : ");
	printdatainfix(root);
	printf("\nPostfix : ");
	printdatapostfix(root);
	puts("");


	scanf("%d",&tc);
	for(int i = 0;i < tc;i++){
		int target;
		scanf("%d",&target);
		root = deletenode(target,root);
	}
	printf("Postfix : ");
	printdatapostfix(root);
}


// 11
// 30 37 15 26 7 32 45 19 35 28 42