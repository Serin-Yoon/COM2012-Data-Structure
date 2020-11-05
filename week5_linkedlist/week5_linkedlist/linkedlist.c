#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* next;
	char key;
} Node;

/* ADT 목록 */

void add(Node* head, Node* ptr);
void delete(Node* head, Node* ptr);
void replace(Node* head, Node* ptr);
void getData(Node* head, Node* ptr);
int dataCount(Node* head);
void printList(Node* head);
void isMember(Node* head);
void isEmpty(Node* head);


/* 메인 */

int main() {

	int command;
	int result; // 다양한 함수 실행 값 받기 위한 임의의 변수

	Node* head = malloc(sizeof(Node));
	Node* my_ptr = head;

	/* 초기 Linked List */

	Node* node1 = malloc(sizeof(Node));
	head->next = node1;
	node1->key = 'a';

	Node* node2 = malloc(sizeof(Node));
	node1->next = node2;
	node2->key = 'b';

	Node* node3 = malloc(sizeof(Node));
	node2->next = node3;
	node3->key = 'c';

	Node* node4 = malloc(sizeof(Node));
	node3->next = node4;
	node4->key = 'd';
	node4->next = NULL;
	my_ptr = node4;

	/* 사용자에게 ADT 안내 */

	printf("\n\n =================== Linked List ADT =================== \n\n");
	printf("  1. Add              2. Delete          3. Replace \n");
	printf("  4. Get Data         5. Data Count      6. Print \n");
	printf("  7. Traverse Front   8. Traverse Rear   9. Is Member \n");
	printf(" 10. Move Left       11. Move Right     12. Is Empty \n");
	printf(" 13. Clear List      14. End Program \n\n");
	printf(" =======================================================\n\n");

	printf(" ▶ Command: ");
	scanf("%d", &command);

	while (command != 14) {
		switch (command) {
		case 1:
			add(head, my_ptr);
			my_ptr = my_ptr->next;
			break;

		case 2:
			delete(head, my_ptr);
			my_ptr = head->next;
			break;

		case 3:
			replace(head, my_ptr);
			break;

		case 4:
			getData(head, my_ptr);
			break;

		case 5:
			result = dataCount(head);
			printf("\n ▷ Data Count: %d \n", result);
			break;

		case 6:
			printList(head);
			break;

		case 7:
			my_ptr = head->next;
			printf("\n ▷ Current Pointer: %c \n", my_ptr->key);
			break;

		case 8:
			my_ptr = head->next;
			while (my_ptr->next != NULL) {
				my_ptr = my_ptr->next;
			}
			printf("\n ▷ Current Pointer: %c \n", my_ptr->key);
			break;

		case 9:
			isMember(head);
			break;

		case 10: {
			int move;
			int can_move; // 최대 이동 가능 수
			int i = 0;
			Node* temp = my_ptr;

			while (temp != NULL) {
				temp = temp->next;
				i++;
			}
			result = dataCount(head);
			can_move = result - i;

			if (can_move <= 0) {
				printf("\n ▷ Cannot move Left! \n");
				break;
			}
			else {
				printf("\n ▷ How much Move: ");
				scanf("%d", &move);
				my_ptr = head->next;
				for (int j = 0; j < result - i - move; j++) {
					my_ptr = my_ptr->next;
				}
			}
			break;
		}

		case 11: {
			int move;

			if (my_ptr->next == NULL) {
				printf("\n ▷ Cannot move Right! \n");
				break;
			}
			else {
				printf("\n ▷ How much Move: ");
				scanf("%d", &move);
				for (int i = 0; i < move; i++) {
					my_ptr = my_ptr->next;
				}
			}
			break;
		}

		case 12:
			isEmpty(head);
			break;

		case 13:
			head->next = NULL;
			my_ptr = head;
			break;

		}

		printf("\n ▶ Command : ");
		scanf("%d", &command);
	}

	return 0;
}

void add(Node* head, Node* ptr) {

	char new;
	Node* newNode;
	Node* temp;

	printf("\n ▷ New Data: ");
	scanf(" %c", &new);

	newNode = (Node*)malloc(sizeof(Node));
	newNode->key = new;

	// 맨 뒤에 삽입 (포인터가 맨 뒤인 경우)
	if (ptr->next == NULL) {
		ptr->next = newNode;
		newNode->next = NULL;
	}

	else {
		temp = ptr->next;
		newNode = temp;
		ptr->next = newNode;
	}
}

void delete(Node* head, Node* ptr) {
	int count;
	int i = 0; //test
	count = dataCount(head);

	while (ptr->next != NULL) {
		ptr->key = ptr->next->key;
		ptr = ptr->next;
	}

	ptr = head;
	while (ptr->next->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = NULL;

}

void replace(Node* head, Node* ptr) {

	char replace;

	printf("\n ▷ Replace Data: ");
	scanf(" %c", &replace);
	ptr->key = replace;

}

void getData(Node* head, Node* ptr) {
	printf("\n ▷ Current Pointer: %c \n", ptr->key);
}

int dataCount(Node* head) {

	Node* temp = head->next;
	int count = 0;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	return count;
}

void printList(Node* head) {

	Node* temp = head->next;

	printf("\n ▷ Total Linked List: ");

	while (temp != NULL) {
		printf(" %c", temp->key);
		temp = temp->next;
	}
	printf("\n");
}

void isMember(Node* head) {

	Node* temp = head->next;
	char find;
	int index = 0;
	int member = 0; // 존재하면 1 존재하지 않으면 0

	printf("\n ▷ Find Data: ");
	scanf(" %c", &find);

	while (temp != NULL) {
		if (temp->key == find) {
			printf("\n ▷ Data Exists in index (%d) \n", index);
			member = 1;
		}
		index++;
		temp = temp->next;
	}

	if (!member) {
		printf("\n ▷ Data doesn't Exist! \n");
		return;
	}
}

void isEmpty(Node* head) {
	int count;
	count = dataCount(head);
	if (!count) printf("\n ▷ List is Empty. \n");
	else printf("\n ▷ List is Not Empty. \n");
}