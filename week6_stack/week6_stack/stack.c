#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char order[300];

struct Node {
	struct Node* next;
	char data;
};

void create(struct Node* Head) {
	char create_data;

	printf(" Stack 1 >> ");
	scanf(" %c", &create_data);
	struct Node* stack1 = malloc(sizeof(struct Node)); // 첫 번째 stack
	Head->next = stack1;
	stack1->data = create_data;

	printf(" Stack 2 >> ");
	scanf(" %c", &create_data);
	struct Node* stack2 = malloc(sizeof(struct Node)); // 두 번째 stack
	stack1->next = stack2;
	stack2->data = create_data;

	printf(" Stack 3 >> ");
	scanf(" %c", &create_data);
	struct Node* stack3 = malloc(sizeof(struct Node)); // 세 번째 stack
	stack2->next = stack3;
	stack3->data = create_data;

	printf("\n");
}

void print(struct Node* Head, int Top) {
	struct Node* temp = Head;
	if (Top > -1) {
		printf(" Stack >>");
		for (int i = 0; i < Top + 1; i++) {
			temp = temp->next;
			printf(" %c", temp->data);
		}
	}
	else {
		printf(" Nothing to print.");
	}
	printf("\n");
}

void is_empty(int Top) {
	if (Top > -1) printf("\n Stack is not empty.\n");
	else printf(" Stack is empty.\n");
}

void is_full(int Top, int Max) {
	if (Top == Max - 1) printf(" Stack is full.\n");
	else printf(" Stack is not full.\n");
}

void element_count(int Top) {
	printf("\n Size: %d", Top + 1);
	printf("\n");
}

void push(struct Node* Head, int Top, int Max) {
	struct Node* pushStack = malloc(sizeof(struct Node));
	struct Node* temp = Head;
	char new_data;

	// stack이 가득 차지 않은 경우
	if (Top < Max - 1) {
		printf(" New Stack >> ");
		scanf(" %c", &new_data);
		pushStack->data = new_data;
		for (int i = 0; i < Top + 1; i++) {
			temp = temp->next;
		}
		temp->next = pushStack;
		pushStack->next = NULL;
	}
	// stack이 가득 찬 경우
	else printf(" Stack is full.\n");
}

void pop(struct Node* Head, int Top) {
	struct Node* temp = Head;
	
	// stack이 비어있지 않은 경우
	if (Top > -1) {
		for (int i = 0; i < Top; i++) {
			temp = temp->next;
		}
		temp->next = NULL;
	}
	// stack이 비어있는 경우
	else printf(" Stack is empty.\n");
}

void see_top(struct Node* Head, int Top) {
	struct Node* temp = Head;
	for (int i = 0; i < Top + 1; i++) {
		temp = temp->next;
	}
	printf(" Stack %d >> %c\n", Top + 1, temp->data);
}

void peek(struct Node* Head, int Top) {
	struct Node* temp = Head;
	for (int i = 0; i < Top + 1; i++) {
		temp = temp->next;
	}
	printf(" Top Stack >> %c\n", temp->data);
}

void is_member(struct Node* Head, int Top) {
	struct Node* temp = Head;
	char find_data;
	printf(" Find Data >> ");
	scanf(" %c", &find_data);
	for (int i = 0; i < Top + 1; i++) {
		temp = temp->next;
		if (temp->data == find_data) {
			printf(" Stack %d >> %c\n", i + 1, find_data);
		}
	}
}

void replace(struct Node* Head, int Top) {
	struct Node* temp = Head;
	char replace_data;
	printf(" Replace Data >> ");
	scanf(" %c", &replace_data);
	for (int i = 0; i < Top + 1; i++) {
		temp = temp->next;
	}
	temp->data = replace_data;
}

void clear(struct Node* Head, int Top) {
	struct Node* temp = Head;
	for (int i = 0; i < Top + 1; i++) {
		temp->data = 0;
	}
}

void my2(struct Node* Head, int Top) {
	struct Node* temp = Head->next;
	printf(" -1\n");
	for (int i = 0; i < Top; i++) {
		printf(" %2d %c\n", i, temp->data);
		temp = temp->next;
	}
	printf(" %2d %c\n", Top, temp->data);
}

void my3(int Top, int Max) {
	int left = Max - Top - 1;
	printf(" %d Stack left\n", left);
}


int main() {

	int max_size = 5; // stack 최대 5칸
	int top = -1;
	char command[100];
	char create_data;

	/* create */
	struct Node* head = malloc(sizeof(struct Node));
	create(head);
	top = 2;

	printf(" Stack ADT Program\n");
	printf(" (Write 'X' to end program.)\n\n");
	printf(" Command: ");
	scanf("%s", command);
	printf("\n\n");

	while (command[0] != 'X') {
		switch (command[0]) {
		/* Print */
		case 'L':
			print(head, top);
			strcat(order, " Print,");
			break;
		/* Element Count */
		case '#':
			element_count(top);
			strcat(order, " Print,");
			break;
		/* Is Empty */
		case 'E':
			is_empty(top);
			strcat(order, " Is empty,");
			break;
		/* Is Full */
		case 'F':
			is_full(top, max_size);
			strcat(order, " Is full,");
			break;
		/* Push */
		case '+':
			push(head, top, max_size);
			strcat(order, " Push,");
			top++;
			break;
		/* Pop */
		case '-':
			pop(head, top);
			strcat(order, " Pop,");
			top--;
			break;
		/* Top */
		case 'T':
			see_top(head, top);
			strcat(order, " Top,");
			break;
		/* Peek */
		case 'P':
			peek(head, top);
			strcat(order, " Peek,");
			break;
		/* Is Member */
		case '?':
			is_member(head, top);
			strcat(order, " Is member,");
			break;
		/* Replace */
		case '=':
			replace(head, top);
			strcat(order, " Replace,");
			break;
		/* Clear */
		case 'C':
			clear(head, top);
			strcat(order, " Clear,");
			top = -1;
			break;
		/* 나만의 기능 1 - 실행한 명령 목록 출력 */
		case 'a':
			strcat(order, " Order List");
			printf("%s\n", order);
			break;
		/* 나만의 기능 2 - 실제 stack처럼 출력 */
		case 'b':
			my2(head, top);
			strcat(order, " Real Stack,");
			break;
		/* 나만의 기능 3 - stack이 가득차기 전까지 몇 칸 남았는지 출력*/
		case 'c':
			my3(top, max_size);
			strcat(order, " Left Stack,");
			break;
		}
		printf("\n Command: ");
		scanf("%s", command);
	}

	return 0;
}