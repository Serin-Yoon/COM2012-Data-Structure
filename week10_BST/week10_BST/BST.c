#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int inorderArray[100];

typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;


treeNode* insertNode(treeNode* ptr, int x) {
	treeNode* newNode;

	if (ptr == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < ptr->data) ptr->left = insertNode(ptr->left, x);
	else if (x > ptr->data) ptr->right = insertNode(ptr->right, x);
	else printf("\n Data Already Exist ! \n");

	return ptr;
}

void deleteNode(treeNode* root, int d) {
	treeNode* parent, * child;
	treeNode* ptr, * s, * s_parent;

	parent = NULL;
	ptr = root;
	while ((ptr != NULL) && (ptr->data != d)) {
		parent = ptr;
		if (d < ptr->data) ptr = ptr->left;
		else ptr = ptr->right;
	}
	if (ptr == NULL) {
		printf("\n Data Doesn't Exist! \n");
	}

	// 자식 노드 없는 경우
	if ((ptr->left == NULL) && (ptr->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == ptr) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 왼쪽 자식 노드 하나 있는 경우
	else if ((ptr->left == NULL) || (ptr->right == NULL)) {
		if (ptr->left != NULL) child = ptr->left;
		else child = ptr->right;

		if (parent != NULL) {
			if (parent->left == ptr) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 왼쪽, 오른쪽 자식 노드 있는 경우
	else {
		s_parent = ptr;
		s = ptr->left;

		while (s->right != NULL) {
			s_parent = s;
			s = s->right;
		}
		if (s_parent->left == s) s_parent->left = s->left;
		else s_parent->right = s->left;
		ptr->data = s->data;
		ptr = s;
	}
	free(ptr);
}

treeNode* findNode(treeNode* root, int x) {
	treeNode* ptr;
	ptr = root;

	while (ptr != NULL) {
		if (x < ptr->data) ptr = ptr->left;
		else if (x == ptr->data) return ptr;
		else ptr = ptr->right;
	}
	return ptr;
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

int height(treeNode* root) {
	treeNode* ptr;
	ptr = root;
	int leftHeight, rightHeight;

	if (!root) return 0;
	else {
		leftHeight = height(root->left);
		rightHeight = height(root->right);
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
}

int countNode(treeNode* root) {

	if (!root) return 0;
	else return countNode(root->left) + countNode(root->right) + 1;

}

int main() {

	treeNode* root = NULL;
	treeNode* foundNode = NULL;
	treeNode* minNode = NULL;
	treeNode* maxNode = NULL;
	treeNode* parent = NULL;
	treeNode* rightChild = NULL;
	treeNode* leftChild = NULL;

	int data;
	int command;

	/* 초기 트리 */

	root = insertNode(root, 40);
	insertNode(root, 25);
	insertNode(root, 30);
	insertNode(root, 45);
	insertNode(root, 55);
	insertNode(root, 10);
	insertNode(root, 75);

	/* 사용자에게 ADT 목록 안내 */


	printf("\n  ==== Binary Search Tree ADT ====\n\n");
	printf("   1. Insert Node\n");
	printf("   2. Delete Node\n");
	printf("   3. Find Node\n");
	printf("   4. Get Min\n");
	printf("   5. Get Max\n");
	printf("   6. Inorder Traversal\n");
	printf("   7. Right-Root-Left Traversal\n");
	printf("   8. Height\n");
	printf("   9. Count Node\n");
	printf("   10. Get Right Child\n");
	printf("   11. Get Left Child\n");
	printf("   12. Clear\n");
	printf("   13. End Program\n\n");
	printf("  ---------------------------------\n\n");

	printf(" Command: ");
	scanf("%d", &command);

	while (command != 13) {
		int number;

		switch (command) {
		case 1:
			printf("\n New Node: ");
			scanf("%d", &number);
			insertNode(root, number);
			break;

		case 2:
			printf("\n Delete Node: ");
			scanf("%d", &number);
			deleteNode(root, number);
			break;

		case 3:
			printf("\n Find Node: ");
			scanf("%d", &number);
			foundNode = findNode(root, number);
			if (foundNode != NULL) printf("\n %d Exist! \n", foundNode->data);
			break;

		case 4:
			minNode = getMin(root);
			printf("\n Min Data: %d \n", minNode->data);
			break;

		case 5:
			maxNode = getMax(root);
			printf("\n Max Data: %d \n", maxNode->data);
			break;

		case 6:
			printf("\n Inorder Traversal: ");
			inorderTraversal(root);
			printf("\n");
			break;

		case 7:
			printf("\n Right Root Left Traversal: ");
			rightrootleftTraversal(root);
			printf("\n");
			break;

		case 8:
			number = height(root);
			printf("\n Height: %d \n", number);
			break;

		case 9:
			number = countNode(root);
			printf("\n Total Node: %d \n", number);
			break;

		case 10:
			printf("\n Parent Node: ");
			scanf("%d", &number);
			parent = getRight(root, number);
			if ((parent != NULL) && (parent->right != NULL)) {
				printf("\n Right Child: %d \n", parent->right->data);
			}
			else printf("\n Data Doesn't Exist! \n");
			break;

		case 11:
			printf("\n Parent Node: ");
			scanf("%d", &number);
			parent = getLeft(root, number);
			if ((parent != NULL) && (parent->left != NULL)) {
				printf("\n Left Child: %d \n", parent->left->data);
			}
			else printf("\n Data Doesn't Exist! \n");
			break;

		case 12:
			root = NULL;
			break;
		}
		printf("\n Command: ");
		scanf("%d", &command);
	}
}