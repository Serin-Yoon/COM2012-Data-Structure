#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10 // �ִ� ���� 10���� ����

char my_array[30];
char* my_ptr = my_array;

/* ADT ��� */

void insert();
void traverseFront();
void traverseRear();
void delete();
void getData();
void replace();
void moveRight();
void moveLeft();
void dataCount();
void printArray();
void findData();
void hindData();
void ascending();
void clear();

/* ���� �Լ� */

int main() {

	int command;
	int result;

	/* �ʱ� Array create */

	my_array[0] = 's';
	my_array[1] = 'e';
	my_array[2] = 'r';
	my_array[3] = 'i';
	my_array[4] = 'n';
	
	my_ptr = my_array;
	for (int i = 0; i < strlen(my_array)-1; i++) {
		my_ptr++;
	}

	/* ����ڿ��� ADT �ȳ� */

	printf("\n\n ======================= Array ADT ======================= \n\n");
	printf("  01. Insert       02. Traverse Front   03. Traverse Rear \n");
	printf("  04. Delete       05. Get Data         06. Replace \n");
	printf("  07. Move Left    08. Move Right       09. Data Count \n");
	printf("  10. Print        11. Find Data        12. Hind Data \n");
	printf("  13. Ascending    14. Clear Array      15. End Program \n\n");
	printf(" ========================================================= \n\n");

	/*

	< �ڽŸ��� ��� >

	11(Find Data): �迭 �� ������ ã��
	12(Hind Data): �迭 �� Ư�� ���� �����
	13(Ascending): ���ĺ� ������ ����ϱ�

	*/

	printf(" �� Command: ");
	scanf("%d", &command);

	while (command != 15) {
		switch (command) {
		case 1:
			insert();
			break;

		case 2:
			traverseFront();
			break;

		case 3:
			traverseRear();
			break;

		case 4:
			delete();
			break;

		case 5:
			getData();
			break;

		case 6:
			replace();
			break;

		case 7:
			moveLeft();
			break;

		case 8:
			moveRight();
			break;

		case 9:
			dataCount();
			break;

		case 10:
			printArray();
			break;

		case 11:
			findData();
			break;

		case 12:
			hindData();
			break;

		case 13:
			ascending();
			break;

		case 14:
			clear();
			break;
		}
		printf("\n �� Command: ");
		scanf("%d", &command);
	}

	return 0;
}

void insert() {
	char new;

	// �迭 �� �� ��� (���� �Ұ���)
	if (strlen(my_array) >= MAX) {
		printf("\n �� Array is Full! \n");
		return;
	}

	// �迭 �� ���� ���� ��� (���� ����)
	else {
		printf("\n �� New Data: ");
		scanf(" %c", &new);
		my_array[strlen(my_array)] = new;
		my_ptr++;
	}
}

void traverseFront() {
	// ������ �Ǿ����� �̵�
	my_ptr = my_array;
	printf("\n �� Current Pointer: %c\n", *my_ptr);
}

void replace() {
	char new;
	char* temp = my_ptr;
	printf("\n �� Change Data: ");
	scanf(" %c", &new);

	// ���� ���ĺ� �Է��� ��� (��ü�� �ʿ� ����)
	if (new == *temp) {
		printf("\n �� Same Data! \n");
		return;
	}

	// �ٸ� ���ĺ� �Է��� ��� (��ü ����)
	else {
		*temp = new;
		my_ptr = temp;
	}
}

void delete() {

	int ptr_index;
	char findData;
	char* temp = my_array;

	// �迭 ����ִ� ��� (���� �Ұ���)
	if (strlen(my_array) <= 0) {
		printf("\n �� Array is Empty! \n");
		return;
	}

	// �迭 ������� ���� ��� (���� ����)
	else {

		// ���� �������� index Ȯ���ϱ�
		for (int i = 0; i < strlen(my_array); i++) {
			if (*temp == *my_ptr) ptr_index = i;
			temp++;
		}

		// ������ index���� ���������� �� ������ ����
		for (int i = ptr_index; i < strlen(my_array) - 1; i++) {
			*my_ptr = *(my_ptr + 1);
			my_ptr++;
		}
		my_array[strlen(my_array) - 1] = '\0';
		my_ptr = my_array;
	}
}

void moveLeft() {

	int move;
	char* temp = my_array;
	int ptr_index;

	// ���� �������� index Ȯ���ϱ�
	for (int i = 0; i < strlen(my_array); i++) {
		if (*temp == *my_ptr) ptr_index = i;
		temp++;
	}

	// �� ����(ó��)�� ��ġ�ؼ� ���� �̵� �Ұ����� ���
	if (ptr_index == 0) {
		printf("\n �� Cannot move Left! \n");
		return;
	}

	else {
		printf("\n �� (Possible Move: 0 ~ %d) \n", ptr_index);
		printf("\n �� How Many Move: ");
		scanf("%d", &move);

		// �迭 ���� �̻����� �̵��ϰ��� �ϴ� ��� (�̵� �Ұ���)
		if (move > ptr_index) {
			printf("\n �� Too Much Move! \n");
			return;
		}

		else {
			for (int i = 0; i < move; i++) {
				my_ptr--;
			}
			printf("\n �� Current Pointer: %c\n", *my_ptr);
		}
	}
}

void moveRight() {

	int move;
	char* temp = my_array;
	int ptr_index;

	// ���� �������� index Ȯ���ϱ�
	for (int i = 0; i < strlen(my_array); i++) {
		if (*temp == *my_ptr) ptr_index = i;
		temp++;
	}

	// �� ������(������)�� ��ġ�ؼ� ������ �̵� �Ұ����� ���
	if (ptr_index == strlen(my_array) - 1) {
		printf("\n �� Cannot move Right! \n");
		return;
	}

	else {
		printf("\n �� (Possible Move: 0 ~ %d) \n", strlen(my_array) - ptr_index - 1);
		printf("\n �� How Many Move: ");
		scanf("%d", &move);

		// �̵� ������ ������ ��� ��� (�̵� �Ұ���)
		if (move > strlen(my_array) - ptr_index - 1) {
			printf("\n �� Too Much Move! \n");
			return;
		}

		else {
			for (int i = 0; i < move; i++) {
				my_ptr++;
			}
			printf("\n �� Current Pointer: %c\n", *my_ptr);
		}
	}
}

void traverseRear() {
	// ������ �ǵڷ� �̵�
	my_ptr = my_array;
	for (int i = 0; i < strlen(my_array) - 1; i++) {
		my_ptr++;
	}
	printf("\n �� Current Pointer: %c\n", *my_ptr);
}

void printArray() {
	printf("\n �� Total Array: ");
	for (int i = 0; i < strlen(my_array); i++) {
		printf("%c ", my_array[i]);
	}
	printf("\n");
}

void findData() {
	char find;
	char* temp = my_array;
	int exist = 0; // �����ϸ� 1 �������� ������ 0

	printf("\n �� Which Data: ");
	scanf(" %c", &find);

	printf("\n ��");
	for (int i = 0; i < strlen(my_array); i++) {
		if (*temp == find) {
			printf(" Exists in index (%d) ", i);
			exist = 1;
		}
		temp++;
	}

	if (!exist) {
		printf(" Data doesn't exist! \n");
		return;
	}
	else printf("\n");
}

void hindData() {
	char find;
	char* temp = my_array;
	int exist = 0; // �����ϸ� 1 �������� ������ 0

	printf("\n �� Which Data: ");
	scanf(" %c", &find);

	for (int i = 0; i < strlen(my_array); i++) {
		if (*temp == find) {
			*temp = '*';
			exist = 1;
		}
		temp++;
	}

	if (!exist) {
		printf(" Data doesn't exist! \n");
		return;
	}
}

void getData() {
	printf("\n �� Current Pointer: %c\n", *my_ptr);
}

void dataCount() {
	printf("\n �� Total Data: %d \n", strlen(my_array));
}

void ascending() {

	char temp;

	for (int i = 0; i < strlen(my_array) - 1; i++) {
		for (int j = i + 1; j < strlen(my_array); j++) {
			if (my_array[i] > my_array[j]) {
				temp = my_array[i];
				my_array[i] = my_array[j];
				my_array[j] = temp;
			}
		}
	}
}

void clear() {
	int length = strlen(my_array);
	for (int i = 0; i < length; i++) {
		my_array[i] = '\0';
	}
}