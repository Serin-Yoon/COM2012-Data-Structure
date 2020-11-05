#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7 // 쵀대 개수 지정

char my_queue[MAX];
int front = 0;
int rear = 0;

void init() {
	front = rear = 0;
}

void printQueue() {
	printf("\n ▷ Queue:");
	for (int i = front + 1; i < rear + 1; i++) {
		printf(" %c", my_queue[i]);
	}
	printf("\n");
}

int isEmpty() {
	if (front == rear) return 1;
	else return 0;
}

int isFull() {
	if ((rear + 1) % MAX == front) return 1;
	else return 0;
}

void enqueue() {
	char new;

	if (isFull()) {
		printf("\n ▷ Queue is Full! \n");
		return;
	}
	else {
		printf("\n ▷ New data: ");
		scanf(" %c", &new);
		rear++;
		my_queue[rear] = new;
	}
}

void dequeue() {
	if (isEmpty()) {
		printf("\n ▷ Queue is Empty! \n");
		return;
	}
	else {
		front++;
	}
}

void dataCount() {
	printf("\n ▷ Data Count: %d \n", rear - front);
}

void head() {
	printf("\n ▷ Head Index: %d \n", front);
}

void tail() {
	printf("\n ▷ Tail Index: %d \n", rear);
}

void peek() {
	printf("\n ▷ First Data: %c \n", my_queue[front + 1]);
}

void replace() {
	char replace;

	printf("\n ▷ Replace Data: ");
	scanf(" %c", &replace);

	my_queue[rear] = replace;
}

void isMember() {
	char member;
	int exists = 0; // 존재하면 1 존재하지 않으면 0

	printf("\n ▷ Find Data: ");
	scanf(" %c", &member);

	for (int i = front + 1; i < rear + 1; i++) {
		if (my_queue[i] == member) {
			printf("\n ▷ Data Exists in Index (%d) \n", i);
			exists = 1;
		}
	}

	if (!exists) {
		printf("\n ▷ Data doesn't Exist! \n");
		return;
	}
}

int main() {

	int command;
	int result;

	/* Queue 초기 설정 */
	init();
	my_queue[1] = 'd';
	my_queue[2] = 'a';
	rear += 2;

	/* 사용자에게 ADT 목록 안내 */

	printf("\n\n ================== Queue ADT ================== \n\n");
	printf("  01. Enqueue     02. Dequeue     03. Print \n");
	printf("  04. Data Count  05. Replace     06. Peek \n");
	printf("  07. Is Member   08. Is Full     09. Is Empty \n");
	printf("  10. Head        11. Tail        12. Clear \n");
	printf("  13. End Program \n\n");
	printf(" =============================================== \n\n");

	printf("\n ▶ Command: ");
	scanf(" %d", &command);

	while (command != 13) {
		switch (command) {

		case 1:
			enqueue();
			break;

		case 2:
			dequeue();
			break;

		case 3:
			printQueue();
			break;

		case 4:
			dataCount();
			break;

		case 5:
			replace();
			break;

		case 6:
			peek();
			break;

		case 7:
			isMember();
			break;

		case 8:
			result = isFull();
			if (result) printf("\n ▷ Queue is Full. \n");
			else printf("\n ▷ Queue is Not Full. \n");
			break;

		case 9:
			result = isEmpty();
			if (result) printf("\n ▷ Queue is Empty. \n");
			else printf("\n ▷ Queue is Not Empty. \n");
			break;

		case 10:
			head();
			break;

		case 11:
			tail();
			break;

		case 12:
			init();
			break;

		}

		printf("\n ▶ Command: ");
		scanf(" %d", &command);

	}
	return 0;
}