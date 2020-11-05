#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
	int height;
} treeNode;

int height(treeNode* N) {
	if (N == NULL) return 0;
	return N->height;
}

int getmax(int a, int b) {
	return (a > b) ? a : b;
}

treeNode* create(int key) {
	treeNode* node = (treeNode*)
		malloc(sizeof(treeNode));
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

treeNode* rightRotate(treeNode* y) {
	treeNode* x = y->left;
	treeNode* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = getmax(height(y->left), height(y->right)) + 1;
	x->height = getmax(height(x->left), height(x->right)) + 1;

	return x;
}

treeNode* leftRotate(treeNode* x) {
	treeNode* y = x->right;
	treeNode* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = getmax(height(x->left), height(x->right)) + 1;
	y->height = getmax(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(treeNode* N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

treeNode* insertNode(treeNode* node, int key) {

	if (node == NULL)	return(create(key));

	if (key < node->data)	node->left = insertNode(node->left, key);
	else if (key > node->data)	node->right = insertNode(node->right, key);
	else return node;

	node->height = 1 + getmax(height(node->left),
		height(node->right));

	/* balance factor 확인 (4가지 경우 존재) */
	int balance = getBalance(node);

	// Left Left Rotation
	if (balance > 1 && key < node->left->data)
		return rightRotate(node);

	// Right Right Rotation
	if (balance < -1 && key > node->right->data)
		return leftRotate(node);

	// Left Right Rotation
	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Rotation
	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

treeNode* minValueNode(treeNode* node) {
	treeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

treeNode* deleteNode(treeNode* root, int key) {

	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);

	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	else {

		if ((root->left == NULL) || (root->right == NULL)) {
			treeNode* temp = root->left ? root->left : root->right;


			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else *root = *temp;

			free(temp);
		}
		else {
			treeNode* temp = minValueNode(root->right);

			root->data = temp->data;

			root->right = deleteNode(root->right, temp->data);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + getmax(height(root->left),
		height(root->right));

	/* balance factor 확인 (4가지 경우 존재) */
	int balance = getBalance(root);

	// Left Left Rotation
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Rotation
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Rotation
	if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

	// Right Left Rotation
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

treeNode* findNode(treeNode* root, int key) {
	treeNode* ptr;
	ptr = root;

	while (ptr != NULL) {
		if (key < ptr->data) ptr = ptr->left;
		else if (key == ptr->data) return ptr;
		else ptr = ptr->right;
	}
	return ptr;
}

treeNode* getMin(treeNode* root) {
	treeNode* ptr;
	ptr = root;

	while (ptr->left != NULL) {
		ptr = ptr->left;
	}

	return ptr;
}

treeNode* getMax(treeNode* root) {
	treeNode* ptr;
	ptr = root;

	while (ptr->right != NULL) {
		ptr = ptr->right;
	}

	return ptr;
}

void inorderTraversal(treeNode* root) {
	if (root) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

void rightrootleftTraversal(treeNode* root) {
	if (root) {
		rightrootleftTraversal(root->right);
		printf("%d ", root->data);
		rightrootleftTraversal(root->left);
	}
}

int countNode(treeNode* root) {

	if (!root) return 0;
	else return countNode(root->left) + countNode(root->right) + 1;

}

treeNode* getRight(treeNode* root, int x) {
	treeNode* ptr;
	ptr = root;

	while (ptr != NULL) {
		if (x < ptr->data) ptr = ptr->left;
		else if (x == ptr->data) return ptr;
		else ptr = ptr->right;
	}
	return ptr;
}

treeNode* getLeft(treeNode* root, int x) {
	treeNode* ptr;
	ptr = root;

	while (ptr != NULL) {
		if (x < ptr->data) ptr = ptr->left;
		else if (x == ptr->data) return ptr;
		else ptr = ptr->right;
	}
	return ptr;
}


int main()
{
	treeNode* root = NULL;
	treeNode* parent = NULL;
	treeNode* result = NULL;

	int command;
	int number;
	int a;

	/* 초기 트리 */

	root = insertNode(root, 20);
	root = insertNode(root, 30);
	root = insertNode(root, 10);
	root = insertNode(root, 0);
	root = insertNode(root, 5);
	root = insertNode(root, 40);
	root = insertNode(root, 90);
	root = insertNode(root, 55);
	root = insertNode(root, 50);

	/* 사용자에게 ADT 목록 안내 */

	printf("\n  ========= AVL Tree ADT =========\n\n");
	printf("   1. Insert Node\n");
	printf("   2. Delete Node\n");
	printf("   3. Find Node\n");
	printf("   4. Get Min\n");
	printf("   5. Get Max\n");
	printf("   6. Print\n");
	printf("   7. Inorder Traversal\n");
	printf("   8. Right-Root-Left Traversal\n");
	printf("   9. Balance Factor\n");
	printf("   10. Height\n");
	printf("   11. Count Node\n");
	printf("   12. Get Right Child\n");
	printf("   13. Get Left Child\n");
	printf("   14. Clear\n");
	printf("   15. End Program\n\n");
	printf("  ---------------------------------\n\n");

	printf(" Command: ");
	scanf("%d", &command);

	while (command != 15) {
		switch (command) {
		case 1:
			printf("\n New Node >> ");
			scanf("%d", &number);
			insertNode(root, number);
			break;

		case 2:
			printf("\n Delete Node >> ");
			scanf("%d", &number);
			deleteNode(root, number);
			break;

		case 3:
			printf("\n Find Node >> ");
			scanf("%d", &number);
			result = findNode(root, number);
			if (result != NULL) printf("\n %d Exist! \n", result->data);
			else printf("\n Node doesn't Exist! \n");
			break;

		case 4:
			result = getMin(root);
			printf("\n Min Data >> %d \n", result->data);
			break;
		case 5:
			result = getMax(root);
			printf("\n Max Data >> %d \n", result->data);
			break;

		case 7:
			printf("\n Inorder Traversal >> ");
			inorderTraversal(root);
			printf("\n");
			break;

		case 8:
			printf("\n Right Root Left Traversal >> ");
			rightrootleftTraversal(root);
			printf("\n");
			break;
		case 9:
			printf("\n Which Node >> ");
			scanf("%d", &number);
			result = findNode(root, number);
			if (result == NULL) printf("\n Node doesn't Exist! \n");
			else {
				a = getBalance(result);
				printf("\n Node Balance >> %d \n", a);
			}
			break;

		case 10:
			printf("\n Which Node >> ");
			scanf("%d", &number);
			if (result == NULL) printf("\n Node doesn't Exist! \n");
			else {
				a = height(result);
				printf("\n Node Height >> %d \n", a);
			}
			break;

		case 11:
			a = countNode(root);
			printf("\n Total Node >> %d \n", a);
			break;

		case 12:
			printf("\n Parent Node >> ");
			scanf("%d", &number);
			parent = getRight(root, number);
			if ((parent != NULL) && (parent->right != NULL)) {
				printf("\n Right Child >> %d \n", parent->right->data);
			}
			else printf("\n Data Doesn't Exist! \n");
			break;

		case 13:
			printf("\n Parent Node >> ");
			scanf("%d", &number);
			parent = getLeft(root, number);
			if ((parent != NULL) && (parent->left != NULL)) {
				printf("\n Left Child >> %d \n", parent->left->data);
			}
			else printf("\n Data Doesn't Exist! \n");
			break;

		case 14:
			root = NULL;
			break;
		}
		printf("\n Command: ");
		scanf("%d", &command);
	}


	return 0;
}