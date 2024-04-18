#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
} TreeNode;

// Global variable to store the root of the binary search tree
TreeNode *root = NULL;

// Function to create a new node in the binary search tree
TreeNode *createNode(int value)
{
	// Allocate memory for a new node
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));

	// Insert/Copy data into the new Node
	newNode->key = value; // Set the key value of the new node
	newNode->left = NULL; // Set the left and right child pointers to NULL
	newNode->right = NULL; // Set the left and right child pointers to NULL

	return newNode;
}

// Function to insert a node into the binary search tree
TreeNode *insertNode(TreeNode *curr, int value){
	// If the current node is NULL, create a new node with the given value
	if (curr == NULL) return createNode(value);
	
	// If the value to be inserted is less( < ) than the key of the current node, go left
	if (value < curr->key) curr->left = insertNode(curr->left, value);
	
	// If the value to be inserted is greater than ( > ) the key of the current node, go right
	else if (value > curr->key) curr->right = insertNode(curr->right, value);
	
	return curr;
}

TreeNode *printInfix(TreeNode *curr)
{
	if (curr == NULL)
		return;
	printInfix(curr->left);
	printf("%d ", curr->key); // Print tengah
	printInfix(curr->right);
}

TreeNode *printPrefix(TreeNode *curr)
{
	if (curr == NULL)
		return;
	printf("%d ", curr->key); // Print Awal
	printPrefix(curr->left);
	printPrefix(curr->right);
}

TreeNode *printPostfix(TreeNode *curr)
{
	if (curr == NULL)
		return;
	printPostfix(curr->left);
	printPostfix(curr->right);
	printf("%d ", curr->key); // print Belakanbg
}

int count(TreeNode *node)
{
	if (node == NULL) return 0;

	// Recursively count the nodes in the left and right subtrees and add 1 for the current node
	return (1 + count(node->left) + count(node->right));
}

int height(TreeNode *node)
{
	if (node == NULL) return 0;

	// Recursively calculate the height of the left and right subtrees
	int leftHeight = height(node->left);
	int rightHeight = height(node->right);

	// Return the maximum height of the left and right subtrees plus 1 for the current node
	int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
	// int maxHeight;
	// if (leftHeight > rightHeight)
	// 	maxHeight = leftHeight;
	// else
	// 	maxHeight = rightHeight;

	return (1 + maxHeight);
}

int findMin(TreeNode *node)
{
	if (node == NULL) return 0;

	// If the current node has no left child, return its key value
	if (node->left == NULL) return node->key;

	// Recursively find the minimum key value in the left subtree
	return findMin(node->left);
}

int findMax(TreeNode *node)
{
	if (node == NULL) return 0;

	// If the current node has no right child, return its key value
	if (node->right == NULL) return node->key;

	// Recursively find the maximum key value in the right subtree
	return findMax(node->right);
}

// Function to search for a key value in the binary search tree
TreeNode *search(TreeNode *curr, int find)
{
	// Base case: If the current node is NULL, the key is not found
	if (curr == NULL)
	{
		printf("%d is not found!\n", find);
		return;
	}

	// If the current node's key is equal to the key being searched for, the key is found
	if (curr->key == find)
	{
		printf("%d is found!\n", find);
		return;
	}

	// If the key being searched for is less than the current node's key, search the left subtree
	if ( find < curr->key) return search(curr->left, find);
	// If the key being searched for is greater than the current node's key, search the right subtree
	else if (find > curr->key) return search(curr->right, find);

	return curr;
}

// Delete
TreeNode *findPredecessor(TreeNode *curr) //sama seperti findMax tapi tipe data struct
{
	if (curr == NULL)
		return NULL;
	if (curr->right == NULL)
		return curr; // beda di sini dengan return curr

	return findPredecessor(curr->right);
}

TreeNode *delete(TreeNode *curr, int del)
{
	// Base Case Recursive
	if (curr == NULL)
		return NULL;
	else if (del < curr->key) curr->left = delete (curr->left, del);
	else if (del > curr->key) curr->right = delete (curr->right, del);
	else // Ketika Nilai sama dengan value
	{
		// No Child
		if (curr->left == NULL && curr->right == NULL)
		{
			free(curr);
			return NULL;
		}

		// 1 Child
		else if (curr->left == NULL || curr->right == NULL)
		{
			// TreeNode *temp;
			// if (curr->left)
			// 	temp = curr->left;
			// else
			// 	temp = curr->right;

			TreeNode *temp = (curr->left) ? curr->left : curr->right;
			free(curr);
			return temp;
		}

		// 2 Children
		else if (curr->left && curr->right)
		{
			TreeNode *temp = findPredecessor(curr->left);
			curr->key = temp->key;
			curr->left = delete (curr->left, temp->key);
		}
	}

	return curr;
}

int main()
{
	root = NULL;
	root = insertNode(root, 54);
	root = insertNode(root, 81);
	root = insertNode(root, 16);
	root = insertNode(root, 27);
	root = insertNode(root, 9);
	root = insertNode(root, 36);
	root = insertNode(root, 63);
	root = insertNode(root, 72);

	// Paragraph 1
	printf("Total nodes in BST: %d\n", count(root));
	printf("Height of BST: %d\n", height(root));
	puts(" ");

	// Paragraph 2
	printf("Infix Inorder: ");
	printInfix(root);
	printf("\n");

	printf("Prefix Preorder: ");
	printPrefix(root);
	printf("\n");

	printf("Postfix Postorder: ");
	printPostfix(root);
	printf("\n");
	puts(" ");

	// Paragraph 3
	delete(root,54);
	printf("Prefix Preorder (after delete 54): ");
	printPrefix(root);
	printf("\n");
	
	delete(root,9);
	printf("Postfix Postorder (after delete 9): ");
	printPostfix(root);
	printf("\n");

	delete(root,81);
	printf("Infix Inorder (after delete 81): ");
	printInfix(root);
	printf("\n");
	puts(" ");

	// Paragraph 4
	printf("Min Val: %d\n", findMin(root));
	printf("Max Val: %d\n", findMax(root));
	puts(" ");

	// Paragraph 5
	search(root, 72);
	search(root, 8);

	return 0;
}
